#include "Simulation.h"



Simulation::Simulation(int i, int j) : data(i,j)
{
    
 
}

Simulation::Simulation(int i, int j, float cellWidth, float cellHeight) : data(i,j,cellWidth,cellHeight)
{
}

Simulation::~Simulation()
{
}
