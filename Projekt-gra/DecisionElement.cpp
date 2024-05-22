#include "DecisionElement.h"
#include "Settings.h"
#include <algorithm>

void DecisionElement::setPosition(float x, float y) {
        base.setPosition(x,y);
}

void DecisionElement::draw(sf::RenderWindow &window) {
    if(!decided) {
        window.draw(base);
        for (auto &e: decisionFrame) {
            window.draw(e);
        }
    }

}

void DecisionElement::update(Player &player, sf::RenderWindow &window ) {
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    if(!decided) { // TODO stage
        for (int i = 0; i < decisionFrame.size(); ++i) {
            line.setPosition(decisionFrame.at(i).getPosition().x, decisionFrame.at(i).getPosition().y + 20);
            if (mouse.x > decisionFrame.at(i).getPosition().x and mouse.x < decisionFrame.at(i).getPosition().x + 100 and
                mouse.y > decisionFrame.at(i).getPosition().y and mouse.y < decisionFrame.at(i).getPosition().y + 30) {
                window.draw(line);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    decision = i;
                    decided = true;
                    stage_0 = true;
                }
            }
        }
    }
}

int DecisionElement::getDecision() {
    return decision;
}

void DecisionElement::setDecisions(std::vector<std::string> newDec) {
    float padding = 5;
    float copyX = base.getPosition().x;
    float copyY = base.getPosition().y;
    decisions = newDec;
    decisionFrame.clear();
    float width = decisions.at(0).size() * 10;
    float height = decisions.size()* 30;
    base.setSize(sf::Vector2f {width,height});
    for(const auto& e: decisions){
        decisionFrame.push_back({sf::Text(e,font,15)});
    }
    for(auto &frame : decisionFrame){
        frame.setFillColor(sf::Color::Black);
        frame.setPosition(copyX + padding, copyY);
        copyY+=30 ;
    }
}
