
#include <random>
#include "Entity.h"
#include "../ResourceManager.h"
#include "fmt/core.h"

class CarEnemy
        : public Entity{

public :CarEnemy(float x, float y) : Entity(x, y, sf::Color::Black) {
        fmt::println("car created");
        car.setPosition(x, y);
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




        initialPositionX = x;
        initialPositionY = y;
        velocity = -100; //TODO
        health = 100;
        horizontalVelocity = 0;
    }


public:
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getGlobalBounds()override;
    void update(sf::Time time, Player& player)override;
    void collision(Player& player)override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~CarEnemy() override;
    void setPosition(float d, float d1);
    void setVerticalVelocity(int i) override;


private:
    int id =5;
    bool followingPlayer = false;
    float gravity = 50;
    int health;
    sf::Sprite car;
    float velocity;
    float horizontalVelocity;
    float initialPositionX;
    float initialPositionY;

};
