#include "EuglenaExperiment.h"


Simulation EuglenaExperiment::getANDGateSimulation()
{
    
    auto cellCountX = 100;
    auto cellCountY = 100;

    auto cellSizeX = 8.0f;
    auto cellSizeY = 8.0f;

    Simulation sim{ cellCountX,cellCountY,cellSizeX,cellSizeY };

    EuglenaAgent templ{ glm::vec2(10, 10), 50, 1.0, 5 };
    std::vector<glm::ivec2> staticLights = { { 0,0 },{ 0,1 },{ 0,2 },{ 1,0 },{ 1,0 },{ 2,0 } };
    sim.setStaticLight(staticLights, 100);

    EuglenaEmitter emitter{ { 30,30 }, templ, 1, 20.0f };
    for (int i = 1; i < 20; i++)
        sim.addLightEmitter(LightEmitter{ 100,{ i,2 },Direction::S });

    sim.setAgentTemplate(templ);
    //Initialize basic simulation
    //set grid resolution
    //set static light
    //define emitters and destructors

    return sim;
}
