#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <random>

class Application {
public:
    Application();
    ~Application();

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
    sf::Clock m_Clock;
    std::random_device m_RandomDevice;
    std::mt19937 m_RandomGenerator;
    std::uniform_real_distribution<float> m_NormalFDistribution;
    std::uniform_int_distribution<unsigned int> m_UIntDistribution;
    std::vector<sf::RectangleShape> m_Rectangles;
};

#endif // APPLICATION_HPP
