#include "EuglenaExperiment.h"
#include <memory>


std::unique_ptr<Simulation> EuglenaExperiment::getORGateSimulation(bool A, bool B)
{

    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(800, 800);


    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};


    //sim.setAgentTemplate(templ);

    //left hopper
    sim->addLightLine(LightLine{ {180,100},{150,70} ,100,20 });
    sim->addLightLine(LightLine{ {240,100},{270,70} ,100,20 });


    //right hopper
    sim->addLightLine(LightLine{ {440,100},{410,70} ,100,20 });
    sim->addLightLine(LightLine{ {500,100},{530,70} ,100,20 });
    //Left outer   
    sim->addLightLine(LightLine{ {180,100},{310,295} ,100,20 });
    //left inner
    sim->addLightLine(LightLine{ {240,100},{340,250} ,100,20 });


    //right outer
    sim->addLightLine(LightLine{ {500,100},{370,295} ,100,20 });
    //right inner
    sim->addLightLine(LightLine{ {440,100},{340,250} ,100,20 });


    sim->addLightLine(LightLine{ {310,295},{310,450} ,100,20 });
    sim->addLightLine(LightLine{ {370,295},{370,450} ,100,20 });


    //    for (int i = 1; i < 20; i++)
    //      sim.addLightEmitter(LightEmitter{ 100,{ 10,20 + i },Direction::E });


    //Initialize basic simulation
    //set grid resolution
    //set static light
    //define emitters and destructors

    //EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.0f };

    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};
    //left emitter
    EuglenaEmitter left{ { 210,80 },EuglenaAgent{ { 0.0,0.0 },1.0,4.0f,5.0f },10,25.0f };
    //right emitter
    EuglenaEmitter right{ { 470,80 },EuglenaAgent { { 0.0,0.0 },1.0,4.0f,5.0f },10,25.0f };

    if (A)
        sim->addEmitter(left);
    if (B)
        sim->addEmitter(right);


    sim->setAgentTemplate(EuglenaAgent{ { 0.0,0.0 },1.0,4.0f,5.0f });

    return sim;
}

std::unique_ptr<Simulation> EuglenaExperiment::getNOTGateSimulation(bool A)
{


    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(800, 800);

    addNotGate(sim, 100, 100);
    


    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.5f };


    EuglenaEmitter input{ { 210,100 },a,1.75f,25.0f };

    EuglenaEmitter m{ { 310,100 },a,1.75f,20.0f };

    //sim->addEmitter(m);
    if (A)
        sim->addEmitter(input);


    sim->setAgentTemplate(a);

    return sim;
}

void EuglenaExperiment::addNotGate(std::unique_ptr<Simulation>& sim, int offset2x, int offset2y)
{
    DynamicLightEmitter light3{ { offset2x + 100,offset2y + 275 },5.5f,385 };
    sim->addLightEmitter(light3);
    sim->addLightLine(LightLine{ { offset2x + 180,offset2y + 10 },{ offset2x + 180,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 10 },{ offset2x + 240,offset2y + 175 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 375 },{ offset2x + 240,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 175 },{ offset2x + 280,offset2y + 265 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 375 },{ offset2x + 280,offset2y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 280,offset2y + 100 },{ offset2x + 280,offset2y + 400 } ,100,20 });




    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 100 },{ offset2x + 340,offset2y + 160 } ,100,20 });



    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 315 },{ offset2x + 355,offset2y + 300 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 315 },{ offset2x + 340,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ {offset2x + 340,offset2y + 160}, { offset2x + 425,offset2y + 220 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 425,offset2y + 220 },{ offset2x + 425,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 280,offset2y + 100 },{ offset2x + 340,offset2y + 100 } ,100,20 });






    EuglenaDestructor d3{ { offset2x + 280,offset2y + 340 },{ 60,60 } }; 
    EuglenaDestructor d6{ { offset2x + 179,offset2y + 375 },{ 61,30 } };
    sim->addEuglenaDestructor(d3);
    sim->addEuglenaDestructor(d6);
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.5f };
    EuglenaEmitter m3{ { offset2x + 310,offset2y + 130 },a,1.75f,20.0f };
    sim->addEmitter(m3);

}

