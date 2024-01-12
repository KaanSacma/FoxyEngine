#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum TypePanel {
    ObjectPanel,
    ScenePanel,
    InspectorPanel,
    ConsolePanel,
    AssetPanel
};

class ViewPanel
{
public:
    ViewPanel(TypePanel panel, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor);
    ~ViewPanel();

    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Event event);
    void setFocus(bool focus);
    bool getFocus();
    void setFocusOnPanel(sf::RenderWindow &window);
    void setFocusOnPanel(sf::RenderWindow &window, sf::Event event);
    void setFocusOnPanel(sf::RenderWindow &window, sf::Vector2i mousePosition);
    void setFocusOnPanel(sf::RenderWindow &window, sf::Vector2i mousePosition, sf::Event event);

    sf::RectangleShape _panel;
    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Color _backgroundColor;
    bool _focus;
    TypePanel _typePanel;
};
