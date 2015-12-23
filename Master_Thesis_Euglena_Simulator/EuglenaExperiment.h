#pragma once
#include "Simulation.h"
#include <memory>

class EuglenaExperiment
{
public:
    static std::unique_ptr<Simulation> EmitterTest();
    static std::unique_ptr<Simulation> getORGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> getNOTGateSimulation(bool A);
    static std::unique_ptr<Simulation> getANDGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> getNANDGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> getXORGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> getMemoryCell(bool A);
    
    static std::unique_ptr<Simulation> getXNORGateSimulation(bool A, bool B);
    static std::unique_ptr<Simulation> HalfAdder(bool A, bool B);
    static std::unique_ptr<Simulation> FullAdder(bool A, bool B);
    
    static void addMemory(std::unique_ptr<Simulation>& sim, EuglenaAgent a, int offset2x, int offset2y);
    static void addXNORGate(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent a);
    static void addNotGate(std::unique_ptr<Simulation>& sim, int offset2x, int offset2y);
    static void addNANDGateTo(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a);
    static void addANDGateTo(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a);
    static void addORGate(std::unique_ptr<Simulation>& sim, int shiftx, int shifty);
    static void addXORGate(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a);
    static void addHalfAdder(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a);
    
};
