#pragma once

#include <random>
#include "../ResourceManager.h"
#include "Interactable.h"
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <vector>
#include <cstdlib>
#include <ctime>
static bool initialized  = false;
static int random_type;
static int number = 0;
class ClassroomDoor
        : public Interactable{

public:
    ClassroomDoor(float x, float y) : Interactable(x,y){
        fmt::println("classRoomCreated");
        rand();
        std::random_device rd;
        std::mt19937 gen(rd());
        val = number++;
        xRand= random_type;
        classroomDoor.setTexture(ResourceManager::getTexture("../graphics/classroomDoorClosed.png"));
        classroomDoor.setPosition(x,y);
        classroomDoor.setScale((float)64/classroomDoor.getTexture()->getSize().x,(float)128/classroomDoor.getTexture()->getSize().y);
        popUp.setString("Press F to open door");
        popUp.setFont(Interactable::font);
        popUp.setPosition(classroomDoor.getPosition().x, classroomDoor.getPosition().y - (classroomDoor.getTexture()->getSize().y*classroomDoor.getScale().y/3));
        if(val != random_type){

            std::uniform_int_distribution<> roomType(0, 5);
            type = roomType(gen);
        }else{
            type = val;
            fmt::println("random //////");
            gameRoom.setSize(sf::Vector2f (350,350));
            gameRoom.setPosition(classroomDoor.getPosition().x + (this->getSize().x/2) - (gameRoom.getSize().x/2), classroomDoor.getPosition().y + (this->getSize().x/y) - (gameRoom.getSize().y/2));
            gameRoom.setFillColor(sf::Color::Black);
            gameRoom.setOutlineColor(sf::Color::Yellow);
            gameRoom.setOutlineThickness(3);
            playerGame.setFillColor(sf::Color::Green);
            playerGame.setSize(sf::Vector2f (8,8));
            playerGame.setPosition(gameRoom.getPosition().x+10, gameRoom.getPosition().y+10);
            endPoint.setFillColor(sf::Color::Blue);
            endPoint.setPosition(gameRoom.getPosition().x + gameRoom.getSize().x - 20, gameRoom.getPosition().y + gameRoom.getSize().y - 20);
            endPoint.setSize(sf::Vector2f (8,8));
            std::uniform_int_distribution<> randXom(0, 100);
            boxes.resize(35, std::vector<int>(35,1));
            srand(time(0));
            generateMaze(35);
            int startingPosx = gameRoom.getPosition().x;
            int startingPosy = gameRoom.getPosition().y;
            for(int i = 0; i<boxes.size(); ++i){
                startingPosx = gameRoom.getPosition().x;
                for(int j = 0; j<boxes.at(0).size(); j++){
                    if(boxes[i][j] == 1){
                        sf::RectangleShape temp;
                        temp.setSize(sf::Vector2f (10,10));
                        temp.setPosition(startingPosx, startingPosy);
                        temp.setFillColor(sf::Color::Red);
                        boxesShapes.push_back(temp);
                    }
                    startingPosx += 10;
                }
                startingPosy += 10;
            }


        }

        fmt::println("random type: {}", random_type);
        fmt::println("{}", boxes);



        isOpen = false;

    }
    sf::Vector2<float> getSize() override;
    sf::Vector2<float> getPosition() override;
    ~ClassroomDoor() override;
    void collisionRight(Player& player, sf::RenderWindow &window) override;
    void collisionLeft(Player& player, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq,  sf::Time, sf::Time deltatime) override;
    bool status() const;

    void setStatus(bool status);


private:
    void generateMaze(int size);
    static void rand() {
        if(!initialized) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> randomLine(0, 5);
            random_type = randomLine(gen);
            initialized = true;
        }
    }
    sf::Text popUp;
    int id = 400;
    float lastUsed;
    sf::Sprite classroomDoor;
    sf::RectangleShape gameRoom;
    sf::RectangleShape playerGame;
    sf::RectangleShape endPoint;
    std::vector<std::vector<int>> boxes;
    std::vector<sf::RectangleShape> boxesShapes;
    bool isOpen = false;
    bool isActive = false;
    bool game = false;
    float gameEnded = 0;
    int val;
    int type;
    int xRand;


};
