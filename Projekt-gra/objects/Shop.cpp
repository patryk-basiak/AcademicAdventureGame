//
// Created by UseR on 05.06.2024.
//

#include "Shop.h"
#include "fmt/core.h"

void Shop::draw(sf::RenderWindow &window) {
    window.draw(shop);
    if(!isOpen and active and (!tried or HackingDone)){
        window.draw(popUp);
    }
    if(isOpen){
        window.draw(inside);
        for(auto& item : itemsInside)
        {
            item.first->draw(window);
        }
    }
    if(closed and tried and !HackingDone){
        window.draw(closedPopUp);
        window.draw(hacked);
    }
    if(hack and !HackingDone){
        window.draw(HackInside);
        window.draw(title);
        if(answers.empty()){
            for(auto & letter: textObjects){
                window.draw(letter);
            }
        }
        else {
            for (auto &vec: answers) {
                for (auto &letter: vec)
                    window.draw(letter);
            }
            for(auto & letter: textObjects){
                window.draw(letter);
            }
        }

    }
    if(HackingDone and showHackingDone){
        window.draw(HackInside);
        window.draw(title);
        for( auto& vec: answers){
            for(auto & letter: vec)
                window.draw(letter);
        }
        window.draw(HackingDoneText);
    }
}

sf::Vector2<float> Shop::getPosition() {
    return shop.getPosition();
}

sf::Vector2<float> Shop::getSize() {
    return sf::Vector2<float>{(float)shop.getTexture()->getSize().x*shop.getScale().x, (float)128/shop.getTexture()->getSize().y*shop.getScale().y};
}

void Shop::update(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Time time) {
    if (player.getPosition().x - shop.getPosition().x > 0 and player.getPosition().x - shop.getPosition().x < 128 and
        std::abs(player.getPosition().y - shop.getPosition().y) < 80) {
        active = true;
    } else {
        active = false;
    }
    if (active) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (time.asSeconds() - lastUsed > 0.5) {
                if (!closed) {
                    if (isOpen) {
                        isOpen = false;
                        player.showPlayer();
                        movable = true;
                    } else {
                        isOpen = true;
                        player.hide();
                        movable = false;
                    }
                    lastUsed = time.asSeconds();
                } else {
                    tried = true;
                }
            }
        }
        if (closed and tried) {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) {
                if (time.asSeconds() - lastUsed > 3) {
                    if (!hack) {
                        hack = true;
                        player.hide();
                        movable = false;
                        blocked = true;
                    } else {
                        if (!blocked) {
                            hack = false;
                            player.showPlayer();
                            movable = true;
                        }

                    }
                    lastUsed = time.asSeconds();
                }
            }
        }
    }
    if (type == 0 and hack and !HackingDone) {
        keyboardInput = true;
        player.hide();
        movable = false;
        fmt::println("{}", word);
        for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) {
                if (!keyState[i]) {
                    keyState[i] = true;
                    fmt::println("{}", textObjects.size());
                    if (textObjects.size() < 6) {
                        char newChar = '\0';
                        if (i >= sf::Keyboard::A && i <= sf::Keyboard::Z) {
                            newChar = static_cast<char>(i - sf::Keyboard::A + 'a');
                        }
                        if(newChar != '\0'){
                        sf::Text newText;
                        newText.setFont(Interactable::font);
                        newText.setString(newChar);
                        newText.setCharacterSize(24);
                        newText.setPosition((HackInside.getPosition().x + 100) + (float)((textObjects.size())*24),HackInside.getPosition().y + 100  + (float)((answers.size())*24));
                        textObjects.push_back(newText);
                    }
                    }
                    if (i == sf::Keyboard::BackSpace) {
                        if (!textObjects.empty()) {
                            textObjects.pop_back();
                        }
                    }
                    if(textObjects.size() == 6 and !HackingDone){
                        if(i == sf::Keyboard::Enter){
                            int guessed = 0;
                            std::vector<std::string> temp;
                            for(int x = 0; x <textObjects.size(); ++x){
                                temp.push_back(textObjects[x].getString());
                                auto it = std::find(word.begin(),word.end(), textObjects[x].getString());
                                if(it != word.end()){
                                    if(std::count(word.begin(), word.end(),textObjects[x].getString()) > 1){
                                        std::vector<int> indices;
                                        std::vector<int> indicesN;
                                        for (int j = 0; j < word.size(); ++j) {
                                            if (word[j] == textObjects[x].getString()) {
                                                indices.push_back(j);
                                            }
                                        }for (int j = 0; j < textObjects.size(); ++j) {
                                            if (textObjects[j].getString() == textObjects[x].getString()) {
                                                indices.push_back(j);
                                            }
                                        }
                                        for(int d = 0; d < word.size(); ++d){
                                            if(indices[d] == indicesN[d]){
                                                textObjects[d].setFillColor(sf::Color::Green);
                                                guessed++;
                                            }
                                            else{
                                                textObjects[d].setFillColor(sf::Color::Yellow);
                                            }
                                        }
                                    }
                                    else if(std::count(word.begin(), word.end(),textObjects[x].getString()) == 1) {
                                        if (x == std::distance(word.begin(), it)) {
                                            textObjects[x].setFillColor(sf::Color::Green);
                                            guessed++;

                                        }
                                        else{
                                            textObjects[x].setFillColor(sf::Color::Yellow);
                                        }
                                }
                                    else{
                                        textObjects[x].setFillColor(sf::Color::Yellow);
                                    }
                                }
                            }
                            answers.push_back(textObjects);
                            textObjects.clear();
                            fmt::println("{}", guessed);
                            if(guessed == 6){
                                HackingDone = true;
                                keyboardInput = false;
                                player.showPlayer();
                                HackDoneTime = time.asSeconds();
                                movable = true;
                                closed = false;
                            }
                        }
                    }
                }
            } else {
                keyState[i] = false;
            }
        }
    }
    if(time.asSeconds() - HackDoneTime < 3 and HackDoneTime != 0){
        showHackingDone = true;
    }else{
        showHackingDone = false;
    }
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    if(isOpen){
        player.hide();
        for(auto &item : itemsInside){
            float posX = item.first->getPosition().x;
            float sizeX = item.first->getSize().x;
            float posY = item.first->getPosition().y;
            float sizeY = item.first->getSize().x;
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (mouse.x > posX and mouse.x < posX + sizeX and mouse.y > posY and mouse.y < posY + sizeY) {
                    if(item.second <= eq.getMoney())
                    {
                        eq.setMoney(eq.getMoney() - item.second);
                        if(item.first->isOneTimeUse())
                        {
                            item.first->usage(player);
                        }
                        else
                        {
                            eq.addItem(item.first->getId());
                        }

                        itemsInside.erase(item.first);
                    }
                    else
                    {
                        fmt::println("not enough money");

                    }
                }
            }
        }
    }
    else{
        player.showPlayer();
    }
}

void Shop::collision(Player &player, sf::RenderWindow &window) {

}

bool Shop::getStatus() {
    return isOpen;
}

Shop::~Shop() = default;
