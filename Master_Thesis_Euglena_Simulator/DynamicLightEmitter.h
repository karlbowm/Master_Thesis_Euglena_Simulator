#pragma once
#include <glm/vec2.hpp>
#include "EuglenaAgent.h"

class DynamicLightEmitter
{
public:
    DynamicLightEmitter(const glm::vec2 pos, float intensity, float range);
    ~DynamicLightEmitter();

    float getIntensity(const std::vector<EuglenaAgent>& agents, const glm::vec2& position);
    float getLightIntensityAt(const glm::vec2& position);
    void draw(sf::RenderWindow& renderWindow) const;
    glm::vec2 getDirectionAt(const glm::vec2& position);
private:
    float calculateShortestDistance(const glm::vec2& start, const glm::vec2& end,const glm::vec2& position);
    glm::vec2 _position;
    glm::vec2 _direction;
    float _intensity;
    float _range;
};

