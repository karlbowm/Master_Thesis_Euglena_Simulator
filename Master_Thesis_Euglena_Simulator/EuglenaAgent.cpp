#include "EuglenaAgent.h"
#include <random>


EuglenaAgent::EuglenaAgent(const glm::vec2& position, float threshold, float speed, float radius) : _position(position), _radius(radius), _intensityThreshold(threshold), _speed(speed), _shape(radius)
{
    _shape.setFillColor(sf::Color::Green);
}

EuglenaAgent::~EuglenaAgent()
{
}


EuglenaAgent& EuglenaAgent::update(float deltaTime, float perceivedIntensity)
{
    _position += m_determineDirection(perceivedIntensity) * _speed *glm::normalize(_direction)*deltaTime;
    //std::cout << "Perceived Intensity: " << perceivedIntensity << "\tDirection: " << _direction.x << "," << _direction.y << "\t directional sign:"<< m_determineDirection(perceivedIntensity) <<std::endl;
    return *this;
}

EuglenaAgent& EuglenaAgent::setGradient(const glm::vec2& gradient, bool noise)
{
    static std::default_random_engine generator;
    static std::uniform_real_distribution<float> distribution(-1.0, 1.0);

    //TODO: add random vector -> some added noise
    if(noise)
        _direction = gradient + glm::vec2{ distribution(generator),distribution(generator) };
        
    else
        _direction = gradient;
        


    return *this;
}

EuglenaAgent& EuglenaAgent::setPosition(const glm::vec2& position)
{
    _position = position;
    return *this;
}

void EuglenaAgent::draw(sf::RenderWindow& renderWindow) const
{
    _shape.setPosition(_position.x, _position.y);
    renderWindow.draw(_shape);
}

glm::vec2 EuglenaAgent::getPosition() const
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

float EuglenaAgent::getSpeed() const
{
    return _speed;
}

glm::vec2 EuglenaAgent::getGradient() const
{
    return _direction;
}

int EuglenaAgent::m_determineDirection(float perceivedIntensity) const
{
    if (perceivedIntensity < _intensityThreshold)
        return -1;
    return 1;
}
