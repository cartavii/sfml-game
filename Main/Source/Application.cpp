#include "Application.hpp"
#include <SFML/Window/Event.hpp>

Application::Application()
: m_Window(sf::Vector2u(800, 800), "Prac4")
, m_GUIPanel(m_RectanglesManager.getCommands()) {}


int Application::run() {
    while (m_Window.isOpen()) {
        m_Window.processEvents();
        gui();
        render();
    }
    return 0;
}

void Application::gui() {
    m_GUIPanel.show();
}

void Application::render() {
    m_Window.renderStart();
    m_RectanglesManager.render(m_Window.getWindow());
    m_Window.renderEnd();
}
