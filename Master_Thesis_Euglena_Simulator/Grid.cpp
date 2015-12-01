#include "Grid.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

Grid::Grid(int i, int j) : _iMax(i), _jMax(j)
{

}

Grid::Grid(int i, int j, float cWidth, float cHeight) : _iMax(i), _jMax(j), _cellWidth(cWidth), _cellHeight(cHeight)
{
  
}

Grid::~Grid()
{
}

glm::ivec2 Grid::convertCoordinateToIndex(const glm::vec2 coordinate) const
{
    if (isOutside(coordinate))
        return{-1,-1};
    return{static_cast<int>(coordinate.x / _cellWidth) ,static_cast<int>(coordinate.y / _cellHeight)};
}












int Grid::getImax() const
{
    return _iMax;
}

glm::vec2 Grid::getSimulationArea() const
{
    return{_cellWidth * _iMax,_cellHeight * _jMax};
}

bool Grid::isOutside(const glm::vec2& position) const
{
    glm::vec2 maxArea = getSimulationArea();
    if (position.x > 0 && position.x < maxArea.x)
        if (position.y > 0 && position.y < maxArea.y)
            return false;

    return true;
}

bool Grid::isOutside(const glm::ivec2& index) const
{
    glm::vec2 maxArea = {_iMax,_jMax};
    if (index.x > 0 && index.x < maxArea.x)
        if (index.y > 0 && index.y < maxArea.y)
            return false;

    return true;
}

int Grid::getJmax() const
{
    return _jMax;
}



float Grid::getWidth() const
{
    return _cellWidth;
}

float Grid::getHeight() const
{
    return _cellHeight;
}
