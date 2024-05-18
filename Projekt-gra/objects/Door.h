#pragma once

#include "Wall.h"

class Door
            : public Wall{

    public:
        Door(float x, float y) : Wall(x,y, 64,64, sf::Color{ 0, 191, 255, 255 }){
            isOpen = true;
        }

        Door(const Door&) = delete;
        Door& operator=(const Door&) = delete;
        Door(Door&&) noexcept = default;
        Door& operator=(Door&&) noexcept = default;
        ~Door() override;

        void collision(Player& player) override;
        bool status() const;
        void setStatus(bool status);

    private:
        int id = 99;
        sf::RectangleShape jumpPad;
        bool isOpen;


    };
