
#include "Elevator.h"
#include "fmt/core.h"

void Elevator::setStatus(bool status) {
    isOpen = status;
}

bool Elevator::status() const {
    return isOpen;
}

void Elevator::collisionLeft(Player &player, sf::RenderWindow &window) {

}

void Elevator::collisionRight(Player &player, sf::RenderWindow &window) {

}

sf::Vector2<float> Elevator::getSize() {
    return sf::Vector2f {(float)elevator.getTexture()->getSize().x * elevator.getScale().x, (float)elevator.getTexture()->getSize().y * elevator.getScale().y};
}

void Elevator::draw(sf::RenderWindow &window)  {
    window.draw(elevator);
    if(isActive and !blocked){
        window.draw(popUp);
    }
    if(isOpen and !blocked){
        window.draw(chooser);
        for(auto &e : floors){
            window.draw(e);
        }
    }
    if(isActive and !blocked){
        elevator.setTexture(ResourceManager::getTexture("../graphics/elevatorOpen.png"));
        elevator.setScale((float)128/elevator.getTexture()->getSize().x,(float)128/elevator.getTexture()->getSize().y);
    }if(!isActive or blocked){
        elevator.setTexture(ResourceManager::getTexture("../graphics/elevatorClosed.png"));
        elevator.setScale((float)128/elevator.getTexture()->getSize().x,(float)128/elevator.getTexture()->getSize().y);
    }
}

sf::Vector2<float> Elevator::getPosition() {
    return elevator.getPosition();
}

void Elevator::update(sf::RenderWindow &window, Player &player, Equipment &eq,  sf::Time deltatime, sf::Time Realdeltatime) {
    if(player.getPosition().x - elevator.getPosition().x < 128 and std::abs(player.getPosition().y - elevator.getPosition().y) < 80) {
        isActive = true;
        mousekeyListener = true;
        lastActive = deltatime.asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (deltatime.asSeconds() - lastUsed > 0.5) {
                if (isOpen) {
                    isOpen = false;
                } else {
                    isOpen = true;
                }
            }
            lastUsed = deltatime.asSeconds();
        }
    }
    else{
        isActive = false;

    }
    if(deltatime.asSeconds() - lastActive > 2 and deltatime.asSeconds() - lastActive < 3){
        mousekeyListener = false;
    }

    if(isOpen){
        sf::Vector2 mouse = sf::Mouse::getPosition(window);
        for (int i = 0; i < floors.size(); ++i) {
            pointer.setPosition(floors.at(i).getPosition().x, floors.at(i).getPosition().y + 20);
            if (mouse.x > floors.at(i).getPosition().x and mouse.x < floors.at(i).getPosition().x + 100 and
                mouse.y > floors.at(i).getPosition().y and mouse.y < floors.at(i).getPosition().y + 30) {
                window.draw(pointer);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if( 2 - i != val){
                        isOpen = false;
                        pickedTime = deltatime.asSeconds();
                        if(i == 0){
                            tempPositionY = 715;
//                            player.setPosition(player.getPosition().x, 715);
                        }
                        if(i == 1){
                            tempPositionY = 520;
//                            player.setPosition(player.getPosition().x, 520);
                        }if(i == 2){
                            tempPositionY = 270;
//                            player.setPosition(player.getPosition().x, 290);
                        }

                    }
                }
            }
        }
    }
    if(pickedTime != 0 and deltatime.asSeconds() - pickedTime < 2){
        player.hide();
        blocked = true;
        movable = false;
        mousekeyListener = true;
    }
    if(pickedTime != 0 and deltatime.asSeconds() - pickedTime > 2 and deltatime.asSeconds() - pickedTime < 3 ){
        player.setPosition(player.getPosition().x, tempPositionY);
        player.showPlayer();
        blocked = false;
        movable = true;
        mousekeyListener = false;
    }
}

Elevator::~Elevator() =default;
