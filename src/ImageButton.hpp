#pragma once

#include <functional>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

class ImageButton : public sf::Drawable
{
public:
    void setPosition(sf::Vector2f position);
    void setIcon(const sf::Texture& texture);

    void handleInput(const sf::Event& event);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void onClick(const std::function<void()>& fn) { m_ClickHandler = fn; }

private:
    sf::Sprite m_Sprite;
    std::function<void()> m_ClickHandler;
};
