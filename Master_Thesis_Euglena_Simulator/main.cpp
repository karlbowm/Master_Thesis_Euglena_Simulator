#include "Simulation.h"
#include<SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Euglena pre Alpha 0.02a");
   
    Simulation sim(100, 100, 6, 6);
    std::vector<glm::ivec2> stats = { glm::ivec2{0,0},glm::ivec2{ 2,2 },glm::ivec2{ 98,98 } };
    EuglenaAgent test(glm::vec2(10,10),0,0,5);
    sim.setStaticLight(stats, 100);
    sim.setAgentTemplate(test);
    EuglenaEmitter emitter({ 30,30 }, test,1, 20.0f);

    sim.addEmitter(emitter);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);        
        sim.draw(window);
        
        //test.draw(window);
        sim.update(1);
        window.display();
        sf::sleep(sf::seconds(0.1));
      
    }
    return 0;

}
