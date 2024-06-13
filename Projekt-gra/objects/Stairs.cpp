
#include "Stairs.h"
#include "fmt/core.h"

void Stairs::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, stairs.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);

//    if(player.getPosition().x + player.getSize()[0] < stairs.getPosition().x + (stairs.getTexture()->getSize().x*stairs.getScale().x/2)){
//        player.setPosition(player.getPosition().x, stairs.getPosition().y - player.getSize()[1] - 0.18 + 32);
//        player.setVerticalVelocity(0);
//    }
//    if(player.getPosition().x + player.getSize()[0] > stairs.getPosition().x + (stairs.getTexture()->getSize().x*stairs.getScale().x/2)){
//        player.setPosition(player.getPosition().x, stairs.getPosition().y - player.getSize()[1] - 0.18);
//        player.setVerticalVelocity(0);
//    }
}

sf::Vector2<float> Stairs::getPosition() {
    return stairs.getPosition();
}

sf::Vector2<float> Stairs::getSize() {
    return sf::Vector2f {(float)stairs.getTexture()->getSize().x * stairs.getScale().x, (float)stairs.getTexture()->getSize().y * stairs.getScale().y};
}

void Stairs::update() {
    ;
}

void Stairs::draw(sf::RenderWindow &window) const {
    window.draw(stairs);
}