std::unique_ptr<Simulation> EuglenaExperiment::getANDGateSimulation(bool A, bool B)
{


    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(1000, 1000);
    int offset0x = 0;
    int offset0y = -50;

    int offset1x = 345;
    int offset1y = -50;

    int offset2x = 345;
    int offset2y = 525;

    DynamicLightEmitter light{ { offset0x + 100,offset0y + 275 },5.5f,385 };
    DynamicLightEmitter light2{ { offset1x + 100,offset1y + 275 },5.5f,385 };
  

    sim->addLightEmitter(light);
    sim->addLightEmitter(light2);
  

    sim->addLightLine(LightLine{ { offset0x + 180,offset0y + 100 },{ offset0x + 180,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 100 },{ offset0x + 240,offset0y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 375 },{ offset0x + 240,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 175 },{ offset0x + 280,offset0y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 375 },{ offset0x + 280,offset0y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 280,offset0y + 100 },{ offset0x + 280,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 100 },{ offset0x + 340,offset0y + 150 } ,100,20 });

    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 150 },{ offset0x + 410,offset0y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 410,offset0y + 220 },{ offset0x + 425,offset0y + 220 } ,100,20 });

    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 315 },{ offset0x + 355,offset0y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 315 },{ offset0x + 340,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 425,offset0y + 220 },{ offset0x + 425,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 280,offset0y + 100 },{ offset0x + 340,offset0y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 400 },{ offset0x + 525,offset0y + 585 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 425,offset0y + 400 },{ offset0x + 555,offset0y + 530 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 180,offset1y + 100 },{ offset1x + 180,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 100 },{ offset1x + 240,offset1y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 240,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 175 },{ offset1x + 280,offset1y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 280,offset1y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 280,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 100 },{ offset1x + 340,offset1y + 150 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 355,offset1y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 340,offset1y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 150 },{ offset1x + 410,offset1y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 410,offset1y + 220 },{ offset1x + 425,offset1y + 220 } ,100,20 });
    //s->m.addLightLine(LightLine{ { offset1x + 340,offset1y + 220 },{ offset1x + 425,offset1y+220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 220 },{ offset1x + 425,offset1y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 340,offset1y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 400 },{ offset1x + 210,offset1y + 530 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 400 },{ offset1x + 240,offset1y + 585 } ,100,20 });
    addNotGate(sim, offset2x, offset2y);

    EuglenaDestructor d1{ { offset0x + 280,offset0y + 340 },{ 60,60 } };
    EuglenaDestructor d2{ { offset1x + 280,offset1y + 340 },{ 60,60 } };
    EuglenaDestructor d4{ { offset0x + 179,offset0y + 375 },{ 61,30 } };
    EuglenaDestructor d5{ { offset1x + 179,offset1y + 375 },{ 61,30 } };
    sim->addEuglenaDestructor(d1);
    sim->addEuglenaDestructor(d2);
   sim->addEuglenaDestructor(d4);
      sim->addEuglenaDestructor(d5);


    
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.5f };





   

    EuglenaEmitter m{ { offset0x + 310,offset0y + 130 },a,1.75f,20.0f };
    EuglenaEmitter m2{ { offset1x + 310,offset1y + 130 },a,1.75f,20.0f };
    //EuglenaEmitter m{ { 310,100 },a,3.0f,25.0f };

    sim->addEmitter(m);
    sim->addEmitter(m2);
    EuglenaEmitter input{ { offset0x + 210,offset0y + 100 },a,1.75f,25.0f };
    EuglenaEmitter input2{ { offset1x + 210,offset1y + 100 },a,1.75f,25.0f };

    if (A)
        sim->addEmitter(input);

    if (B)
        sim->addEmitter(input2);




    sim->setAgentTemplate(a);

    return sim;
}

std::unique_ptr<Simulation> EuglenaExperiment::getNANDGateSimulation(bool A, bool B)
{
    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(2000, 2000);
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.9f };
    addNANDGateTo(sim,200,200,a);


    EuglenaEmitter m_A{ { 410, 255},a,1.75f,20.0f };
    EuglenaEmitter m_B{ { 755, 255},a,1.75f,20.0f };
    if(A)
        sim->addEmitter(m_A);
    if (B)
        sim->addEmitter(m_B);
    return sim;
}

