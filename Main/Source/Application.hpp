#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "GUIPanel.hpp"
#include "RandomAPI.hpp"
#include "RectangleManager.hpp"
#include "WindowManager.hpp"

#include <SFML/System/Clock.hpp>

class Application {
public:
    Application();

public:
    int run();

private:
    void update();
    void gui();
    void render();

private:
    sf::Clock m_DeltaClock;
    WindowManager m_Window;
    RandomAPI m_RandomAPI;
    GUIPanel m_GUIPanel;
    RectangleManager m_RectanglesManager;
};

#endif // APPLICATION_HPP
