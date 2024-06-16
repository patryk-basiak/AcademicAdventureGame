#pragma once

#include <random>
#include "Entity.h"
#include "../ResourceManager.h"

class NPC
        : public Entity{
public:
    NPC(float x, float y) : Entity(x,y) {
        npc.setPosition(x,y);
        gen =  std::mt19937(rd());
        genType = std::uniform_int_distribution<>(0,3);
        type = genType(gen);
        if(type == 0) {
            genTexturePos = std::uniform_int_distribution<>(0,6);
            currentTexture = genTexturePos(gen);
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/men/0/Idle" + std::to_string(currentTexture) + ".png"));
            for(int i = 0; i<7; ++i){
                sf::Sprite temp;
                temp.setTexture(ResourceManager::getTexture(
                        "../graphics/npc/men/0/Idle" + std::to_string(i) + ".png"));
                npc_images.push_back(temp);
            }
        }if(type == 1) {
            genTexturePos = std::uniform_int_distribution<>(0,3);
            currentTexture = 0;
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/men/1/Idle" + std::to_string(currentTexture) + ".png"));
            for(int i = 0; i<3; ++i){
                sf::Sprite temp;
                temp.setTexture(ResourceManager::getTexture(
                        "../graphics/npc/men/1/Idle" + std::to_string(i) + ".png"));
                npc_images.push_back(temp);
            }
        }if(type == 2) {
            genTexturePos = std::uniform_int_distribution<>(0,3);
            currentTexture = 0;
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/female/0/Idle" + std::to_string(currentTexture) + ".png"));
            for(int i = 0; i<3; ++i){
                sf::Sprite temp;
                temp.setTexture(ResourceManager::getTexture(
                        "../graphics/npc/female/0/Idle" + std::to_string(i) + ".png"));
                npc_images.push_back(temp);
            }
        }if(type == 3) {
            genTexturePos = std::uniform_int_distribution<>(0,3);
            currentTexture = 0;
            npc.setTexture(ResourceManager::getTexture(
                    "../graphics/npc/female/1/Idle" + std::to_string(currentTexture) + ".png"));
            for(int i = 0; i<3; ++i){
                sf::Sprite temp;
                temp.setTexture(ResourceManager::getTexture(
                        "../graphics/npc/female/1/Idle" + std::to_string(i) + ".png"));
                npc_images.push_back(temp);
            }
        }

    }
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds();
    void update(sf::Time time, Player& player);
    void collision(Player& player);
    sf::Vector2<float> getPosition();
    sf::Vector2<float> getSize() override;

    ~NPC();

    void setPosition(float d, float d1) override;
    bool isFriendly() override;
    void setVerticalVelocity(int i) override;
    void setVelocity(int i) override;
    void setHealth(int i) override;
    int getHealth() override;
    bool diesOutsideScreen() override;

private:

    int health = 1;
    float velocity = 0;
    float VerticalVelocity = 0;
    sf::RectangleShape entity;
    sf::Vector2<float> startPosition;
    bool toRight = true;
    bool friendly = true;
    sf::Clock animation_clock;
    sf::Sprite npc;
    std::vector<sf::Sprite> npc_images;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> genType;
    std::uniform_int_distribution<> genTexturePos;
    int type;
    float gravity = 50;
    float horizontalVelocity;
    int currentTexture;
};


