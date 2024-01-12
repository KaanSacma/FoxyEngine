#include "../include/system.hpp"

int main(void)
{
    Window window = Window("FoxyEngine", 3024, 1964, 60);

    while(window._isRunning) {
        while (window.getRender().pollEvent(window._event)) {
            if (window._event.type == sf::Event::Closed)
                window._isRunning = false;
        }
        window._deltaTime = 1.0f / window._frameRate;
        window.getRender().clear(sf::Color::Black);
        // window.getRender().draw();
        window.getRender().display();
    }
    return 0;
}
