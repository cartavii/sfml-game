#ifndef RANDOMBYTE_HPP
#define RANDOMBYTE_HPP

#include "IRandom.hpp"
#include <random>

class RandomByte : public IRandom<unsigned short> {
public:
    RandomByte();

public:
    unsigned short getRandom() override;

private:
    std::uniform_int_distribution<unsigned short> m_Distribution;
};

#endif //RANDOMBYTE_HPP
