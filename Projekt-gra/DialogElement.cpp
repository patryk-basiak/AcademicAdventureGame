//
// Created by UseR on 19.05.2024.
//

#include "DialogElement.h"
#include "fmt/core.h"

#include <utility>

DialogElement::DialogElement(std::string sentces) {
    Sentences = std::move(sentces);
    if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
        fmt::println("font loading error");
    }
    message.setFont(font);
    message.setFillColor(sf::Color::Black);
    message.setPosition(0,0);
    message.setCharacterSize(15);
    base.setSize(sf::Vector2f(100,Sentences.size()*2));;
    base.setFillColor(sf::Color::White);
    base.setPosition(0,0);

}

void DialogElement::draw(sf::RenderWindow &window)  {
//    fmt::println("help");
    window.draw(base);
    window.draw(message);

}

void DialogElement::update(Player &player) {
    message.setString(Sentences);
    message.setPosition(player.getPosition().x, player.getPosition().y - 50);
    base.setPosition(player.getPosition().x, player.getPosition().y - 50);
}

void DialogElement::setPosition(float x, float y) {

}

void DialogElement::setText(std::string text) {
    Sentences =std::move(text);
    base.setSize(sf::Vector2f(150,Sentences.size()));;

}
