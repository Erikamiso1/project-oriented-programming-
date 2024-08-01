#include "Paddle.h"

Paddle::Paddle(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    paddleShape.setSize(size);
    paddleShape.setFillColor(color);
    paddleShape.setPosition(position);
}

void Paddle::update(const sf::Vector2f& windowSize) {
    //paddle mt key arrows te bewegn
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        paddleShape.move(-speed * 1.0f / 60.0f, 0); // links
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        paddleShape.move(speed * 1.0f / 60.0f, 0); // rechts
    }

    // Keep the paddle within the window bounds
    if (paddleShape.getPosition().x < 0) {
        paddleShape.setPosition(0, paddleShape.getPosition().y);
    }
    if (paddleShape.getPosition().x + paddleShape.getSize().x > windowSize.x) {
        paddleShape.setPosition(windowSize.x - paddleShape.getSize().x, paddleShape.getPosition().y);
    }
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(paddleShape);
}

sf::FloatRect Paddle::getBounds() const {
    return paddleShape.getGlobalBounds();
}
