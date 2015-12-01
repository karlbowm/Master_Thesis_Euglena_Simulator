#include "DynamicLightEmitter.h"
#include<glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>


DynamicLightEmitter::DynamicLightEmitter(const glm::vec2 pos, float intensity, float range): _position{pos},_intensity{intensity},_range{range}
{

}

DynamicLightEmitter::~DynamicLightEmitter()
{
}

float DynamicLightEmitter::getIntensity(const std::vector<EuglenaAgent>& agents, const glm::vec2& position)
{

    if(_position.x>position.x || glm::angle(glm::normalize(_position), glm::normalize(position))>40.0f)
    {
        return 0.0;
    }
    auto intensity=getLightIntensityAt(position);
    if (intensity == 0.0)
        return 0.0;

    //since below this loop will count the agent with the the same position as the input pusition 
    int count = -1;
    for(const auto& agent :  agents)
    {
        if (calculateShortestDistance(_position, position, agent.getPosition()) < agent.getRadius())
        {
            count++;
        }
    }

    return std::max(intensity-count*agents[0].getAbsorbtionRate(),0.0f);


}

float DynamicLightEmitter::getLightIntensityAt(const glm::vec2& position)
{

    auto distance = glm::length(_position-position);

    auto factor = distance / _range;

    auto intensity= factor < 1 ? (1 - factor) * _intensity : 0.0f;
   
    return intensity;
}

void DynamicLightEmitter::draw(sf::RenderWindow& renderWindow) const
{

    sf::CircleShape _shape(10);
    auto t = _range *(1.0f-1.0f/ _intensity);
    
    sf::CircleShape _thresh(t);
    sf::CircleShape _cone(_range);
    _shape.setPosition(_position.x - 10, _position.y - 10);
    _shape.setFillColor(sf::Color::Yellow);
    _thresh.setPosition(_position.x - t, _position.y - t);
    _cone.setPosition(_position.x - _range, _position.y - _range);
    _cone.setFillColor(sf::Color::Transparent);
    _cone.setOutlineColor(sf::Color::Green);
    _cone.setOutlineThickness(2);

    _thresh.setFillColor(sf::Color::Transparent);
    _thresh.setOutlineColor(sf::Color::Magenta);
    _thresh.setOutlineThickness(4);
  /* renderWindow.draw(_thresh);
    renderWindow.draw(_cone);*/
    renderWindow.draw(_shape);
}

glm::vec2 DynamicLightEmitter::getDirectionAt(const glm::vec2& position)
{
    return _position - position;
}

float DynamicLightEmitter::calculateShortestDistance(const glm::vec2& start, const glm::vec2& end, const glm::vec2& position)
{
    auto deltaVec = end - start;
    auto lengthSq = glm::dot(deltaVec, deltaVec);

    auto u = ((position.x - start.x) * deltaVec.x + (position.y - start.y) * deltaVec.y) / lengthSq;

    if (u > 1)
        u = 1;
    else if (u < 0)
        u = 0;

    auto k = start + u*deltaVec;


    auto delta = k - position;

    return glm::length(delta);
}
