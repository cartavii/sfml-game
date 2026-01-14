#ifndef RECTANGLEMANAGER_HPP
#define RECTANGLEMANAGER_HPP

#include "Rectangles.hpp"
#include "RectangleGenerator.hpp"
#include "JSONRectangleStorage.hpp"
#include "RectangleCommandsHandler.hpp"
#include "RectangleRenderer.hpp"
#include "Event.hpp"

class RectangleManager {
public:
    RectangleManager(Event<>& generateEvent,
                     Event<>& clearEvent,
                     Event<>& saveEvent,
                     Event<>& loadEvent);

public:
    void render(sf::RenderTarget& target);

    RectangleCommandsHandler& getCommands();

private:
    Rectangles m_Rectangles;
    RectangleGenerator m_Generator;
    JSONRectangleStorage m_Storage;
    RectangleCommandsHandler m_CommandsHandler;
    RectangleRenderer m_Renderer;
};

#endif //RECTANGLEMANAGER_HPP
