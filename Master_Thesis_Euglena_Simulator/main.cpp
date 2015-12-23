#include "Simulation.h"
#include<SFML/Graphics.hpp>
#include <iostream>

#include<gsl.h>

#include "Log.h"
#include "EuglenaExperiment.h"

enum SimState
{
    RUN,
    PAUSE
};

enum SpawnMode
{
    Agent,
    Emitter,
    StaticLight
};


SimState toggle(SimState state)
{
    if (state == SimState::RUN)
        return SimState::PAUSE;

    return SimState::RUN;
};

int main(int argc, char* argv[])
{
    auto cellCountX = 50;
    auto cellCountY = 50;

    auto cellSizeX = 12.0f;
    auto cellSizeY = 12.0f;


    //sSimulation sim = EuglenaExperiment::getANDGateSimulation(true,true);
    std::unique_ptr<Simulation> sim = EuglenaExperiment::getMemoryCell(false);
    //Simulation sim = EuglenaExperiment::EmitterTest();
    long unsigned int frameCounter = 0;
  
    sf::RenderWindow window{ sf::VideoMode(1000,1000), "Euglena Blpha 0.79" };
    

    float timestepSize = 0.05f;
    float speedFactor = 3;
    //sim.addEmitter(emitter);
    auto state = SimState::RUN;
    int shiftX = 0;
    int shiftY = 0;
    int width = 1000;
    int height = 1000;

    while (window.isOpen())
    {
        window.setView(sf::View(sf::FloatRect(shiftX, shiftY, width, height)));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (state == SimState::PAUSE)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    auto position = sf::Mouse::getPosition(window);
                    //sim.setStaticLight({{position.x / cellSizeX,position.y / cellSizeY}}, 100);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    auto position = sf::Mouse::getPosition(window);
                    sim->spawnAgentAt({ position.x, position.y });
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    state = toggle(state);
                    std::cout << (state == SimState::RUN ? "Unpaused\n" : "Paused\n");
                }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    shiftY -= 10;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    shiftY += 10;
                }    
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    shiftX -= 10;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    shiftX += 10;
                }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                {
                    width += 20;
                    height += 20;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    width -= 20;
                    height -= 20;
                }




            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        sim->draw(window);


        //test.draw(window);
        if (state == SimState::RUN)
            sim->update(timestepSize);

        window.display();

        static int runner = 0;
        static float timer = 1.0f;
        if (state == SimState::RUN)
        {
            if (timer > 10.0f)
            {
                auto screenshot = window.capture();
                screenshot.saveToFile("L:\\frame_" + std::to_string(runner++) + ".png");
                timer = 0;
            }

            timer += timestepSize;
        }

        //sf::sleep(sf::seconds(timestepSize/speedFactor));
    }
    return 0;
}
