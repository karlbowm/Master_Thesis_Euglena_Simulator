#pragma once
#include<glm/glm.hpp>

#include "Grid.h"
#include "EuglenaAgent.h"
#include "EuglenaEmitter.h"

#include "LightLine.h"
#include "DynamicLightEmitter.h"
#include"EuglenaDestructor.h"

class Simulation
{
public:
    Simulation(int i, int j);
    //Simulation(int i, int j, float cellWidth, float cellHeight);
    Simulation& setAgentTemplate(const EuglenaAgent& agentTemplate);
    Simulation& addEmitter(EuglenaEmitter emitter);
    Simulation& addAgent(const EuglenaAgent& agent);
    Simulation& addLightEmitter(const DynamicLightEmitter& lightEmitter);
    Simulation& addEuglenaDestructor(const EuglenaDestructor& eDestructor);
    Simulation& addLightLine(const LightLine& lightLine);
    Simulation& spawnAgentAt(glm::vec2 position);
    Simulation& update(float deltaTime);
    Simulation& draw(sf::RenderWindow& renderWindow);


    int getScreenWidth() const;
    int getScreenHeight() const;
   

    ~Simulation();

private:
    

    bool isOutside(const glm::ivec2& position) const, isOutside(const glm::vec2& position) const, isOutside(const EuglenaAgent& agent) const;  
    bool isInDestructor(const EuglenaAgent& agent);

    
    std::vector<EuglenaAgent> _agents;
    std::vector<EuglenaEmitter> _emitters;
    std::vector<DynamicLightEmitter> _lightEmitters;
    std::vector<LightLine> _lightLines;
    std::vector<EuglenaDestructor> _destructors;

    glm::vec2 _gravityVector = glm::vec2{0.0f,1.0f};
    float _lossFactor = 0.90f;
    EuglenaAgent _agentTemplate;
    int _width;
    int _height;
};
