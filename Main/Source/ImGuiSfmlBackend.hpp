#ifndef IMGUISFMLBACKEND_HPP
#define IMGUISFMLBACKEND_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class ImGuiSFMLBackend {
public:
    ImGuiSFMLBackend(sf::RenderWindow& renderWindow);
    ~ImGuiSFMLBackend();

public:
    void processEvent(const sf::Event& event);
    void update();
    void render();

private:
    sf::RenderWindow& m_RenderWindow;
    sf::Clock m_DeltaClock;
};

#endif // IMGUISFMLBACKEND_HPP
