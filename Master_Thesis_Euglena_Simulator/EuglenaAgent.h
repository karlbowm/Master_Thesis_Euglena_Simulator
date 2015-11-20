#pragma once
#include<glm/glm.hpp>
#include<SFML/Graphics.hpp>
#include <algorithm>
#include <glm/detail/type_mat.hpp>
#include <random>
enum class AgentMode
{
    EXPLORING,
    ATTRACTED,
    FEAR
};
class EuglenaAgent
{
public:

    EuglenaAgent(const glm::vec2& position, float threshold, float speed = 4.0f, float radius = 1.0f);


    ~EuglenaAgent();

    EuglenaAgent& update(const glm::vec2& gravity, float deltaTime);
    EuglenaAgent& setPosition(const glm::vec2& position);
    void draw(sf::RenderWindow& renderWindow) const ;
    glm::vec2 getPosition() const;
    float getRadius() const;
    float getIntensityThreshold() const;
    float getSpeed() const;
    glm::vec2 getGradient() const;
    float getAbsorbtionRate() const;
    EuglenaAgent& clearPerception();
    EuglenaAgent& addIntensity(float pIntensity);
    EuglenaAgent& addDirection(glm::vec2 pDirection);
    glm::vec2 getRandomDirection();
    void reSeed();
private:

    AgentMode mode = AgentMode::EXPLORING;
    void moveAgent(float dt,const  glm::vec2& gravity);
    float _perceivedIntensity;
    glm::vec2 _perceivedDirection;
    int m_determineDirection(float perceivedIntensity) const;
    glm::vec2 _position;
    glm::vec2 _direction;
    float _radius = 1.0f;
    float _intensityThreshold;
    float _speed = 2;
    float _absorbtionRate = 0.25;
    sf::CircleShape mutable _shape;
    std::mt19937_64 generator;
    std::uniform_real_distribution<float> distribution;
    float lastUpdated = 0;
    glm::vec2 randomDirection;
    float fearTimer = 0;
};
