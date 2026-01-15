#ifndef RECTANGLESIZEGENERATOR_HPP
#define RECTANGLESIZEGENERATOR_HPP

#include "RandomFNormal.hpp"

class RectangleSizeGenerator : public RandomFNormal {
public:
    float getRandom() override;
};

#endif //RECTANGLESIZEGENERATOR_HPP
