#include "Equipment.h"
#include "fmt/ranges.h"
#include "objects/Pistol.h"
#include "Player.h"
#include "Settings.h"
#include "objects/Coin.h"
#include "objects/UniCard.h"
#include "objects/CarWinchItem.h"
#include "objects/Disk.h"
#include "objects/Shotgun.h"
#include "objects/AssultRiffle.h"
#include <algorithm>

std::vector<int> Equipment::eq;

Equipment::Equipment(){
    if (!this->font.loadFromFile("../graphics/arial.ttf")) {
        fmt::println("font loading error");
    }
    this->currentEq = 0;
    eqRect.setTexture(ResourceManager::getTexture("../graphics/shelf.png"));
    eqRect.setScale((float)300/eqRect.getTexture()->getSize().x,(float)300/eqRect.getTexture()->getSize().y);
    eqRect.setPosition(800 - (eqRect.getTexture()->getSize().x*eqRect.getScale().x/2),450 - (eqRect.getTexture()->getSize().x*eqRect.getScale().y/2));
    smallEq.setTexture(ResourceManager::getTexture("../graphics/eqImage.png"));
    smallEq.setScale((float)300/smallEq.getTexture()->getSize().x, (float)100/smallEq.getTexture()->getSize().y);
    smallEq.setPosition(800 - (300/2),900 - (100));
    pointer.setSize(sf::Vector2f(70,60));
    pointer.setPosition(680,835);
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



void Equipment::update(sf::RenderWindow& window, Player& player, sf::Time timer)  {
    Equipment::showInHand(player, window);
    if (!this->isShown and !finished and !items.empty()) {
        window.draw(smallEq);
        window.draw(pointer);
        float x = smallEq.getPosition().x + padding;
        float y = smallEq.getPosition().y + padding;
        for(int i = 0; i<3; ++i){
            auto temp = items.find(itemPos[i]);
            if(temp != items.end()){
                if ((*temp).second.first->isStackable() and (*temp).second.second > 1) {
                auto itemCount = sf::Text("000", font, 12);
                itemCount.setPosition({x + 20, y + 30});
                itemCount.setFillColor(sf::Color::Black);
                itemCount.setString(std::to_string((*temp).second.second));
                window.draw(itemCount);
            }
                temp_items.at(i)->setPosition(x,y);
                temp_items.at(i)->draw(window);
            x += 75.0f;
            }
        }
        if(timer.asSeconds() - lastOpen < 0.3 and timer.asSeconds() - lastOpen > 0.2){
            mousekeyListener = false;
        }
    } else if(isShown and !finished and !items.empty()) {
        lastOpen = timer.asSeconds();
        mousekeyListener = true;
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        window.draw(eqRect);
        float x = eqRect.getPosition().x + padding;
        float y = eqRect.getPosition().y + padding + 10;
        for(int i = 0; i<9; ++i){
            if(i < itemPos.size()) {
                auto temp = items.find(itemPos[i]);
                if (temp != items.end()) {
                    if ((*temp).second.first->isStackable() and (*temp).second.second > 1 and i != holding) {
                        auto itemCount = sf::Text("000", font, 12);
                        itemCount.setPosition({x + 20, y + 30});
                        itemCount.setFillColor(sf::Color::Black);
                        itemCount.setString(std::to_string((*temp).second.second));
                        window.draw(itemCount);
                    }
                    if ((!isHolding and !mouseClicked) or i != holding) {
                        temp_items.at(i)->setPosition(x, y);
                    } else {
                        temp_items.at(i)->setPosition(pos.x, pos.y);
                    }
                    temp_items.at(i)->draw(window);
                    if (i % 3 == 2 and i != 0) {
                        x = eqRect.getPosition().x + padding;
                        y += 90.0f;
                    } else {
                        x += 80.0f;
                    }

                }
            }
        }



                for (int i = 0; i <3 ; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if(pos.x >= eqRect.getPosition().x + j*80 and pos.x <= eqRect.getPosition().x + ((j+1)*80) and
                           pos.y >= eqRect.getPosition().y + i*90 and pos.y <= eqRect.getPosition().y + ((i+1)*90)){
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                if(timer.asSeconds() - lastClicked > 0.2) {
                                    lastClicked = timer.asSeconds();
                                    mouseClicked = true;
                                    if (!isHolding) {
                                        holding = j + (i * 3);
                                        isHolding = true;
                                    } else {
                                        if (j != holding and holding != 99) {
                                            if (j + (i * 3) >= temp_items.size()) {
                                                fmt::println("help");
                                                iter_swap(temp_items.begin() + holding, temp_items.end() - 1);
                                                iter_swap(itemPos.begin() + holding, itemPos.end() - 1);
                                                isHolding = false;
                                                holding = 99;
                                            } else if (temp_items.at(j + (i * 3)) != nullptr) {
                                                fmt::println("second {}{}", holding, j);
                                                iter_swap(temp_items.begin() + holding,
                                                          temp_items.begin() + (j + (i * 3)));
                                                iter_swap(itemPos.begin() + holding, itemPos.begin() + (j + (i * 3)));
                                                isHolding = false;
                                                holding = 99;
                                            }
                                        } else {
                                            fmt::println("last");
                                            holding = 99;
                                            isHolding = false;
                                        }

                                    }
                                } else {
                                    mouseClicked = false;
                                }
                            }
                        }
                    }
                }

        }

    }
