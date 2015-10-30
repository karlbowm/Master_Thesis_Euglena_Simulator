#pragma once
#include <glm/detail/type_vec2.hpp>
#include <SFML/Graphics.hpp>

class StaticLight
{
public:
    StaticLight(const glm::vec2& start, const glm::vec2& end, float intensity, float range);
    ~StaticLight();
    //float getLightIntensityAt(const glm::vec2& position);
    //glm::vec2 getDirectionAt(const glm::vec2& position);
    //void draw(sf::RenderWindow& window);
    //float getDistanceTo(glm::vec2 position);

private:

  
    glm::vec2 _start;
    glm::vec2 _end;

    float _range;
    float _intensity;
};

