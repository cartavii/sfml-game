#include "JSONRectangleStorage.hpp"

#include "JSONManager.hpp"

void JSONRectangleStorage::save(const Rectangles& rectangles) {
    nlohmann::json fileData = nlohmann::json::array();
    for (const auto& rectangle : rectangles) {
        nlohmann::json rectJson;
        auto pos = rectangle.position;
        auto color = rectangle.color;
        rectJson["position"] = { {"x", pos.x}, {"y", pos.y} };
        rectJson["color"] = { {"r", color.r}, {"g", color.g}, {"b", color.b} };
        fileData.push_back(rectJson);
    }
    JSONManager::save(fileData, "Rectangles.json");
}

void JSONRectangleStorage::load(Rectangles& rectangles) {
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
        rectangles.addRectangle(rectangle);
    }
}
