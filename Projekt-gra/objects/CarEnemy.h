
#include <random>
#include "Entity.h"
#include "../ResourceManager.h"
#include "fmt/core.h"

class CarEnemy
        : public Entity{

public :CarEnemy(float x, float y) : Entity(x, y, sf::Color::Black) {
        fmt::println("car created");
        car.setPosition(x, y);
        randomGraphic();
        initialPositionX = x;
        initialPositionY = y;
        velocity = -200; //TODO
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
    bool diesOutsideScreen() override;


private:
    void randomGraphic();
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