std::unique_ptr<Simulation> EuglenaExperiment::getXORGateSimulation(bool A, bool B)
{

    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(2000, 2000);
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.9f };
    addXORGate(sim, 200, -200, a);


    EuglenaEmitter m_A{ { 410, 255 },a,1.75f,20.0f };
    EuglenaEmitter m_A1{ { 975, 255 },a,1.75f,20.0f };
    EuglenaEmitter m_B{ { 755, 255 },a,1.75f,20.0f };
    EuglenaEmitter m_B1{ {1225, 255 },a,1.75f,20.0f };
    if (A)
    {
        sim->addEmitter(m_A);
        sim->addEmitter(m_A1);
    }
        
    if (B)
    {
        sim->addEmitter(m_B);
        sim->addEmitter(m_B1);
    }
        
    return sim;

}

void EuglenaExperiment::addMemory(std::unique_ptr<Simulation>& sim, EuglenaAgent a, int offset2x, int offset2y)
{
    DynamicLightEmitter light3{ { offset2x + 100,offset2y + 220 },6.5f,345 };
    sim->addLightEmitter(light3);

    sim->addLightLine(LightLine{ { offset2x + 140,offset2y + 10 },{ offset2x + 140,offset2y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 195,offset2y + 10 },{ offset2x + 195,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 10 },{ offset2x + 240,offset2y + 175 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 375 },{ offset2x + 240,offset2y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 175 },{ offset2x + 280,offset2y + 215 } ,100,20 });





    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 285 },{ offset2x + 280,offset2y + 245 } ,100,20 });
    //sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 345 },{ offset2x + 280,offset2y + 305 } ,100,20 });



    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 285 },{ offset2x + 240,offset2y + 375 } ,100,20 });




    sim->addLightLine(LightLine{ { offset2x + 280,offset2y + 100 },{ offset2x + 280,offset2y + 400 } ,100,20 });




    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 100 },{ offset2x + 340,offset2y +240 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 240 },{ offset2x + 425,offset2y + 240 } ,100,20 });



    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 315 },{ offset2x + 355,offset2y + 300 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 315 },{ offset2x + 340,offset2y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 425,offset2y + 240 },{ offset2x + 425,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 280,offset2y + 100 },{ offset2x + 340,offset2y + 100 } ,100,20 });






    EuglenaDestructor d3{ { offset2x + 280,offset2y + 340 },{ 60,60 } };
    EuglenaDestructor d6{ { offset2x + 139,offset2y + 375 },{101,30 } };
    sim->addEuglenaDestructor(d3);
    sim->addEuglenaDestructor(d6);

    EuglenaEmitter m3{ { offset2x + 310,offset2y + 130 },a,1.75f,20.0f };
    sim->addEmitter(m3);
}

std::unique_ptr<Simulation> EuglenaExperiment::getMemoryCell(bool A)
{
    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(2000, 2000);
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.0f };
    int offset2x = 0;
    int offset2y = 0;
    addMemory(sim, a, offset2x, offset2y);

    auto setEmitter = EuglenaEmitter{ {220,25},a,1.75,20.0f };
    //sim->addEmitter(setEmitter);
    sim->setAgentTemplate(a);
    return sim;
}

std::unique_ptr<Simulation> EuglenaExperiment::getXNORGateSimulation(bool A, bool B)
{
    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(2000, 2000);
    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.9f };
    addXNORGate(sim, 200, -200, a);


    EuglenaEmitter m_A{ { 410, 255 },a,1.75f,20.0f };
    EuglenaEmitter m_A1{ { 975, 255 },a,1.75f,20.0f };
    EuglenaEmitter m_B{ { 755, 255 },a,1.75f,20.0f };
    EuglenaEmitter m_B1{ { 1225, 255 },a,1.75f,20.0f };
    if (A)
    {
        sim->addEmitter(m_A);
        sim->addEmitter(m_A1);
    }

    if (B)
    {
        sim->addEmitter(m_B);
        sim->addEmitter(m_B1);
    }

    return sim;


}

