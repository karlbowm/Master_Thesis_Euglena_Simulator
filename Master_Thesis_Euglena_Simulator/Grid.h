#pragma once
#include "Cell.h"
#include "EuglenaAgent.h"
#include <vector>

/*Two dimensional area of cells, holds additional information about cell size (cell sizes are uniform)*/
class Grid
{
public:

    Grid(int i, int j);
    Grid(int i, int j, float cWidth, float cHeight);
    ~Grid();
    glm::ivec2 convertCoordinateToIndex(const glm::vec2 coordinate) const;
    Cell& getCell(int i, int j), & getCell(float x, float y), & getCell(const glm::vec2& position), & getCell(const glm::ivec2& position), & getCell(const EuglenaAgent& agent);
    void draw(sf::RenderWindow& renderWindow)const;
    float getWidth() const;
    float getHeight() const;
    int getImax() const;
    int getJmax() const;
    glm::vec2 getSimulationArea() const;
    bool isOutside(const glm::vec2& position)const, isOutside(const glm::ivec2& position)const;
private:
    int _iMax = -1;
    int _jMax = -1;
    
    float _cellWidth = 1.0f;
    float _cellHeight = 1.0f;
    std::vector<std::vector<Cell>> _data;
};
