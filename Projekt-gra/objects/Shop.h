#pragma once

#include <random>
#include "Interactable.h"
#include "../ResourceManager.h"
#include "CarWinch.h"
#include "Coin.h"
#include "CarWinchItem.h"
#include <fstream>
#include <fmt/core.h>
#include <fmt/ranges.h>

class Shop
        : public Interactable{
public:
    Shop(float x, float y, float i) : Interactable(x,y){
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> randomLine(0, 99);

        this->shop.setTexture(ResourceManager::getTexture("../graphics/shop.png"));
        this->shop.setPosition(x, y);
        this->shop.scale((float)128/shop.getTexture()->getSize().x, (float)128/shop.getTexture()->getSize().y);
        inside.setSize(sf::Vector2f {200,200});
        inside.setPosition(shop.getPosition().x + (this->getSize().x/2 )  - (inside.getSize().x/2),  (shop.getPosition().y + (this->getSize().y/2 )  - (inside.getSize().y/2)));
        inside.setFillColor(sf::Color::White);
        HackInside.setSize(sf::Vector2f {300,300});
        HackInside.setPosition((shop.getPosition().x + this->getSize().x/2 ) - (inside.getSize().x/2),  (shop.getPosition().y + this->getSize().y/2 )  - (inside.getSize().y/2));
        HackInside.setFillColor(sf::Color::Black);
        type = 0;
        popUp.setString("Press F enter shop");
        popUp.setFont(Interactable::font);
        popUp.setFillColor(sf::Color::Black);
        popUp.setPosition(shop.getPosition().x, shop.getPosition().y - 30);
        closedPopUp.setString("Shop is closed");
        closedPopUp.setFont(Interactable::font);
        closedPopUp.setFillColor(sf::Color::Red);
        closedPopUp.setPosition(shop.getPosition().x, shop.getPosition().y);
        hacked.setString("Pres Q to hack");
        hacked.setFont(Interactable::font);
        hacked.setFillColor(sf::Color::Green);
        hacked.setPosition(shop.getPosition().x, shop.getPosition().y + 60);
        closed = true;
        itemsInside.emplace(std::make_unique<CarWinchItem>(inside.getPosition().x, inside.getPosition().y), 0);
        title.setPosition(HackInside.getPosition().x + 125, HackInside.getPosition().y + 25);
        title.setString("Wordle Hack");
        title.setFont(Interactable::font);

        info.setTexture(ResourceManager::getTexture("../graphics/info.png"));
        info.setPosition(HackInside.getPosition().x + 125, HackInside.getPosition().y + 250);
        info.setScale((float)32/info.getTexture()->getSize().x,(float)32/info.getTexture()->getSize().y );

        tryAgain.setTexture(ResourceManager::getTexture("../graphics/tryAgain.png"));
        tryAgain.setPosition(HackInside.getPosition().x + 165, HackInside.getPosition().y + 250);
        tryAgain.setScale((float)32/tryAgain.getTexture()->getSize().x,(float)32/tryAgain.getTexture()->getSize().y );


        HackingDoneText.setPosition(HackInside.getPosition().x + 75, HackInside.getPosition().y + 150);
        HackingDoneText.setString("Hack successful \n access granted");
        HackingDoneText.setFillColor(sf::Color::Green);
        HackingDoneText.setFont(Interactable::font);

        std::ifstream file("../words/SixLetterWords.txt");
        std::string line;
        std::string wantedLine;
       int wantedLineNumber = randomLine(gen);
        int currentLine =0;
        if(file.is_open()){
            while (std::getline(file, line)){
                ++currentLine;
                if(currentLine == wantedLineNumber){
                    wantedLine = line;
                }
            }
            file.close();
        }else{
            fmt::println("Error reading file");
        }
        for(auto & ch : wantedLine){
            word.emplace_back(1,ch);
        }

        text.setFont(Interactable::font);

        text.setCharacterSize(24);

        text.setFillColor(sf::Color::White);

        text.setPosition(HackInside.getPosition().x + 100, HackInside.getPosition().y + 100);


    }
    Shop(float x, float y) : Interactable(x,y){
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> shopN(1, 2);
        int shopNumber = shopN(gen);

        if(shopNumber == 1)
        {
            this->shop.setTexture(ResourceManager::getTexture("../graphics/shop1.png"));
        }
        if(shopNumber == 2)
        {
            this->shop.setTexture(ResourceManager::getTexture("../graphics/shop2.png"));
        }
        this->shop.setPosition(x, y);
        this->shop.scale((float)128/shop.getTexture()->getSize().x, (float)128/shop.getTexture()->getSize().y);
        inside.setSize(sf::Vector2f {300,300});
        inside.setPosition((shop.getPosition().x + this->getSize().x/2 ) - (inside.getSize().x/2),  (shop.getPosition().y + this->getSize().y/2) - (inside.getSize().y/2));
        inside.setFillColor(sf::Color::White);
        type = shopNumber;
        popUp.setString("Press F to buy");
        popUp.setFont(Interactable::font);
        popUp.setFillColor(sf::Color::Black);
        popUp.setPosition(shop.getPosition().x, shop.getPosition().y - 30);
        closed = false;
    }
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~Shop()override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time,  sf::Time deltatime) override;
    void collision(Player& player, sf::RenderWindow &window) override;
    bool getStatus() override;
    
private:
    void clear();
    sf::Text popUp;
    sf::Sprite shop;
    std::map<std::unique_ptr<Collectable>, int> itemsInside;
    std::map<std::unique_ptr<Interactable>, int> interact;
//    sf::Sprite shelf;
    bool active = false;
    sf::RectangleShape inside;
    sf::RectangleShape HackInside;
    int type;
    int id=300;
    bool isOpen = false;
    std::vector<float> position;
    float lastUsed =0;
    bool closed;
    bool tried = false;
    bool hack = false;
    sf::Text closedPopUp;
    sf::Text hacked;
    sf::Text title;
    sf::Text text;
    bool blocked;
    std::string inputString;
    std::vector<sf::Text> textObjects;
    std::vector<std::vector<sf::Text>> answers;
    bool keyState[sf::Keyboard::KeyCount] = {false};
    std::vector<std::string> word;
    bool HackingDone = false;
    sf::Text HackingDoneText;
    float HackDoneTime = 0;
    bool showHackingDone = false;
    sf::Sprite info;
    sf::Sprite tryAgain;
    int xd =0;

};