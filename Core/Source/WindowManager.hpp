#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "ImGuiSfmlBackend.hpp"

class WindowManager {
public:
    WindowManager(const sf::Vector2u& size, const sf::String& title);

public:
    sf::RenderWindow& getWindow();
    const sf::RenderWindow& getWindow() const;

    bool isOpen() const;

    void processEvents();
    void renderStart(const sf::Color& clearColor = sf::Color::Black);
    void render(const sf::Drawable& drawable);
    void renderEnd();

private:
    sf::RenderWindow m_Window;
    ImGuiSFMLBackend m_ImGuiBackend;
};

#endif //WINDOWMANAGER_HPP
