#ifndef RECTANGLESMANAGER_HPP
#define RECTANGLESMANAGER_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

class RectanglesManager {
public:
    void generate(const sf::View& view);
    void clearAll();

    void save();
    void loadLast();

    void render(sf::RenderTarget& target);

private:
    sf::Clock m_DeltaClock;
    std::vector<sf::RectangleShape> m_Rectangles;
};

#endif // RECTANGLESMANAGER_HPP
