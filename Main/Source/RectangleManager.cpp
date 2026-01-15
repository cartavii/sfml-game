#include "RectangleManager.hpp"
#include "RectanglePositionGenerator.hpp"
#include "RectangleAngleGenerator.hpp"
#include "RectangleRotationGenerator.hpp"
#include "RectangleSizeGenerator.hpp"
#include "RectangleColorGenerator.hpp"
#include "Systems.hpp"

RectangleManager::RectangleManager(Event<>& generateEvent,
                                 Event<>& clearEvent,
                                 Event<>& saveEvent,
                                 Event<>& loadEvent)
: m_Generator(
    std::make_shared<RectanglePositionGenerator>(),
    std::make_shared<RectangleAngleGenerator>(),
    std::make_shared<RectangleRotationGenerator>(),
    std::make_shared<RectangleSizeGenerator>(),
    std::make_shared<RectangleColorGenerator>()) {
    generateEvent.subscribe([this]() { m_Generator.generate(m_Registry); });
    clearEvent.subscribe([this]() { m_Registry.clear(); });
    saveEvent.subscribe([this]() { SaveSystem(m_Registry, "rectangles_save.json"); });
    loadEvent.subscribe([this]() { LoadSystem(m_Registry, "rectangles_save.json"); });
}

void RectangleManager::update(const float deltaTime) {
    MovementSystem(m_Registry, deltaTime);
}

void RectangleManager::render(sf::RenderTarget& target) {
    RenderSystem(m_Registry, target);
}
