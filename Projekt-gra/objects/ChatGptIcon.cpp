//
// Created by UseR on 09.06.2024.
//

#include "ChatGptIcon.h"
#include <cmath>
#include "../ResourceManager.h"
#include "fmt/core.h"


void ChatGptIcon::draw(sf::RenderWindow &window) {
    window.draw(icon);

}

void ChatGptIcon::update(sf::RenderWindow &window) {
    sf::Vector2 vec = sf::Mouse::getPosition(window);
    if (std::pow(vec.x - centerX, 2) + std::pow(vec.y - centerY, 2) <= 4096) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            active = true;
        }
    }
    if (std::pow(vec.x - 1175, 2) + std::pow(vec.y - 125, 2) <= 800 and active) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            active = false;
        }
    }
    if (active) {
        for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) {
                if (!keyState[i]) {
                    keyState[i] = true;
                    if (inputString.size() < 100) {
                        if (i >= sf::Keyboard::A && i <= sf::Keyboard::Z) {
                            inputString += static_cast<char>(i - sf::Keyboard::A + 'a');
                        } else if (i >= sf::Keyboard::Num0 && i <= sf::Keyboard::Num9) {
                            inputString += static_cast<char>(i - sf::Keyboard::Num0 + '0');
                        } else if (i == sf::Keyboard::Space) {
                            inputString += ' ';
                        }
                        if (i == sf::Keyboard::BackSpace) {
                            if (!inputString.empty()) {
                                inputString.pop_back();
                            }
                        }
                        currentText.setString(inputString);
                    }

                }
                if (i == sf::Keyboard::Enter) {
                    answers.push_back(currentText);
                    inputString.clear();
                }
            } else {
                keyState[i] = false;
            }
        }
    }
}

void ChatGptIcon::collision() {

}

bool ChatGptIcon::isActive() {
    return active;
}

void ChatGptIcon::drawApp(sf::RenderWindow &window) {
    window.draw(this->windowScreen);
    window.draw(chat);
    if(answers.empty()){
        window.draw(currentText);
    }
    for(auto &e : answers){
        window.draw(e);
    }


}