void Equipment::showInHand(Player& player, sf::RenderWindow& window) const {
    if (!items.empty() && currentEq < items.size()  and player.isSeen()) {
        auto iterator = items.find(itemPos[currentEq]);
        auto& item = (*iterator).second.first;
        if (item == nullptr) {
            return;
        }
        if(player.getFacingRight()){
            item->setPosition(player.getPosition().x + 30, player.getPosition().y + (player.getSize()[1]/2) - 10);
        }
        else{
            item->setPosition(player.getPosition().x - 25, player.getPosition().y + (player.getSize()[1]/2) - 10);
        }
        item->draw(window);
        item->update(window, player);
        }
    }

void Equipment::movedMouse() {
    if(this->currentEq >=2){
        this->currentEq = 0;
        pointer.setPosition(680, 830);
    }else{
        this->currentEq += 1;
        pointer.setPosition(pointer.getPosition().x + 80, pointer.getPosition().y);
    }
}

void Equipment::movedMouseDown() {
    if(this->currentEq <= 0){
        pointer.setPosition(840, pointer.getPosition().y);
        this->currentEq = 2;
    }else{
        pointer.setPosition(pointer.getPosition().x - 80, pointer.getPosition().y);
        this->currentEq -= 1;
    }
}

void Equipment::addItem(int id) {
    fmt::println("item added id: {}", id);
    if (items.find(id) == items.end()) {
        isEmpty = false;
        if (id == 2) {
            std::unique_ptr<Collectable> pistol = std::make_unique<Pistol>(0, 0);
            items.insert({id, std::make_pair(std::move(pistol), 1)});
                temp_items.push_back(std::make_unique<Pistol>(0, 0));
        }
        if (id == 3) {
            items.insert({id, std::make_pair(std::make_unique<Coin>(0, 0), 1)});
                temp_items.push_back(std::make_unique<Coin>(0, 0));
        }
        if (id == 5) {
            items.insert({id, std::make_pair(std::make_unique<UniCard>(0, 0), 1)});
                temp_items.push_back(std::make_unique<UniCard>(0, 0));
        }
        if (id == 11) {
            items.insert({
                id, std::make_pair(std::make_unique<CarWinchItem>(0, 0), 1)});
                temp_items.push_back(std::make_unique<CarWinchItem>(0, 0));
        }if (id == 12) {
            items.insert({
                id, std::make_pair(std::make_unique<Shotgun>(0, 0), 1)});
                temp_items.push_back(std::make_unique<Shotgun>(0, 0));
        }if (id == 13) {
            items.insert({id, std::make_pair(std::make_unique<AssultRiffle>(0, 0), 1)});
            temp_items.push_back(std::make_unique<AssultRiffle>(0, 0));

        }if (id == 20) {
            items.insert({
                id, std::make_pair(std::make_unique<Disk>(0, 0), 1)});
            temp_items.push_back(std::make_unique<Disk>(0, 0));
        }
        itemPos.push_back(id);
    }
    else {
        auto iter = items.find(id);
            if ((*iter).second.first->isStackable()) {
                items.find(id)->second.second++;
            }
        }
}



void Equipment::useItemInHand(Player& player) {
    if (!items.empty()) {
        if(!mousekeyListener) {
            if (currentEq < itemPos.size() and !items.empty()) {
                auto iter = ((items.find(itemPos[currentEq])));
                if ((*items.find(itemPos[currentEq])).second.first->isOneTimeUse()) {
                    (*iter).second.first->usage(player);
                    auto it = std::find(items.begin(), items.end(), (*iter));
                    auto temp = (*iter).second.first->getId();
                    items.erase(temp);
                    auto xIt = std::find(itemPos.begin(), itemPos.end(), temp);
                    temp_items.erase(temp_items.begin() + currentEq);
                    itemPos.erase(xIt);
                } else {
                    (*iter).second.first->usage(player);
                }
            }
        }
    }
}
bool Equipment::getStatus() {
    return isEmpty;
}

int Equipment::getMoney() {
    auto x = items.find(3);
    if(x == items.end()){
        return 0;
    }else{
        return (*x).second.second;;
    }

}

void Equipment::setMoney(int n) {
    auto x = items.find(3);
    auto d = std::find(itemPos.begin(), itemPos.end(),3);
    if(x != items.end()){
        x->second.second = n;
    }
    if(x->second.second == 0){
        items.erase(x);
    }
}

bool Equipment::hasItem(int ID) {
    if (items.find(ID) == items.end()) {
        return false;
    }
    else{
        return true;
    }
}

std::vector<std::string> Equipment::getSave() {
        std::vector<std::string> saves;
        for (int itemPo : itemPos) {
            auto it = items.find(itemPo);
            if (it != items.end()) {
                std::string temp = std::to_string(it->second.first->getId());
                if (it->second.first->isStackable()) {
                    temp += "," + std::to_string(it->second.second);
                }
                saves.push_back(temp);
            } else {
                fmt::println("item save error");
            }
        }
        return saves;
    }



std::string Equipment::getItemInfo() {
    if (!items.empty() and currentEq < items.size()) {
        return items.find(itemPos[currentEq])->second.first->getInfo();
    }else{
        return "";
    }
}
void Equipment::clear() {
    items.clear();
    temp_items.clear();
    itemPos.clear();
}


