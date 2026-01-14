#ifndef GUIPANEL_HPP
#define GUIPANEL_HPP

#include "Event.hpp"

class GUIPanel {
public:
    void show();

    Event<>& getGenerateEvent();
    Event<>& getClearEvent();
    Event<>& getSaveEvent();
    Event<>& getLoadEvent();

private:
    void render();

private:
    Event<> m_GenerateEvent;
    Event<> m_ClearEvent;
    Event<> m_SaveEvent;
    Event<> m_LoadEvent;
};

#endif //GUIPANEL_HPP
