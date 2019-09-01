#include "Grid.hpp"

#include <functional>
#include <random>

#include <SFML/Graphics.hpp>

Grid::Grid(unsigned int rows, unsigned int cols, sf::Vector2f cellSize)
    : m_Rows(rows), m_Cols(cols), m_CellSize(cellSize), m_Cells(rows * cols)
{
}

void Grid::randomise()
{
    auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());

    for (unsigned int i = 0; i < m_Rows; i++)
    {
        for (unsigned int j = 0; j < m_Cols; j++)
        {
            m_Cells[i * m_Cols + j] = !gen();
        }
    }
}

Grid Grid::next() const
{
    Grid next(m_Rows, m_Cols, m_CellSize);

    for (unsigned int i = 0; i < m_Rows; i++)
    {
        for (unsigned int j = 0; j < m_Cols; j++)
        {
            bool alive = getCell(i, j);
            int livingNeighbours = getLivingNeighbours(i, j);

            if (alive)
            {
                // Lives on iff it has exactly 2 or 3 living neighbours
                alive = !(livingNeighbours < 2 || livingNeighbours > 3);
            }
            else
            {
                // Comes to life iff it has exactly 3 living neighbours
                alive = livingNeighbours == 3;
            }

            next.setCell(i, j, alive);
        }
    }

    return next;
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape shape(m_CellSize);
    shape.setFillColor(sf::Color::White);

    for (unsigned int i = 0; i < m_Rows; i++)
    {
        for (unsigned int j = 0; j < m_Cols; j++)
        {
            if (!getCell(i, j))
            {
                continue;
            }

            sf::Vector2f position = sf::Vector2f(
                (float)j * m_CellSize.x,
                (float)i * m_CellSize.y);

            shape.setPosition(position);
            target.draw(shape, states);
        }
    }
}

int Grid::getCellIndex(int row, int col) const
{
    if (row < 0) row = m_Rows - row;
    if (col < 0) col = m_Cols - col;
    if (row >= m_Rows) row = row - m_Rows;
    if (col >= m_Cols) col = col - m_Cols;
    return row * m_Cols + col;
}

bool Grid::getCell(int row, int col) const
{
    return m_Cells[getCellIndex(row, col)];
}

void Grid::setCell(int row, int col, bool isAlive)
{
    m_Cells[getCellIndex(row, col)] = isAlive;
}

int Grid::getLivingNeighbours(int row, int col) const
{
    int count = 0;

    for (unsigned int r = row - 1; r <= row + 1; r++)
    {
        for (unsigned int c = col - 1; c <= col + 1; c++)
        {
            if (r == row && c == col) continue;
            if (getCell(r, c)) count += 1;
        }
    }

    return count;
}
