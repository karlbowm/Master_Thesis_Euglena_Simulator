#pragma once
#include "LightEmitter.h"
#include<SFML/Graphics.hpp>


/*Cell class hold data about static light values and dynamic light values and a draw function */
class Cell
{
public:
    Cell();
    
    Cell(float staticLightIntensity);
 
   
    float getTotalIntensity() const;
    float getDynamicLightIntensity();
    float getStaticLightIntensity() const;
    void draw(sf::RenderWindow& renderWindow) const;

    ~Cell();
    void setStaticLightIntensity(float intensity);
    void setDynamicLightIntensity(float intensity);
private:
    float _staticLightIntensity = 0;
    float _dynamicLightIntensity = 0;

   
};
