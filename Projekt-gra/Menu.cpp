#include "Menu.h"
#include <cmath>

void Menu::draw(sf::RenderWindow &window) {
    window.draw(menuImage);
    if(pointChooser){
        window.draw(playerPointChooser);
        window.draw(points);
    }

}

void Menu::update(sf::RenderWindow& window, Game &gameClass, Player &player, Equipment& eq, sf::Clock timer) {
//    if(pos.x >= eqRect.getPosition().x + j*70 and pos.x <= eqRect.getPosition().x + ((j+1)*70) and
//       pos.y >= eqRect.getPosition().y + i*70 and pos.y <= eqRect.getPosition().y + ((i+1)*70)){
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    sf::Time time = timer.getElapsedTime();
    if(inMenu) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (pos.x > 480 and pos.x < 1120 and pos.y > 310 and pos.y < 450) {
                pointChooser = true;
                inMenu = false;
//                game = true;
//                gameClass.startGame();
//                menuX = false;
            }
            if (pos.x > 480 and pos.x < 1120 and pos.y > 490 and pos.y < 630) {
                gameClass.gameLoad(window, player, eq, timer, true, "../saves/save0.txt");
                game = true;
                menuX = false;
            }
            if (pos.x > 480 and pos.x < 1120 and pos.y > 680 and pos.y < 820) {
                window.close();
                //source https://www.gavilan.edu/csis/languages/stop-end.html#:~:text=C%2B%2B%20uses%20the%20exit()%20function%20to%20terminate%20the%20program%20execution.
                std::exit(EXIT_SUCCESS);
            }

        }
    }
    if(pointChooser){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(time.asSeconds() - lastUsed > 0.5) {
                fmt::println("x{}", pos.x);
                fmt::println("y{}", pos.y);
                if (pos.x > 1140 and pos.x < 1165) {
                    if (pos.y > 225 and pos.y < 245) {
                        allPoints--;
                    }
                    if (pos.y > 340 and pos.y < 370) {
                        fmt::println("plus1");
                        allPoints--;
                    }
                    if (pos.y > 455 and pos.y < 485) {
                        fmt::println("plus2");
                        allPoints--;
                    }
                    if (pos.y > 570 and pos.y < 600) {
                        fmt::println("plus3");
                        allPoints--;

                    }
                    if (pos.y > 685 and pos.y < 715) {
                        fmt::println("plus4");
                        allPoints--;
                    }
                }
                lastUsed = time.asSeconds();
        }

        }
        points.setString(std::to_string(allPoints));
    }
}

