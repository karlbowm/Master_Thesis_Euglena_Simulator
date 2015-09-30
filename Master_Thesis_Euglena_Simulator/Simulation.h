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
    glm::vec2 getGradient(int i, int j), getGradient(float x, float y), getGradient(const glm::vec2& position);


    ~Simulation();

private:
    Grid _data;
    std::vector<EuglenaAgent> _agents;
    std::vector<EuglenaEmitter> _emitters;

    EuglenaAgent _agentTemplate;

};

