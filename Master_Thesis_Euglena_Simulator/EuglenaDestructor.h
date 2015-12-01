#pragma once
#include<glm/glm.hpp>
#include<SFML/Graphics.hpp>
class EuglenaDestructor
{
public:
    EuglenaDestructor(glm::vec2 pos,glm::vec2 widthAndHeight);
    ~EuglenaDestructor();

    bool isInside(const glm::vec2& point) const;

    void draw(sf::RenderWindow& renderWindow) const;

    glm::vec2 _position;
    glm::vec2 _size;

    
};

