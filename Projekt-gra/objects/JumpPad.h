#pragma once

#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "Wall.h"
class JumpPad
        : public Wall{

public:
    JumpPad(float x, float y) : Wall(x,y, 64,64, sf::Color{ 255, 255, 0, 255 }){

    }

    JumpPad(const JumpPad&) = delete;
    JumpPad& operator=(const JumpPad&) = delete;
    JumpPad(JumpPad&&) noexcept = default;
    JumpPad& operator=(JumpPad&&) noexcept = default;
    ~JumpPad() override;

    void collision(Player& player) override;

private:
    sf::RectangleShape jumpPad;


};