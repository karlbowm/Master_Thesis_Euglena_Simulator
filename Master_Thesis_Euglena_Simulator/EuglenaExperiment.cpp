#include "EuglenaExperiment.h"
#include <memory>


std::unique_ptr<Simulation> EuglenaExperiment::getORGateSimulation(bool A, bool B)
{

    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(800,800);


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
    auto cellCountX = 100;
    auto cellCountY = 100;

    auto cellSizeX = 8.0f;
    auto cellSizeY = 8.0f;

    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(800, 800);


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
    sim->addLightLine(LightLine{ { 180,100 },{ 180,500 } ,100,20 });
    sim->addLightLine(LightLine{ { 240,100 },{ 240,175} ,100,20 });
    sim->addLightLine(LightLine{ { 240,375 },{ 240,500 } ,100,20 });
    sim->addLightLine(LightLine{ { 240,175 },{ 280,265 } ,100,20 });
    sim->addLightLine(LightLine{ { 240,375 },{ 280,335 } ,100,20 });
    sim->addLightLine(LightLine{ { 280,100 },{ 280,500 } ,100,20 });
    sim->addLightLine(LightLine{ { 340,100 },{ 340,220 } ,100,20 });
    sim->addLightLine(LightLine{ { 340,315 },{ 355,300 } ,100,20 });
    sim->addLightLine(LightLine{ { 340,315 },{ 340,500 } ,100,20 });
    sim->addLightLine(LightLine{ { 340,220 },{ 425,220 } ,100,20 });
    sim->addLightLine(LightLine{ { 425,220 },{ 425,500 } ,100,20 });
    //sim.addLightLine(LightLine{ { 240,100 },{ 270,70 } ,100,20 });

    DynamicLightEmitter light{ {100,275},5.0f,385 };

    sim->addLightEmitter(light);


    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.0f };


    EuglenaEmitter input{ { 210,100 },a,1.75f,25.0f };

    EuglenaEmitter m{ { 310,100 },a,3.0f,25.0f };

    sim->addEmitter(m);
    if (A)
        sim->addEmitter(input);


    sim->setAgentTemplate(a);

    return sim;
}

