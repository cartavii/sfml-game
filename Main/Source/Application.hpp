#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Application {
public:
    Application();
    ~Application();

public:
    int run();

private:
    void processEvents();
    void guiRender();
    void render();

private:
    sf::RenderWindow m_Window;
    sf::Clock m_Clock;
};

#endif // APPLICATION_HPP
