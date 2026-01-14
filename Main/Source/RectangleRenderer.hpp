#ifndef RECTANGLERENDERER_HPP
#define RECTANGLERENDERER_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "Rectangles.hpp"

class RectangleRenderer {
public:
    RectangleRenderer();

public:
    void render(sf::RenderTarget& target, const Rectangles& rectangles);

private:
    void render(sf::RenderTarget& target, const RectangleData& rectangleData);

private:
    sf::RectangleShape m_RectangleShape;
};

#endif //RECTANGLERENDERER_HPP
