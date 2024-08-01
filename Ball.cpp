#include "Ball.h"

Ball::Ball(sf::Vector2f position, float radius, sf::Color color, sf::Vector2f velocity, float speed)
    : velocity(velocity), speed(speed) {
    ballShape.setRadius(radius);
    ballShape.setFillColor(color);
    ballShape.setPosition(position);
    ballShape.setOrigin(radius, radius); // Set origin to center
}

void Ball::update(const sf::Vector2f& windowSize, const Paddle& paddle, std::vector<Diamond>& diamonds) {
    // Move the ball, hier kan ik mischien die options van speed kunnen veranderen 
    ballShape.move(velocity * speed * 1.5f / 60.0f);

    // Bounce off the walls
    if (ballShape.getPosition().x - ballShape.getRadius() <= 0 || ballShape.getPosition().x + ballShape.getRadius() >= windowSize.x) {
        velocity.x = -velocity.x;
    }
    if (ballShape.getPosition().y - ballShape.getRadius() <= 0) {
        velocity.y = -velocity.y;
    }

    // Bounce off the paddle
    if (ballShape.getGlobalBounds().intersects(paddle.getBounds())) {
        velocity.y = -velocity.y;
        ballShape.setPosition(ballShape.getPosition().x, paddle.getBounds().top - ballShape.getRadius());
    }

    // Reset ball position if it goes below the paddle (optional: end game or lose a life)
    if (ballShape.getPosition().y > windowSize.y) {
        ballShape.setPosition(windowSize.x / 2, windowSize.y / 2 );
        velocity = sf::Vector2f(4.0f, 4.0f); // Reset velocity
    }

    // Check collision with diamonds
    checkCollisionWithDiamonds(diamonds);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(ballShape);
}

sf::FloatRect Ball::getBounds() const {
    return ballShape.getGlobalBounds();
}

void Ball::applySpeed()
{
}

void Ball::checkCollisionWithDiamonds(std::vector<Diamond>& diamonds) {
    for (auto& diamond : diamonds) {
        if (!diamond.isDestroyed() && ballShape.getGlobalBounds().intersects(diamond.getBounds())) {
            diamond.destroy();
            velocity.y = -velocity.y; // Bounce off the diamond
            break;
        }
    }
}
