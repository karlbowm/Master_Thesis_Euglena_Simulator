#pragma once
#include <glm/vec2.hpp>

enum Direction
{
    N,
    E,
    S,
    W
};

class LightEmitter
{
public:
    LightEmitter(float intensity, glm::ivec2 position, Direction direction = Direction::N);
    ~LightEmitter();

    float getIntensity() const;
    Direction getDirection() const;

    LightEmitter& setIntensity(float newIntensity);
    LightEmitter& setDirection(Direction newDirection);
    float getIntensityAt(glm::vec2 position);
    glm::ivec2 getPosition() const;


private:

    glm::vec2 _position;
    float _intensity = 0;
    Direction _direction;
    float _lossRate=0.1;
};
