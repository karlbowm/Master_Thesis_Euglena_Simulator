#include "EuglenaEmitter.h"
#include<glm/gtc/constants.hpp>
#include<glm/gtx/rotate_vector.hpp>
EuglenaEmitter::EuglenaEmitter(const glm::vec2& position, const EuglenaAgent& templ, float spawnRate, float spawnRadius): _position(position), _spawnRadius(spawnRadius),_spawnRate(spawnRate), _agentTemplate(templ), _rangeDistribution(0.0f,_spawnRadius),_angleDistribution(0,2*glm::pi<float>())
{
}

void EuglenaEmitter::update(float dt, std::vector<EuglenaAgent>& agents)
{
    _lastSpawnTime += dt;
    if (_lastSpawnTime < _spawnRate)
        return;
    
    //create ran
    EuglenaAgent spawn = _agentTemplate;

    auto randomvec = _position + _rangeDistribution(_generator)*glm::rotate(glm::vec2(0.0f, 1.0f), _angleDistribution(_generator));
    spawn.setPosition(randomvec);
    agents.emplace_back(_agentTemplate);
    _lastSpawnTime = 0;
    

}