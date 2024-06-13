#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "ResourceManager.h"
#include "Game.h"
#include "Player.h"

class Menu {
private:
    sf::Sprite menuImage;
    sf::Sprite playerPointChooser;
    std::vector<sf::Sprite> vector_inteli;
    std::vector<sf::Sprite> vector_enduran;
    std::vector<sf::Sprite> vector_strengt;
    std::vector<sf::Sprite> vector_agile;
    std::vector<sf::Sprite> vector_luck;
    sf::Text points;
    sf::Font font;

    int allPoints;
    int endurance;
    int intelligence;
    int luck;
    int strength;
    int agile;

    float lastUsed;

    bool settings;
    bool pointChooser;
    bool inMenu;
    bool start_game;
    bool exit;
    bool load_game;
public:
    Menu(){
        menuImage.setTexture(ResourceManager::getTexture("../graphics/menu.png"));
        menuImage.setScale((float)1600/menuImage.getTexture()->getSize().x,(float)900/menuImage.getTexture()->getSize().y);
        playerPointChooser.setTexture(ResourceManager::getTexture("../graphics/chooser.png"));
        playerPointChooser.setScale((float)900/playerPointChooser.getTexture()->getSize().x,(float)800/playerPointChooser.getTexture()->getSize().y);
        playerPointChooser.setPosition(800 - (playerPointChooser.getTexture()->getSize().x*playerPointChooser.getScale().x/2), 50);
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }
        int strengX = 480;
        int strengY = 275;
        for(int i = 0; i<8; ++i){
            sf::Sprite temp;
            temp.setTexture(ResourceManager::getTexture("../graphics/point.png"));
            temp.setScale(0.05,0.05);
            temp.setPosition(strengX, strengY);
            vector_strengt.push_back(temp);
            strengX += temp.getTexture()->getSize().x*temp.getScale().x + 10;
        }
        int intelY = 400;
        int intelX = 480;
        for(int i = 0; i<8; ++i){
            sf::Sprite temp;
            temp.setTexture(ResourceManager::getTexture("../graphics/point.png"));
            temp.setScale(0.05,0.05);
            temp.setPosition(intelX, intelY);
            vector_inteli.push_back(temp);
            intelX += temp.getTexture()->getSize().x*temp.getScale().x + 10;
        }
        int luckY = 520;
        int luckX = 480;
        for(int i = 0; i<8; ++i){
            sf::Sprite temp;
            temp.setTexture(ResourceManager::getTexture("../graphics/point.png"));
            temp.setScale(0.05,0.05);
            temp.setPosition(luckX, luckY);
            vector_luck.push_back(temp);
            luckX += temp.getTexture()->getSize().x*temp.getScale().x + 10;
        }
        int agileY = 635;
        int agileX = 480;
        for(int i = 0; i<8; ++i){
            sf::Sprite temp;
            temp.setTexture(ResourceManager::getTexture("../graphics/point.png"));
            temp.setScale(0.05,0.05);
            temp.setPosition(agileX, agileY);
            vector_agile.push_back(temp);
            agileX += temp.getTexture()->getSize().x*temp.getScale().x + 10;
        }
        int enduranceY = 760;
        int enduranceX = 480;
        for(int i = 0; i<8; ++i){
            sf::Sprite temp;
            temp.setTexture(ResourceManager::getTexture("../graphics/point.png"));
            temp.setScale(0.05,0.05);
            temp.setPosition(enduranceX, enduranceY);
            vector_enduran.push_back(temp);
            enduranceX += temp.getTexture()->getSize().x*temp.getScale().x + 10;
        }
        settings = false;
        inMenu = true;
        allPoints = 15;
        points.setString(std::to_string(allPoints));
        points.setFillColor(sf::Color::White);
        points.setFont(font);
        points.setCharacterSize(50);
        points.setPosition(810, 135);
        pointChooser = false;
        start_game = false;
        exit = false;
        load_game = false;
        lastUsed = 0;

        endurance = 1;
        intelligence = 1;
        luck = 1;
        strength = 1;
        agile =1;
    }




   void draw(sf::RenderWindow& window);
   void update(sf::RenderWindow& window, Game& gameClass, Player& player, Equipment& eq, sf::Clock timer);








};

