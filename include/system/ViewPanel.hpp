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

struct SizeLimit {
    sf::Vector2f _min;
    sf::Vector2f _max;
};

class ViewPanel
{
public:
    ViewPanel(TypePanel panel, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor, SizeLimit sizeLimit);
    ~ViewPanel();

    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Event event);

    void setFocusOnPanel(sf::RenderWindow &window);

    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Color _backgroundColor;
    bool _focus;
    SizeLimit _sizeLimit;
    TypePanel _typePanel;

private:
    sf::RectangleShape _panel;
};
