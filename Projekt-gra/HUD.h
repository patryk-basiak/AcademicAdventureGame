#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "Equipment.h"
#include "fmt/core.h"
#include "FPS.h"
#include "DialogElement.h"

class HUD {

public:
    HUD(){
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }

//        mission.setPosition(800,750);
//        mission.setFont(font);
//        mission.setString("Mission:");
//        mission.setCharacterSize(30);
        positionX.setPosition(1250,150);
        positionX.setFont(font);
        positionX.setCharacterSize(30);
        positionY.setPosition(1250,100);
        positionY.setFont(font);
        positionY.setCharacterSize(30);
        fps.setFont(font);
        fps.setPosition(1250,250);
        fps.setCharacterSize(30);
        lvlNumber.setFont(font);
        lvlNumber.setPosition(1250,200);
        lvlNumber.setCharacterSize(30);
        health.setFont(font);
        health.setPosition(100,800);
        health.setCharacterSize(30);

    }

    void draw(sf::RenderWindow& window, Equipment& eq, Player& player);
    void update(Player& player, FPS& fps, int lvl);
    void lvls(int roomlvl);

    void showDebug();

    void hideDebug();

private:
    bool debug = false;
    bool dialogShow = true;
    sf::Clock clock;
    sf::Text health;
    sf::Text lvlNumber;
    sf::Font font;
    sf::Text fps;
    sf::Text positionX;
    sf::Text positionY;
    sf::Text mission;
    std::vector<DialogElement> dialog = std::vector<DialogElement>{DialogElement("What a lovely day!")};
    DialogElement mess = DialogElement("What a lovely day");
};
