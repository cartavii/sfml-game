#include "Random.hpp"
#include <random>

static inline std::mt19937 randomGenerator;
static inline std::uniform_real_distribution<float> normalFDistribution;
static inline std::uniform_int_distribution<unsigned short> byteDistribution;

float Random::randomNormalFloat() {
    return normalFDistribution(randomGenerator);
}

unsigned short Random::randomByte() {
    return byteDistribution(randomGenerator);
}
