#include "Simulation.h"
#include<SFML/Graphics.hpp>
#include <iostream>

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

 
    
    Simulation sim = EuglenaExperiment::getANDGateSimulation();

    auto cellx = sim.getCellCountX();
    auto celly = sim.getCellCountY();

    auto cWidth = sim.getCellSizeX();
    auto cHeihght = sim.getCellSizeY();
    sf::RenderWindow window{sf::VideoMode(sim.getCellCountX() * sim.getCellSizeX(), sim.getCellCountY() * sim.getCellSizeY()), "Euglena pre Alpha 0.02a"};

    
    


    
   

    float timestepSize = 0.1f;
    float speedFactor = 3;
    //sim.addEmitter(emitter);
    auto state = SimState::RUN;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (state == SimState::PAUSE)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    auto position = sf::Mouse::getPosition(window);                  
                    //sim.setStaticLight({{position.x / cellSizeX,position.y / cellSizeY}}, 100);
                    sim.addLightEmitter(LightEmitter{ 100,{ position.x / cellSizeX,position.y / cellSizeY },Direction::E });
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    auto position = sf::Mouse::getPosition(window);
                    sim.spawnAgentAt({ position.x, position.y });
                    
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    state = toggle(state);
                    std::cout << (state == SimState::RUN ? "Unpaused\n" : "Paused\n");
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    std::cout << (state == SimState::RUN ? "Unpaused\n" : "Paused\n");
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        sim.draw(window);


        //test.draw(window);
        if (state == SimState::RUN)
            sim.update(timestepSize);

        window.display();
        //sf::sleep(sf::seconds(timestepSize/speedFactor));
    }
    return 0;
}



