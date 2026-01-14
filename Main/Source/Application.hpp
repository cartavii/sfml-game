#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ImGuiSfmlBackend.hpp"
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
    void guiRender();
    void render();

private:
    sf::RenderWindow m_Window;
    ImGuiSFMLBackend m_Backend;
    RandomizerAPI m_Randomizer;
    RectanglesManager m_RectanglesManager;
};

#endif // APPLICATION_HPP
