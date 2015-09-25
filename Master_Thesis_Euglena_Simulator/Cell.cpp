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

bool Cell::hasEmitter()
{
    return _emitterComponent != nullptr;
}

LightEmitter& Cell::getEmitter()
{
    return *_emitterComponent;
}

float Cell::getTotalIntensity()
{
    return _dynamicLightIntensity + _staticLightIntensity;
}

Cell::~Cell()
{
    if (_emitterComponent != nullptr)
        delete _emitterComponent;
}