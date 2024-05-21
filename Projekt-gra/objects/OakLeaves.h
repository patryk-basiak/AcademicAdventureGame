#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class OakLeaves
    : public Wall{

        public:
        OakLeaves(float x, float y) : Wall(x,y, 64,65, sf::Color{ 255, 255, 0, 255 }){
            leaves.setTexture(ResourceManager::getTexture("../graphics/oak-leavespng.png"));
            leaves.setScale(0.213,0.213);
            leaves.setPosition(x,y);
        }
        void draw(sf::RenderWindow &window) const override;
        ~OakLeaves() override;

        void collision(Player& player, sf::RenderWindow &window) override;

        private:
        int id = 201;
        sf::Sprite leaves;


    };

