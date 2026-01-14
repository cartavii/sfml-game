#include "Application.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

Application::Application()
: m_Window(sf::VideoMode(sf::Vector2u(800, 600)), "Prac1")
, m_Backend(m_Window) {
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

void Application::guiRender() {
    if (ImGui::Begin("Panel")) {
        ImGui::SeparatorText("Rectangle");
        if (ImGui::Button("Spawn rectangle")) {
            m_RectanglesManager.generate(m_Window.getView());
        }
        if (ImGui::Button("Clear rectangles")) {
            m_RectanglesManager.clearAll();
        }
        ImGui::SeparatorText("File");
        if (ImGui::Button("Save")) {
            m_RectanglesManager.save();
        }
        if (ImGui::Button("Load last")) {
            m_RectanglesManager.loadLast();
        }
    }
    ImGui::End();
}

void Application::render() {
    guiRender();
    m_Window.clear();
    m_RectanglesManager.render(m_Window);
    m_Backend.render();
    m_Window.display();
}
