#include "LightEmitter.h"
#include <glm/detail/func_geometric.inl>

LightEmitter::LightEmitter(float intensity,glm::ivec2 position,  Direction direction):_intensity(intensity), _direction(direction), _position(position)
{
}

LightEmitter::~LightEmitter()
{
}

float LightEmitter::getIntensity() const
{
    return _intensity;
}

LightEmitter& LightEmitter::setIntensity(float newIntensity)
{
    _intensity = newIntensity;
    return *this;
}

Direction LightEmitter::getDirection() const
{
    return _direction;
}

LightEmitter& LightEmitter::setDirection(Direction newDirection)
{
    _direction = newDirection;
    return *this;
}

float LightEmitter::getIntensityAt(glm::vec2 position)
{
    auto resultIntensity=_intensity - _lossRate*glm::length(_position - position);
    return resultIntensity > 0 ? resultIntensity : 0;
}

glm::ivec2 LightEmitter::getPosition() const
{
    return _position;
}
