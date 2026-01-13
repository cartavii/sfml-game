#include "Application.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

Application::Application()
: m_Window(sf::VideoMode(sf::Vector2u(800, 600)), "Prac1") {
    m_Window.setFramerateLimit(60);
}

Application::~Application() {
    ImGui::SFML::Shutdown();
}

int Application::run() {
    if (!ImGui::SFML::Init(m_Window)) {
        return -1;
    }
    while (m_Window.isOpen()) {
        processEvents();
    }
    return 0;
}

void Application::processEvents() {
    while (const auto event = m_Window.pollEvent()) {
        ImGui::SFML::ProcessEvent(m_Window, *event);
        if (event->is<sf::Event::Closed>()) {
            m_Window.close();
        }
    }
    ImGui::SFML::Update(m_Window, m_Clock.restart());
    render();
}

void Application::guiRender() {
    ImGui::ShowDemoWindow();
}

void Application::render() {
    guiRender();
    m_Window.clear();
    ImGui::SFML::Render(m_Window);
    m_Window.display();
}
