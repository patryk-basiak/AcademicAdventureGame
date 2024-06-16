//
// Created by UseR on 16/06/2024.
//

#include "NPC.h"

#include "Npc.h"
#include "fmt/core.h"
#include "../ResourceManager.h"


sf::FloatRect NPC::getGlobalBounds() {
    return this->npc.getGlobalBounds();
}

void NPC::draw(sf::RenderWindow &window) {
    window.draw(this->npc);

}

void NPC::update(sf::Time time, Player& player) {
    float deltaTime = time.asSeconds();
    if (type == 0) {
        if (animation_clock.getElapsedTime().asSeconds() > 0.5) {
            if (currentTexture < 6) {
                currentTexture++;
            } else {
                currentTexture = 0;
            }
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/men/0/Idle" + std::to_string(currentTexture) + ".png"));
            animation_clock.restart();
        }
    }if(type == 1) {
        if (animation_clock.getElapsedTime().asSeconds() > 0.5) {
            if (currentTexture < 3) {
                currentTexture++;
            } else {
                currentTexture = 0;
            }
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/men/1/Idle" + std::to_string(currentTexture) + ".png"));
            animation_clock.restart();
        }

    }if(type == 2) {
        if (animation_clock.getElapsedTime().asSeconds() > 0.5) {
            if (currentTexture < 3) {
                currentTexture++;
            } else {
                currentTexture = 0;
            }
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/female/0/Idle" + std::to_string(currentTexture) + ".png"));
            animation_clock.restart();
        }

    }if(type == 3) {
        if (animation_clock.getElapsedTime().asSeconds() > 0.5) {
            if (currentTexture < 3) {
                currentTexture++;
            } else {
                currentTexture = 0;
            }
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/female/1/Idle" + std::to_string(currentTexture) + ".png"));
            animation_clock.restart();
        }

    }
    horizontalVelocity += gravity * deltaTime;
    npc.move(velocity * deltaTime, horizontalVelocity);
}

void NPC::collision(Player &player) {

}

sf::Vector2<float> NPC::getPosition() {
    return this->npc.getPosition();
}

sf::Vector2<float> NPC::getSize() {
    return sf::Vector2f ((float)npc.getTexture()->getSize().x, (float)npc.getTexture()->getSize().y);

}

void NPC::setPosition(float d, float d1) {
    this->npc.setPosition(d,d1);
}

NPC::~NPC() =default;

void NPC::setVerticalVelocity(int i) {
    horizontalVelocity=0;
}

bool NPC::isFriendly() {
    return friendly;
}

void NPC::setVelocity(int i) {
    velocity = i;
}

void NPC::setHealth(int i) {
    health = i;
}

int NPC::getHealth() {
    return health;
}

bool NPC::diesOutsideScreen() {
    return true;
}

