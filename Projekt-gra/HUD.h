#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "Equipment.h"
#include "fmt/core.h"

class HUD {

public:
    HUD(){
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }
        mission.setPosition(800,100);
        mission.setFont(font);
        mission.setString("Mission:");
        mission.setCharacterSize(30);
    }

    void draw(sf::RenderWindow& window, Equipment& eq, Player& player);
    void update(Player& player);


    void showDebug();

    void hideDebug();

private:
    sf::Font font;
    sf::Text mission;
};