std::unique_ptr<Simulation> EuglenaExperiment::EmitterTest()
{


    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(800, 800);


    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};
    //EuglenaEmitter e{ {100,100}, EuglenaAgent{ { 0.0,0.0 },1.0,3.0f,6.0f },1,50.0f };
    //sim.addEmitter(e);


    sim->setAgentTemplate(EuglenaAgent{ { 110,140 },1.0,3.0f,6.0f });
    sim->addAgent(EuglenaAgent{ { 0.0,0.0 },1.0,3.0f,6.0f });


    sim->addLightEmitter(DynamicLightEmitter{ { 100,200 },10,100 });

    //sim.setAgentTemplate(templ);

    return sim;
}

void EuglenaExperiment::addNANDGateTo(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a)
{
    int offset0x = shiftx+0;
    int offset0y = shifty +-50;

    int offset1x = shiftx+345;
    int offset1y = shifty +-50;

    int offset2x = shiftx+ 345;
    int offset2y = shifty+525;

    DynamicLightEmitter light{ { offset0x + 100,offset0y + 275 },5.5f,385 };
    DynamicLightEmitter light2{ { offset1x + 100,offset1y + 275 },5.5f,385 };

    sim->addLightEmitter(light);
    sim->addLightEmitter(light2);

    
    sim->addLightLine(LightLine{ { offset0x + 180,offset0y + 100 },{ offset0x + 180,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 100 },{ offset0x + 240,offset0y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 375 },{ offset0x + 240,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 175 },{ offset0x + 280,offset0y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 375 },{ offset0x + 280,offset0y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 280,offset0y + 100 },{ offset0x + 280,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 100 },{ offset0x + 340,offset0y + 150 } ,100,20 });

    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 150 },{ offset0x + 410,offset0y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 410,offset0y + 220 },{ offset0x + 425,offset0y + 220 } ,100,20 });

    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 315 },{ offset0x + 355,offset0y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 315 },{ offset0x + 340,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 425,offset0y + 220 },{ offset0x + 425,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 280,offset0y + 100 },{ offset0x + 340,offset0y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 400 },{ offset0x + 525,offset0y + 585 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 425,offset0y + 400 },{ offset0x + 555,offset0y + 530 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 180,offset1y + 100 },{ offset1x + 180,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 100 },{ offset1x + 240,offset1y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 240,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 175 },{ offset1x + 280,offset1y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 280,offset1y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 280,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 100 },{ offset1x + 340,offset1y + 150 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 355,offset1y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 340,offset1y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 150 },{ offset1x + 410,offset1y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 410,offset1y + 220 },{ offset1x + 425,offset1y + 220 } ,100,20 });
 
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 220 },{ offset1x + 425,offset1y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 340,offset1y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 400 },{ offset1x + 210,offset1y + 530 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 400 },{ offset1x + 240,offset1y + 585 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 180,offset2y + 10 },{ offset2x + 180,offset2y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 10 },{ offset2x + 240,offset2y + 100 } ,100,20 });
   

    EuglenaDestructor d1{ { offset0x + 280,offset0y + 340 },{ 60,60 } };
    EuglenaDestructor d2{ { offset1x + 280,offset1y + 340 },{ 60,60 } };
    EuglenaDestructor d4{ { offset0x + 179,offset0y + 375 },{ 61,30 } };
    EuglenaDestructor d5{ { offset1x + 179,offset1y + 375 },{ 61,30 } };
    EuglenaDestructor d6{ { offset2x + 179,offset2y + 375 },{ 61,30 } };
    sim->addEuglenaDestructor(d1);
    sim->addEuglenaDestructor(d2);
    sim->addEuglenaDestructor(d4);
    sim->addEuglenaDestructor(d5);


   // a = { { 0.0,0.0 },1.0,4.0f,5.5f };
  
    EuglenaEmitter m{ { offset0x + 310,offset0y + 130 },a,1.75f,20.0f };
    EuglenaEmitter m2{ { offset1x + 310,offset1y + 130 },a,1.75f,20.0f };
 
    sim->addEmitter(m);
    sim->addEmitter(m2);
    sim->setAgentTemplate(a);
}

