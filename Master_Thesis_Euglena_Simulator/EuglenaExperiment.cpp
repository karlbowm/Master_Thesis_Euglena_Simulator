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

    //left hopper
    sim.addLightLine(LightLine{{180,100},{150,70} ,100,20});
    sim.addLightLine(LightLine{{240,100},{270,70} ,100,20 });


    //right hopper
    sim.addLightLine(LightLine{{440,100},{410,70} ,100,20 });
    sim.addLightLine(LightLine{{500,100},{530,70} ,100,20 });
    //Left outer   
    sim.addLightLine(LightLine{{180,100},{310,295} ,100,20 });
    //left inner
    sim.addLightLine(LightLine{{240,100},{340,250} ,100,20 });


    //right outer
    sim.addLightLine(LightLine{{500,100},{370,295} ,100,20 });
    //right inner
    sim.addLightLine(LightLine{{440,100},{340,250} ,100,20 });


    sim.addLightLine(LightLine{{310,295},{310,450} ,100,20 });
    sim.addLightLine(LightLine{{370,295},{370,450} ,100,20 });


    //    for (int i = 1; i < 20; i++)
    //      sim.addLightEmitter(LightEmitter{ 100,{ 10,20 + i },Direction::E });


    //Initialize basic simulation
    //set grid resolution
    //set static light
    //define emitters and destructors
    
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.0f };

    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};
    //left emitter
    EuglenaEmitter left{ { 210,80 },a,10,25.0f };
    //right emitter
    EuglenaEmitter right{ { 470,80 },a,10,25.0f };

    if(A)
        sim.addEmitter(left);
    if(B)
        sim.addEmitter(right);


    sim.setAgentTemplate(a);

    return sim;
}

Simulation EuglenaExperiment::getNOTGateSimulation(bool A)
{
    auto cellCountX = 100;
    auto cellCountY = 100;

    auto cellSizeX = 8.0f;
    auto cellSizeY = 8.0f;

    Simulation sim{ cellCountX,cellCountY,cellSizeX,cellSizeY };

    /*
    
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |  \
    |  |    \
    |  |      \
    |  |      |
    |  |   |  |
    |  |   |  |
    
    
    
    */

    //left hopper
    sim.addLightLine(LightLine{ { 180,100 },{ 180,500 } ,100,20 });
    sim.addLightLine(LightLine{ { 240,100 },{ 240,175} ,100,20 });
    sim.addLightLine(LightLine{ { 240,375 },{ 240,500 } ,100,20 });

    sim.addLightLine(LightLine{ { 240,175 },{ 280,265 } ,100,20 });

    sim.addLightLine(LightLine{ { 240,375 },{ 280,335 } ,100,20 });

    sim.addLightLine(LightLine{ { 280,100 },{ 280,500 } ,100,20 });
    sim.addLightLine(LightLine{ { 340,100 },{ 340,220 } ,100,20 });


    sim.addLightLine(LightLine{ { 340,315 },{ 355,300 } ,100,20 });
    sim.addLightLine(LightLine{ { 340,315 },{ 340,500 } ,100,20 });

    sim.addLightLine(LightLine{ { 340,220 },{ 425,220 } ,100,20 });

    sim.addLightLine(LightLine{ { 425,220 },{ 425,500 } ,100,20 });
    //sim.addLightLine(LightLine{ { 240,100 },{ 270,70 } ,100,20 });

    DynamicLightEmitter light{{100,275},5.0f,385};

    sim.addLightEmitter(light);


    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.0f };

  
    EuglenaEmitter input{ { 210,100 },a,1.75f,25.0f };

    EuglenaEmitter m{ { 310,100 },a,3.0f,25.0f };
   
    sim.addEmitter(m);
    if (A)
        sim.addEmitter(input);  


    sim.setAgentTemplate(a);

    return sim;
}

Simulation EuglenaExperiment::EmitterTest()
{
    auto cellCountX = 100;
    auto cellCountY = 100;

    auto cellSizeX = 8.0f;
    auto cellSizeY = 8.0f;

    Simulation sim{ cellCountX,cellCountY,cellSizeX,cellSizeY };
    EuglenaAgent a{ {0.0,0.0},1.0,3.0f,6.0f };

    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};
    EuglenaEmitter e{ {100,100},a,1,50.0f };
    //sim.addEmitter(e);

    a.setPosition({ 110,140 });
    sim.setAgentTemplate(a);
    sim.addAgent(a);
    DynamicLightEmitter light{ { 100,200 },10,100 };

    sim.addLightEmitter(light);

    //sim.setAgentTemplate(templ);

    return sim;
}
