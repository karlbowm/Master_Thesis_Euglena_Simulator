#include "Simulation.h"
#include<SFML/Graphics.hpp>
#include <iostream>

#include "Log.h"

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

    auto cellSizeX = 8.0f;
    auto cellSizeY = 8.0f;

 
    auto logger = Log();
    logger.print("THIS IS A TEST");

    sf::RenderWindow window{sf::VideoMode(cellCountX * cellSizeX, cellCountY * cellSizeY), "Euglena pre Alpha 0.02a"};

    Simulation sim{ cellCountX,cellCountY,cellSizeX,cellSizeY };
    
    std::vector<glm::ivec2> stats = {{0,0},{0,1},{0,2},{1,0},{1,0},{2,0}};
    EuglenaAgent test{ glm::vec2(10, 10), 50, 1.0, 5 };
    sim.setStaticLight(stats, 100);
    sim.setAgentTemplate(test);
    EuglenaEmitter emitter{ {30,30}, test, 1, 20.0f };

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
                    sim.setStaticLight({{position.x / cellSizeX,position.y / cellSizeY}}, 100);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    auto position = sf::Mouse::getPosition(window);
                    test.setPosition({position.x,position.y});
                    sim.addAgent(test);
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
            sim.update(0.1f);

        window.display();
        sf::sleep(sf::seconds(0.1f));
    }
    return 0;
}
