//
// Created by UseR on 18.05.2024.
//

#include "Door.h"
#include "fmt/core.h"

void Door::collision(Player &player) {
    if(!isOpen){
        fmt::println("door is locked");
        player.setPosition(player.getPosition().x, jumpPad.getPosition().y - player.getSize()[1]);
        player.setVerticalVelocity(0);
    }
}

void Door::setStatus(bool status) {
    isOpen = status;
}

bool Door::status() const {
    return isOpen;
}

Door::~Door() =default;
