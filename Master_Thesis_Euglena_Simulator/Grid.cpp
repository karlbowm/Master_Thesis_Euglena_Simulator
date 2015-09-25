#include "Grid.h"

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