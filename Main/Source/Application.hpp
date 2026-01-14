#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ImGuiSfmlBackend.hpp"
#include "GUIPanel.hpp"
#include "RandomizerAPI.hpp"
#include "RectanglesManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class Application {
public:
    Application();

public:
    int run();

private:
    void processEvents();
    void render();

private:
    sf::RenderWindow m_Window;
    ImGuiSFMLBackend m_Backend;
    RandomizerAPI m_Randomizer;
    RectanglesManager m_RectanglesManager;
    GUIPanel m_GUIPanel;
};

#endif // APPLICATION_HPP
