#pragma once
#include "EuglenaAgent.h"
#include<glm/glm.hpp>
#include <vector>
#include <random>

class EuglenaEmitter
{
public:
    EuglenaEmitter(const glm::vec2& position, const EuglenaAgent& templ, float spawnRate, float spawnRadius);
    void update(float dt, std::vector<EuglenaAgent>& agents);
    void draw(sf::RenderWindow& renderWindow);
    void setAgentTemplate(EuglenaAgent& agentTemplate);
    
private:
    glm::vec2 _position;
    float _spawnRate;
    float _spawnRadius;
    float _lastSpawnTime = 0;
    EuglenaAgent _agentTemplate;

    std::default_random_engine _generator;

    std::uniform_real<float> _rangeDistribution;
    std::uniform_real<float> _angleDistribution;
    sf::RectangleShape _shape;
    sf::CircleShape _radShape;
};
