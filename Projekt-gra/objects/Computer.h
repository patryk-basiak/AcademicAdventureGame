#pragma once

#include "../Player.h"
#include "../ResourceManager.h"
#include "Interactable.h"
#include "fmt/core.h"
#include "Icons.h"

class Computer
    : public Interactable{

        public:
        Computer(float x, float y) : Interactable(x,y){
            computer.setTexture(ResourceManager::getTexture("../graphics/computer.png"));
            computer.setScale(0.05,0.05);
            computer.setPosition(x,y);
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

        }

        Computer(const Computer&) = delete;
        Computer& operator=(const Computer&) = delete;
        Computer(Computer&&) noexcept = default;
        Computer& operator=(Computer&&) noexcept = default;
        ~Computer() override;
        void draw(sf::RenderWindow& window) override;
        void update(sf::RenderWindow& window) override;
        void collision(Player& player, sf::RenderWindow &window) override;
        bool getStatus() override;
        sf::Vector2<float> getPosition() override;
        std::vector<float> getSize() override;


        private:
        std::vector<Icons> icons = std::vector<Icons>{{Icons(311.5,161.5)}, Icons(451,161.5)};
        bool inUse = false;
        int id = 102;
        sf::Sprite computer;
        sf::Sprite wallpaper;
        std::vector<float> size;
        sf::RectangleShape screen;

    };


