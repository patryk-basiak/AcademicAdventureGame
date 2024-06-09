#pragma

#include "Wall.h"
#include "../ResourceManager.h"

class Bed
        : public Wall{

public:
    Bed(float x, float y) : Wall(x,y, 64,64, sf::Color{ 0, 191, 255, 255 }){
        bed.setPosition(x,y+32);
        bed.setTexture(ResourceManager::getTexture("../graphics/bedsmaller.png"));
        bed.setScale((float)80/bed.getTexture()->getSize().x,(float)32/bed.getTexture()->getSize().y);

    }

    void draw(sf::RenderWindow& window) const override ;
    void collision(Player& player, sf::RenderWindow &window) override ;
    void collisionRight(Player& player, sf::RenderWindow &window) override ;
    void collisionLeft(Player& player, sf::RenderWindow &window) override ;
    void collisionBottom(Player& player, sf::RenderWindow &window) override ;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    ~Bed() override;


private:
    int id = 101;
    sf::Sprite bed;


};
