#include "EuglenaAgent.h"
#include <random>
#include "Log.h"


EuglenaAgent::EuglenaAgent(const glm::vec2& position, float threshold, float speed, float radius) : _position(position), _radius(radius), _intensityThreshold(threshold), _speed(speed), _shape(radius), distribution(-1.0, 1.0), generator{position.x+position.y}
{
    _shape.setFillColor(sf::Color::Blue);
    
    
    randomDirection = glm::vec2{ distribution(generator),distribution(generator) };
}
EuglenaAgent::~EuglenaAgent()
{
}


EuglenaAgent& EuglenaAgent::update(const glm::vec2& gravity, float deltaTime)
{

    if(lastUpdated>1.0f)
    {
        randomDirection = glm::vec2{ distribution(generator),distribution(generator) };
        lastUpdated = 0;
    }
    lastUpdated += deltaTime;
    
    
  
    
    moveAgent(deltaTime, gravity);
    return *this;
}



EuglenaAgent& EuglenaAgent::setPosition(const glm::vec2& position)
{
    _position = position;
    return *this;
}

void EuglenaAgent:: draw(sf::RenderWindow& renderWindow) const
{
    switch (mode)
    {
    case AgentMode::ATTRACTED:
        _shape.setFillColor(sf::Color::Green);
        break;
    case AgentMode::FEAR:
        _shape.setFillColor(sf::Color::Red);
        break;
    case AgentMode::EXPLORING:
        _shape.setFillColor(sf::Color::Blue);
        break;

    }

     sf::Vertex line[] = { sf::Vector2f{ _position.x, _position.y },sf::Vector2f{ _position.x+_radius*_direction.x,_position.y+_radius*_direction.y } };
    

    _shape.setPosition(_position.x-_radius, _position.y-_radius);
    renderWindow.draw(_shape);
    renderWindow.draw(line, 2, sf::Lines);

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

float EuglenaAgent::getAbsorbtionRate() const
{
    return _absorbtionRate;
}

EuglenaAgent& EuglenaAgent::clearPerception()
{
    _perceivedIntensity = 0.0f;
    _perceivedDirection = { 0,0 };
    return *this;
}

EuglenaAgent& EuglenaAgent::addIntensity(float pIntensity)
{
    _perceivedIntensity += pIntensity;
    return *this;
}

EuglenaAgent& EuglenaAgent::addDirection(glm::vec2 pDirection)
{

    _perceivedDirection += pDirection;
    return *this;
}

glm::vec2 EuglenaAgent::getRandomDirection()
{
    return glm::vec2();
}

void EuglenaAgent::moveAgent(float dt, const  glm::vec2& gravity)
{
    glm::vec2 photoTaxis;
    glm::vec2 graviTaxis;

    if (glm::length(_perceivedDirection) > 0.001)
        photoTaxis = glm::normalize(_perceivedDirection);

    if (glm::length(gravity) > 0.001)
        graviTaxis = glm::normalize(gravity);

    _perceivedIntensity = glm::length(_perceivedDirection);
    //_perceivedDirection = _perceivedIntensity*photoTaxis;
    auto threshold = [&]() {return _perceivedIntensity > _intensityThreshold ? -1.0f : 1.0f; };
    
  /*  if (_perceivedDirection.x == _perceivedDirection.y && _perceivedDirection.x == 0)
        _perceivedDirection =glm::normalize(randomDirection);
    else
    _perceivedDirection = glm::normalize(_perceivedDirection);*/

   _direction= 0.45f*threshold()*photoTaxis + 0.30f*graviTaxis + 0.25f*glm::normalize(randomDirection);
        


    _position += _speed*_direction*dt;
   
    
}

void EuglenaAgent::reSeed()
{
    generator.seed((time(nullptr) + _position.x + _position.y));
}


int EuglenaAgent::m_determineDirection(float perceivedIntensity) const
{
    if (perceivedIntensity < _intensityThreshold)
        return 1;
    return -1;
}
