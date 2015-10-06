#pragma once
#include "Cell.h"
#include <glm/glm.hpp>
#include <vector>
#include <algorithm>
#include <glm/detail/type_mat.hpp>

namespace sf{
    class RenderWindow;
}

class Grid
{
public:

    Grid(int i, int j);
    Grid(int i, int j, float cWidth, float cHeight);
    ~Grid();
    glm::ivec2 convertCoordinateToIndex(const glm::vec2 coordinate);
    Cell& getCell(int i,int j);
    Cell& getCell(float x, float y);
    Cell& getCell(const glm::vec2& position);
    void draw(sf::RenderWindow& renderWindow);
    float getWidth();
    float getHeight();
    int getImax();
    int getJmax();
private:
    int _iMax = -1;
    int _jMax = -1;

    float _cellWidth=1.0f;
    float _cellHeight=1.0f;
    std::vector<std::vector<Cell>> _data;
};
