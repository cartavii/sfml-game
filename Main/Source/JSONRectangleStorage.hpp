#ifndef JSONRECTANGLESTORAGE_HPP
#define JSONRECTANGLESTORAGE_HPP
#include "IRectangleStorage.hpp"

class JSONRectangleStorage : public IRectangleStorage {
public:
    void save(const Rectangles& rectangles) override;
    void load(Rectangles& rectangles) override;
};

#endif //JSONRECTANGLESTORAGE_HPP
