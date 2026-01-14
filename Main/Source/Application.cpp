#include "Application.hpp"
#include <SFML/Window/Event.hpp>

Application::Application()
: m_Window(sf::VideoMode(sf::Vector2u(800, 600)), "Prac1")
, m_Backend(m_Window)
, m_GUIPanel(m_RectanglesManager) {
    m_Window.setFramerateLimit(60);
}

int Application::run() {
    while (m_Window.isOpen()) {
        processEvents();
    }
    return 0;
}

void Application::processEvents() {
    while (const auto event = m_Window.pollEvent()) {
        m_Backend.processEvent(*event);
        if (event->is<sf::Event::Closed>()) {
            m_Window.close();
        }
    }
    m_Backend.update();
    render();
}

void Application::render() {
    m_GUIPanel.show();
    m_Window.clear();
    m_RectanglesManager.render(m_Window);
    m_Backend.render();
    m_Window.display();
}
