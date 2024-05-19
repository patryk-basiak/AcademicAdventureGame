#pragma once
#include "SFML/Graphics.hpp"

class Player {

public:
    Player();
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
    void setX(float x);
    void setY(float y);
    sf::FloatRect getGlobalBounds();
    void jump();
    void move(float x, float y);
    void update(sf::Time time);
    float getSurface() const;
    int getHealth() const;
    void setHealth(int n);
    void setSurface(float x);
//    void itemInHand(Collectable& collactable);
    sf::Vector2f getPosition();
    const std::vector<float> &getSize();

    void setStartPosition();

    void setEndPosition();
    void isGroundCheck(bool boolean);
    void setVelocity(float i);
    void setVerticalVelocity(float i);


private:
    int val= 0;
    int health = 3;
    float jumpVelocity = -100;
    bool died = false;
    bool isGround = true;
    float surface = 800;
    bool isFacingRight = true;
    float maxY = surface - 100;
    float speed = 200;
    float gravity = 200;
    float verticalVelocity = 5;
    bool inAir;
    std::vector<float> size;
    float velocity = 0;
    sf::Texture playerImgText = sf::Texture();
    sf::Sprite playerImgSpire = sf::Sprite();
    sf::Sprite player;
    sf::FloatRect collisionRect;


};