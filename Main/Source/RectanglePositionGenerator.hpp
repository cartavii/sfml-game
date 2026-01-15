#ifndef RECTANGLEPOSITIONGENERATOR_HPP
#define RECTANGLEPOSITIONGENERATOR_HPP

#include "RandomFNormal.hpp"

class RectanglePositionGenerator : public RandomFNormal {
public:
    float getRandom() override;
};

#endif //RECTANGLEPOSITIONGENERATOR_HPP
