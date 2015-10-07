#include "EuglenaEmitter.h"
#include<glm/gtc/constants.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include <iostream>

EuglenaEmitter::EuglenaEmitter(const glm::vec2& position, const EuglenaAgent& templ, float spawnRate, float spawnRadius) : _position(position), _spawnRate(spawnRate), _spawnRadius(spawnRadius), _agentTemplate(templ), _rangeDistribution(0.0f, _spawnRadius), _angleDistribution(0, 2 * glm::pi<float>()), _shape({10,10}),_radShape(spawnRadius)
{
    _shape.setFillColor(sf::Color::White);
    _radShape.setFillColor(sf::Color::Transparent);
    _radShape.setOutlineThickness(1);
    _radShape.setOutlineColor(sf::Color::White);

}

void EuglenaEmitter::update(float dt, std::vector<EuglenaAgent>& agents)
{
    static bool spawned = false;
    _lastSpawnTime += dt;
    if (_lastSpawnTime < _spawnRate || spawned)
        return;
    
    //create ran
    EuglenaAgent spawn = _agentTemplate;

    auto randomvec = _position + _rangeDistribution(_generator)*glm::rotate(glm::vec2(0.0f, 1.0f), _angleDistribution(_generator));
    spawn.setPosition(randomvec);
    agents.emplace_back(spawn);
    spawned = true;
    _lastSpawnTime = 0;
    std::cout << "Agent spawned at ("<< randomvec.x<<"," <<randomvec.y<<")\n";

}

void EuglenaEmitter::draw(sf::RenderWindow& renderWindow)
{

    _shape.setPosition(_position.x, _position.y);
    _radShape.setPosition(_position.x-_spawnRadius/2-5, _position.y - _spawnRadius / 2-5);
    renderWindow.draw(_radShape);
    renderWindow.draw(_shape);
}

void EuglenaEmitter::setAgentTemplate(EuglenaAgent& agentTemplate)
{
    _agentTemplate = agentTemplate;
}