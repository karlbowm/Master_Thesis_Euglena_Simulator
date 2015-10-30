#include "LightEmitter.h"
#include <glm/detail/func_geometric.inl>


LightEmitter::LightEmitter(float intensity, glm::vec2 position, float lossRate) : _intensity{intensity}, _position{position}, _lossRate{lossRate}
{
}

LightEmitter::~LightEmitter()
{
}


float LightEmitter::getIntensityAt(glm::vec2 position)
{
    auto resultIntensity = _intensity - _lossRate * glm::length(_position - position);
    return resultIntensity > 0 ? resultIntensity : 0;
}

glm::vec2 LightEmitter::getDirectionAt(glm::vec2 position)
{
    return this->getPosition() - position;
}

float LightEmitter::getIntensity()
{
    return _intensity;
}

glm::vec2 LightEmitter::getPosition()
{
    return _position;
}

void LightEmitter::setIntensity(float intensity)
{
    _intensity = intensity;
}

float LightEmitter::getLossRate()
{
    return _lossRate;
}

void LightEmitter::setLossRate(float lossRate)
{
    _lossRate = lossRate;
}

void LightEmitter::draw(sf::RenderWindow& renderWindow) const
{
    auto radius = _intensity / _lossRate;

    sf::CircleShape circle{radius};
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(1);
    circle.setPosition(_position.x - radius, _position.y - radius);

    renderWindow.draw(circle);
}
