#include "Simulation.h"



Simulation::Simulation(int i, int j) : data(i,j)
{
    
 
}

Simulation::Simulation(int i, int j, float cellWidth, float cellHeight) : data(i,j,cellWidth,cellHeight)
{
}

void Simulation::update(float deltaTime)
{
    //update grid values

    for (auto& agent : _agents)
    {
        float perceivedIntensity = data.getCell(agent.getPosition()).getTotalIntensity();
        glm::vec2 direction = getGradient(agent.getPosition());
        
        
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
    //TODO: return the gradient of the cell
    return glm::vec2();
}

Simulation::~Simulation()
{
}
