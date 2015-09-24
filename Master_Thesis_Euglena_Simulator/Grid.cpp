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
    return getCell(x / _cellWidth, y / _cellHeight);
}