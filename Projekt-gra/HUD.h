#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "Equipment.h"
#include "fmt/core.h"
#include "FPS.h"
#include "DialogElement.h"
#include "DecisionElement.h"

class HUD {

public:
    HUD(){
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }

        objective.setPosition(1000,800);
        objective.setFont(font);
        objective.setCharacterSize(30);
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
        roomAvail.setFont(font);
        roomAvail.setPosition(1250,300);
        roomAvail.setCharacterSize(30);
        health.setFont(font);
        health.setPosition(100,800);
        health.setCharacterSize(30);
        timer.setFont(font);
        timer.setPosition(100,830);
        timer.setCharacterSize(30);
        itemInfo.setFont(font);
        itemInfo.setPosition(100,860);
        itemInfo.setCharacterSize(30);
        numberOfEnemies.setFont(font);
        numberOfEnemies.setPosition(1250,350);
        numberOfEnemies.setCharacterSize(30);
        endTime.setFont(font);
        endTime.setPosition(800,400);
        endTime.setCharacterSize(30);


    }

    void draw(sf::RenderWindow& window, Equipment& eq, Player& player);
    void update(Player& player, FPS& fps, int lvl, bool nextRoomAvailable, int numOfEnemies, float time, float minutes );
    void lvls(int roomlvl);

    void showDebug();

    void hideDebug();

    bool dialogGet() const;
    void dialogSet(bool state);
    void setMessage(std::string);
    void setObjective(std::string);
    int getDecision();
    void setDecision(std::vector<std::string>, float x, float y);
    void setDecisionVisibility(bool visible);

private:
    bool debug = false;
    bool dialogShow = true;
    sf::Clock clock;
    sf::Text health;
    sf::Text timer;
    sf::Text itemInfo;
    sf::Text lvlNumber;
    sf::Text numberOfEnemies;
    sf::Font font;
    sf::Text roomAvail;
    sf::Text endTime;
    sf::Text fps;
    sf::Text positionX;
    sf::Text positionY;
    sf::Text objective;
    sf::RectangleShape time;
    DecisionElement decisionElement = DecisionElement(std::vector<std::string>{"im","default", "frame"}, 0,0);
    std::vector<DialogElement> dialog = std::vector<DialogElement>{DialogElement("What a lovely day!")};
    DialogElement mess = DialogElement("");
    bool decisionShow = false;
};
