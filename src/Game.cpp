#include "Game.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

constexpr unsigned int MENU_HEIGHT = 64;

Game::Game(const std::string& title, unsigned int width, unsigned int height)
    : m_Window(sf::VideoMode(width, height), title),
      m_Grid((height - MENU_HEIGHT) / 16, width / 16, sf::Vector2f(16, 16)),
      m_MenuRect({ (float)width, MENU_HEIGHT })
{
    m_MenuRect.setPosition({ 0, (float)height - MENU_HEIGHT });
    m_MenuRect.setFillColor(sf::Color(200, 200, 200));

    m_PlayIcon.loadFromFile("assets/play.png");

    m_PlayButton.setIcon(m_PlayIcon);
    m_PlayButton.setPosition({ (float)width / 2 - 16, (float)height - MENU_HEIGHT + 16 });
    m_PlayButton.onClick([this]()
        {
            m_State = Game::State::Running;
        });
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
            else
            {
                m_PlayButton.handleInput(event);
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

    if (m_State == Game::State::Running)
    {
        elapsed += delta;

        if (elapsed.asMilliseconds() >= 200)
        {
            elapsed = sf::Time::Zero;
            m_Grid = m_Grid.next();
        }
    }
}

void Game::draw(sf::RenderTarget& target) const
{
    target.draw(m_Grid);
    target.draw(m_MenuRect);
    target.draw(m_PlayButton);
}
