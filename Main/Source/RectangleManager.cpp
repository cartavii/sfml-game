#include "RectangleManager.hpp"
#include "JSONManager.hpp"

void RectangleManager::generate() {
    m_Rectangles.addRectangle(m_Generator.generate());
}

void RectangleManager::clear() {
    m_Rectangles.clear();
}

void RectangleManager::save() {
    nlohmann::json fileData = nlohmann::json::array();
    for (const auto& rectangle : m_Rectangles) {
        nlohmann::json rectJson;
        auto pos = rectangle.position;
        auto color = rectangle.color;
        rectJson["position"] = { {"x", pos.x}, {"y", pos.y} };
        rectJson["color"] = { {"r", color.r}, {"g", color.g}, {"b", color.b} };
        fileData.push_back(rectJson);
    }
    JSONManager::save(fileData, "Rectangles.json");
}

void RectangleManager::loadLast() {
    m_Rectangles.clear();
    const nlohmann::json fileData = JSONManager::load("Rectangles.json");
    for (const auto& rectJson : fileData) {
        if (!rectJson.contains("position") || !rectJson.contains("color")) continue;
        const auto& pos = rectJson["position"];
        const auto& color = rectJson["color"];
        if (!pos.contains("x") || !pos.contains("y")) continue;
        if (!color.contains("r") || !color.contains("g") || !color.contains("b")) continue;
        RectangleData rectangle;
        rectangle.position = sf::Vector2f(pos["x"].get<float>(), pos["y"].get<float>());
        rectangle.color = sf::Color(
            static_cast<unsigned int>(color["r"].get<int>()),
            static_cast<unsigned int>(color["g"].get<int>()),
            static_cast<unsigned int>(color["b"].get<int>())
        );
        m_Rectangles.addRectangle(rectangle);
    }
}

void RectangleManager::render(sf::RenderTarget& target) {
    m_Renderer.render(target, m_Rectangles);
}
