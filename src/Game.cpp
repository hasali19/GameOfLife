#include "Game.hpp"

Game::Game(const std::string& title, unsigned int width, unsigned int height)
    : m_Window(sf::VideoMode(width, height), title),
      m_Grid(height / 16, width / 16, sf::Vector2f(16, 16))
{
}

Game::~Game()
{
}

void Game::Run()
{
    m_Grid.randomise();

    while (m_Window.isOpen())
    {
        sf::Event event;

        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_Window.close();
            }
        }

        m_Window.clear(sf::Color::Black);
        m_Window.draw(m_Grid);
        m_Window.display();

        m_Grid = m_Grid.next();
    }
}
