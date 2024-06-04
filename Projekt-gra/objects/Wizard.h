#pragma once

#include "Entity.h"
#include "../ResourceManager.h"

class Wizard
        : public Entity {
public: Wizard(float x, float y): Entity(x, y, sf::Color::Black){
    wizard.setTexture(ResourceManager::getTexture("../graphics/wizard.png"));
    wizard.setScale(0.24,0.24);
    wizard.setPosition(x,y);
}
public:
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getGlobalBounds()override;
    void update(sf::Time time, Player& player)override;
    void collision(Player& player)override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~Wizard() override;
    bool isFriendly() override;
    void setPosition(float d, float d1) override;
    void setVerticalVelocity(int i) override;

private:
    int id = 4;
    sf::Sprite wizard;
    bool friendly = true;



};
