#ifndef RECTANGLEGENERATOR_HPP
#define RECTANGLEGENERATOR_HPP

#include "IRandom.hpp"

#include "entt/entt.hpp"
#include <memory>

class RectangleGenerator {
public:
    RectangleGenerator(std::shared_ptr<IRandom<float>> positionGenerator,
                       std::shared_ptr<IRandom<float>> angleGenerator,
                       std::shared_ptr<IRandom<float>> rotationGenerator,
                       std::shared_ptr<IRandom<float>> sizeGenerator,
                       std::shared_ptr<IRandom<unsigned short>> colorGenerator);

public:
    void generate(entt::registry& registry) const;

private:
    std::shared_ptr<IRandom<float>> m_PositionGenerator;
    std::shared_ptr<IRandom<float>> m_AngleGenerator;
    std::shared_ptr<IRandom<float>> m_RotationGenerator;
    std::shared_ptr<IRandom<float>> m_SizeGenerator;
    std::shared_ptr<IRandom<unsigned short>> m_ColorGenerator;
};

#endif //RECTANGLEGENERATOR_HPP
