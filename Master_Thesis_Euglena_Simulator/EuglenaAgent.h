﻿#pragma once
#include<glm/glm.hpp>
class EuglenaAgent
{
public:
   
    EuglenaAgent(const glm::vec2& position,float threshold,float speed=1.0f, float radius=1.0f );

   
    ~EuglenaAgent();
    
    EuglenaAgent& update(float deltaTime, float perceivedIntensity);
    EuglenaAgent& setGradient(const glm::vec2& gradient);
    EuglenaAgent& setPosition(const glm::vec2& position);

    glm::vec2 getPosition();
    float getRadius() const;
    float getIntensityThreshold() const;

private:

    int m_determineDirection(float perceivedIntensity) const;
    glm::vec2 _position;
    glm::vec2 _direction;
    float _radius=1.0f;
    float _intensityThreshold;
    float _speed=1.0;
};
