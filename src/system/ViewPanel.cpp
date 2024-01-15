#include "../../include/system/ViewPanel.hpp"

ViewPanel::ViewPanel(TypePanel panel, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor, SizeLimit sizeLimit) :
_typePanel(panel),
_position(position),
_size(size),
_backgroundColor(backgroundColor),
_focus(false),
_sizeLimit(sizeLimit),
_panel(sf::RectangleShape(_size))
{
    _panel.setPosition(_position);
    _panel.setFillColor(_backgroundColor);
}

ViewPanel::~ViewPanel() {}

void ViewPanel::draw(sf::RenderWindow &window)
{
    window.draw(_panel);
}

void ViewPanel::update(sf::RenderWindow &window)
{
    setFocusOnPanel(window);
}

void ViewPanel::handleEvent(sf::RenderWindow &window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed ||
        event.type == sf::Event::MouseMoved)
        setFocusOnPanel(window);
}

void ViewPanel::setFocusOnPanel(sf::RenderWindow &window)
{
    if (sf::Mouse::getPosition(window).x >= _position.x && sf::Mouse::getPosition(window).x <= _position.x + _size.x &&
        sf::Mouse::getPosition(window).y >= _position.y && sf::Mouse::getPosition(window).y <= _position.y + _size.y) {
        _focus = true;
        _panel.setOutlineThickness(5);
    } else {
        _focus = false;
        _panel.setOutlineThickness(0);
    }
}
