#include "Simulation.h"
#include<SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML WORKS");
   
    Simulation sim(100, 100, 1, 1);

    EuglenaAgent test(glm::vec2(10,10),0,0,5);

    sim.setAgentTemplate(test);
    EuglenaEmitter emitter({ 20,20 }, test,1, 20.0f);

   // sim.addEmitter(emitter);

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
