#pragma once
#include <glm/detail/type_vec2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class LightLine
{
public:
    LightLine(const glm::vec2& start, const glm::vec2& end, float intensity, float range);
    ~LightLine();

    float getLightIntensityAt(const glm::vec2& position);
    void draw(sf::RenderWindow& window);
    float calculateShortestDistanceTo(const glm::vec2& position);
    float getDistanceTo(glm::vec2 position);
    glm::vec2 getDirectionAt(const glm::vec2& position);

private:
    glm::vec2 _start;
    glm::vec2 _end;
    double _range;
    double _intensity;
};