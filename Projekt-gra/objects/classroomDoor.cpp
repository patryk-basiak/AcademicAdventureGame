//
// Created by UseR on 09.06.2024.
//

#include "classroomDoor.h"
#include "fmt/core.h"


void ClassroomDoor::setStatus(bool status) {
    isOpen = status;
}

bool ClassroomDoor::status() const {
    return isOpen;
}

void ClassroomDoor::collisionLeft(Player &player, sf::RenderWindow &window) {

}

void ClassroomDoor::collisionRight(Player &player, sf::RenderWindow &window) {

}

sf::Vector2<float> ClassroomDoor::getSize() {
    return sf::Vector2f {(float)classroomDoor.getTexture()->getSize().x * classroomDoor.getScale().x, (float)classroomDoor.getTexture()->getSize().y * classroomDoor.getScale().y};
}

void ClassroomDoor::draw(sf::RenderWindow &window)  {
    window.draw(classroomDoor);
    if(isActive){
        window.draw(popUp);
    }
    if(isOpen){
        classroomDoor.setTexture(ResourceManager::getTexture("../graphics/classroomDoorOpen.png"));
        classroomDoor.setScale((float)192/classroomDoor.getTexture()->getSize().x,(float)140/classroomDoor.getTexture()->getSize().y);
    }if(!isOpen){
        classroomDoor.setTexture(ResourceManager::getTexture("../graphics/classroomDoorClosed.png"));
        classroomDoor.setScale((float)64/classroomDoor.getTexture()->getSize().x,(float)128/classroomDoor.getTexture()->getSize().y);
    }
    if(val == xRand){
        if(game){
            window.draw(gameRoom);
            window.draw(playerGame);
            for(auto const &e: boxesShapes){
                window.draw(e);
            }
            window.draw(endPoint);
        }
    }
}

sf::Vector2<float> ClassroomDoor::getPosition() {
    return classroomDoor.getPosition();
}

void ClassroomDoor::update(sf::RenderWindow &window, Player &player, Equipment &eq,  sf::Time deltatime, sf::Time realDeltaTime) {
    if (player.getPosition().x - classroomDoor.getPosition().x < 128 and
        player.getPosition().x - classroomDoor.getPosition().x > 0 and
        std::abs(player.getPosition().y - classroomDoor.getPosition().y) < 80) {
        isActive = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            fmt::println("hello");
            if (deltatime.asSeconds() - lastUsed > 0.5) {
                fmt::println("inside");
                if (isOpen) {
                    isOpen = false;
                    fmt::println("classroomDoor closed");
                } else {
                    isOpen = true;
                }
            }
            lastUsed = deltatime.asSeconds();
        }
    } else {
        isActive = false;
    }
    if (val == xRand) {
        if (isOpen) {
            game = true;
            isActive = false;
        }
        if (game) {
            player.hide();
            movable = false;
            keyboardInput = true;
            jumpable = false;
            mousekeyListener = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                playerGame.move(100 * realDeltaTime.asSeconds(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                playerGame.move(-100 * realDeltaTime.asSeconds(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                playerGame.move(0, -100 * realDeltaTime.asSeconds());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                playerGame.move(0, 100 * realDeltaTime.asSeconds());
            }
            // moving player
            if (playerGame.getPosition().x <= gameRoom.getPosition().x) {
                playerGame.setPosition(gameRoom.getPosition().x, playerGame.getPosition().y);
            }
            if (playerGame.getPosition().y <= gameRoom.getPosition().y) {
                playerGame.setPosition(playerGame.getPosition().x, gameRoom.getPosition().y);

            }
            if (playerGame.getPosition().x >= gameRoom.getPosition().x + gameRoom.getSize().x - 3) {
                playerGame.setPosition(gameRoom.getPosition().x + gameRoom.getSize().x - 3, playerGame.getPosition().y);

            }
            if (playerGame.getPosition().y >= gameRoom.getPosition().y + gameRoom.getSize().y - 3) {
                playerGame.setPosition(playerGame.getPosition().x, gameRoom.getPosition().y + gameRoom.getSize().y - 3);
            }
            for(auto &e: boxesShapes){
                if (playerGame.getPosition().x + playerGame.getSize().x > e.getPosition().x &&
                    playerGame.getPosition().x < e.getPosition().x + e.getSize().x &&
                    playerGame.getPosition().y + playerGame.getSize().y > e.getPosition().y &&
                    playerGame.getPosition().y < e.getPosition().y + e.getSize().y) {

                    float overlapRight = (playerGame.getPosition().x + playerGame.getSize().x) - e.getPosition().x;
                    float overlapLeft = (e.getPosition().x + e.getSize().x) - playerGame.getPosition().x;
                    float overlapBottom = (playerGame.getPosition().y + playerGame.getSize().y) - e.getPosition().y;
                    float overlapTop = (e.getPosition().y + e.getSize().y) - playerGame.getPosition().y;

                    // Determine the smallest overlap
                    float smallestOverlap = std::min({overlapRight, overlapLeft, overlapBottom, overlapTop});

                    if (smallestOverlap == overlapRight) {
                        // Collision right
                        playerGame.setPosition(e.getPosition().x - playerGame.getSize().x, playerGame.getPosition().y);
                    } else if (smallestOverlap == overlapLeft) {
                        // Collision left
                        playerGame.setPosition(e.getPosition().x + e.getSize().x, playerGame.getPosition().y);
                    } else if (smallestOverlap == overlapBottom) {
                        // Collision bottom
                        playerGame.setPosition(playerGame.getPosition().x, e.getPosition().y - playerGame.getSize().y);
                    } else if (smallestOverlap == overlapTop) {
                        // Collision top
                        playerGame.setPosition(playerGame.getPosition().x, e.getPosition().y + e.getSize().y);
                    }
                }
            }
            if (playerGame.getPosition().x + playerGame.getSize().x > endPoint.getPosition().x &&
                playerGame.getPosition().x < endPoint.getPosition().x + endPoint.getSize().x &&
                playerGame.getPosition().y + playerGame.getSize().y > endPoint.getPosition().y &&
                playerGame.getPosition().y < endPoint.getPosition().y + endPoint.getSize().y){
                game = false;
                isOpen = false;
                gameEnded = deltatime.asSeconds();
            }

        }
    }
    if(!game and gameEnded != 0 and deltatime.asSeconds() - gameEnded > 3 and deltatime.asSeconds() - gameEnded < 5){
        player.showPlayer();
        movable = true;
        keyboardInput = false;
        jumpable = true;
        mousekeyListener = false;
    }

}

void ClassroomDoor::generateMaze(int size) {
    boxes.resize(size, std::vector<int>(size, 1));
    for (int o = 1; o < size - 1; o += 2) {
        for (int k = 1; k < size - 1; k += 2) {
            boxes[o][k] = 0;

            if (o > 1 && k > 1) {
                if (std::rand() % 2 == 0) {
                    boxes[o - 1][k] = 0;
                } else {
                    boxes[o][k - 1] = 0;
                }
            } else if (o > 1) {
                boxes[o - 1][k] = 0;
            } else if (k > 1) {
                boxes[o][k - 1] = 0;
            }
        }
    }
}


ClassroomDoor::~ClassroomDoor() =default;
