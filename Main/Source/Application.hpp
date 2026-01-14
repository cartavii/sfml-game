#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ImGuiSFMLBackend.hpp"
#include "GUIPanel.hpp"
#include "RandomAPI.hpp"
#include "RectangleManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "WindowManager.hpp"

class Application {
public:
    Application();

public:
    int run();

private:
    void gui();
    void render();

private:
    WindowManager m_Window;
    RandomAPI m_RandomAPI;
    RectangleManager m_RectanglesManager;
    GUIPanel m_GUIPanel;
};

#endif // APPLICATION_HPP
