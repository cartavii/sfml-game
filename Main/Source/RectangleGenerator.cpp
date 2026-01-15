#include "RectangleGenerator.hpp"

RectangleGenerator::RectangleGenerator(
    std::shared_ptr<IRandom<float>> positionGenerator,
    std::shared_ptr<IRandom<unsigned short>> colorGenerator)
: m_PositionGenerator(positionGenerator)
, m_ColorGenerator(colorGenerator) {}

RectangleData RectangleGenerator::generate() const {
    RectangleData data;
    data.position.x = m_PositionGenerator->getRandom();
    data.position.y = m_PositionGenerator->getRandom();
    data.color.r = m_ColorGenerator->getRandom();
    data.color.g = m_ColorGenerator->getRandom();
    data.color.b = m_ColorGenerator->getRandom();
    return data;
}
