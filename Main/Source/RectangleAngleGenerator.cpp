#include "RectangleAngleGenerator.hpp"

float RectangleAngleGenerator::getRandom() {
    return RandomFNormal::getRandom() * 360.f;
}
