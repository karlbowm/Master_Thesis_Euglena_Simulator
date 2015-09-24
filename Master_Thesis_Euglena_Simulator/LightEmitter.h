#pragma once
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
    LightEmitter(float intensity, Direction direction=Direction::N);
    ~LightEmitter();

    float getIntensity() const;
    Direction getDirection() const;

    LightEmitter& setIntensity(float newIntensity);
    LightEmitter& setDirection(Direction newDirection);

private:

    float _intensity=0;
    Direction _direction;
    
};
