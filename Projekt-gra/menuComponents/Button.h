#pragma once
#include <functional>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "../ResourceManager.h"
#include "fmt/ostream.h"

enum types {
    Circle, Box
};


class Button {
    public:
    Button(float const x, float const y, const types type, std::string  const& string){
        posx = x;
        posy = y;
        if (type == Circle) {
            sprite.setTexture(ResourceManager::getTexture("../graphics/point.png"));
        }else if (type == Box) {
            sprite.setTexture(ResourceManager::getTexture("../graphics/box.png"));
        }
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }
        sprite.setScale( 0.2, 0.2 ); //TODO edit
        text.setFont(font);
        text.setString(string);
        text.setPosition(posx+posx/2, posy+posy/2);


    };
    void draw(sf::RenderWindow &window);


private:
    float posx;
    float posy;
    sf::Text text;
    sf::Font font;
    sf::Sprite sprite;
};


