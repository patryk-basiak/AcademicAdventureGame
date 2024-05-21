//
// Created by UseR on 19.05.2024.
//

#include "Game.h"

void Game::update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud) {
    sf::Event event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            game = false;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                fmt::println("working");
                eq.show();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                if (pause) {
                    movable = true;
                    pause = false;
                } else {
                    movable = false;
                    pause = true;
                }

            }
            if (event.key.code == sf::Keyboard::SemiColon) {
                if (debug) {
                    debug = false;
                    hud.showDebug();
                } else {
                    debug = true;
                    hud.hideDebug();
                }
            }

        }
        if (event.type == sf::Event::GainedFocus) {
            // resume
        }
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0) {
                eq.movedMouse();
            } else if (event.mouseWheelScroll.delta < 0) {
                eq.movedMouseDown();
            }


        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Left){
                eq.useItemInHand();
            }

        }
    }

        if (player.getPosition().x >=  (float)(window.getSize().x - 30)) {
            if (currentLvl != lastLvl and nextRoomAvailable) {
                this->nextLvl(player);
                player.setPosition(0.f, 500);
            }
            else{
                player.setPosition((float)window.getSize().x-35, player.getPosition().y);
            }
        }
        if (player.getPosition().x < -40) {
            player.setPosition((float)(window.getSize().x - 30), player.getSurface());
        }

        currentMap.draw(window);
        currentMap.update(window,deltaTime,player,eq);


}

void Game::loadGraphics() {
    if(!loaded) {
        maps.emplace_back(0, 0, MapTypes::FOREST, 0);
        maps.emplace_back(15, 0, MapTypes::FOREST, 1);
//        maps.emplace_back(0, 0, MapTypes::TESTING, 0);
////                Map(0, 0, MapTypes::STARTING, 0),
////
////                Map(3, 0, MapTypes::FOREST, 0),
////                Map(5, 1, MapTypes::FOREST, 1),
////                Map(1, 10, MapTypes::CITY, 0),
////                Map(0, 6, MapTypes::CITY, 1),
////                Map(1, 3, MapTypes::PJATK, 0),
////                Map(2, 14, MapTypes::PJATK, 1),
////                Map(0, 6, MapTypes::CITY, 2),
////                Map(2, 4, MapTypes::FOREST, 2),
////                Map(2, 4, MapTypes::ENDING, 0),
////        };
        currentLvl = 0;
        currentMap = maps[currentLvl];
        lastLvl = maps.size();
        loaded = true;
    }
}

int Game::getCurrentLvl() const {
    return currentLvl;
}


void Game::gameRules(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud) {
    if(currentLvl == 0){
        float currentTime = clockLvl0.getElapsedTime().asSeconds();
        if(currentTime <= 10){
            movable = false;
            player.setPosition(player.getPosition().x - 0.03, player.getPosition().y);
        } if(currentTime >= 10 and currentTime <= 12){
//            dialog.clear();
            movable = true;

        }
        if(stage_0 and stage_1){
            nextRoomAvailable = true;
        }

    }
    if(currentLvl == 1){
        nextRoomAvailable = true;
    }

}

void Game::nextLvl(Player & player) {
    this->nextRoomAvailable = false;
    stage_0 = false;
    stage_1 = false;
    stage_2 = false;
    stage_3 = false;
    currentLvl += 1;
    currentMap = maps[currentLvl];
    player.setStartPosition();
}

bool Game::getNextRoomAvailability() const {
    return nextRoomAvailable;
}
