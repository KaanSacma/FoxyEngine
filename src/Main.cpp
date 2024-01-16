#include "../include/system.hpp"

int main(void)
{
    Window window = Window("FoxyEngine", 3024, 1964, 60);
    ViewPanel objectPanel = ViewPanel(ObjectPanel, Left, sf::Vector2f(0, 0), sf::Vector2f(604, 1830), sf::Color(80, 82, 87), SizeLimit({sf::Vector2f(302, 1830), sf::Vector2f(604, 1830)}));
    ViewPanel propertiesPanel = ViewPanel(InspectorPanel, Right, sf::Vector2f(2420, 0), sf::Vector2f(604, 1830), sf::Color(80, 82, 87), SizeLimit({sf::Vector2f(302, 1830), sf::Vector2f(604, 1830)}));

    while(window._isRunning) {
        while (window.getRender().pollEvent(window._event)) {
            if (window._event.type == sf::Event::Closed)
                window._isRunning = false;
            objectPanel.handleEvent(window.getRender(), window._event);
            propertiesPanel.handleEvent(window.getRender(), window._event);
        }
        window._deltaTime = 1.0f / window._frameRate;
        window.getRender().clear(sf::Color(59, 59, 59));
        objectPanel.update(window.getRender());
        objectPanel.draw(window.getRender());
        propertiesPanel.update(window.getRender());
        propertiesPanel.draw(window.getRender());
        window.getRender().display();
    }
    return 0;
}
