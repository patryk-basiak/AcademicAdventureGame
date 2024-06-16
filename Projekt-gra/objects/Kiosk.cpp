//
// Created by UseR on 04.06.2024.
//

#include "Kiosk.h"
#include "fmt/core.h"

sf::Vector2<float>  Kiosk::getSize()
{
    return sf::Vector2<float> {size[0], size[1]};
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

}

void Kiosk::update(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Time time, sf::Time deltatime)
{
    if (player.getPosition().x - kiosk.getPosition().x < 128 and
        player.getPosition().x - kiosk.getPosition().x > 0 and
        std::abs(player.getPosition().y - kiosk.getPosition().y) < 80 ) {
        active = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (time.asSeconds() - lastUsed > 0.5) {
                if (inUse) {
                    inUse = false;
                    mousekeyListener = false;
                } else {
                    inUse = true;
                    mousekeyListener = true;
                }
            }
            lastUsed = time.asSeconds();
        }
    } else {
        active = false;
    }
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    if(inUse){
        player.hide();
        auto it = price.begin();
        for(auto &item : items){
            float posX = item.first->getPosition().x;
            float sizeX = item.first->getSize().x;
            float posY = item.first->getPosition().y;
            float sizeY = item.first->getSize().x;
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (mouse.x > posX and mouse.x < posX + sizeX and mouse.y > posY and mouse.y < posY + sizeY) {
                    if(item.second.first <= eq.getMoney())
                    {
                        eq.setMoney(eq.getMoney() - item.second.first);
                        if(item.first->isOneTimeUse())
                        {
                            item.first->usage(player);
                        }
                        else
                        {
                            eq.addItem(item.first->getId());
                        }

                        items.erase(item.first);
                        price.erase(it);

                    }
                    else
                    {
                        fmt::println("not enough money");

                    }
                }
            }
            it++;
        }
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
            for(auto &e : price){
                window.draw(e);
            }
        }
    }
    if(active and !inUse) {
        window.draw(text);
    }
}

Kiosk::~Kiosk() = default;