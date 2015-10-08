#include "Cell.h"


Cell::Cell()
{
}


Cell::Cell(float staticLightIntensity) : _staticLightIntensity(staticLightIntensity)
{
}


float Cell::getTotalIntensity() const
{
    return _dynamicLightIntensity + _staticLightIntensity;
}

float Cell::getDynamicLightIntensity()
{
    return _dynamicLightIntensity;
}

float Cell::getStaticLightIntensity() const
{
    return _staticLightIntensity;
}

void Cell::draw(sf::RenderWindow& renderWindow) const
{
}

void Cell::setStaticLightIntensity(float intensity)
{
    _staticLightIntensity = intensity;
}

void Cell::setDynamicLightIntensity(float intensity)
{
    _dynamicLightIntensity = intensity;
}

Cell::~Cell()
{
   
}
