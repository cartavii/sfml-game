#include "Application.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include <fstream>

Application::Application()
: m_Window(sf::VideoMode(sf::Vector2u(800, 600)), "Prac1")
, m_RandomGenerator(m_RandomDevice())
, m_NormalFDistribution(0.0f, 1.0f)
, m_UIntDistribution(0, 255) {
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
    if (ImGui::Begin("Panel")) {
        ImGui::SeparatorText("Rectangle");
        if (ImGui::Button("Spawn rectangle")) {
            spawnRectangle();
        }
        if (ImGui::Button("Clear rectangles")) {
            clearRectangles();
        }
        ImGui::SeparatorText("File");
        if (ImGui::Button("Save")) {
            saveRectangles();
        }
        if (ImGui::Button("Load last")) {
            loadRectangles();
        }
    }
    ImGui::End();
}

void Application::renderRectangles() {
    for (const auto& rectangle : m_Rectangles) {
        m_Window.draw(rectangle);
    }
}

void Application::render() {
    guiRender();
    m_Window.clear();
    renderRectangles();
    ImGui::SFML::Render(m_Window);
    m_Window.display();
}

void Application::spawnRectangle() {
    const sf::View& view = m_Window.getView();
    sf::Vector2f position = { 1.f, 1.f };
    position.x *= m_NormalFDistribution(m_RandomGenerator);
    position.y *= m_NormalFDistribution(m_RandomGenerator);
    const sf::Vector2f viewSize = view.getSize();
    const sf::Vector2f viewTolLeft = view.getCenter() - viewSize / 2.f;
    position.x *= viewSize.x;
    position.y *= viewSize.y;
    position += viewTolLeft;
    sf::Color color;
    color.r = m_UIntDistribution(m_RandomGenerator);
    color.g = m_UIntDistribution(m_RandomGenerator);
    color.b = m_UIntDistribution(m_RandomGenerator);
    sf::RectangleShape rectangle;
    rectangle.setSize({ 50.f, 50.f });
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    m_Rectangles.push_back(rectangle);
}

void Application::clearRectangles() {
    m_Rectangles.clear();
}

void Application::saveRectangles() {
    std::ofstream file;
    file.open("rectangles.dat", std::ios::binary |  std::ios::trunc);
}

void Application::loadRectangles() {

}
