#ifndef RANDOMFNORMAL_HPP
#define RANDOMFNORMAL_HPP

#include "IRandom.hpp"
#include <random>

class RandomFNormal : public IRandom<float> {
public:
    RandomFNormal();

public:
    float getRandom() override;

private:
    std::uniform_real_distribution<float> m_Distribution;
};

#endif //RANDOMFNORMAL_HPP
