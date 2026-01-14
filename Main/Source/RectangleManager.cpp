#include "RectangleManager.hpp"

RectangleManager::RectangleManager()
: m_CommandsHandler{
    { m_Rectangles, m_Generator },
    { m_Rectangles },
    { m_Rectangles },
    { m_Rectangles }
} {}

void RectangleManager::render(sf::RenderTarget& target) {
    m_Renderer.render(target, m_Rectangles);
}

RectangleCommandsHandler& RectangleManager::getCommands() {
    return m_CommandsHandler;
}
