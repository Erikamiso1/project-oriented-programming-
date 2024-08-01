#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

MainMenu::MainMenu(float width, float height) {
    if (!font.loadFromFile("PressStart2P-Regular.ttf")) {
        std::cerr << "No Font has been found. Please check your files properly" << std::endl;
    }
    Texture texturebackground;
    Sprite spritebackground;

    if (!backgroundTexture.loadFromFile("Background.jpg")) {
        std::cerr << "Error loading background image" << std::endl;
    }
   
    backgroundSprite.setTexture(backgroundTexture);
    spritebackground.setPosition(0, 0);
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(25);
    mainMenu[0].setPosition(420, 130);

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(25);
    mainMenu[1].setPosition(380, 230);

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("About Us");
    mainMenu[2].setCharacterSize(25);
    mainMenu[2].setPosition(375, 330);

    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit the Game");
    mainMenu[3].setCharacterSize(25);
    mainMenu[3].setPosition(310, 430);

    MainMenuSelected = 0;
    mainMenu[MainMenuSelected].setFillColor(Color::Black);
}

void MainMenu::draw(RenderWindow& window) {
    window.clear();
    window.draw(backgroundSprite); 
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]); // Draw menu items
    }
    window.display(); // Display the contents of the window
}

void MainMenu::MoveUp() {
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected--;
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
    }
}

void MainMenu::MoveDown() {
    if (MainMenuSelected + 1 < Max_main_menu) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
    }
}

// Function to return the index of the selected menu item
int MainMenu::MainMenuPressed() const {
    return MainMenuSelected;
}
