#include "Simulation.h"
#include<algorithm>
#include "Log.h"


Simulation::Simulation(int i, int j) : _data{i, j}, _agentTemplate{{0,0}, 1.0, 0, 10}
{
    //TODO
}

Simulation::Simulation(int i, int j, float cellWidth, float cellHeight) : _data{i, j, cellWidth, cellHeight}, _agentTemplate{{0,0}, 1.0, 2.0, 10},_gravityVector{0.0f,1.0f}
{
    
}

Simulation& Simulation::setAgentTemplate(const EuglenaAgent& agentTemplate)
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


Simulation& Simulation::update(float deltaTime)
{
    //spawn new agents
    for (auto& emitter : _emitters)
        emitter.update(deltaTime, _agents);

    //move all agents
    for (auto it = _agents.begin(); it != _agents.end();)
    {
        it->clearPerception();
        for (auto& light :_lightLines)
        {
           
            auto inte = light.getLightIntensityAt(it->getPosition());
            if (inte > 1.0e-10)
            {
                it->addIntensity(inte);
                it->addDirection(light.getDirectionAt(it->getPosition()));
            }
        }

        it->update(_gravityVector, deltaTime);

        //Remove Agents outside of the Simulation
        if (isOutside(*it))
            Log::print("Delete Agent");
        isOutside(*it) ? it = _agents.erase(it) : ++it;
    }
    //update dynamic lights

    return *this;
}

Simulation& Simulation::draw(sf::RenderWindow& renderWindow)
{
    //Render Grid
    _data.draw(renderWindow);

    //Render Emitter
    for (auto const& emitter : _emitters)
        emitter.draw(renderWindow);

    //Render Agents
    for (auto const& agent : _agents)
        agent.draw(renderWindow);


    //render lighta
    for (auto& light : _lightEmitters)
        light.draw(renderWindow);

    for (auto& light : _lightLines)
        light.draw(renderWindow);

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

Simulation& Simulation::addLightLine(const LightLine& lightLine)
{
    _lightLines.push_back(lightLine);
    return *this;
}

Simulation& Simulation::spawnAgentAt(glm::vec2 position)
{
    auto newAgent = EuglenaAgent{position,_agentTemplate.getIntensityThreshold(),_agentTemplate.getSpeed(),_agentTemplate.getRadius()};

    _agents.push_back(newAgent);
    return *this;
}

glm::vec2 Simulation::getGradient(int i, int j)
{
    glm::vec2 gradient{0,0};
    if (i > 0 && i < _data.getImax() - 1)
    {
        if (j > 0 && j < _data.getJmax() - 1)
        {
            auto i_x = _data.getCell(i + 1, j).getDynamicLightIntensity() - 2 * _data.getCell(i, j).getDynamicLightIntensity() + _data.getCell(i - 1, j).getDynamicLightIntensity();
            auto i_y = _data.getCell(i, j + 1).getDynamicLightIntensity() - 2 * _data.getCell(i, j).getDynamicLightIntensity() + _data.getCell(i, j - 1).getDynamicLightIntensity();

            gradient = {i_x ,i_y};
        }
    }
    return gradient;
}

glm::vec2 Simulation::getGradient(float x, float y)
{
    auto index = _data.convertCoordinateToIndex({x,y});
    return getGradient(index.x, index.y);
}

glm::vec2 Simulation::getGradient(const glm::vec2& position)
{
    auto index = _data.convertCoordinateToIndex({position.x,position.y});
    return getGradient(index.x, index.y);
}

glm::vec2 Simulation::getGradient(const EuglenaAgent& agent)
{
    return getGradient(agent.getPosition());
}

Simulation::~Simulation()
{
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
