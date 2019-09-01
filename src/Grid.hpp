#pragma once

#include <vector>

#include <SFML/Graphics/Drawable.hpp>

class Grid : public sf::Drawable
{
public:
    Grid(unsigned int rows, unsigned int cols, sf::Vector2f cellSize);

    void randomise();
    Grid next() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    int getCellIndex(int row, int col) const;
    bool getCell(int row, int col) const;
    void setCell(int row, int col, bool isAlive);
    int getLivingNeighbours(int row, int col) const;

private:
    unsigned int m_Rows;
    unsigned int m_Cols;
    sf::Vector2f m_CellSize;
    std::vector<bool> m_Cells;
};
