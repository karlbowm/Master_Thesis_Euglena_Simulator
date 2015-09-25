#pragma once
#include<glm/glm.hpp>

#include "Grid.h"
#include "EuglenaAgent.h"
class Simulation
{
public:
    Simulation(int i, int j);
    Simulation(int i, int j, float cellWidth, float cellHeight);

    void update(float deltaTime);

    glm::vec2 getGradient(int i, int j), getGradient(float x, float y), getGradient(const glm::vec2& position);


    ~Simulation();

private:
    Grid data;
    std::vector<EuglenaAgent> _agents;
};

