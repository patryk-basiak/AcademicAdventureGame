//
// Created by UseR on 07.06.2024.
//

#include "CarWinch.h"
#include "fmt/core.h"
#include "Car.h"

void CarWinch::draw(sf::RenderWindow &window) {
    window.draw(winch);
    if(active){
        window.draw(popUp);
    }
    if(isPicked or run){
        window.draw(line);
    }
    if(possibleToAttached){
        window.draw(attach);
    }

}

sf::Vector2<float> CarWinch::getPosition() {
    return winch.getPosition();
}

sf::Vector2<float> CarWinch::getSize() {
    return sf::Vector2<float>{(float) winch.getTexture()->getSize().x*winch.getScale().x, (float) winch.getTexture()->getSize().y*winch.getScale().y};
}

void CarWinch::update(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Time time) {
    if (player.getPosition().x - winch.getPosition().x < 40 and player.getPosition().x - winch.getPosition().x > 0 and
        std::abs(player.getPosition().y - winch.getPosition().y) < 40) {
        active = true;
    } else {
        active = false;
    }
    if (active) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            line.setPosition(winch.getPosition().x + (player.getSize()[0]), winch.getPosition().y);
            if (isPicked) {
                isPicked = false;
                jumpable = true;
            } else {
                isPicked = true;
                jumpable = false;
            }
        }
    }
    if (isPicked and !isAttached) {
        line.setSize(sf::Vector2f(player.getPosition().x - line.getPosition().x + player.getSize()[0], line.getSize().y));
        if (player.getPosition().x > 1300) {
            attach.setPosition(player.getPosition().x, player.getPosition().y - 15);
            possibleToAttached = true;
        } else {
            possibleToAttached = false;
        }
    }
    if (possibleToAttached) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            isAttached = true;
            possibleToAttached = false;
        }
    }
    if (isAttached) {
        jumpable = true;
        popUp.setString("Press F to start");
        if (player.getPosition().x - winch.getPosition().x < 40 and
            player.getPosition().x - winch.getPosition().x > 0 and
            std::abs(player.getPosition().y - winch.getPosition().y) < 40) {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
                run = true;

            }

        }
    }
    if (run) {
        if(line.getSize().x > 10) {
            line.setSize(
                    sf::Vector2f{static_cast<float>(line.getSize().x - 0.03),
                                 line.getSize().y}); //TODO DELTATIME\

        }else{
            run = false;
        }

    }
}


void CarWinch::collision(Player &player, sf::RenderWindow &window) {

}

bool CarWinch::getStatus() {
    return isPlaced;
}

void CarWinch::check(std::unique_ptr<Wall> &wall) {
    if (Car *car = dynamic_cast<Car *>(wall.get())) {
        fmt::println("car:{} line:{}", car->getPosition().x, line.getPosition().x);
        if(car->getPosition().x - (line.getPosition().x + line.getSize().x) < 75 and run and line.getSize().x > 10){
            car->setPosition(car->getPosition().x - 0.03, car->getPosition().y);
        }
    }
}

CarWinch::~CarWinch() = default;