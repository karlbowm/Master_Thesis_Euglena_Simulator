#include "Grid.h"
#include <SFML/Graphics/RenderWindow.hpp>

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

void Grid::draw(sf::RenderWindow& renderWindow)
{
    for (int i = 0; i < _iMax;++i)
        for (int j = 0; j < _jMax; ++j)
        {
            sf::RectangleShape cell({ _cellWidth,_cellHeight });
            sf::Color col=sf::Color::Yellow;
            col.a = 255*std::min(1.0f, _data[i][j].getTotalIntensity() / 100);
            cell.setFillColor(col);
            cell.setPosition(i*_cellWidth, j*_cellHeight);
            renderWindow.draw(cell);
            
        }
}