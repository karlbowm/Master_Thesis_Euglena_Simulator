#include "EuglenaAgent.h"



EuglenaAgent::EuglenaAgent(const glm::vec2& position, float threshold, float speed, float radius): _position(position), _radius(radius), _intensityThreshold(threshold), _speed(speed)
{
}

EuglenaAgent::~EuglenaAgent()
{
}


EuglenaAgent & EuglenaAgent::update(float deltaTime, float perceivedIntensity)
{
    

    _position += m_determineDirection(perceivedIntensity)*_speed*_direction;
    
    return *this;
}

EuglenaAgent & EuglenaAgent::setGradient(const glm::vec2 & gradient)
{
    if(gradient.length()!=0)
    {
        
        _direction = glm::normalize(gradient);   
    }

    return *this;
}

glm::vec2 EuglenaAgent::getPosition()
{
    return _position;
}

float EuglenaAgent::getRadius() const
{
    return _radius;
}

float EuglenaAgent::getIntensityThreshold() const
{
    return _intensityThreshold;
}

int EuglenaAgent::m_determineDirection(float perceivedIntensity) const
{
    if (perceivedIntensity < _intensityThreshold)
        return 1;
    else
        return -1;
}