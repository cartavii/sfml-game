#include "Rectangles.hpp"

void Rectangles::clear() {
    m_Data.clear();
}

void Rectangles::addRectangle(const RectangleData& rectangle) {
    m_Data.push_back(rectangle);
}

Rectangles::Iterator Rectangles::begin() {
    return m_Data.begin();
}

Rectangles::Iterator Rectangles::end() {
    return m_Data.end();
}

Rectangles::ConstIterator Rectangles::begin() const {
    return m_Data.begin();
}

Rectangles::ConstIterator Rectangles::end() const {
    return m_Data.end();
}
