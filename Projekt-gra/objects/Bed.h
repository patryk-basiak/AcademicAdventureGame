#pragma

#include "Wall.h"
#include "../ResourceManager.h"

class Bed
        : public Wall{

public:
    Bed(float x, float y) : Wall(x,y, 64,64, sf::Color{ 0, 191, 255, 255 }){
        bed.setPosition(x,y);
        bed.setScale(0.2,0.2);
        bed.setTexture(ResourceManager::getTexture("../graphics/bedsmaller.png"));
    }
    void draw(sf::RenderWindow& window) const override ;
    Bed(const Bed&) = delete;
    Bed& operator=(const Bed&) = delete;
    Bed(Bed&&) noexcept = default;
    Bed& operator=(Bed&&) noexcept = default;
    ~Bed() override;

    void collision(Player& player, sf::RenderWindow &window) override;

private:
    int id = 101;
    sf::Sprite bed;


};