void EuglenaExperiment::addORGate(std::unique_ptr<Simulation>& sim, int shiftx, int shifty)
{
    sim->addLightLine(LightLine{ {shiftx+ 180,shifty+100 },{shiftx+ 310,shifty+295 } ,100,20 });
    sim->addLightLine(LightLine{ {shiftx+ 240,shifty+100 },{shiftx+ 340,shifty+250 } ,100,20 });
    sim->addLightLine(LightLine{ {shiftx+ 500,shifty+100 },{shiftx+ 370,shifty+295 } ,100,20 });    
    sim->addLightLine(LightLine{ {shiftx+ 440,shifty+100 },{shiftx+ 340,shifty+250 } ,100,20 });    
    sim->addLightLine(LightLine{ {shiftx+ 310,shifty+295 },{shiftx+ 310,shifty+450 } ,100,20 });
    sim->addLightLine(LightLine{ {shiftx+ 370,shifty+295 },{shiftx+ 370,shifty+450 } ,100,20 });
}

void EuglenaExperiment::addXORGate(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a)
{
    addNotGate(sim, shiftx+690, shifty+1500);


    addORGate(sim, shiftx+560, shifty+350);
    sim->addLightLine(LightLine{ { shiftx+560 + 310,shifty+350 + 450 },{ shiftx+560 + 310,shifty+350 + 650 } ,100,20 });
    sim->addLightLine(LightLine{ { shiftx+560 + 370,shifty+350 + 450 },{ shiftx+560 + 370,shifty+350 + 650 } ,100,20 });


    addNANDGateTo(sim, shiftx, shifty+400, a);
    addNANDGateTo(sim, shiftx+345, shifty+ 950, a);
}

void EuglenaExperiment::addHalfAdder(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a)
{
     


    addANDGateTo(sim, shiftx+1000, shifty+400, a);
    addXORGate(sim, shiftx, shifty, a);
}

std::unique_ptr<Simulation> EuglenaExperiment::HalfAdder(bool A, bool B)
{
    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(4000, 2000);

        int shiftx = 0;
        int shifty = 000;

    EuglenaAgent a { { 0.0,0.0 },1.0,4.0f,5.9f };
    addHalfAdder(sim, shiftx, shifty, a);


    EuglenaEmitter input10{ {210,480 },a,1.75f,20.0f };
    EuglenaEmitter input20{ { 580 + 210,480 },a,1.75f,20.0f };
    EuglenaEmitter input30{ { 790 +420,480 },a,1.75f,20.0f };

    EuglenaEmitter input11{ {555,480 },a,1.75f,20.0f };
    EuglenaEmitter input21{ { 1010,480 },a,1.75f,20.0f };
    EuglenaEmitter input31{ { 1010+545,480 },a,1.75f,20.0f };


    if (A)
    {
        sim->addEmitter(input10); 
       sim->addEmitter(input20);
        sim->addEmitter(input30);
    }
          if (B)
    {
        sim->addEmitter(input11); 
        sim->addEmitter(input21);
        sim->addEmitter(input31);
    }
        


    sim->setAgentTemplate(a);


 

    return sim;

}




