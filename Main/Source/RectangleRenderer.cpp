#include "RectangleRenderer.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

RectangleRenderer::RectangleRenderer()
: m_RectangleShape(sf::Vector2f(50.f, 50.f)){
    m_RectangleShape.setOrigin(m_RectangleShape.getSize() / 2.f);
}

void RectangleRenderer::render(sf::RenderTarget& target, const Rectangles& rectangles) {
    for (const RectangleData& rectangle : rectangles) {
        render(target, rectangle);
    }
}

void RectangleRenderer::render(sf::RenderTarget& target, const RectangleData& rectangleData) {
    m_RectangleShape.setPosition(rectangleData.position);
    m_RectangleShape.setFillColor(rectangleData.color);
    target.draw(m_RectangleShape);
}