std::unique_ptr<Simulation> EuglenaExperiment::getANDGateSimulation(bool A, bool B)
{
    auto cellCountX = 100;
    auto cellCountY = 100;

    auto cellSizeX = 10.0f;
    auto cellSizeY = 10.0f;

    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(1000, 1000);
    int offset0x = 0;
    int offset0y = -50;

    int offset1x = 345;
    int offset1y = -50;

    int offset2x = 345;
    int offset2y = 525;

    DynamicLightEmitter light{ { offset0x+100,offset0y+275 },5.5f,385 };
    DynamicLightEmitter light2{ { offset1x+100,offset1y +275 },5.5f,385 };
    DynamicLightEmitter light3{ { offset2x+100,offset2y+275 },4.9f,385 };

    sim->addLightEmitter(light);
    sim->addLightEmitter(light2);
    sim->addLightEmitter(light3);

    sim->addLightLine(LightLine{ { offset0x+ 180,offset0y+100 },{ offset0x+180,offset0y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 240,offset0y+100 },{ offset0x+240,offset0y+175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 240,offset0y+375 },{ offset0x+240,offset0y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 240,offset0y+175 },{ offset0x+280,offset0y+265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 240,offset0y+375 },{ offset0x+280,offset0y+335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 280,offset0y+100 },{ offset0x+280,offset0y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 340,offset0y+100 },{ offset0x+340,offset0y+150 } ,100,20 });
 
    sim->addLightLine(LightLine{ { offset0x + 340,offset0y + 150 },{ offset0x+410,offset0y+220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 410,offset0y+220 },{ offset0x+425,offset0y+220 } ,100,20 });
  
    sim->addLightLine(LightLine{ { offset0x+ 340,offset0y+315 },{ offset0x+355,offset0y+300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 340,offset0y+315 },{ offset0x+340,offset0y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 425,offset0y+220 },{ offset0x+425,offset0y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 280,offset0y+100 },{ offset0x+340,offset0y+100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 340,offset0y+400 },{ offset0x+525,offset0y+585 } ,100,20 });
    sim->addLightLine(LightLine{ { offset0x+ 425,offset0y+400 },{ offset0x+555,offset0y+530 } ,100,20 });
   
    sim->addLightLine(LightLine{ { offset1x + 180,offset1y + 100 },{ offset1x + 180,offset1y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 100 },{ offset1x + 240,offset1y+175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 240,offset1y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 175 },{ offset1x + 280,offset1y+265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 240,offset1y + 375 },{ offset1x + 280,offset1y+335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 280,offset1y + 100 },{ offset1x + 280,offset1y+400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 100 },{ offset1x + 340,offset1y+150 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 355,offset1y+300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 315 },{ offset1x + 340,offset1y+400 } ,100,20 });
     
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 150 },{ offset1x + 410,offset1y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 410,offset1y + 220 },{ offset1x + 425,offset1y + 220 } ,100,20 });
    //s->m.addLightLine(LightLine{ { offset1x + 340,offset1y + 220 },{ offset1x + 425,offset1y+220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 220 },{ offset1x + 425,offset1y+400 } ,100,20 });
   
    sim->addLightLine(LightLine{ { offset1x+ 280,offset1y + 100 },{ offset1x + 340,offset1y + 100 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 340,offset1y + 400 },{ offset1x + 210,offset1y + 530 } ,100,20 });
    sim->addLightLine(LightLine{ { offset1x + 425,offset1y + 400 },{ offset1x + 240,offset1y + 585 } ,100,20 });
   
    sim->addLightLine(LightLine{ { offset2x + 180,offset2y + 10 },{ offset2x + 180,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 10 },{ offset2x + 240,offset2y + 175 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 375 },{ offset2x + 240,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 175 },{ offset2x + 280,offset2y + 265 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 240,offset2y + 375 },{ offset2x + 280,offset2y + 335 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 280,offset2y + 100 },{ offset2x + 280,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 100 },{ offset2x + 340,offset2y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 315 },{ offset2x + 355,offset2y + 300 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 315 },{ offset2x + 340,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 340,offset2y + 220 },{ offset2x + 425,offset2y + 220 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 425,offset2y + 220 },{ offset2x + 425,offset2y + 400 } ,100,20 });
    sim->addLightLine(LightLine{ { offset2x + 280,offset2y + 100 },{ offset2x + 340,offset2y + 100 } ,100,20 });


    


    EuglenaDestructor d1{ { offset0x+280,offset0y+340},{60,60} };
    EuglenaDestructor d2{ { offset1x+280,offset1y+340},{60,60} };
    EuglenaDestructor d3{ { offset2x+280,offset2y+340},{60,60} };
   
    EuglenaDestructor d4{ { offset0x+179,offset0y+375},{61,30} };
    EuglenaDestructor d5{ { offset1x +179,offset1y +375},{61,30} };
    EuglenaDestructor d6{ { offset2x +179,offset2y +375},{61,30} };
    sim->addEuglenaDestructor(d1);
    sim->addEuglenaDestructor(d2);
    sim->addEuglenaDestructor(d3);
    sim->addEuglenaDestructor(d4);
    sim->addEuglenaDestructor(d5);
    sim->addEuglenaDestructor(d6);



    EuglenaAgent a{ { 0.0,0.0 },1.0,4.0f,5.5f };


     


     EuglenaEmitter input{ { offset0x +210,offset0y+100 },a,1.75f,25.0f };
     EuglenaEmitter input2{ { offset1x+210,offset1y+100 },a,1.75f,25.0f };

     EuglenaEmitter m{ { offset0x+310,offset0y+130 },a,1.75f,20.0f };
     EuglenaEmitter m2{ { offset1x + 310,offset1y + 130 },a,1.75f,20.0f };
     EuglenaEmitter m3{ { offset2x + 310,offset2y + 130 },a,1.75f,20.0f };
     //EuglenaEmitter m{ { 310,100 },a,3.0f,25.0f };

      sim->addEmitter(m);
      sim->addEmitter(m2);
      sim->addEmitter(m3);

      
       if (A)
           sim->addEmitter(input);

       if (B)
           sim->addEmitter(input2);

       


           sim->setAgentTemplate(a);

    return sim;
}

std::unique_ptr<Simulation> EuglenaExperiment::EmitterTest()
{
   

    std::unique_ptr<Simulation> sim= std::make_unique<Simulation>(800, 800);
  

    //EuglenaAgent templ{glm::vec2(10, 10), 20, 2.0, 5};
    //EuglenaEmitter e{ {100,100}, EuglenaAgent{ { 0.0,0.0 },1.0,3.0f,6.0f },1,50.0f };
    //sim.addEmitter(e);

   
    sim->setAgentTemplate(EuglenaAgent{ { 110,140 },1.0,3.0f,6.0f });
    sim->addAgent(EuglenaAgent{ { 0.0,0.0 },1.0,3.0f,6.0f });
  

    sim->addLightEmitter(DynamicLightEmitter{ { 100,200 },10,100 });

    //sim.setAgentTemplate(templ);

    return sim;
}
