#ifndef RECTANGLEANGLEGENERATOR_HPP
#define RECTANGLEANGLEGENERATOR_HPP

#include "RandomFNormal.hpp"

class RectangleAngleGenerator : public RandomFNormal {
public:
    float getRandom() override;
};

#endif //RECTANGLEANGLEGENERATOR_HPP
