//
// Created by UseR on 19.05.2024.
//

#include "Game.h"
#include "ThrowableContainer.h"
#include <fmt/ostream.h>
#include <fmt/ranges.h>

#include <utility>
void Game::update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Clock& clock, HUD& hud, FPS& fps, sf::Time deltaTime) {
    if(!started){
        clockLvl0.restart();
        timeClock.restart();
        started = true;
    }
    sf::Time time = clock.getElapsedTime();

    if(!paused and game_started){
        minutes = timeClock.getElapsedTime().asSeconds();
        if(minutes > 58){
            hour++;
            timeClock.restart();
        }
    }
    if(hour >= 24){
        game = false;
        //TODO game lost due to not enough time
    }
    sf::Event event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            game = false;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E and !keyboardInput) {
                eq.show();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                if (paused) {
                    movable = true;
                    jumpable = true;
                    paused = false;
                } else {
                    movable = false;
                    jumpable = false;
                    paused = true;
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
           paused = false;
        }if (event.type == sf::Event::LostFocus) {
            paused = true;
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
                if(time.asSeconds() - lastLvlChanged > 5) {
                    this->nextLvl(window, player, eq, clock);
                    lastLvlChanged = time.asSeconds();
                }
            }
            else{
                player.setPosition((float)window.getSize().x-35, player.getPosition().y);
            }
        }
        if (player.getPosition().x < -40) {
            player.setPosition((float)(window.getSize().x - 30), player.getSurface());
        }
        if(game_started) {
            if(!clockedRestarted){
                clock.restart();
                clockedRestarted = true;
                clockLvl0.restart();
            }
            currentMap.draw(window);
            currentMap.update(window, deltaTime, player, eq, time);
            hud.update(player, fps, currentLvl, nextRoomAvailable, currentMap.getNumberOfEnemies(), hour, minutes);
            hud.draw(window, eq, player);
        }


}

void Game::loadGraphics() {
    if(!loaded) {

//        maps.emplace_back(0, 0, MapTypes::TESTING, 0);
////                Map(0, 0, MapTypes::STARTING, 0),
////
////                Map(3, 0, MapTypes::FOREST, 0),
////                Map(5, 1, MapTypes::FOREST, 1),

////                Map(0, 6, MapTypes::CITY, 1),

////                Map(2, 14, MapTypes::PJATK, 1),
////                Map(0, 6, MapTypes::CITY, 2),
////                Map(2, 4, MapTypes::FOREST, 2),
////                Map(2, 4, MapTypes::ENDING, 0),
////        };
//        currentLvl = 0;
//        currentMap = std::move(maps[currentLvl]);
//        lastLvl = maps.size();
//        for(auto &e : maps) {
//            spawnPoints.insert({{e.getMainType(), e.getSubType()},
//                                {e.getSpawnPoint(),e.getSpawnPoint() }}); //TODO
//        }
//        loaded = true;
    }
}

int Game::getCurrentLvl() const {
    return currentLvl;
}


