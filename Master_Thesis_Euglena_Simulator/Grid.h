#pragma once
#include "Cell.h"
#include "EuglenaAgent.h"
#include <glm/glm.hpp>
#include <vector>


class Grid
{
public:

    Grid(int i, int j);
    Grid(int i, int j, float cWidth, float cHeight);
    ~Grid();
    glm::ivec2 convertCoordinateToIndex(const glm::vec2 coordinate) const;
    Cell& getCell(int i, int j);
    Cell& getCell(float x, float y);
    Cell& getCell(const glm::vec2& position);
    Cell& getCell(const EuglenaAgent& agent);
    void draw(sf::RenderWindow& renderWindow)const;
    float getWidth() const;
    float getHeight() const;
    int getImax() const;
    int getJmax() const;
    glm::vec2 getSimulationArea() const;
    bool isOutside(const glm::vec2& position)const ;
private:
    int _iMax = -1;
    int _jMax = -1;
    
    float _cellWidth = 1.0f;
    float _cellHeight = 1.0f;
    std::vector<std::vector<Cell>> _data;
};
