#include "ImageButton.hpp"

#include <SFML/Graphics.hpp>

void ImageButton::setPosition(sf::Vector2f position)
{
    m_Sprite.setPosition(position);
}

void ImageButton::setIcon(const sf::Texture& texture)
{
    m_Sprite.setTexture(texture);
}

void ImageButton::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Button::Left
        && m_Sprite.getGlobalBounds().contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
    {
        if (m_ClickHandler) m_ClickHandler();
    }
}

void ImageButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite);
}
