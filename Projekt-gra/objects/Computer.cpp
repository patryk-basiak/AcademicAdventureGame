//
// Created by UseR on 18.05.2024.
//

#include "Computer.h"
#include "fmt/core.h"
#include "../Settings.h"
#include <iostream>
#include <chrono>
#include <thread>

void Computer::collision(Player &player, sf::RenderWindow& window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}


void Computer::update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time time, sf::Time deltatime) {
    if(coll and type == 0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if(time.asSeconds() - lastUsed > 0.8) {
                if (inUse) {
                    movable = true;
                    inUse = false;
                } else {
                    movable = false;
                    inUse = true;
                }
            }
            lastUsed = time.asSeconds();
        }
    }if(coll and type == 1){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            if(time.asSeconds() - lastUsed > 0.8) {
                if (inUse) {
                    movable = true;
                    inUse = false;
                } else {
                    movable = false;
                    inUse = true;
                    pendriveInserted = true;
                }
            }
            lastUsed = time.asSeconds();
        }
    } if(inUse and type==1 and pendriveInserted) {
        sf::Vector2 mouse = sf::Mouse::getPosition(window);
        if (mouse.x > 300 and mouse.x < 1300 and mouse.y > 50 and mouse.y < 650) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                fmt::println("mouse x : {}", mouse.x);
                fmt::println("mouse y : {}", mouse.y);
            }
            if (mouse.x > 590 and mouse.x < 700 and mouse.y > 500 and mouse.y < 520) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and fileSelected and selection.getSize().x <= 10 and !fileAttached) {
                    fileClicked = true;
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and !fileClicked and !fileAttached) {
                fmt::println("i'm here");
                if (!positionSet) {
                    fmt::println("there");
                    initialPosX = mouse.x;
                    initialPosY = mouse.y;
                    selection.setPosition(initialPosX, initialPosY);
                    positionSet = true;
                }
                selection.setSize(sf::Vector2f(mouse.x - initialPosX, mouse.y - initialPosY));
            } else {
                positionSet = false;
                selection.setSize(sf::Vector2f(0, 0));
            }
        } else {
            positionSet = false;
            selection.setSize(sf::Vector2f(0, 0));
        }
        if (selection.getPosition().x < 590 and selection.getPosition().x + selection.getSize().x > 590 and
            selection.getPosition().y < 500 and selection.getPosition().y + selection.getSize().y > 500) {
            fileSelected = true;
        }
        if (fileClicked and !fileAttached) {
            fileMouse.setPosition(mouse.x,mouse.y);
            if(mouse.x > 431 and mouse.x < 774 and mouse.y >373 and mouse.y < 391){
                fileAttached = true;
            }
        }if(fileAttached){
            teams.setTexture(ResourceManager::getTexture("../graphics/assigmentTeamsEndingFileAttached.png"));
            if(mouse.x > 1063 and mouse.x < 1167 and mouse.y >94 and mouse.y < 120){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    inUse = false;
                }
            }
        }
    }

    if(inUse){
        player.hide();
    }
    else{
        player.showPlayer();
    }
    for(auto &e: icons){
        e->update(window);
    }
    coll = false;

}

void Computer::draw(sf::RenderWindow &window) {
    window.draw(computer);

}

bool Computer::getStatus() {
    return this->inUse;
}

Computer::~Computer() {

}

sf::Vector2<float> Computer::getPosition() {
    return this->computer.getPosition();
}

sf::Vector2<float> Computer::getSize() {
    return sf::Vector2<float>{size[0], size[1] };
}

void Computer::collisionRight(Player &player, sf::RenderWindow &window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}

void Computer::collisionLeft(Player &player, sf::RenderWindow &window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}

void Computer::collisionBottom(Player &player, sf::RenderWindow &window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}

void Computer::drawWindow(sf::RenderWindow &window) {
    if(inUse and type == 0){
        window.draw(screen);
        window.draw(wallpaper);
        for(auto &e: icons){
            e->draw(window);
        }
        for(auto &e: icons){
            if(e->isActive()){
                e->drawApp(window);
            }
        }
    }
    if(inUse and type==1){
        window.draw(screen);
        window.draw(wallpaper);
        if(pendriveInserted){
            window.draw(teams);
            window.draw(explorator);
            if(!fileClicked){
                window.draw(selection);
            }
            if(fileSelected){
                window.draw(Fileselection);
            }if(fileClicked and !fileAttached){
                window.draw(fileMouse);
            }
        }
    }
}
