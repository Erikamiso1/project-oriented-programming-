#include "Diamond.h"

Diamond::Diamond(sf::Vector2f position, float size, sf::Color color)
    : destroyed(false) {

    diamondShape.setPointCount(4); // Diamond shape with 4 points
    diamondShape.setPoint(0, sf::Vector2f(size / 2.0f, 0.0f));           // Top point
    diamondShape.setPoint(1, sf::Vector2f(size, size / 2.0f));          // Right point
    diamondShape.setPoint(2, sf::Vector2f(size / 2.0f, size));          // Bottom point
    diamondShape.setPoint(3, sf::Vector2f(0.0f, size / 2.0f));          // Left point



    diamondShape.setFillColor(color);
    diamondShape.setPosition(position);
    diamondShape.setOrigin(size / 2.0f, size / 2.0f); // Set origin to center
}

void Diamond::draw(sf::RenderWindow& window) {
    if (!destroyed) {
        window.draw(diamondShape);
    }
}

sf::FloatRect Diamond::getBounds() const {
    return diamondShape.getGlobalBounds();
}

bool Diamond::isDestroyed() const {
    return destroyed;
}

void Diamond::destroy() {
    destroyed = true;
}
