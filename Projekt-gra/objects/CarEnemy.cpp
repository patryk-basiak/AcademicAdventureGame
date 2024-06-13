//
// Created by UseR on 07.06.2024.
//

#include "CarEnemy.h"
void CarEnemy::draw(sf::RenderWindow &window) {
    window.draw(car);

}

sf::FloatRect CarEnemy::getGlobalBounds() {
    return car.getGlobalBounds();
}


void CarEnemy::collision(Player &player) {
    player.setHealth(player.getHealth() - 1);
}

sf::Vector2<float> CarEnemy::getPosition() {
    return car.getPosition();
}

sf::Vector2<float> CarEnemy::getSize() {
    return sf::Vector2f {(float)car.getTexture()->getSize().x * car.getScale().x, (float)car.getTexture()->getSize().y * car.getScale().y};
}

CarEnemy::~CarEnemy() = default;
void CarEnemy::update(sf::Time time, Player &player) {

    float deltaTime = time.asSeconds();

    horizontalVelocity += gravity * deltaTime;
    car.move(velocity * deltaTime, horizontalVelocity);
    if(car.getPosition().x < 50 - this->getSize().x){
        car.setPosition(1600, car.getPosition().y);
//        randomGraphic();
    }
}

void CarEnemy::setPosition(float d, float d1) {
    car.setPosition(d,d1);
}

void CarEnemy::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}

bool CarEnemy::diesOutsideScreen() {
    return false;
}

void CarEnemy::randomGraphic() {
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> carGrpahics(0, 2);
    int temp = carGrpahics(gen);
    if(temp == 0)
    {
        car.setTexture(ResourceManager::getTexture("../graphics/carEnemy0.png"));
        float sizeX = (float)car.getTexture()->getSize().x;
        float sizeY = (float)car.getTexture()->getSize().y;
        car.setScale(320/sizeX, 128/sizeY);
    }if(temp == 1)
    {
        car.setTexture(ResourceManager::getTexture("../graphics/carEnemy1.png"));
        float sizeX = (float)car.getTexture()->getSize().x;
        float sizeY = (float)car.getTexture()->getSize().y;
        car.setScale(256/sizeX, 64/sizeY);

    }if(temp == 2)
    {
        car.setTexture(ResourceManager::getTexture("../graphics/carEnemy2.png"));
        float sizeX = (float)car.getTexture()->getSize().x;
        float sizeY = (float)car.getTexture()->getSize().y;
        car.setScale(256/sizeX, 128/sizeY);
    }
}
