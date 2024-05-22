#include "Equipment.h"
#include "fmt/ranges.h"
#include "objects/Pistol.h"
#include "Player.h"
#include "Settings.h"
#include "objects/Coin.h"
#include "objects/UniCard.h"
#include <algorithm>

std::vector<int> Equipment::eq;

Equipment::Equipment(){
    if (!this->font.loadFromFile("../graphics/arial.ttf")) {
        fmt::println("font loading error");
    }
    this->currentEq = 0;
    eqRect.setSize(sf::Vector2f(220,220));
    eqRect.setPosition(800 - (eqRect.getSize().x/2),450 - (eqRect.getSize().y/2));
    eqRect.setFillColor({173,216,230,255});
    smallEq.setSize(sf::Vector2f(220,70));
    smallEq.setPosition(800 - (smallEq.getSize().x/2),900 - (smallEq.getSize().y));
    smallEq.setFillColor(sf::Color::Magenta);
    pointer.setSize(sf::Vector2f(70,50));
    pointer.setPosition(700,840);
    pointer.setOutlineColor(sf::Color::Black);
    pointer.setFillColor(sf::Color{0,0,0,0});
    pointer.setOutlineThickness(2);
}

void Equipment::show() {
    if(isShown){
        isShown = false;
        movable = true;
    }else {
        this->isShown = true;
        movable = false;
    }
}



void Equipment::update(sf::RenderWindow& window, Player& player)  {
    for(auto &e: temp_items){
        if(!e->getThrowable().empty()){
            throwable = e->getThrowable();
            fmt::println("eq");
        }
    }
    Equipment::showInHand(player, window);
    if (!this->isShown) {
        window.draw(smallEq);
        window.draw(pointer);
        float x = smallEq.getPosition().x + padding, y = smallEq.getPosition().y + padding;
        for (auto &item: items) { //TODO
            if (item.second.first->isStackable() and item.second.second > 1) {
                auto itemCount = sf::Text("000", font, 12);
                itemCount.setPosition({x + 20, y + 30});
                itemCount.setFillColor(sf::Color::Black);
                itemCount.setString(std::to_string(item.second.second));
                window.draw(itemCount);
            }
            item.second.first->setPosition(x,y);
            item.second.first->draw(window);
            x += 70.0f;
        }
    } else {
        window.draw(eqRect);
        float x = eqRect.getPosition().x + padding, y = eqRect.getPosition().y + padding;
        for (auto &item: items) {
            if (item.second.first->isStackable() and item.second.second > 1) {
                auto itemCount = sf::Text("0", font, 12);
                itemCount.setPosition({x + 20, y + 30});
                itemCount.setFillColor(sf::Color::Black);
                itemCount.setString(std::to_string(item.second.second));
                window.draw(itemCount);
            }
            fmt::println("{}",item.second.first->getPosition().x);
            item.second.first->setPosition(x,y);
            item.second.first->draw(window);
            x += 70.0f;
            if (y > 470) {
                x = 320;
                y += 70.0f;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {

                    if (pos.x >= 320 + (70 * i) && pos.x <= 380 + (70 * i) && pos.y >= 320 + (70 * j) &&
                        pos.y <= 380 + (70 * j)) {
                        if (j == 0) {
                            fmt::println("Kliknięto w pole: {}", i);
                        }
                        if (j == 1)
                            fmt::println("Kliknięto w pole: {}", i + j + 2);
                        if (j == 2) {
                            fmt::println("Kliknięto w pole: {}", i + j + 4);
                        }
                    }
                }


            }

        }

    }
}

int Equipment::itemInHand() const {
    if (!eq.empty()){
        return eq[currentEq];
    }
    return -1;
}
void Equipment::showInHand(Player& player, sf::RenderWindow& window) const {
    if (!items.empty() && currentEq < items.size() and player.isSeen()) {
        auto& item = temp_items.at(currentEq);
        if (item == nullptr) {
            return;
        }
        if(player.getFacingRight()){
            item->setPosition(player.getPosition().x + 25, player.getPosition().y + 5);
        }
        else{
            item->setPosition(player.getPosition().x - 25, player.getPosition().y + 5);
        }

        item->draw(window);
        item->update(window, player);


        }
    }

void Equipment::movedMouse() {
    this->currentEq += 1;
    pointer.setPosition(pointer.getPosition().x + 70, pointer.getPosition().y);
    if(this->currentEq >= 3){
        this->currentEq = 0;
        pointer.setPosition(700, 840);
    }
    if(pointer.getPosition().x < 700  or pointer.getPosition().x > 900){
        pointer.setPosition(700,840);
    }

}

void Equipment::movedMouseDown() {
    this->currentEq -= 1;
    pointer.setPosition(pointer.getPosition().x - 70, pointer.getPosition().y);
    if(this->currentEq < 0){
        pointer.setPosition(840, pointer.getPosition().y);
        this->currentEq = 3;
    }
    if(pointer.getPosition().x < 690 or pointer.getPosition().x > 900 ){
        pointer.setPosition(840, 840);
    }
}

void Equipment::addItem(const std::shared_ptr<Collectable>& itemPtr) {
    int id = itemPtr->getId();
    fmt::println("item added id: {}", id);
    if (items.find(itemPtr->getId()) == items.end()) {
        isEmpty = false;
        if (id == 2) {
            items.insert({id, {std::make_shared<Pistol>(0, 0), 1}});
            if (temp_items.size() < 3) {
                temp_items.push_back(std::make_unique<Pistol>(0, 0));
            }

        }
        if (id == 3) {
            items.insert({id, {std::make_shared<Coin>(0, 0), 1}});
            if (temp_items.size() < 3) {
                temp_items.push_back(std::make_unique<Coin>(0, 0));
            }
        }
        if (id == 5) {
            items.insert({id, {std::make_shared<UniCard>(0, 0), 1}});
            if (temp_items.size() < 3) {
                temp_items.push_back(std::make_unique<UniCard>(0, 0));
            }
        }
        std::ranges::reverse(temp_items);
    }
    else {
            if (itemPtr->isStackable()) {
                items.find(itemPtr->getId())->second.second++;
            }
        }
}



void Equipment::useItemInHand(Player& player) {
    if (!temp_items.empty()) {
        if(currentEq < temp_items.size()){
            this->temp_items[currentEq]->usage(player);
        }

    }
}

std::shared_ptr<Collectable> Equipment::getItemInHand() {
    if(currentEq < temp_items.size()){
        return temp_items[0];//TODO napraw to gowno
    }
    return temp_items[currentEq];
}

bool Equipment::getStatus() {
    return isEmpty;
}


