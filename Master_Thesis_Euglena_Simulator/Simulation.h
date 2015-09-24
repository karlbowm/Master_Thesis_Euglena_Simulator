#pragma once
#include "Grid.h"
#include "EuglenaAgent.h"

class Simulation
{
public:
    Simulation(int i, int j);
    Simulation(int i, int j, float cellWidth, float cellHeight);

    void update();
   
    ~Simulation();

private:
    Grid data;
    std::vector<EuglenaAgent> _agents;
};

