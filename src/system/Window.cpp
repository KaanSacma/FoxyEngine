#include "../../include/system/Window.hpp"

Window::Window()
{
    _render.create(sf::VideoMode(3024, 1964), "FoxyEngine", sf::Style::Default);
    _render.setFramerateLimit(60);
    _frameRate = 60;
    _deltaTime = 0;
    _isRunning = true;
}

Window::Window(std::string title, int width, int height, int frameRate)
{
    _render.create(sf::VideoMode(width, height), title, sf::Style::Default);
    _render.setFramerateLimit(frameRate);
    _frameRate = frameRate;
    _deltaTime = 0;
    _isRunning = true;
}

Window::~Window()
{
    _render.close();
}

sf::RenderWindow &Window::getRender()
{
    return _render;
}
