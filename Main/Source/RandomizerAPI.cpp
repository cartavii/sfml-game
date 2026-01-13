#include "RandomizerAPI.hpp"
#include <random>

std::random_device randomDevice;
std::mt19937 randomGenerator;
std::uniform_real_distribution<float> normalFDistribution;
std::uniform_int_distribution<unsigned short> byteDistribution;

RandomizerAPI::RandomizerAPI() {
    randomGenerator = std::mt19937(randomDevice());
    normalFDistribution = std::uniform_real_distribution<float>(0, 1);
    byteDistribution = std::uniform_int_distribution<unsigned short>(0, 255);
}

RandomizerAPI::~RandomizerAPI() {
    randomGenerator.seed(0);
}

float RandomizerAPI::randomNormalFloat() {
    return normalFDistribution(randomGenerator);
}

unsigned short RandomizerAPI::randomByte() {
    return byteDistribution(randomGenerator);
}
