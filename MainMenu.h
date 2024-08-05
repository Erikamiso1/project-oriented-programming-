


/*#include <SFML/Graphics.hpp>

class MainMenu {

private:
    static const int Max_main_menu = 4;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
    int MainMenuSelected;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    MainMenu(float width, float height);
    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int MainMenuPressed() const; // Function declaration


};

#endif*/

#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>

class MainMenu {

private:
    static const int Max_main_menu = 4;
    sf::Font font;
    sf::Text text;
    sf::Text mainMenu[Max_main_menu];
    int MainMenuSelected;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    MainMenu(float width, float height);
    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int MainMenuPressed() const; // Function declaration


};

#endif
