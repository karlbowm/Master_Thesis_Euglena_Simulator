#include "Simulation.h"
#include<algorithm>


Simulation::Simulation(int i, int j) : _data{ i, j },  _agentTemplate{ { 0,0 }, 1.0, 0, 10 }
{
    //TODO
}

Simulation::Simulation(int i, int j, float cellWidth, float cellHeight) : _data{ i, j, cellWidth, cellHeight }, _agentTemplate{ { 0,0 }, 1.0, 0, 10 }
{
}

Simulation& Simulation::setAgentTemplate(EuglenaAgent& agentTemplate)
{
    _agentTemplate = agentTemplate;
    for (auto& emitter : _emitters)
        emitter.setAgentTemplate(_agentTemplate);


    return *this;
}

Simulation& Simulation::addEmitter(EuglenaEmitter emitter)
{
    emitter.setAgentTemplate(_agentTemplate);
    _emitters.push_back(emitter);

    return *this;
}

Simulation& Simulation::setStaticLight(const std::vector<glm::ivec2> coordinates, float intensity)
{
    for (auto& pair : coordinates)
    {
        if (pair.x < _data.getImax() && pair.y < _data.getJmax())
        {
            _data.getCell(pair.x, pair.y).setStaticLightIntensity(intensity);
        }
    }
    return *this;
}

Simulation& Simulation::update(float deltaTime)
{
    //update grid values



    for (auto & emitter : _emitters)
        emitter.update(deltaTime, _agents);


    for (auto it = _agents.begin(); it != _agents.end();)
    {
        auto percIntensity = _data.getCell(*it).getTotalIntensity();
        //Log::print("Intensity: " + std::to_string(percIntensity));
        glm::vec2 direction = getGradient(*it);
        //Log::print("Gradient: " + std::to_string(direction.x)+","+std::to_string(direction.y));
        it->setGradient(direction);
        it->update(_gravityVector, deltaTime, percIntensity);

        //Remove Agents outside of the Simulation
        isOutside(*it) ? it = _agents.erase(it) : ++it;
    }
    updateDynamicLight();
    return *this;
}

Simulation& Simulation::draw(sf::RenderWindow& renderWindow)
{
    //Render Grid
    _data.draw(renderWindow);

    //Render Emitter
    for (auto const & emitter : _emitters)
        emitter.draw(renderWindow);

    //Render Agents
    for (auto const& agent : _agents)
        agent.draw(renderWindow);
    return *this;
}

int Simulation::getCellCountX() const
{
    return _data.getImax();
}

float Simulation::getCellSizeX() const
{
    return _data.getWidth();
}

float Simulation::getCellSizeY() const
{
    return _data.getHeight();
}

int Simulation::getCellCountY() const
{
    return _data.getJmax();
}

Simulation& Simulation::addAgent(const EuglenaAgent& agent)
{
    _agents.push_back(agent);
    return *this;
}

Simulation& Simulation::addLightEmitter(const LightEmitter& lightEmitter)
{
    _lightEmitters.push_back(lightEmitter);
    return *this;
}

Simulation& Simulation::spawnAgentAt(glm::vec2 position)
{
    auto newAgent = _agentTemplate;
    newAgent.setPosition(position);

    _agents.push_back(newAgent);
    return *this;
}

glm::vec2 Simulation::getGradient(int i, int j)
{
    glm::vec2 gradient{ 0,0 };
    if (i > 0 && i < _data.getImax() - 1)
    {
        if (j > 0 && j < _data.getJmax() - 1)
        {
            auto i_x = _data.getCell(i + 1, j).getDynamicLightIntensity() - 2 * _data.getCell(i, j).getDynamicLightIntensity() + _data.getCell(i - 1, j).getDynamicLightIntensity();
            auto i_y = _data.getCell(i, j + 1).getDynamicLightIntensity() - 2 * _data.getCell(i, j).getDynamicLightIntensity() + _data.getCell(i, j - 1).getDynamicLightIntensity();

            gradient = { i_x ,i_y };
        }
    }
    return gradient;
}

glm::vec2 Simulation::getGradient(float x, float y)
{
    auto index = _data.convertCoordinateToIndex({ x,y });
    return getGradient(index.x, index.y);
}

glm::vec2 Simulation::getGradient(const glm::vec2& position)
{
    auto index = _data.convertCoordinateToIndex({ position.x,position.y });
    return getGradient(index.x, index.y);
}

glm::vec2 Simulation::getGradient(const EuglenaAgent& agent)
{
    return getGradient(agent.getPosition());
}

Simulation::~Simulation()
{
}



void Simulation::updateDynamicLight()
{
    for (const auto& lightSource : _lightEmitters)
    {
        auto intenisty = lightSource.getIntensity();
        auto direction = lightSource.getDirection();
        auto position = lightSource.getPosition();


        //TODO: actually test
        while (intenisty > 1 && !isOutside(position))
        {

            _data.getCell(position).setDynamicLightIntensity(intenisty);
            //will that actually work, if yes, amazing
            auto isInCell = [&](const EuglenaAgent&agent) {  return(_data.convertCoordinateToIndex(agent.getPosition()) == position); };

            auto agentsInCell = std::count_if(_agents.begin(), _agents.end(), isInCell);
            intenisty = (intenisty - agentsInCell*_agentTemplate.getAbsorbtionRate())*0.90f;
            //_data.getCell(position).setDynamicLightIntensity(intenisty);
            position = shiftPositionInDirection(position, direction);

        }
    }
}

glm::ivec2 Simulation::shiftPositionInDirection(const glm::vec2& position, Direction direction)
{
    switch (direction)
    {
    case Direction::N:
        return{ position.x,position.y - 1 };

    case Direction::S:
        return{ position.x,position.y + 1 };

    case Direction::E:
        return{ position.x + 1,position.y };

    case Direction::W:
        return{ position.x - 1,position.y };
    default:
        return position;
    }
}

bool Simulation::isOutside(const glm::vec2& position) const
{
    return _data.isOutside(position);

}


bool Simulation::isOutside(const glm::ivec2& index) const
{
    return _data.isOutside(index);

}
bool Simulation::isOutside(const EuglenaAgent& agent) const
{
    return _data.isOutside(agent.getPosition());
}
