#ifndef RECTANGLEMANAGER_HPP
#define RECTANGLEMANAGER_HPP

#include <entt/entt.hpp>
#include "RectangleGenerator.hpp"
#include "Event.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

class RectangleManager {
public:
    RectangleManager(Event<>& generateEvent,
                     Event<>& clearEvent,
                     Event<>& saveEvent,
                     Event<>& loadEvent);

public:
    void update(float deltaTime);
    void render(sf::RenderTarget& target);

private:
    entt::registry m_Registry;
    RectangleGenerator m_Generator;
};

#endif //RECTANGLEMANAGER_HPP
