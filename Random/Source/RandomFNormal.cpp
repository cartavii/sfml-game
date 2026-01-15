#include "RandomFNormal.hpp"

static inline std::mt19937 randomGenerator;

RandomFNormal::RandomFNormal()
: m_Distribution(0.f, 1.f) {}

float RandomFNormal::getRandom() {
    return m_Distribution(randomGenerator);
}
