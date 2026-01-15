#include "RectangleSizeGenerator.hpp"

float RectangleSizeGenerator::getRandom() {
    return RandomFNormal::getRandom() * 30.f + 20.f;
}
