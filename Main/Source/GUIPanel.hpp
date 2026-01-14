#ifndef GUIPANEL_HPP
#define GUIPANEL_HPP

#include "RectanglesManager.hpp"

class GUIPanel {
public:
    explicit GUIPanel(RectanglesManager& rectanglesManager);

public:
    void show();

private:
    void render();

private:
    RectanglesManager& m_RectanglesManager;
};

#endif //GUIPANEL_HPP
