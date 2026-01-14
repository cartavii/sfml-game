#ifndef RECTANGLES_HPP
#define RECTANGLES_HPP

#include "RectangleData.hpp"
#include <vector>

class Rectangles {
public:
    using Iterator = std::vector<RectangleData>::iterator;
    using ConstIterator = std::vector<RectangleData>::const_iterator;

public:
    void clear();
    void addRectangle(const RectangleData& rectangle);

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

private:
    std::vector<RectangleData> m_Data;
};

#endif //RECTANGLES_HPP
