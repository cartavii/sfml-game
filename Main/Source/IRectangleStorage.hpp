#ifndef IRECTANGLESTORAGE_HPP
#define IRECTANGLESTORAGE_HPP

#include "Rectangles.hpp"

class IRectangleStorage {
public:
    virtual ~IRectangleStorage() = default;

public:
    virtual void save(const Rectangles& rectangles) = 0;
    virtual void load(Rectangles& rectangles) = 0;
};

#endif //IRECTANGLESTORAGE_HPP
