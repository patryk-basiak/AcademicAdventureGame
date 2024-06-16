//
// Created by UseR on 15/06/2024.
//

#include "End.h"
#include <cmath>
sf::Sprite End::end;
sf::Text End::time;
sf::Font  End::font;
sf::Clock End::clock;
float End::timeElapsed;
bool End::started;
void End::draw(sf::RenderWindow &window) {
    if(!started){
        clock.restart();
        started = true;
    }
    window.draw(end);
    window.draw(time);
    if(clock.getElapsedTime().asSeconds() > 4){
        std::exit(EXIT_SUCCESS);
    }
}

void End::setTime(float minutes, float seconds) {
    if(minutes > 0){
        time.setString("Minutes: " + std::to_string((int)std::round(minutes)) + " " + "Seconds: " + std::to_string((int)std::round(seconds)));
        time.setPosition(800 - (time.getCharacterSize()*time.getString().getSize()/4),450);
    }else{
        time.setString("Seconds: " + std::to_string((int)std::round(seconds)));
        time.setPosition(800 - (time.getCharacterSize()*time.getString().getSize()/4),450);
    }

}

