#pragma once
#include "LightEmitter.h"

class Cell
{
public:
    Cell();
    explicit Cell(LightEmitter& emitter);
    Cell(float staticLightIntensity, LightEmitter& emitter);
    bool hasEmitter();
    LightEmitter& getEmitter();

    ~Cell();
private:
    float _staticLightIntensity=0;
    float _dynamicLightIntensity=0;

    LightEmitter* _emitterComponent = nullptr;


};
