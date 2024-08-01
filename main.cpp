#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Diamond.h"
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid Game");

    Paddle paddle(sf::Vector2f(350.0f, 550.0f), sf::Vector2f(100.0f, 20.0f), sf::Color::Blue);
    Ball ball(sf::Vector2f(400.0f, 300.0f), 10.0f, sf::Color::Red, sf::Vector2f(4.0f, 4.0f), 4.0f);

    std::vector<Diamond> diamonds;
    int rows = 5;
    float size = 35.0f;
    float offsetX = window.getSize().x / 2.0f;
    float offsetY = 12.0f;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) {
            float posX = offsetX - (i * size) + (j * 2 * size);
            float posY = offsetY + i * 2 * size;
            diamonds.push_back(Diamond(sf::Vector2f(posX, posY), size, sf::Color::Green));
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2u size = window.getSize();
        sf::Vector2f windowSize(static_cast<float>(size.x), static_cast<float>(size.y));

        window.clear();

        paddle.update(windowSize);
        paddle.draw(window);

        ball.update(windowSize, paddle, diamonds);
        ball.draw(window);

        for (auto& diamond : diamonds) {
            diamond.draw(window);
        }

        window.display();
    }

    return 0;
}
