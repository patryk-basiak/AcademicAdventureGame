//
// Created by UseR on 19.05.2024.
//

#include "Game.h"

void Game::update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud, FPS& fps) {
    if(!started){
        clockLvl0.restart();
        started = true;
    }

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
                eq.useItemInHand(player);
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
        hud.update(player, fps, currentLvl, nextRoomAvailable, currentMap.getNumberOfEnemies());
        hud.draw(window,eq,player);


}

void Game::loadGraphics() {
    if(!loaded) {
        maps.emplace_back(0, 0, MapTypes::FOREST, 0);
        maps.emplace_back(15, 0, MapTypes::FOREST, 1);
        maps.emplace_back(0, 1, MapTypes::FOREST, 2);
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
        currentMap = std::move(maps[currentLvl]);
        lastLvl = maps.size();
        loaded = true;
    }
}

int Game::getCurrentLvl() const {
    return currentLvl;
}


void Game::gameRules(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud) {
    if(currentLvl == 0 and game){
        float currentTime = clockLvl0.getElapsedTime().asSeconds();
        if(!stage_0) {
            if (currentTime <= 3) {
                movable = false;
                hud.dialogSet(true);
                player.setPosition(player.getPosition().x - 0.03, player.getPosition().y);
            }
            if (currentTime > 3 and currentTime <= 6) {
                hud.dialogSet(true);
                hud.setMessage("Should I go on a walk or ride a bike with friends?");
            }
            if (currentTime > 6 and currentTime <= 7) {
                // decision window
                hud.dialogSet(true);
                hud.setDecision(std::vector<std::string>{"Go for a walk", "Go ride a bike with friends"},
                                player.getPosition().x - (player.getSize()[0] * 1.5),
                                player.getPosition().y - (player.getSize()[1])); //
            }
            if (currentTime > 8 and currentTime <= 12) {
                hud.dialogSet(false);
                hud.setDecisionVisibility(true);
                hud.setMessage("Wait, What's that sound?");

            }
        }
        if(stage_0) {
//            clockLvl0.restart(); TODO
            float newTime = clockLvl0.getElapsedTime().asSeconds();
            hud.dialogSet(true);
            hud.setDecisionVisibility(false);
            movable = true;
            if(newTime > 3) {
                hud.dialogSet(false);
                if (!hud.dialogGet()) {
//                    hud.dialogSet(false);
                    int tempDecision = hud.getDecision();
                    // TODO resultat decyzji
                    decisions.push_back(tempDecision);
                    hud.setObjective("Check computer");
                }
            }
        }
        if(stage_1){
            hud.setObjective("Look for disk");
        }
        if(stage_1 and stage_2){
            nextRoomAvailable = true;
            hud.setObjective("Go back to Uni and find your files");
        }

    }
    if(currentLvl == 1){
        nextRoomAvailable = true;
    }
    if(currentLvl == 2){
        if(currentMap.getNumberOfEnemies() <= 0){
            nextRoomAvailable = true;
        }
    }


}

void Game::nextLvl(Player & player) {
    player.setStartPosition();
    this->nextRoomAvailable = false;
    stage_0 = false;
    stage_1 = false;
    stage_2 = false;
    stage_3 = false;
    currentLvl += 1;
    currentMap = std::move(maps[currentLvl]);
    fmt::println("Next lvl");

}

bool Game::getNextRoomAvailability() const {
    return nextRoomAvailable;
}
