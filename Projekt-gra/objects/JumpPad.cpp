//
// Created by UseR on 18.04.2024.
//
#include <iostream>
#include "jumpPad.h"
#include "../Player.h"



void JumpPad::collision(Player& player){
    player.setY(-2);
}

JumpPad::~JumpPad() = default;