void Game::gameRules(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud) {
    if(!debugMode) {
        if(game_started) {
            float currentTime = clockLvl0.getElapsedTime().asSeconds();
            if (currentMap.getMainType() == MapTypes::STARTING) {
                if (!stage_0) {
                    if (currentTime <= 3) {
                        movable = false;
                        combat = false;
                        mousekeyListener = true;
                        hud.dialogSet("What a lovely day");
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
                if (stage_0) {
                    float newTime = clockLvl0.getElapsedTime().asSeconds();
                    hud.dialogSet(true);
                    hud.setDecisionVisibility(false);
                    movable = true;
                    if (newTime > 3) {
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
                if (stage_1) {
                    hud.setObjective("Look for disk");
                }
                if (stage_1 and stage_2) {
                    nextRoomAvailable = true;
                    hud.setObjective("Go back to Uni and find your files");
                }

            }
            if (currentMap.getMainType() == MapTypes::FOREST) {
                hud.setObjective("Jump over the trees and go to Uni");
                if (currentMap.getSubType() == 0) {
                    nextRoomAvailable = true;

                }
                if (currentMap.getSubType() == 1) {
                    hud.setObjective("Eliminate enemies");
                    combat = true;
                    if (currentMap.getNumberOfEnemies() <= 0) {
                        nextRoomAvailable = true;

                    }
                }
                if (currentMap.getSubType() == 2) {

                    nextRoomAvailable = true;
                    hud.setObjective("");
                }
            }
            if (currentMap.getMainType() == MapTypes::CITY) {
                if (currentMap.getSubType() == 0) {
                    nextRoomAvailable = true;
                    combat = false;
                    hud.setObjective("Avoid cars");
                }
                if (currentMap.getSubType() == 1) {
                    combat = false;
                    nextRoomAvailable = true;
                    hud.setObjective("Find a way to go further");
                }
                if (currentMap.getSubType() == 2) {
                    combat = true;
                    hud.setObjective("Eliminate Boss");
                    if (currentMap.getNumberOfEnemies() <= 0) {
                        nextRoomAvailable = true;
                    }
                }
            }
            if (currentMap.getMainType() == MapTypes::PJATK) {
                combat = false;
                if (currentMap.getSubType() == 0) {
                    nextRoomAvailable = true;
                    hud.setObjective("Go to the Uni building B");
                }
                if (currentMap.getSubType() == 1) {
                    hud.setObjective("Find class room where you left your disk");
                    if (eq.hasItem(20)) {
                        nextRoomAvailable = true;
                        hud.setObjective("Go back to home and return an assignment");
                    }
                }
            }
        }
    }
    else
    {
        hud.dialogSet(false);
        hud.setDecisionVisibility(false);
        nextRoomAvailable = true;
        stage_0 = true;
        stage_1 = true;
    }


}

void Game::nextLvl(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Clock Time)
{
    this->nextRoomAvailable = false;
    stage_0 = false;
    stage_1 = false;
    stage_2 = false;
    stage_3 = false;
    currentLvl += 1;
    currentMap = std::move(maps[currentLvl]);
    player.setPosition(spawnPoints.at(std::make_pair(currentMap.getMainType(), currentMap.getSubType())).first[0],spawnPoints.at(std::make_pair(currentMap.getMainType(), currentMap.getSubType())).first[1]);
    ThrowableContainer::getVector().clear();
    ThrowableContainer::getInteractVector().clear();
    this->gameSave(window,player,eq, Time, false);
    fmt::println("Next lvl");

}

bool Game::getNextRoomAvailability() const {
    return nextRoomAvailable;
}

void Game::startGame() {
    game_started = true;
}

void Game::gameSave(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Clock Time, bool permanent) {
    if(permanent){
        if(file_path.empty()) {
            file_path = "../saves/save" + std::to_string(1) + ".txt";
        }
        auto file = std::fstream(file_path, std::ios::out | std::ios::trunc);
        switch(currentMap.getMainType()){
            case MapTypes::STARTING:
                fmt::println(file, "{}", "STARTING");
                break;
            case MapTypes::FOREST:
                fmt::println(file, "{}", "FOREST");
                break;
            case MapTypes::CITY:
                fmt::println(file, "{}", "CITY");
                break;
            case MapTypes::PJATK:
                fmt::println(file, "{}", "PJATK");
                break;
            case MapTypes::ENDING:
                fmt::println(file, "{}", "ENDING");
                break;
            case MapTypes::TESTING:
                fmt::println(file, "{}", "TESTING");
                break;
        }
        fmt::println(file, "{}", currentMap.getSubType());
        fmt::println(file, "{}", Time.getElapsedTime().asSeconds());
        fmt::println(file, "{}", player.getHealth());
        fmt::println(file, "{}", fmt::join(eq.getSave(), "\n"));
        file.close();
    }else{
        if(temp_path.empty()) {
            temp_path = "../saves/temp/temp" + std::to_string(0) + ".txt";
        }
        auto file = std::fstream(temp_path, std::ios::out | std::ios::trunc);
        switch(currentMap.getMainType()){
            case MapTypes::STARTING:
                fmt::println(file, "{}", "STARTING");
                break;
            case MapTypes::FOREST:
                fmt::println(file, "{}", "FOREST");
                break;
            case MapTypes::CITY:
                fmt::println(file, "{}", "CITY");
                break;
            case MapTypes::PJATK:
                fmt::println(file, "{}", "PJATK");
                break;
            case MapTypes::ENDING:
                fmt::println(file, "{}", "ENDING");
                break;
            case MapTypes::TESTING:
                fmt::println(file, "{}", "TESTING");
                break;
        }
        fmt::println(file, "{}", currentMap.getSubType());
        fmt::println(file, "{}", Time.getElapsedTime().asSeconds());
        fmt::println(file, "{}", player.getHealth());
        fmt::println(file, "eq--");
        fmt::println(file, "{}", fmt::join(eq.getSave(), "\n"));
        file.close();

    }

}

void Game::gameLoad(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Clock Time, bool newGame, std::string filePath) {
    file_path = std::move(filePath);
    std::ifstream file(file_path);
    std::string line;
    int index = 0;
    MapTypes::types type;
    int subtype = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (index == 0) {
                auto iterator = maps.begin();
                std::string temporary;
                for (auto e: line) {
                    temporary += e;
                }
                if (temporary == "FOREST") {
                    type = MapTypes::FOREST;
                }
                if (temporary == "CITY") {
                    type = MapTypes::CITY;
                }
                if (temporary == "PJATK") {
                    type = MapTypes::PJATK;
                }
                if (temporary == "ENDING") {
                    type = MapTypes::ENDING;
                }
                fmt::println("{}", temporary);
            }
            if (index == 1) {
                subtype = std::stoi(line);
                fmt::println("{}", subtype);
            }
            if (index == 2) {
                //TODO Time
            }if (index == 3) {
                player.setHealth(std::stoi(line));
            }
            if (index >= 5) {
                int commaPoint = 0;
                for (int i = 0; i < line.size(); ++i) {
                    if (line[i] == ',') {
                        commaPoint = i;
                    }
                }
                if (commaPoint == 0) {
                    eq.addItem(std::stoi(line));
                } else {
                    std::string item;
                    std::string number;
                    for (int j = 0; j < line.size(); ++j) {
                        if (j < commaPoint) {
                            item += line[j];
                        }
                        if (j > commaPoint) {
                            number += line[j];
                        }
                    }
                    for (int x = 0; x < std::stoi(number); ++x) {
                        eq.addItem(std::stoi(item));
                    }
                }
            }

            index++;
        }
        file.close();
        int n = 0;
        for (auto &e: maps) {
            if (e.getSubType() == subtype and e.getMainType() == type) {
                fmt::println("help");
                break;
            }
            n++;
        }
        fmt::println("n: {}{}", n, subtype);
        auto iterator = maps.begin();
        iterator += n;
//        maps.erase(maps.begin(), iterator);
        fmt::println("maps size{}", maps.size());
        currentLvl = n;
        currentMap = std::move(maps[currentLvl]);
        game_started = true;
        player.setPosition(spawnPoints.at(std::make_pair(currentMap.getMainType(), currentMap.getSubType())).first[0],spawnPoints.at(std::make_pair(currentMap.getMainType(), currentMap.getSubType())).first[1]);
    }else {
            fmt::println("File error");
        }
    }
