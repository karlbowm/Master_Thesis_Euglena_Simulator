#pragma once
#include<glm/glm.hpp>

#include "Grid.h"
#include "EuglenaAgent.h"
#include "EuglenaEmitter.h"

class Simulation
{
public:
    Simulation(int i, int j);
    Simulation(int i, int j, float cellWidth, float cellHeight);
    Simulation& setAgentTemplate(EuglenaAgent& agentTemplate);
    Simulation& setStaticLight(const std::vector<glm::ivec2> coordinates, float intensity);
    Simulation& addEmitter(EuglenaEmitter emitter);
    Simulation& addAgent(const EuglenaAgent& agent);
    Simulation& addLightEmitter(const LightEmitter& lightEmitter);
    Simulation& spawnAgentAt(glm::vec2 position);
    Simulation& update(float deltaTime);
    Simulation& draw(sf::RenderWindow& renderWindow);
    int getCellCountX() const;
    int getCellCountY() const;
    float getCellSizeX() const;

    float getCellSizeY() const;

    ~Simulation();

private:

    void updateDynamicLight();
    bool isOutside(const glm::ivec2& position) const,  isOutside(const glm::vec2& position) const, isOutside(const EuglenaAgent& agent) const;
    glm::vec2 getGradient(int i, int j), getGradient(float x, float y), getGradient(const glm::vec2& position), getGradient(const EuglenaAgent& agent);
    glm::ivec2 shiftPositionInDirection(const glm::vec2& position, Direction direction);

    Grid _data;

    std::vector<EuglenaAgent> _agents;
    std::vector<EuglenaEmitter> _emitters;
    std::vector<LightEmitter> _lightEmitters;

    glm::vec2 _gravityVector = glm::vec2{ 0.0f, 1.0f };
    EuglenaAgent _agentTemplate;
};
