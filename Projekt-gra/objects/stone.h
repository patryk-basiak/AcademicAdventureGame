#include "Wall.h"
#include "../ResourceManager.h"
class Stone
        :public Wall {

public:
    Stone(float x, float y) : Wall(x,y){
        stone.setPosition(x,y);
        stone.setTexture(ResourceManager::getTexture("../graphics/stone.png"));
        float sizeX = (float)stone.getTexture()->getSize().x;
        float sizeY = (float)stone.getTexture()->getSize().y;
        stone.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite stone;
    int id = 9;
};