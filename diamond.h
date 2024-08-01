#ifndef DIAMOND_H
#define DIAMOND_H

#include <SFML/Graphics.hpp>

class Diamond {
public:
    Diamond(sf::Vector2f position, float size, sf::Color color);

    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isDestroyed() const;
    void destroy();

private:
    sf::ConvexShape diamondShape;
    
    bool destroyed;
};

#endif // DIAMOND_H
