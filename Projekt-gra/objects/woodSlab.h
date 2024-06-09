#include "Wall.h"
#include "../ResourceManager.h"

class WoodSlab
        :public Wall {

public:
    WoodSlab(float x, float y) : Wall(x,y){
        woodSlab.setPosition(x,y);
        woodSlab.setTexture(ResourceManager::getTexture("../graphics/woodenSlab.png"));
        float sizeX = (float)woodSlab.getTexture()->getSize().x;
        float sizeY = (float)woodSlab.getTexture()->getSize().y;
        woodSlab.setScale(64/sizeX, 32/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;
    void collisionBottom(Player& player, sf::RenderWindow &window) override;

private:
    sf::Sprite woodSlab;
    int id = 7;
};