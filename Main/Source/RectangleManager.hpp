#ifndef RECTANGLEMANAGER_HPP
#define RECTANGLEMANAGER_HPP

#include "Rectangles.hpp"
#include "RectangleRenderer.hpp"

class RectangleManager {
public:
    void generate();
    void clear();
    void save();
    void loadLast();
    void render(sf::RenderTarget& target);

private:
    Rectangles m_Rectangles;
    RectangleRenderer m_RectangleRenderer;
};

#endif //RECTANGLEMANAGER_HPP
