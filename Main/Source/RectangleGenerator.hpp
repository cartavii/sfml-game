#ifndef RECTANGLEGENERATOR_HPP
#define RECTANGLEGENERATOR_HPP

#include "RectangleData.hpp"
#include "IRandom.hpp"

#include <memory>

class RectangleGenerator {
public:
    RectangleGenerator(std::shared_ptr<IRandom<float>> positionGenerator,
                       std::shared_ptr<IRandom<unsigned short>> colorGenerator);

public:
    RectangleData generate() const;

private:
    std::shared_ptr<IRandom<float>> m_PositionGenerator;
    std::shared_ptr<IRandom<unsigned short>> m_ColorGenerator;
};

#endif //RECTANGLEGENERATOR_HPP
