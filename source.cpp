#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"

using namespace sf;

int main() {
   
    RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    // Set the framerate limit for smooth rendering
    
    while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close();
            }
            // Handle keyboard inputs
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    mainMenu.MoveUp();
                }
                else if (event.key.code == Keyboard::Down) {
                    mainMenu.MoveDown();
                }
                else if (event.key.code == Keyboard::Return) {
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        // Handle "Play" option
                        std::cout << "Play selected" << std::endl;
                        // Implement game start logic
                    }
                    else if (x == 1) {
                        // Handle "Options" option
                        std::cout << "Options selected" << std::endl;
                        // Implement options menu logic
                    }
                    else if (x == 2) {
                        // Handle "About Us" option
                        std::cout << "About Us selected" << std::endl;
                        // Implement about us logic
                    }
                    else if (x == 3) {
                        // Handle "Exit" option
                        MENU.close();
                    }
                }
            }
        }

        // Clear and draw the main menu
        MENU.clear();
        mainMenu.draw(MENU);
        MENU.display();
    }

    return 0;
}
