#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Diamond.h"
#include "GameState.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using namespace sf;

// Constanten voor die game def
const std::string GAME_OVER_TEXT = "andere keer beter lol!";
const std::string GAME_WIN_TEXT = "You Win!";
const float TEXT_SIZE = 20.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 720), "Arkanoid Game");



    // Om die texture te houden binnen de GPU 
    Texture backgroundTexture;

    // graphic te loaden 
    if (!backgroundTexture.loadFromFile("Background.jpg")) {
        cerr << "Error loading background image" << endl;
        return -1;
    }
    // Create a sprite
    //Sprite spriteBackground;

    // texture met sprite verbinden 
    Sprite backgroundSprite(backgroundTexture);
    sf::Vector2u windowSize = window.getSize(); 
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(float(windowSize.x) / float(textureSize.x),
    float(windowSize.y) / float(textureSize.y)
);




    GameState gameState = GameState::Playing;
  

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

            //push_back = >
            diamonds.push_back
            
            
            (Diamond(sf::Vector2f(posX, posY), size, sf::Color::Green));
        }
    }

    sf::Font font;
    if (!font.loadFromFile("PressStart2P-Regular.ttf")) {
        // error te handelen
    }

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString(GAME_OVER_TEXT);
    gameOverText.setCharacterSize(TEXT_SIZE);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(200.0f, 300.0f);

    sf::Text gameWinText;
    gameWinText.setFont(font);
    gameWinText.setString(GAME_WIN_TEXT);
    gameWinText.setCharacterSize(TEXT_SIZE);
    gameWinText.setFillColor(sf::Color::Green);
    gameWinText.setPosition(200.0f, 300.0f);

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
        window.draw(backgroundSprite);
        if (gameState == GameState::Playing) {
            paddle.update(windowSize);
            paddle.draw(window);

            ball.update(windowSize, paddle, diamonds);
            ball.draw(window);

            //om die diamanten te tek

            for (auto& diamond : diamonds) {
            
                if (!diamond.isDestroyed()) {
                
                    diamond.draw(window);
                
                
                }
            
            
            
            }



            // Check for Game Over
            if (ball.getBounds().top + ball.getBounds().height > windowSize.y) {
                gameState = GameState::GameOver;
            }

            // Check for die  Game Win
            bool allDiamondsDestroyed = std::all_of(diamonds.begin(), 
                
                diamonds.end(), [](const Diamond& d)
                { return d.isDestroyed();
                
                
                });
            if (allDiamondsDestroyed) {
                gameState = GameState::GameWin;
            }
        }
        else if (gameState == GameState::GameOver) {
            window.draw(gameOverText);
        }
        else if (gameState == GameState::GameWin) {
            window.draw(gameWinText);
        }
       
        window.display();

    }

    return 0;
}


//condities idk: 
// Game Over: Als de bal de onderkant van het scherm raakt zonder de paddle te raken.
//Gewonnen: Als alle diamanten vernietigd zijn

