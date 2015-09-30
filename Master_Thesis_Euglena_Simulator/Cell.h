#pragma once
#include "LightEmitter.h"


namespace sf{
    class RenderWindow;
}

class Cell
{
public:
    Cell();
    explicit Cell(LightEmitter& emitter);
    Cell(float staticLightIntensity, LightEmitter& emitter);
    bool hasEmitter();
    LightEmitter& getEmitter();
    float getTotalIntensity();
    void draw(sf::RenderWindow& renderWindow);

    ~Cell();
    void setStaticLightIntensity(float intensity);
private:
    float _staticLightIntensity=0;
    float _dynamicLightIntensity=0;

    LightEmitter* _emitterComponent = nullptr;




};
