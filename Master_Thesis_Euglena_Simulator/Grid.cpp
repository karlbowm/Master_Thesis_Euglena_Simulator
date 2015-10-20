#include "Grid.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

Grid::Grid(int i, int j) : _iMax(i), _jMax(j)
{
    _data.resize(i);
    for (auto& column : _data)
        column.resize(j);
}

Grid::Grid(int i, int j, float cWidth, float cHeight) : _iMax(i), _jMax(j), _cellWidth(cWidth), _cellHeight(cHeight)
{
    _data.resize(i);
    for (auto& column : _data)
        column.resize(j);
}

Grid::~Grid()
{
}

glm::ivec2 Grid::convertCoordinateToIndex(const glm::vec2 coordinate) const
{
    if (isOutside(coordinate))
        return{ -1,-1 };
    return{ static_cast<int>(coordinate.x / _cellWidth) ,static_cast<int>(coordinate.y / _cellHeight) };
}
Cell& Grid::getCell(const glm::ivec2& position)
{
    return _data[position.x][position.y];
}

Cell& Grid::getCell(int i, int j)
{    
    return _data[i][j];
}

Cell& Grid::getCell(float x, float y)
{
    return _data[static_cast<int>(x / _cellWidth)][static_cast<int>(y / _cellHeight)];
}


Cell& Grid::getCell(const glm::vec2& position)
{
    return _data[static_cast<int>(position.x / _cellWidth)][static_cast<int>(position.y / _cellHeight)];
}

Cell& Grid::getCell(const EuglenaAgent& agent)
{
    auto position = agent.getPosition();
    return _data[static_cast<int>(position.x / _cellWidth)][static_cast<int>(position.y / _cellHeight)];
}

int Grid::getImax() const
{
    return _iMax;
}

glm::vec2 Grid::getSimulationArea() const
{
    return{ _cellWidth * _iMax,_cellHeight * _jMax };
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

Grid& Grid::draw(sf::RenderWindow& renderWindow) const
{
    for (auto i = 0; i < _iMax; ++i)
        for (auto j = 0; j < _jMax; ++j)
        {
            sf::RectangleShape cell({ _cellWidth,_cellHeight });
            auto col = sf::Color::Yellow;

            col.a = 255 * std::min(1.0f, _data[i][j].getTotalIntensity() / 100);
            cell.setFillColor(col);
            cell.setOutlineThickness(1);
            cell.setOutlineColor({ 255,255,255,100 });
            cell.setPosition(i * _cellWidth, j * _cellHeight);
            renderWindow.draw(cell);
        }
    return *this;
}

float Grid::getWidth() const
{
    return _cellWidth;
}

float Grid::getHeight() const
{
    return _cellHeight;
}
