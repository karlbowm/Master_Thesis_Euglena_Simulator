#pragma once
#include "Simulation.h"

class EuglenaExperiment
{
public:
  
    static Simulation getORGateSimulation(bool A, bool B);
    static Simulation getNOTGateSimulation(bool A);
    static Simulation EmitterTest();
};
