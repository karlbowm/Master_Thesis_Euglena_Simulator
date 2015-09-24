#pragma once
#include "Cell.h"
#include <array>
#include <vector>

class Grid
{
public:

    Grid(int i, int j);
    Grid(int i, int j, float cWidth, float cHeight);
    ~Grid();

    Cell& getCell(int i,int j);
    Cell& getCell(float x, float y);


private:
    float _cellWidth=1.0f;
    float _cellHeight=1.0f;

    int _iMax = -1;
    int _jMax = -1;
    std::vector<std::vector<Cell>> _data;
};
