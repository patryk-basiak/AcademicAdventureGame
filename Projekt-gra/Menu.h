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

