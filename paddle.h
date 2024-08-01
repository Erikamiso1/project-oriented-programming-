#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void update(const sf::Vector2f& windowSize);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape paddleShape;
    float speed = 50.0f; // Paddle movement speed
};

#endif // PADDLE_H
