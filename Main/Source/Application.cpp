#include "Application.hpp"
#include <SFML/Window/Event.hpp>
#include "Systems.hpp"

Application::Application()
: m_Window(sf::Vector2u(800, 800), "Prac7")
, m_RectanglesManager(m_GUIPanel.getGenerateEvent(),
                      m_GUIPanel.getClearEvent(),
                      m_GUIPanel.getSaveEvent(),
                      m_GUIPanel.getLoadEvent()) {}


int Application::run() {
    while (m_Window.isOpen()) {
        m_Window.processEvents();
        update();
        gui();
        render();
    }
    return 0;
}

void Application::update() {
    m_RectanglesManager.update(m_DeltaClock.restart().asSeconds() * 60.f);
}

void Application::gui() {
    m_GUIPanel.show();
}

void Application::render() {
    m_Window.renderStart();
    m_RectanglesManager.render(m_Window.getWindow());
    m_Window.renderEnd();
}
