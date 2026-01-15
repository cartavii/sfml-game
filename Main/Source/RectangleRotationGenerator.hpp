#ifndef RECTANGLEROTATIONGENERATOR_HPP
#define RECTANGLEROTATIONGENERATOR_HPP

#include "RandomFNormal.hpp"

class RectangleRotationGenerator : public RandomFNormal {
public:
    float getRandom() override;
};

#endif //RECTANGLEROTATIONGENERATOR_HPP
