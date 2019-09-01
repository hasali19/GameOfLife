#pragma once

#include <SFML/Graphics.hpp>

#include "Grid.hpp"

class Game
{
public:
    Game(const std::string& title, unsigned int width, unsigned int height);
    ~Game();

    void Run();

private:
    sf::RenderWindow m_Window;
    Grid m_Grid;
};
