#include "../../include/system/ViewPanel.hpp"

ViewPanel::ViewPanel(TypePanel panel, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor) :
_typePanel(panel), _position(position), _size(size), _backgroundColor(backgroundColor)
{
    _focus = false;
    _panel = sf::RectangleShape(_size);
    _panel.setPosition(_position);
    _panel.setFillColor(_backgroundColor);
}

ViewPanel::~ViewPanel()
{
}

void ViewPanel::draw(sf::RenderWindow &window)
{
    window.draw(_panel);
}

void ViewPanel::update(sf::RenderWindow &window)
{
    if (_focus)
        setFocusOnPanel(window);
}

void ViewPanel::handleEvent(sf::RenderWindow &window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        setFocusOnPanel(window, event);
    if (event.type == sf::Event::MouseMoved)
        setFocusOnPanel(window, sf::Mouse::getPosition(window), event);
}

void ViewPanel::setFocus(bool focus)
{
    _focus = focus;
}

bool ViewPanel::getFocus()
{
    return _focus;
}

void ViewPanel::setFocusOnPanel(sf::RenderWindow &window)
{
    if (sf::Mouse::getPosition(window).x >= _position.x && sf::Mouse::getPosition(window).x <= _position.x + _size.x &&
        sf::Mouse::getPosition(window).y >= _position.y && sf::Mouse::getPosition(window).y <= _position.y + _size.y)
        _focus = true;
    else
        _focus = false;
}

void ViewPanel::setFocusOnPanel(sf::RenderWindow &window, sf::Event event)
{
    if (event.mouseButton.x >= _position.x && event.mouseButton.x <= _position.x + _size.x &&
        event.mouseButton.y >= _position.y && event.mouseButton.y <= _position.y + _size.y)
        _focus = true;
    else
        _focus = false;
}

void ViewPanel::setFocusOnPanel(sf::RenderWindow &window, sf::Vector2i mousePosition)
{
    if (mousePosition.x >= _position.x && mousePosition.x <= _position.x + _size.x &&
        mousePosition.y >= _position.y && mousePosition.y <= _position.y + _size.y)
        _focus = true;
    else
        _focus = false;
}

void ViewPanel::setFocusOnPanel(sf::RenderWindow &window, sf::Vector2i mousePosition, sf::Event event)
{
    if (mousePosition.x >= _position.x && mousePosition.x <= _position.x + _size.x &&
        mousePosition.y >= _position.y && mousePosition.y <= _position.y + _size.y)
        _focus = true;
    else
        _focus = false;
}
