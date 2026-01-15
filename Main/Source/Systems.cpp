#include "Systems.hpp"
#include "Components.hpp"
#include "JSONManager.hpp"

#include <nlohmann/json.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

void MovementSystem(entt::registry& registry, const float deltaTime) {
    auto view = registry.view<Angle>();
    for (auto entity : view) {
        auto& angle = view.get<Angle>(entity);
        angle.degrees += deltaTime;
    }
}

void SaveSystem(entt::registry& registry, const std::filesystem::path& filename) {
    nlohmann::json saveData;
    auto view = registry.view<Position, Angle, Color, RectangleProperties>();
    for (auto entity : view) {
        const auto& [x, y]       = view.get<Position>(entity);
        const auto& [degrees, rotation] = view.get<Angle>(entity);
        const auto& [r, g, b, a] = view.get<Color>(entity);
        const auto& [width, height] = view.get<RectangleProperties>(entity);

        nlohmann::json rectangleData;
        rectangleData["position"]   = { {"x", x}, {"y", y} };
        rectangleData["angle"]      = { {"angle", degrees}, {"rotation", rotation} };
        rectangleData["color"]      = { {"r", r}, {"g", g}, {"b", b}, {"a", a} };
        rectangleData["size"] = { {"width", width}, {"height", height} };

        saveData.push_back(rectangleData);
    }
    JSONManager::save(saveData, filename);
}

void LoadSystem(entt::registry& registry, const std::filesystem::path& filename) {
    registry.clear();
    const nlohmann::json json = JSONManager::load(filename);
    for (const auto& rectangleData : json) {
        auto entity = registry.create();

        if (!rectangleData.contains("position") ||
            !rectangleData.contains("color") ||
            !rectangleData.contains("angle") ||
            !rectangleData.contains("size")) continue;
        const auto& positionData = rectangleData["position"];
        Position position;
        position.x = positionData["x"].get<float>();
        position.y = positionData["y"].get<float>();
        registry.emplace<Position>(entity, position);

        const auto& angleData = rectangleData["angle"];
        Angle angle;
        angle.degrees = angleData["angle"].get<float>();
        angle.rotation = angleData["rotation"].get<float>();
        registry.emplace<Angle>(entity, angle);

        const auto& colorData = rectangleData["color"];
        Color color;
        color.r = colorData["r"].get<unsigned short>();
        color.g = colorData["g"].get<unsigned short>();
        color.b = colorData["b"].get<unsigned short>();
        color.a = colorData["a"].get<unsigned short>();
        registry.emplace<Color>(entity, color);

        const auto& sizeData = rectangleData["size"];
        RectangleProperties properties;
        properties.width = sizeData["width"].get<float>();
        properties.height = sizeData["height"].get<float>();
        registry.emplace<RectangleProperties>(entity, properties);

        Origin origin;
        origin.offsetX = properties.width / 2.f;
        origin.offsetY = properties.height / 2.f;
        registry.emplace<Origin>(entity, origin);
    }
}

void RenderSystem(entt::registry& registry, sf::RenderTarget& target) {
    auto view = registry.view<Position, Origin, Angle, Color, RectangleProperties>();
    sf::RectangleShape rectangle;
    for (auto entity : view) {
        const auto& [x, y]              = view.get<Position>(entity);
        const auto& [offsetX, offsetY]  = view.get<Origin>(entity);
        const auto& [degrees, rotation] = view.get<Angle>(entity);
        const auto& [r, g, b, a]        = view.get<Color>(entity);
        const auto& [width, height]     = view.get<RectangleProperties>(entity);

        rectangle.setPosition(sf::Vector2f(x, y));
        rectangle.setOrigin(sf::Vector2f(offsetX, offsetY));
        rectangle.setRotation(sf::degrees(degrees));
        rectangle.setFillColor(sf::Color(r, g, b, a));
        rectangle.setSize(sf::Vector2f(width, height));

        target.draw(rectangle);
    }
}
