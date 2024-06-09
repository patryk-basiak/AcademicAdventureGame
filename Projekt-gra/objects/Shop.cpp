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
            window.draw(tryAgain);
            window.draw(info);
        }
        else {
            for (auto &vec: answers) {
                for (auto &letter: vec)
                    window.draw(letter);
            }
            for(auto & letter: textObjects){
                window.draw(letter);
            }
            window.draw(tryAgain);
            window.draw(info);
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

void Shop::update(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Time time, sf::Time deltatime) {
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
    if(type == 0) {
        if (hack and !HackingDone) {

            sf::Vector2 mouse = sf::Mouse::getPosition(window);
            if (mouse.x > info.getPosition().x and
                mouse.x < info.getPosition().x + (info.getTexture()->getSize().x * info.getScale().x)
                and mouse.y > info.getPosition().y and
                mouse.y < info.getPosition().y + (info.getTexture()->getSize().y * info.getScale().y)) {
                fmt::println("info clicked");
            }
            if (mouse.x > tryAgain.getPosition().x and
                mouse.x < tryAgain.getPosition().x + (tryAgain.getTexture()->getSize().x * tryAgain.getScale().x)
                and mouse.y > tryAgain.getPosition().y and
                mouse.y < tryAgain.getPosition().y + (tryAgain.getTexture()->getSize().y * tryAgain.getScale().y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    this->clear();
                }
            }
            keyboardInput = true;
            movable = false;
            if (xd == 0) {
                fmt::println("{}", word);
            }
            xd++;
            for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
                if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) {
                    if (!keyState[i]) {
                        keyState[i] = true;
                        if (textObjects.size() < 6 and answers.size() < 5) {
                            char newChar = '\0';
                            if (i >= sf::Keyboard::A && i <= sf::Keyboard::Z) {
                                newChar = static_cast<char>(i - sf::Keyboard::A + 'a');
                            }
                            if (newChar != '\0') {
                                sf::Text newText;
                                newText.setFont(Interactable::font);
                                newText.setString(newChar);
                                newText.setCharacterSize(24);
                                newText.setPosition(
                                        (HackInside.getPosition().x + 100) + (float) ((textObjects.size()) * 24),
                                        HackInside.getPosition().y + 100 + (float) ((answers.size()) * 24));
                                textObjects.push_back(newText);
                            }
                        }
                        if (i == sf::Keyboard::BackSpace) {
                            if (!textObjects.empty()) {
                                textObjects.pop_back();
                            }
                        }
                        if (textObjects.size() == 6 and !HackingDone) {
                            if (i == sf::Keyboard::Enter) {
                                int guessed = 0;
                                for (int x = 0; x < textObjects.size(); ++x) {
                                    auto it = std::find(word.begin(), word.end(), textObjects[x].getString());
                                    if (it != word.end()) {
                                        if (std::count(word.begin(), word.end(), textObjects[x].getString()) > 1) {
                                            for (int p = 0; p <= x; ++p) {
                                                std::string a = textObjects[p].getString();
                                                fmt::println("word: {}", word[p]);
                                                fmt::println("anserw: {}", a);
                                                fmt::println("looking for: {}", (*it));
                                                if (word[p] == (*it) && a == (*it)) {
                                                    fmt::println("hello");
                                                    textObjects[x].setFillColor(sf::Color::Green);
                                                    guessed++;
                                                }
                                                if (((word[p] != (*it) && a == (*it)) or
                                                     (word[p] == (*it) && a != (*it)))) {
                                                    textObjects[x].setFillColor(sf::Color::Yellow);
                                                }
                                            }

                                        } else if (std::count(word.begin(), word.end(), textObjects[x].getString()) ==
                                                   1) {
                                            if (x == std::distance(word.begin(), it)) {
                                                textObjects[x].setFillColor(sf::Color::Green);
                                                guessed++;

                                            } else {
                                                fmt::println("im here");
                                                textObjects[x].setFillColor(sf::Color::Yellow);
                                            }
                                        }
                                    }
                                }
                                answers.push_back(textObjects);
                                textObjects.clear();
                                fmt::println("{}", guessed);
                                if (guessed >= 6) {
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
        if (time.asSeconds() - HackDoneTime < 3 and HackDoneTime != 0) {
            showHackingDone = true;
        } else {
            showHackingDone = false;
        }
        sf::Vector2 mouse_1 = sf::Mouse::getPosition(window);
        if (isOpen) {
            player.hide();
            for (auto &item: itemsInside) {
                float posX = item.first->getPosition().x;
                float sizeX = item.first->getSize().x;
                float posY = item.first->getPosition().y;
                float sizeY = item.first->getSize().x;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (mouse_1.x > posX and mouse_1.x < posX + sizeX and mouse_1.y > posY and
                        mouse_1.y < posY + sizeY) {
                        if (item.second <= eq.getMoney()) {
                            eq.setMoney(eq.getMoney() - item.second);
                            {
                                eq.addItem(item.first->getId());
                            }

                            itemsInside.erase(item.first);
                        } else {
                            fmt::println("not enough money");

                        }
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

void Shop::clear() {
    answers.clear();
    textObjects.clear();
}

Shop::~Shop() = default;
