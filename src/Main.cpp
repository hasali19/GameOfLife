#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game of Life");
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event e;

        while (window.pollEvent(e))
        {
            switch (e.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        float time = clock.getElapsedTime().asSeconds();

        sf::Uint8 r = (sf::Uint8)((std::sin(time) + 1) / 2 * 255);
        sf::Uint8 g = (sf::Uint8)((std::cos(time) + 1) / 2 * 255);
        sf::Uint8 b = (sf::Uint8)((std::sin(time / 2) + 1) / 2 * 255);

        sf::Color color = sf::Color(r, g, b);

        window.clear(color);
        window.display();
    }

    return 0;
}
