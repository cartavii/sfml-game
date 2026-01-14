#ifndef RECTANGLEMANAGER_HPP
#define RECTANGLEMANAGER_HPP

#include "Rectangles.hpp"
#include "RectangleGenerator.hpp"
#include "RectangleCommandsHandler.hpp"
#include "RectangleRenderer.hpp"

class RectangleManager {
public:
    RectangleManager();

public:
    void render(sf::RenderTarget& target);

    RectangleCommandsHandler& getCommands();

private:
    Rectangles m_Rectangles;
    RectangleGenerator m_Generator;
    RectangleCommandsHandler m_CommandsHandler;
    RectangleRenderer m_Renderer;
};

#endif //RECTANGLEMANAGER_HPP
