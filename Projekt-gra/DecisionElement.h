#pragma once

#include <string>
#include <utility>
#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"
#include "fmt/core.h"
#include "ResourceManager.h"

static int tempID = 0;
class DecisionElement {

public:
    explicit DecisionElement(std::vector<std::string> choices, float x, float y){
        decisions = std::move(choices);
        base.setSize(sf::Vector2f{(float)decisions.size()*30, (float)decisions.at(0).size()*50});
        base.setPosition(x,y);
        base.setFillColor(sf::Color::White);
        id = tempID++;
        base.setOutlineColor((sf::Color{255,215,0,255}));
        base.setOutlineThickness(3);
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }
        for(const auto& e: decisions){
            decisionFrame.push_back({sf::Text(e,font,15)});
        }
        for(auto &frame : decisionFrame){
            frame.setFillColor(sf::Color::Black);
            frame.setPosition(x, y);
            y+=(float)decisions.at(0).size() + 5 ;
        }
        line = sf::RectangleShape(sf::Vector2f(150, 3));
        line.setFillColor((sf::Color{255,215,0,255}));

    }
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) ;
    void update(Player& player, sf::RenderWindow &window);
    void setDecisions(std::vector<std::string>);
    int getDecision();
    int x;
    int y;
//    void setText(std::string text);




private:
    std::vector<std::string> decisions;
    bool isShown = false;
    bool decided = false;
    int decision = 0 ;
    int id;
    sf::Font font;
    sf::RectangleShape line;
    std::vector<sf::Text> decisionFrame;
    sf::RectangleShape base;


};

