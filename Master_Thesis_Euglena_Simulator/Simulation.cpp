#include "Simulation.h"
#include<algorithm>


Simulation::Simulation(int i, int j) : _data{ i, j }, _gravityVector{ 0.0, -1.0 }, _agentTemplate{ { 0,0 }, 1.0, 0, 10 }
{
    //TODO
}

Simulation::Simulation(int i, int j, float cellWidth, float cellHeight) : _data{ i, j, cellWidth, cellHeight }, _gravityVector{ 0.0, -1.0 }, _agentTemplate{ { 0,0 }, 1.0, 0, 10 }
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

void Simulation::setStaticLight(const std::vector<glm::ivec2> coordinates, float intensity)
{
    for (auto& pair : coordinates)
    {
        if (pair.x < _data.getImax() && pair.y < _data.getJmax())
        {
            _data.getCell(pair.x, pair.y).setStaticLightIntensity(intensity);
        }
    }
}

void Simulation::update(float deltaTime)
{
    //update grid values

    for (auto & emitter : _emitters)        
        emitter.update(deltaTime, _agents);


    for (auto agent_it = _agents.begin(); agent_it != _agents.end();)
    {
        auto percIntensity = _data.getCell(*agent_it).getTotalIntensity();

        glm::vec2 direction = getGradient(*agent_it);
        agent_it->setGradient(direction + _gravityVector);
        agent_it->update(deltaTime, percIntensity);

        //Remove Agents outside of the Simulation
        isOutside(*agent_it) ? agent_it = _agents.erase(agent_it) : ++agent_it;
    }
}

void Simulation::draw(sf::RenderWindow& renderWindow)
{
    //Render Grid
    _data.draw(renderWindow);

    //Render Emitter
    for (auto const & emitter : _emitters)
        emitter.draw(renderWindow);

    //Render Agents
    for (auto const& agent : _agents)
        agent.draw(renderWindow);
}

void Simulation::addAgent(const EuglenaAgent& agent)
{
    _agents.push_back(agent);
}

void Simulation::addLightEmitter(const LightEmitter& lightEmitter)
{
    _lightEmitters.push_back(lightEmitter);
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

            gradient = {i_x / (_data.getWidth() * _data.getWidth()),i_y / (_data.getHeight() * _data.getHeight())};
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


//bool isInCell(const EuglenaAgent& agent, const Grid& grid, const glm::ivec2 index)
//{
//    auto indexOfAgent=grid.convertCoordinateToIndex(agent.getPosition());
//    if(indexOfAgent==index)
//        return true;
//    return false;
//}
void Simulation::updateDynamicLight()
{
    for(const auto& lightSource: _lightEmitters)
    {
        auto intenisty = lightSource.getIntensity();
        auto direction = lightSource.getDirection();
        auto position = lightSource.getPosition();
        

        //TODO: actually test
        while(intenisty>1)
        {
            auto index = _data.convertCoordinateToIndex(position);
            _data.getCell(index).setDynamicLightIntensity(intenisty);
            //will that actually work, if yes, amazing
            auto isInCell =[&](const EuglenaAgent&agent){ auto indexOfAgent = _data.convertCoordinateToIndex(agent.getPosition());
               if(indexOfAgent==index)
                   return true;
               return false;
            };
            auto agentsInCell = std::count_if(_agents.begin(), _agents.end(), isInCell);
            intenisty = (intenisty - agentsInCell*_agentTemplate.getAbsorbtionRate())*0.9f;
        }
    }
}

bool Simulation::isOutside(const glm::vec2& position) const
{
    return _data.isOutside(position);
   
}

bool Simulation::isOutside(const EuglenaAgent& agent) const
{
    return _data.isOutside(agent.getPosition());
}
