#include "WindowManager.hpp"

#include <SFML/Window/Event.hpp>

WindowManager::WindowManager(const sf::Vector2u& size, const sf::String& title)
: m_Window(sf::VideoMode(size), title)
, m_ImGuiBackend(m_Window) {
    m_Window.setFramerateLimit(60);
}

sf::RenderWindow& WindowManager::getWindow() { return m_Window; }

const sf::RenderWindow& WindowManager::getWindow() const { return m_Window; }

bool WindowManager::isOpen() const {
    return m_Window.isOpen();
}

void WindowManager::processEvents() {
    while (const auto event = m_Window.pollEvent()) {
        m_ImGuiBackend.processEvent(*event);
        if (event->is<sf::Event::Closed>()) {
            m_Window.close();
        }
    }
    m_ImGuiBackend.update();
}

void WindowManager::renderStart(const sf::Color& clearColor) {
    m_Window.clear(clearColor);
}

void WindowManager::render(const sf::Drawable& drawable) {
    m_Window.draw(drawable);
}

void WindowManager::renderEnd() {
    m_ImGuiBackend.render();
    m_Window.display();
}

