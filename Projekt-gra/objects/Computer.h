#pragma once

#include "../Player.h"
#include "../ResourceManager.h"
#include "Interactable.h"
#include "fmt/core.h"
#include "Icons.h"
#include "GoogleIcons.h"
#include "TeamsIcon.h"
#include "ChatGptIcon.h"

class Computer
    : public Interactable{

        public:
        Computer(float x, float y) : Interactable(x,y){
            computer.setTexture(ResourceManager::getTexture("../graphics/computer.png"));
            computer.setScale(0.05,0.05);
            computer.setPosition(x,y - 5);
            screen.setSize(sf::Vector2f{1000,600});
            screen.setPosition(800 - 500, 450 - 400);
            screen.setFillColor(sf::Color::White);
            screen.setOutlineThickness(10);
            screen.setOutlineColor(sf::Color::Black);
            fmt::println("Computer created");
            size = std::vector<float>{61.1, 70.9};
            wallpaper.setTexture(ResourceManager::getTexture("../graphics/windowsWallpaper.png"));\
            wallpaper.setPosition(300,50);
            wallpaper.setScale(0.374,0.395);
            icons.push_back(std::make_unique<GoogleIcons>(311.5, 161.5));
            icons.push_back(std::make_unique<TeamsIcon>(451, 161.5));
            icons.push_back(std::make_unique<ChatGptIcon>(590.5, 161.5));
            text.setString("Press F to use computer");
            text.setFont(Interactable::font);
            text.setPosition(computer.getPosition().x, computer.getPosition().y - this->size[1]);

        }Computer(float x, float y, float e) : Interactable(x,y){
            computer.setTexture(ResourceManager::getTexture("../graphics/computer.png"));
            computer.setScale(0.05,0.05);
            computer.setPosition(x,y - 5);
            screen.setSize(sf::Vector2f{1000,600});
            screen.setPosition(800 - 500, 450 - 400);
            screen.setFillColor(sf::Color::White);
            screen.setOutlineThickness(10);
            screen.setOutlineColor(sf::Color::Black);
            fmt::println("Computer created");
            size = std::vector<float>{61.1, 70.9};
            wallpaper.setTexture(ResourceManager::getTexture("../graphics/windowsWallpaper.png"));
            wallpaper.setPosition(300,50);
            wallpaper.setScale(0.374,0.395);
            icons.push_back(std::make_unique<GoogleIcons>(311.5, 161.5));
            icons.push_back(std::make_unique<TeamsIcon>(451, 161.5));
            icons.push_back(std::make_unique<ChatGptIcon>(590.5, 161.5));
            text.setString("Press Q to insert pendrive computer");
            text.setFont(Interactable::font);
            text.setFillColor(sf::Color::Red);
            text.setPosition(computer.getPosition().x, computer.getPosition().y - this->size[1]);
            type = 1;
            explorator.setTexture(ResourceManager::getTexture("../graphics/FileExplorator.png"));
            explorator.setScale((float)150/explorator.getTexture()->getSize().y, (float)200/explorator.getTexture()->getSize().y);
            explorator.setPosition(430,400);
            this->teams.setTexture(ResourceManager::getTexture("../graphics/assigmentTeamsEnding.png"));
            this->teams.scale((float)900/teams.getTexture()->getSize().x, (float)350/teams.getTexture()->getSize().y);
            this->teams.setPosition(350,60);
            selection.setFillColor(sf::Color{0,120,215,100});
            selection.setOutlineColor(sf::Color{0,120,215,255});
            selection.setOutlineThickness(3);

            Fileselection.setFillColor(sf::Color{0,120,215,100});
            Fileselection.setOutlineColor(sf::Color{0,120,215,255});
            Fileselection.setOutlineThickness(2);
            Fileselection.setPosition(597,509);
            Fileselection.setSize(sf::Vector2f (450,15));
            fileMouse.setSize(sf::Vector2f (30,30));
            fileMouse.setFillColor(sf::Color::Red);
        }

        Computer(const Computer&) = delete;
        Computer& operator=(const Computer&) = delete;
        Computer(Computer&&) noexcept = default;
        Computer& operator=(Computer&&) noexcept = default;
        ~Computer() override;
        void draw(sf::RenderWindow& window) override;
        void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time, sf::Time deltatime) override;
        void collision(Player& player, sf::RenderWindow &window) override;
        void collisionBottom(Player& player, sf::RenderWindow &window) override;
        void collisionLeft(Player& player, sf::RenderWindow &window) override;
        void collisionRight(Player& player, sf::RenderWindow &window) override;
        bool getStatus() override;
        sf::Vector2<float> getPosition() override;
        sf::Vector2<float> getSize() override;
        void drawWindow(sf::RenderWindow& window) override;

        private:
        std::vector<std::unique_ptr<Icons>> icons = std::vector<std::unique_ptr<Icons>>();
        bool inUse = false;
        int id = 102;
        sf::Text text;
        sf::Sprite computer;
        sf::Sprite wallpaper;
        std::vector<float> size;
        sf::RectangleShape screen;
        bool coll = false;
        bool pendriveInserted = false;
        bool fileClicked = false;
        sf::Sprite explorator;
        sf::RectangleShape selection;
        sf::RectangleShape Fileselection;
        sf::RectangleShape fileMouse;
        float initialPosX = 0;
        float initialPosY = 0;
        bool positionSet = false;
        bool fileSelected = false;
        bool fileAttached = false;
        sf::Sprite teams;
        float lastUsed =0;
        int type = 0;

    };


