#include "Wall.h"
#include "../ResourceManager.h"

class Street
        :public Wall {

public:
    Street(float x, float y) : Wall(x,y){
        street.setPosition(x,y);
        street.setTexture(ResourceManager::getTexture("../graphics/street.png"));
        float sizeX = (float)street.getTexture()->getSize().x;
        float sizeY = (float)street.getTexture()->getSize().y;
        street.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite street;
    int id = 8;
};