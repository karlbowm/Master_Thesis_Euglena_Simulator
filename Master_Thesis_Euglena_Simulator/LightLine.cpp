#include "LightLine.h"
#include <glm/glm.hpp> 



LightLine::LightLine(const glm::vec2& start, const glm::vec2& end, float intensity, float range) : _start{start}, _end{end}, _range{range}, _intensity{intensity}
{
}



LightLine::~LightLine()
{
}



float LightLine::getLightIntensityAt(const glm::vec2& position)
{
    auto distance = calculateShortestDistanceTo(position);

    float factor = distance / _range;

    return factor < 1 ? (1.0f - factor) * _intensity : 0.0f;
}

void LightLine::draw(sf::RenderWindow& window)
{
    sf::Vertex line[] = {sf::Vector2f{_start.x,_start.y},sf::Vector2f{_end.x,_end.y}};
    window.draw(line, 2, sf::Lines);
}

float LightLine::getDistanceTo(glm::vec2 position)
{
    auto distance = calculateShortestDistanceTo(position);
    return distance;
}

float LightLine::calculateShortestDistanceTo(const glm::vec2& position)
{
    auto deltaVec = _end - _start;
    auto lengthSq = glm::dot(deltaVec, deltaVec);

    auto u = ((position.x - _start.x) * deltaVec.x + (position.y - _start.y) * deltaVec.y) / lengthSq;

    if (u > 1)
        u = 1;
    else if (u < 0)
        u = 0;

    auto k = _start + u*deltaVec;
  

    auto delta = k - position;

    return glm::length(delta);
}

glm::vec2 LightLine::getDirectionAt(const glm::vec2& position)
{
    auto p = _end - _start;
    auto lengthSq = glm::dot(p, p);

    auto u = ((position.x - _start.x) * p.x + (position.y - _start.y) * p.y) / lengthSq;

    if (u > 1)
        u = 1;
    else if (u < 0)
        u = 0;

    auto x = _start.x + u * p.x;
    auto y = _start.y + u * p.y;

    auto dx = x - position.x;
    auto dy = y - position.y;


    return glm::normalize(glm::vec2{dx,dy});
}
