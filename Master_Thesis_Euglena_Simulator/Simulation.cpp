#include "Simulation.h"



Simulation::Simulation(int i, int j) : _data(i,j), _agentTemplate({0,0},1.0,0,10)
{
    
 //TODO
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
        auto perceivedIntensity = _data.getCell(agent.getPosition()).getTotalIntensity();
        glm::vec2 direction = getGradient(agent.getPosition());     
        agent.setGradient(direction).update(deltaTime,perceivedIntensity);
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
    glm::vec2 gradient{0,0};
    if(i>0 && i<_data.getImax()-1)
    {
        if (j>0 && j<_data.getJmax()-1)
        {
            auto i_x = _data.getCell(i + 1, j).getTotalIntensity() - 2 * _data.getCell(i, j).getTotalIntensity() + _data.getCell(i - 1, j).getTotalIntensity();
            auto i_y = _data.getCell(i , j+1).getTotalIntensity() - 2 * _data.getCell(i, j).getTotalIntensity() + _data.getCell(i, j-1).getTotalIntensity();

            gradient = { i_x / (_data.getWidth()*_data.getWidth()),i_y / (_data.getHeight()*_data.getHeight()) };
        }
    }
    //TODO: return the gradient of the cell
    return gradient;
}

glm::vec2 Simulation::getGradient(float x, float y)
{
    auto index=_data.convertCoordinateToIndex({ x,y });   
    return getGradient(index.x, index.y);
}

glm::vec2 Simulation::getGradient(const glm::vec2 & position)
{
    auto index = _data.convertCoordinateToIndex({ position.x,position.y });    
    return getGradient(index.x, index.y);
}

Simulation::~Simulation()
{
}
