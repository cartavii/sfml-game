#include "RandomAPI.hpp"
#include <random>

static inline std::random_device randomDevice;
static inline std::mt19937 randomGenerator;
static inline std::uniform_real_distribution<float> normalFDistribution;
static inline std::uniform_int_distribution<unsigned short> byteDistribution;

RandomAPI::RandomAPI() {
    randomGenerator = std::mt19937(randomDevice());
    normalFDistribution = std::uniform_real_distribution<float>(0, 1);
    byteDistribution = std::uniform_int_distribution<unsigned short>(0, 255);
}

RandomAPI::~RandomAPI() {
    randomGenerator.seed(0);
}