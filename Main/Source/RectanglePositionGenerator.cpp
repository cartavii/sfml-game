#include "RectanglePositionGenerator.hpp"

float RectanglePositionGenerator::getRandom() {
    return RandomFNormal::getRandom() * 800.f;
}
