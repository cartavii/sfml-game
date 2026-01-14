#include "RectangleGenerator.hpp"
#include "Random.hpp"

RectangleData RectangleGenerator::generate() const {
    RectangleData data;
    data.position = { 1.f, 1.f };
    data.position.x *= Random::randomNormalFloat();
    data.position.y *= Random::randomNormalFloat();
    const sf::Vector2f viewSize(800.f, 600.f);
    data.position.x *= viewSize.x;
    data.position.y *= viewSize.y;
    data.color.r = Random::randomByte();
    data.color.g = Random::randomByte();
    data.color.b = Random::randomByte();
    return data;
}
