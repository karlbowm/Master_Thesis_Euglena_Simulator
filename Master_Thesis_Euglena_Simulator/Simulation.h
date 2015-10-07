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
    void addEmitter(EuglenaEmitter emitter);
    void setStaticLight(const std::vector<glm::ivec2> coordinates, float intensity);
    void update(float deltaTime);
    void draw(sf::RenderWindow& renderWindow);
    glm::vec2 getGradient(int i, int j), getGradient(float x, float y), getGradient(const glm::vec2& position), getGradient(const EuglenaAgent& agent);
    void addAgent(EuglenaAgent& agent);

    ~Simulation();

private:

    bool isOutside(const glm::vec2& position), isOutside(const EuglenaAgent& agent);
    Grid _data;
    std::vector<EuglenaAgent> _agents;
    std::vector<EuglenaEmitter> _emitters;
    glm::vec2 _gravityVector = -glm::vec2(0.0f, 1.0f);
    EuglenaAgent _agentTemplate;
};
