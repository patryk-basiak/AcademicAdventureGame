//
// Created by UseR on 18.04.2024.
//
#include <iostream>
#include "jumpPad.h"
#include "../Player.h"
#include "fmt/core.h"


void JumpPad::collision(Player& player){
    fmt::println("collision with jumpad");
}

JumpPad::~JumpPad() = default;
