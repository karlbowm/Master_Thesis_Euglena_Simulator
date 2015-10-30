#include "EuglenaExperiment.h"



Simulation EuglenaExperiment::getORGateSimulation(bool A, bool B)
{
    auto cellCountX = 100;
    auto cellCountY = 100;

    auto cellSizeX = 8.0f;
    auto cellSizeY = 8.0f;

    Simulation sim{cellCountX,cellCountY,cellSizeX,cellSizeY};

    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};


    //sim.setAgentTemplate(templ);

    ////left hopper
    //sim.addLightLine(LightLine{{180,100},{150,70} ,100,10});
    //sim.addLightLine(LightLine{{240,100},{270,70} ,100,10});


    ////right hopper
    //sim.addLightLine(LightLine{{440,100},{410,70} ,100,10});
    //sim.addLightLine(LightLine{{500,100},{530,70} ,100,10});
    ////Left outer   
    //sim.addLightLine(LightLine{{180,100},{310,295} ,100,10});
    ////left inner
    //sim.addLightLine(LightLine{{240,100},{340,250} ,100,10});


    ////right outer
    //sim.addLightLine(LightLine{{500,100},{370,295} ,100,10});
    ////right inner
    //sim.addLightLine(LightLine{{440,100},{340,250} ,100,10});


    //sim.addLightLine(LightLine{{310,295},{310,450} ,100,10});
    //sim.addLightLine(LightLine{{370,295},{370,450} ,100,10});


    //    for (int i = 1; i < 20; i++)
    //      sim.addLightEmitter(LightEmitter{ 100,{ 10,20 + i },Direction::E });


    //Initialize basic simulation
    //set grid resolution
    //set static light
    //define emitters and destructors

    return sim;
}
