#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Diamond.h"
#include <vector>

class Ball {
public:
    Ball(sf::Vector2f position, float radius, sf::Color color, sf::Vector2f velocity, float speed);

    void update(const sf::Vector2f& windowSize, const Paddle& paddle, std::vector<Diamond>& diamonds);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape ballShape;
    sf::Vector2f velocity;
    float speed;

    void applySpeed();
    void checkCollisionWithDiamonds(std::vector<Diamond>& diamonds);
};

#endif // BALL_H
