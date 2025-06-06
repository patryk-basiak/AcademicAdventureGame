#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
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
    bool getFacingRight();
    void setEndPosition();
    void isGroundCheck(bool boolean);
    void setVelocity(float i);
    void setVerticalVelocity(float i);

    int getStrength() const;
    int getIntelligence() const;
    int getLuck() const;

    bool isGround1() const;

    void setIsGround(bool isGround);

    int getAgile() const;
    int getEndurance() const;

    void setStrength(int strength);

    void setIntelligence(int intelligence);

    void setLuck(int luck);

    void setAgile(int agile);

    void setEndurance(int endurance);

    void hide();

    void showPlayer();

    bool isSeen();

private:
    sf::Clock clock;
    bool isShown = true;
    int strength = 3;
    int intelligence = 3;
    int luck = 3;
    int agile = 3;
    int damage = 1;
public:
    int getDamage() const;

private:
    int endurance = 3;
    float lastJumpTime = 0;
    float JumpCooldown = 1.2;
    int val= 0;
    int health = 3 + (endurance/3);
    float jumpVelocity = (float) -150 - ((float)(150*agile)/20);
    bool isGround = true;
    float surface = 1000;
    bool isFacingRight = true;
    float maxY = surface - 100;
    float speed = 200;
    float gravity = 200;
    float verticalVelocity = 5;
    bool inAir;
    bool game_started = false;
    std::vector<float> size;
    float velocity = 0;
    sf::Texture playerImgText = sf::Texture();
    sf::Sprite playerImgSpire = sf::Sprite();
    sf::Sprite player;
    sf::FloatRect collisionRect;
    std::vector<sf::Sprite> idleAnimation;
    std::vector<sf::Sprite> run;
    sf::Clock animation_clock;
    int currentTexture = 0;
    int currentTextureMove = 0;

};