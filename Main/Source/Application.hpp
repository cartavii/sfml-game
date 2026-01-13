#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ImGuiSfmlBackend.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "RandomizerAPI.hpp"

class Application {
public:
    Application();

public:
    int run();

private:
    void processEvents();
    void guiRender();
    void renderRectangles();
    void render();

    void spawnRectangle();
    void clearRectangles();

    void saveRectangles();
    void loadRectangles();

private:
    sf::RenderWindow m_Window;
    ImGuiSFMLBackend m_Backend;
    RandomizerAPI m_Randomizer;
    std::vector<sf::RectangleShape> m_Rectangles;
};

#endif // APPLICATION_HPP
