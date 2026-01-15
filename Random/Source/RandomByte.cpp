#include "RandomByte.hpp"

static inline std::mt19937 randomGenerator;

RandomByte::RandomByte()
: m_Distribution(0, 255) {}

unsigned short RandomByte::getRandom() {
    return m_Distribution(randomGenerator);
}
