#include "RectangleManager.hpp"
#include "JSONManager.hpp"
#include "Random.hpp"

void RectangleManager::generate() {
    sf::Vector2f position = { 1.f, 1.f };
    position.x *= Random::randomNormalFloat();
    position.y *= Random::randomNormalFloat();
    const sf::Vector2f viewSize(800.f, 600.f);
    position.x *= viewSize.x;
    position.y *= viewSize.y;
    sf::Color color;
    color.r = Random::randomByte();
    color.g = Random::randomByte();
    color.b = Random::randomByte();
    m_Rectangles.addRectangle(RectangleData{ position, color });
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
    m_RectangleRenderer.render(target, m_Rectangles);
}
