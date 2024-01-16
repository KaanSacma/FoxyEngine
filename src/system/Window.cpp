#include "../../include/system/Window.hpp"

Window::Window(std::string title, int width, int height, int frameRate) :
_screenRender(sf::VideoMode(width, height), title, sf::Style::Default),
_frameRate(frameRate),
_deltaTime(0),
_isRunning(true)
{
    _screenRender.setFramerateLimit(frameRate);
}

Window::~Window()
{
    _screenRender.close();
}

sf::RenderWindow &Window::getRender()
{
    return _screenRender;
}
