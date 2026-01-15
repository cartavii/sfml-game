#include "RectangleManager.hpp"
#include "RectanglePositionGenerator.hpp"
#include "RectangleColorGenerator.hpp"

RectangleManager::RectangleManager(Event<>& generateEvent,
                                 Event<>& clearEvent,
                                 Event<>& saveEvent,
                                 Event<>& loadEvent)
: m_CommandsHandler{
    { m_Rectangles, m_Generator },
    { m_Rectangles },
    { m_Rectangles, m_Storage },
    { m_Rectangles, m_Storage }}
, m_Generator(std::make_shared<RectanglePositionGenerator>(), std::make_shared<RectangleColorGenerator>()) {
    generateEvent.subscribe([this]() { m_CommandsHandler.m_Generate.execute(); });
    clearEvent.subscribe([this]() { m_CommandsHandler.m_Clear.execute(); });
    saveEvent.subscribe([this]() { m_CommandsHandler.m_Save.execute(); });
    loadEvent.subscribe([this]() { m_CommandsHandler.m_LoadLast.execute(); });
}

void RectangleManager::render(sf::RenderTarget& target) {
    m_Renderer.render(target, m_Rectangles);
}

RectangleCommandsHandler& RectangleManager::getCommands() {
    return m_CommandsHandler;
}
