#include "EuglenaDestructor.h"




EuglenaDestructor::EuglenaDestructor(glm::vec2 pos, glm::vec2 size): _position{pos}, _size{size}
{
}

EuglenaDestructor::~EuglenaDestructor()
{
}

bool EuglenaDestructor::isInside(const glm::vec2& point) const
{
    if (point.y > _position.y && point.y< _position.y+_size.y)       
        if (point.x > _position.x && point.x< _position.x + _size.x)
        return true;


    return false;
}

void EuglenaDestructor::draw(sf::RenderWindow& renderWindow) const
{
    sf::RectangleShape rect({ _size.x,_size.y });
    rect.setPosition({ _position.x,_position.y });
    renderWindow.draw(rect);    
}


