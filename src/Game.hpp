#pragma once

#include <string>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "Grid.hpp"

class Game
{
public:
    Game(const std::string& title, unsigned int width, unsigned int height);
    ~Game();

    void run();

private:
    void update(sf::Time delta);
    void draw(sf::RenderTarget& target) const;

private:
    sf::RenderWindow m_Window;
    Grid m_Grid;
};
