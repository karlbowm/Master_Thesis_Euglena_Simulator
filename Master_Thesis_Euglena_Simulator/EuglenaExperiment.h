#pragma once
#include "Simulation.h"
#include <memory>

class EuglenaExperiment
{
public:
  
    static std::unique_ptr<Simulation> getORGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> getNOTGateSimulation(bool A);
    static std::unique_ptr<Simulation> getANDGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> EmitterTest();
};
