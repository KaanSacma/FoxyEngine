#include "../../include/system/ViewPanel.hpp"

#include <iostream>

ViewPanel::ViewPanel(TypePanel panel, PanelPosition panel_position, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor, SizeLimit sizeLimit) :
_typePanel(panel),
_panelPosition(panel_position),
_position({position.x + 1, position.y + 1}),
_size({size.x - 1, size.y - 1}),
_backgroundColor(backgroundColor),
_focus(false),
_sizeLimit(sizeLimit),
_isResizing(false),
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
    if (event.type == sf::Event::MouseMoved) {
        setFocusOnPanel(window);
        if (_isResizing) {
            switch (_panelPosition) {
                case Left:
                    if (event.mouseMove.x > _position.x + _sizeLimit._min.x &&
                        event.mouseMove.x < _position.x + _sizeLimit._max.x) {
                        _size.x = event.mouseMove.x - _position.x;
                        _panel.setSize(_size);
                    }
                    break;
                case Right:
                    if (event.mouseMove.x < 3024 - _sizeLimit._min.x &&
                        event.mouseMove.x > 3024 - _sizeLimit._max.x) {
                        _size.x = _position.x + _size.x - event.mouseMove.x;
                        _position.x = event.mouseMove.x;
                        _panel.setPosition(_position);
                        _panel.setSize(_size);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        switch (_panelPosition) {
            case Left:
                if (event.mouseButton.button == sf::Mouse::Left &&
                    event.mouseButton.x >= _position.x + (_size.x - 50) &&
                    event.mouseButton.x <= _position.x + (_size.x + 50)) {
                    _isResizing = true;
                } else {
                    _isResizing = false;
                }
                break;
            case Right:
                if (event.mouseButton.button == sf::Mouse::Left &&
                    event.mouseButton.x <= _position.x + 50 &&
                    event.mouseButton.x >= _position.x - 50) {
                    _isResizing = true;
                } else {
                    _isResizing = false;
                }
                break;
            default:
                break;
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        _isResizing = false;
    }
}

void ViewPanel::setFocusOnPanel(sf::RenderWindow &window)
{
    if (sf::Mouse::getPosition(window).x >= _position.x &&
        sf::Mouse::getPosition(window).x <= _position.x + _size.x &&
        sf::Mouse::getPosition(window).y >= _position.y &&
        sf::Mouse::getPosition(window).y <= _position.y + _size.y) {
        _focus = true;
        _panel.setOutlineThickness(1);
    } else {
        _focus = false;
        _panel.setOutlineThickness(0);
    }
}
