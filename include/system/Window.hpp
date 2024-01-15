#pragma once

#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    Window(std::string title, int width, int height, int frameRate);
    ~Window();

    sf::RenderWindow &getRender();

    sf::Event _event;
    float _deltaTime;
    int _frameRate;
    bool _isRunning;
private:
    sf::RenderWindow _screenRender;
};
