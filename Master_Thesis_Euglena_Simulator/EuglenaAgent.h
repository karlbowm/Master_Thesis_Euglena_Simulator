﻿#pragma once
#include<glm/glm.hpp>
#include<SFML/Graphics.hpp>
#include <algorithm>
#include <glm/detail/type_mat.hpp>

class EuglenaAgent
{
public:

    EuglenaAgent(const glm::vec2& position, float threshold, float speed = 1.0f, float radius = 1.0f);


    ~EuglenaAgent();

    EuglenaAgent& update(const glm::vec2& gravity, float deltaTime, float perceivedIntensity);
    EuglenaAgent& setGradient(const glm::vec2& gradient, bool noise=true);
    EuglenaAgent& setPosition(const glm::vec2& position);
    void draw(sf::RenderWindow& renderWindow) const ;
    glm::vec2 getPosition() const;
    float getRadius() const;
    float getIntensityThreshold() const;
    float getSpeed() const;
    glm::vec2 getGradient() const;
    float getAbsorbtionRate();
private:

    int m_determineDirection(float perceivedIntensity) const;
    glm::vec2 _position;
    glm::vec2 _direction;
    float _radius = 1.0f;
    float _intensityThreshold;
    float _speed = 1;
    float _absorbtionRate = 5;
    sf::CircleShape mutable _shape;
};
