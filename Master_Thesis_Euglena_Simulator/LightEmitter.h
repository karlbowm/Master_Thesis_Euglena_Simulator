#pragma once
#include <glm/vec2.hpp>
#include<SFML/Graphics.hpp>


class LightEmitter
{
public:
    LightEmitter(float intensity, glm::vec2 position, float lossRate = 1.0);
    ~LightEmitter();
    float getIntensityAt(glm::vec2 position);
    glm::vec2 getDirectionAt(glm::vec2 position);
    float getIntensity();
    glm::vec2 getPosition();
    void setIntensity(float intensity);
    float getLossRate();
    void setLossRate(float lossRate);

    void draw(sf::RenderWindow& renderWindow) const;


private:

    float _lossRate = 0.1;

    float _intensity;
    glm::vec2 _position;
};
