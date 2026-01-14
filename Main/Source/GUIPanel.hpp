#ifndef GUIPANEL_HPP
#define GUIPANEL_HPP

#include "RectangleManager.hpp"
#include "RectangleCommandsHandler.hpp"

class GUIPanel {
public:
    explicit GUIPanel(RectangleCommandsHandler& commands);

public:
    void show();

private:
    void render();

private:
    RectangleCommandsHandler& m_Commands;
};

#endif //GUIPANEL_HPP
