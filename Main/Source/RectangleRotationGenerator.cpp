#include "RectangleRotationGenerator.hpp"

float RectangleRotationGenerator::getRandom() {
    return 2.f - RandomFNormal::getRandom() * 4.f;
}
