//
// Created by UseR on 04.06.2024.
//

#include "Kiosk.h"
#include "fmt/core.h"

std::vector<float> Kiosk::getSize()
{
    return size;
}

sf::Vector2<float> Kiosk::getPosition()
{
    return kiosk.getPosition();
}

bool Kiosk::getStatus()
{
    return inUse;
}

void Kiosk::collision(Player &player, sf::RenderWindow &window)
{
    if(!inUse) {
        window.draw(text);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (inUse) {
            movable = true;
            inUse = false;
        } else {
            movable = false;
            inUse = true;
        }
    }
}

void Kiosk::update(sf::RenderWindow &window, Player &player, Equipment &eq)
{
    if(inUse){
        player.hide();
    }
    else{
        player.showPlayer();
    }
}

void Kiosk::draw(sf::RenderWindow &window)
{
    window.draw(kiosk);
    if(inUse)
    {
        window.draw(tempInside);
        for(auto& item : items)
        {
            item.first->draw(window);
            window.draw(price);
        }
    }
}

Kiosk::~Kiosk() = default;