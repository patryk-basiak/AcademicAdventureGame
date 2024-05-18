//
// Created by UseR on 18.04.2024.
//
#include <iostream>
#include "jumpPad.h"
#include "../Player.h"
#include "fmt/core.h"


void JumpPad::collision(Player& player){
//    player.setPosition(player.getPosition().x, jumpPad.getPosition().y - player.getSize()[1]);
    player.setVerticalVelocity(-400);
}

JumpPad::~JumpPad() = default;
