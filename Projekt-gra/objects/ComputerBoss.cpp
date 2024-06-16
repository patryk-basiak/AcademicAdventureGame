//
// Created by UseR on 10.06.2024.
//

#include "ComputerBoss.h"

#include <cmath>
#include "fmt/core.h"

#include "../ThrowableContainer.h"

void ComputerBoss::draw(sf::RenderWindow &window) {
    window.draw(computer);
//    if(health != 3){
    window.draw(healthLine);
//    }
}

sf::FloatRect ComputerBoss::getGlobalBounds() {
    return computer.getGlobalBounds();
}


void ComputerBoss::collision(Player &player) {
    player.setHealth(player.getHealth() - 1);
    computer.setPosition(computer.getPosition().x + 10, computer.getPosition().y);

}

sf::Vector2<float> ComputerBoss::getPosition() {
    return computer.getPosition();
}

sf::Vector2<float> ComputerBoss::getSize() {
    return sf::Vector2f {computer.getTexture()->getSize().x*computer.getScale().x,computer.getTexture()->getSize().y*computer.getScale().y };
}

ComputerBoss::~ComputerBoss() = default;


void ComputerBoss::update(sf::Time time, Player &player) {

    healthLine.setSize(sf::Vector2f (part * health, healthLine.getSize().y));
    healthLine.setPosition(computer.getPosition().x, computer.getPosition().y - 15);

    if(addMoney and health > 3 and health %3 ==0) {
        int temp = sign(gen);
        if (temp == -1) {
            ThrowableContainer::addItem(3, computer.getPosition().x - (float) coinPos(gen),
                                        computer.getPosition().y + (float) coinPosY(gen));

        }
        if (temp == 1) {
            ThrowableContainer::addItem(3, computer.getPosition().x + this->getSize().x + (float) coinPos(gen),
                                        computer.getPosition().y + (float) coinPosY(gen));
        }
        int nextTemp = coinPos(gen);
        if (nextTemp < 40) {
            ThrowableContainer::addItemEntity(7, computer.getPosition().x, computer.getPosition().y, 4);
        }
        addMoney = false;
    }if(health % 2 == 1 and bulletSpawn){
        int temp = sign(gen);
        int amount = bulletAmount(gen);
        if(temp == -1){
            for(int i = 0; i<amount + (std::abs(30 - health)/5); ++i)
                ThrowableContainer::addItem(4, computer.getPosition().x - 25, computer.getPosition().y + bulletPosY(gen) ,-1);
        }if(temp == 1){
            for(int i = 0; i<amount + (std::abs(30 - health)/5); ++i)
                ThrowableContainer::addItem(4, computer.getPosition().x + this->getSize().x, computer.getPosition().y + bulletPosY(gen) ,1);
        }
        bulletSpawn = false;
    }
}

void ComputerBoss::setPosition(float d, float d1) {
    computer.setPosition(d,d1);
}

void ComputerBoss::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}

void ComputerBoss::setVelocity(int i) {
//    velocity = i;
}

void ComputerBoss::setHealth(int i) {
    health = i;
    addMoney = true;
    bulletSpawn = true;

}

int ComputerBoss::getHealth() {
    return health;
}
