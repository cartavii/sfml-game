#ifndef RECTANGLECOLORGENERATOR_HPP
#define RECTANGLECOLORGENERATOR_HPP

#include "RandomByte.hpp"

class RectangleColorGenerator : public RandomByte {
public:
    unsigned short getRandom() override;
};



#endif //RECTANGLECOLORGENERATOR_HPP
