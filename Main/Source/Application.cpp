#include "Application.hpp"

#include "imgui.h"
#include "imgui-SFML.h"
#include "nlohmann/json.hpp"

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
    nlohmann::json fileData = nlohmann::json::array();
    for (const auto& rectangle : m_Rectangles) {
        nlohmann::json rectJson;
        auto pos = rectangle.getPosition();
        auto color = rectangle.getFillColor();
        rectJson["position"] = { {"x", pos.x}, {"y", pos.y} };
        rectJson["color"] = { {"r", color.r}, {"g", color.g}, {"b", color.b} };
        fileData.push_back(rectJson);
    }
    std::ofstream file("Rectangles.json");
    if (file.is_open()) {
        file << fileData.dump(4);
        file.close();
    }
}

void Application::loadRectangles() {
    clearRectangles();
    std::ifstream file("Rectangles.json");
    if (!file.is_open()) return;
    nlohmann::json fileData;
    try {
        file >> fileData;
        for (const auto& rectJson : fileData) {
            if (!rectJson.contains("position") || !rectJson.contains("color")) continue;
            const auto& pos = rectJson["position"];
            const auto& color = rectJson["color"];
            if (!pos.contains("x") || !pos.contains("y")) continue;
            if (!color.contains("r") || !color.contains("g") || !color.contains("b")) continue;
            sf::RectangleShape rectangle;
            rectangle.setSize({50.f, 50.f});
            rectangle.setPosition(sf::Vector2f(pos["x"].get<float>(), pos["y"].get<float>()));
            rectangle.setFillColor(sf::Color(
                static_cast<unsigned int>(color["r"].get<int>()),
                static_cast<unsigned int>(color["g"].get<int>()),
                static_cast<unsigned int>(color["b"].get<int>())
            ));
            m_Rectangles.push_back(rectangle);
        }
    } catch (const std::exception&) {}
}
