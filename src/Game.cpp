#include "Game.hpp"

#include <SFML/Graphics.hpp>

Game::Game(const std::string& title, unsigned int width, unsigned int height)
    : m_Window(sf::VideoMode(width, height), title),
      m_Grid(height / 16, width / 16, sf::Vector2f(16, 16))
{
}

Game::~Game()
{
}

void Game::run()
{
    sf::Clock clock;

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
        draw(m_Window);
        m_Window.display();

        sf::Time delta = clock.getElapsedTime();
        clock.restart();
        update(delta);
    }
}

void Game::update(sf::Time delta)
{
    static sf::Time elapsed;

    elapsed += delta;

    if (elapsed.asMilliseconds() >= 200)
    {
        elapsed = sf::Time::Zero;
        m_Grid = m_Grid.next();
    }
}

void Game::draw(sf::RenderTarget& target) const
{
    target.draw(m_Grid);
}
