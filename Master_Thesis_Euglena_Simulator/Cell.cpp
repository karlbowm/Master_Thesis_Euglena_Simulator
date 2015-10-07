#include "Cell.h"


Cell::Cell()
{
}

Cell::Cell(LightEmitter& emitter): _emitterComponent(&emitter)
{    
}

Cell::Cell(float staticLightIntensity, LightEmitter& emitter) : _staticLightIntensity(staticLightIntensity), _emitterComponent(&emitter)
{ 
}

bool Cell::hasEmitter() const
{
    return _emitterComponent != nullptr;
}

LightEmitter& Cell::getEmitter()
{
    return *_emitterComponent;
}

float Cell::getTotalIntensity() const
{
    return _dynamicLightIntensity + _staticLightIntensity;
}

float Cell::getDynamicLightIntensity()
{
    return _dynamicLightIntensity;
}

void Cell::draw(sf::RenderWindow& renderWindow) const
{
}

void Cell::setStaticLightIntensity(float intensity)
{
    _staticLightIntensity = intensity;
}

Cell::~Cell()
{
    if (_emitterComponent != nullptr)
        delete _emitterComponent;
}