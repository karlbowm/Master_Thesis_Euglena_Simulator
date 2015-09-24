#include "LightEmitter.h"

LightEmitter::LightEmitter(float intensity, Direction direction):_intensity(intensity), _direction(direction)
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