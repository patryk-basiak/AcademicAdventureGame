#include "Menu.h"
#include <cmath>

void Menu::draw(sf::RenderWindow &window) {
    window.draw(menuImage);
    if(pointChooser){
        window.draw(playerPointChooser);
        window.draw(points);

        for(int i = 0; i<endurance; ++i){
            window.draw(vector_enduran[i]);
        }for(int i = 0; i<intelligence; ++i){
            window.draw(vector_inteli[i]);
        }for(int i = 0; i<endurance; ++i){

        }for(int i = 0; i<strength; ++i){
            window.draw(vector_strengt[i]);
        }for(int i = 0; i<agile; ++i){
            window.draw(vector_agile[i]);
        }
        for(int i = 0; i<luck; ++i){
            window.draw(vector_luck[i]);
        }
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
                if(debugMode){
                    game = true;
                    gameClass.startGame();
                    menuX = false;
                }else{
                    pointChooser = true;
                    inMenu = false;
                }
//
            }
            if (pos.x > 480 and pos.x < 1120 and pos.y > 490 and pos.y < 630) {
                gameClass.gameLoad(window, player, eq, timer, true, "../saves/savesX1.txt");
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
            if(time.asSeconds() - lastUsed > 0.3) {
                fmt::println("x{}", pos.x);
                fmt::println("y{}", pos.y);
                if (pos.x > 1140 and pos.x < 1165) {
                    if (pos.y > 225 and pos.y < 245) {
                        if(strength < 8 and allPoints > 0){
                            strength++;
                            allPoints--;
                        }
                    }
                    if (pos.y > 340 and pos.y < 370) {
                        fmt::println("plus1");
                        if(intelligence < 8 and allPoints > 0){
                            intelligence++;
                            allPoints--;
                        }
                    }
                    if (pos.y > 455 and pos.y < 485) {
                        fmt::println("plus2");
                        if(luck < 8 and allPoints > 0){
                            luck++;
                            allPoints--;
                        }
                    }
                    if (pos.y > 570 and pos.y < 600) {
                        fmt::println("plus3");
                        if(agile < 8 and allPoints > 0){
                            agile++;
                            allPoints--;
                        }

                    }
                    if (pos.y > 685 and pos.y < 715) {
                        fmt::println("plus4");
                        if(endurance < 8 and allPoints > 0){
                            endurance++;
                            allPoints--;
                        }
                    }
                }if (pos.x > 485 and pos.x < 510) {
                    if (pos.y > 225 and pos.y < 255) {
                        if(strength > 1){
                            strength--;
                            allPoints++;
                        }
                    }
                    if (pos.y > 340 and pos.y < 370) {
                        fmt::println("plus1");
                        if(intelligence > 1){
                            intelligence--;
                            allPoints++;
                        }
                    }
                    if (pos.y > 455 and pos.y < 485) {
                        fmt::println("plus2");
                        if(luck > 1){
                            luck--;
                            allPoints++;
                        }
                    }
                    if (pos.y > 570 and pos.y < 600) {
                        fmt::println("plus3");
                        if(agile > 1){
                            agile--;
                            allPoints++;
                        }

                    }
                    if (pos.y > 685 and pos.y < 715) {
                        fmt::println("plus4");
                        if(endurance > 1){
                            endurance--;
                            allPoints++;
                        }
                    }
                }
                lastUsed = time.asSeconds();
        }

        }
        points.setString(std::to_string(allPoints));
        if(pos.x > 700 and pos.x < 945 and pos.y > 810 and pos.y < 845){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if(allPoints == 0) {
                    player.setAgile(agile);
                    player.setLuck(luck);
                    player.setStrength(strength);
                    player.setEndurance(endurance);
                    player.setIntelligence(intelligence);
                    game = true;
                    gameClass.startGame();
                    menuX = false;
                }
            }
        }
    }
}

