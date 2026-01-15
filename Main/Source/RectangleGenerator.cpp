#include "RectangleGenerator.hpp"
#include "Components.hpp"

RectangleGenerator::RectangleGenerator(
    std::shared_ptr<IRandom<float>> positionGenerator,
    std::shared_ptr<IRandom<float>> angleGenerator,
    std::shared_ptr<IRandom<float>> rotationGenerator,
    std::shared_ptr<IRandom<float>> sizeGenerator,
    std::shared_ptr<IRandom<unsigned short>> colorGenerator)
: m_PositionGenerator(positionGenerator)
, m_AngleGenerator(angleGenerator)
, m_RotationGenerator(rotationGenerator)
, m_SizeGenerator(sizeGenerator)
, m_ColorGenerator(colorGenerator) {}

void RectangleGenerator::generate(entt::registry& registry) const {
    Position position;
    Origin origin;
    Angle angle;
    Color color;
    RectangleProperties properties;
    position.x = m_PositionGenerator->getRandom();
    position.y = m_PositionGenerator->getRandom();
    angle.degrees = m_AngleGenerator->getRandom();
    angle.degrees = m_RotationGenerator->getRandom();
    color.r = m_ColorGenerator->getRandom();
    color.g = m_ColorGenerator->getRandom();
    color.b = m_ColorGenerator->getRandom();
    color.a = 255;
    properties.width = m_SizeGenerator->getRandom();
    properties.height = m_SizeGenerator->getRandom();
    origin.offsetX = properties.width / 2.f;
    origin.offsetY = properties.height / 2.f;
    auto entity = registry.create();
    registry.emplace<Position>(entity, position);
    registry.emplace<Origin>(entity, origin);
    registry.emplace<Angle>(entity, angle);
    registry.emplace<Color>(entity, color);
    registry.emplace<RectangleProperties>(entity, properties);
}
