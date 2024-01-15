#include "../include/system.hpp"

int main(void)
{
    Window window = Window("FoxyEngine", 3024, 1964, 60);
    ViewPanel objectPanel = ViewPanel(ObjectPanel, sf::Vector2f(0, 0), sf::Vector2f(604, 1964), sf::Color(140,146,172), SizeLimit({sf::Vector2f(604, 0), sf::Vector2f(604, 1964)}));
    ViewPanel propertiesPanel = ViewPanel(InspectorPanel, sf::Vector2f(3024 - 604, 0), sf::Vector2f(604, 1964), sf::Color(140,146,172), SizeLimit({sf::Vector2f(3024 - 604, 0), sf::Vector2f(3024, 1964)}));

    while(window._isRunning) {
        while (window.getRender().pollEvent(window._event)) {
            if (window._event.type == sf::Event::Closed)
                window._isRunning = false;
        }
        window._deltaTime = 1.0f / window._frameRate;
        window.getRender().clear(sf::Color::Black);
        objectPanel.update(window.getRender());
        objectPanel.draw(window.getRender());
        propertiesPanel.update(window.getRender());
        propertiesPanel.draw(window.getRender());
        window.getRender().display();
    }
    return 0;
}
