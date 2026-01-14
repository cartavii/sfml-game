#ifndef GUIPANEL_HPP
#define GUIPANEL_HPP

#include "RectangleManager.hpp"

class GUIPanel {
public:
    explicit GUIPanel(RectangleManager& rectanglesManager);

public:
    void show();

private:
    void render();

private:
    RectangleManager& m_RectanglesManager;
};

#endif //GUIPANEL_HPP
