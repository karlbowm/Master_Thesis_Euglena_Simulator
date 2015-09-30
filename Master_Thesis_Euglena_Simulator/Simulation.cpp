#include "Simulation.h"



Simulation::Simulation(int i, int j) : _data(i,j), _agentTemplate({0,0},1.0,0,10)
{
    
 //RODO
}

Simulation::Simulation(int i, int j, float cellWidth, float cellHeight) : _data(i,j,cellWidth,cellHeight), _agentTemplate({ 0,0 }, 1.0, 0, 10)
{
}

Simulation& Simulation::setAgentTemplate(EuglenaAgent& agentTemplate)
{
    for(auto& emitter : _emitters)    
        emitter.setAgentTemplate(agentTemplate);
    
    _agentTemplate = agentTemplate;
    return *this;
}

void Simulation::addEmitter(EuglenaEmitter emitter)
{
    emitter.setAgentTemplate(_agentTemplate);
    _emitters.push_back(emitter);
}

void Simulation::setStaticLight(const std::vector<glm::ivec2> coordinates, float intensity)
{
    for(auto& pair : coordinates)
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

    for (auto& emitter : _emitters)
        emitter.update(deltaTime, _agents);


    for (auto& agent : _agents)
    {
        float perceivedIntensity = _data.getCell(agent.getPosition()).getTotalIntensity();
        glm::vec2 direction = getGradient(agent.getPosition());       
        
    }
}

void Simulation::draw(sf::RenderWindow& renderWindow)
{
    _data.draw(renderWindow);

    for (auto& emitter : _emitters)
    {
        emitter.draw(renderWindow);
    }

    for(auto& agent :_agents)
    {
        agent.draw(renderWindow);
    }

  
}


glm::vec2 Simulation::getGradient(int i, int j)
{
    //TODO: return the gradient of the cell
    return glm::vec2();
}

glm::vec2 Simulation::getGradient(float x, float y)
{
    //TODO: return the gradient of the cell
    return glm::vec2();
}

glm::vec2 Simulation::getGradient(const glm::vec2 & position)
{
    //TODO: return the gradient of the cellg
    return glm::vec2();
}

Simulation::~Simulation()
{
}
