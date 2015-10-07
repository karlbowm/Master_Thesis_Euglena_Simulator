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
    return{ static_cast<int>(coordinate.x / _cellWidth) ,static_cast<int>(coordinate.y / _cellHeight) };
}

Cell& Grid::getCell(int i, int j)
{
    return _data[i][j];
}

Cell& Grid::getCell(float x, float y){
    
    return _data[static_cast<int>(x / _cellWidth)][static_cast<int>(y / _cellHeight)];
}
    

Cell& Grid::getCell(const glm::vec2& position)
{
    return _data[static_cast<int>(position.x / _cellWidth)][static_cast<int>(position.y / _cellHeight)];
}

int Grid::getImax() const
{
    return _iMax;
}

int Grid::getJmax() const
{
    return _jMax;
}

void Grid::draw(sf::RenderWindow& renderWindow)
{
    for (int i = 0; i < _iMax;++i)
        for (int j = 0; j < _jMax; ++j)
        {
            sf::RectangleShape cell({ _cellWidth,_cellHeight });
            auto col=sf::Color::Yellow;
            col.a = 255*std::min(1.0f, _data[i][j].getTotalIntensity() / 100);
            cell.setFillColor(col);
            cell.setOutlineThickness(1);
            cell.setOutlineColor({ 255,255,255,100 });
            cell.setPosition(i*_cellWidth, j*_cellHeight);
            renderWindow.draw(cell);
            
        }
}

float Grid::getWidth() const
{
    return _cellWidth;
}

float Grid::getHeight() const
{
    return _cellHeight;
}