#include "RectanglesManager.hpp"
#include "JSONManager.hpp"
#include "Random.hpp"

#include "nlohmann/json.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void RectanglesManager::generate(const sf::View& view) {
    sf::Vector2f position = { 1.f, 1.f };
    position.x *= Random::randomNormalFloat();
    position.y *= Random::randomNormalFloat();
    const sf::Vector2f viewSize = view.getSize();
    const sf::Vector2f viewTolLeft = view.getCenter() - viewSize / 2.f;
    position.x *= viewSize.x;
    position.y *= viewSize.y;
    position += viewTolLeft;
    sf::Color color;
    color.r = Random::randomByte();
    color.g = Random::randomByte();
    color.b = Random::randomByte();
    sf::RectangleShape rectangle;
    rectangle.setSize({ 50.f, 50.f });
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    m_Rectangles.push_back(rectangle);
}

void RectanglesManager::clearAll() {
    m_Rectangles.clear();
}

void RectanglesManager::save() {
    nlohmann::json fileData = nlohmann::json::array();
    for (const auto& rectangle : m_Rectangles) {
        nlohmann::json rectJson;
        auto pos = rectangle.getPosition();
        auto color = rectangle.getFillColor();
        rectJson["position"] = { {"x", pos.x}, {"y", pos.y} };
        rectJson["color"] = { {"r", color.r}, {"g", color.g}, {"b", color.b} };
        fileData.push_back(rectJson);
    }
    JSONManager::save(fileData, "Rectangles.json");
}

void RectanglesManager::loadLast() {
    clearAll();
    const nlohmann::json fileData = JSONManager::load("Rectangles.json");
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
}

void RectanglesManager::render(sf::RenderTarget& target) {
    for (const auto& rectangle : m_Rectangles) {
        target.draw(rectangle);
    }
}