void EuglenaExperiment::addANDGateTo(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent& a)
{
    int offset0x = shiftx + 0;
    int offset0y = shifty + -50;

    int offset1x = shiftx + 345;
    int offset1y = shifty + -50;

    int offset2x = shiftx + 345;
    int offset2y = shifty + 525;

    DynamicLightEmitter light{ { offset0x + 100,offset0y + 275 },5.5f,385 };
    DynamicLightEmitter light2{ { offset1x + 100,offset1y + 275 },5.5f,385 };

    sim->addLightEmitter(light);
    sim->addLightEmitter(light2);


    sim->addLightLine(LightLine{ { offset0x + 180,offset0y + 100 },{ offset0x + 180,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 100 },{ offset0x + 240,offset0y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 375 },{ offset0x + 240,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 175 },{ offset0x + 280,offset0y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 240,offset0y + 375 },{ offset0x + 280,offset0y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 280,offset0y + 100 },{ offset0x + 280,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 100 },{ offset0x + 340,offset0y + 150 } ,100,20 });

    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 150 },{ offset0x + 410,offset0y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 410,offset0y + 220 },{ offset0x + 425,offset0y + 220 } ,100,20 });

    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 315 },{ offset0x + 355,offset0y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 315 },{ offset0x + 340,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 425,offset0y + 220 },{ offset0x + 425,offset0y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 280,offset0y + 100 },{ offset0x + 340,offset0y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 400 },{ offset0x + 525,offset0y + 585 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x + 425,offset0y + 400 },{ offset0x + 555,offset0y + 530 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 180,offset1y + 100 },{ offset1x + 180,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 100 },{ offset1x + 240,offset1y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 240,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 175 },{ offset1x + 280,offset1y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 280,offset1y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 280,offset1y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 100 },{ offset1x + 340,offset1y + 150 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 355,offset1y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 340,offset1y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 150 },{ offset1x + 410,offset1y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 410,offset1y + 220 },{ offset1x + 425,offset1y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 220 },{ offset1x + 425,offset1y + 400 } ,100,20 });

    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 340,offset1y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 400 },{ offset1x + 210,offset1y + 530 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 400 },{ offset1x + 240,offset1y + 585 } ,100,20 });

    sim->addLightLine(LightLine{ { offset2x + 180,offset2y + 10 },{ offset2x + 180,offset2y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 10 },{ offset2x + 240,offset2y + 100 } ,100,20 });


    EuglenaDestructor d1{ { offset0x + 280,offset0y + 340 },{ 60,60 } };
    EuglenaDestructor d2{ { offset1x + 280,offset1y + 340 },{ 60,60 } };
    EuglenaDestructor d4{ { offset0x + 179,offset0y + 375 },{ 61,30 } };
    EuglenaDestructor d5{ { offset1x + 179,offset1y + 375 },{ 61,30 } };
    EuglenaDestructor d6{ { offset2x + 179,offset2y + 375 },{ 61,30 } };
    sim->addEuglenaDestructor(d1);
    sim->addEuglenaDestructor(d2);
    sim->addEuglenaDestructor(d4);
    sim->addEuglenaDestructor(d5);


    

    EuglenaEmitter m{ { offset0x + 310,offset0y + 130 },a,1.75f,20.0f };
    EuglenaEmitter m2{ { offset1x + 310,offset1y + 130 },a,1.75f,20.0f };

    sim->addEmitter(m);
    sim->addEmitter(m2);

    addNotGate(sim, shiftx +345, shifty + 610);
}


std::unique_ptr<Simulation> EuglenaExperiment::FullAdder(bool A, bool B)
{
    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(6000, 6000);

    int shiftx = 0;
    int shifty = 0;

    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.5f };
    addHalfAdder(sim, shiftx+000, shifty, a);
    addHalfAdder(sim, shiftx+400, shifty+1900, a);


    /*EuglenaEmitter input10{ {210,475 },a,1.75f,20.0f };
    EuglenaEmitter input11{ {575+210,475 },a,1.75f,20.0f };
    EuglenaEmitter input20{ { 550,475 },a,1.75f,20.0f };
    EuglenaEmitter input21{ { 800 + 210,475 },a,1.75f,20.0f };*/


    /*   if (A)
    {
    sim->addEmitter(input10);
    sim->addEmitter(input11);
    }
    if (B)
    {
    sim->addEmitter(input20);
    sim->addEmitter(input21);
    }*/



    sim->setAgentTemplate(a);




    return sim;

}

void EuglenaExperiment::addXNORGate(std::unique_ptr<Simulation>& sim, int shiftx, int shifty, EuglenaAgent a)
{

    //addNotGate(sim, shiftx + 690, shifty + 1500);


    addORGate(sim, shiftx + 560, shifty + 350);
    sim->addLightLine(LightLine{ { shiftx + 560 + 310,shifty + 350 + 450 },{ shiftx + 560 + 310,shifty + 350 + 650 } ,100,20 });
    sim->addLightLine(LightLine{ { shiftx + 560 + 370,shifty + 350 + 450 },{ shiftx + 560 + 370,shifty + 350 + 650 } ,100,20 });


    addNANDGateTo(sim, shiftx, shifty + 400, a);
    addNANDGateTo(sim, shiftx + 345, shifty + 950, a);
}
