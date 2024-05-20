#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Icons.h"
#include "../ResourceManager.h"

class TeamsIcon
        : public Icons{
public:
    TeamsIcon(float x, float y) : Icons(x, y) {
        this->icon.setPosition(x, y);
        this->icon.setTexture(ResourceManager::getTexture("../graphics/microsoftTeamsIcon.png"));
        this->icon.scale(0.13, 0.13);
        this->teams.setTexture(ResourceManager::getTexture("../graphics/mainTeams.png"));
        this->teams.scale(0.5186,0.4823);
        this->teams.setPosition(425,125);
        //====================================
        this->teams_window_activity.setTexture(ResourceManager::getTexture("../graphics/teamsActivity.png"));
        this->teams_window_activity.scale(0.5186,0.4823);
        this->teams_window_activity.setPosition(425,125);

        this->teams_window_chat.setTexture(ResourceManager::getTexture("../graphics/teamsChats.png"));
        this->teams_window_chat.scale(0.5186,0.4823);
        this->teams_window_chat.setPosition(425,125);

        this->teams_window_assignments.setTexture(ResourceManager::getTexture("../graphics/assigmentTeams.png"));
        this->teams_window_assignments.scale(0.5186,0.4823);
        this->teams_window_assignments.setPosition(425,125);


        // ==============================================
        this->centerX = icon.getPosition().x + 64;
        this->centerY = icon.getPosition().y + 64;
        this->windowScreen.setSize(sf::Vector2f(750, 450));
        this->windowScreen.setOutlineThickness(10);
        this->windowScreen.setOutlineColor(sf::Color::Black);
        this->windowScreen.setFillColor(sf::Color::White);
        this->windowScreen.setPosition(425, 125);
        this->notification.setPosition(445,230);
        this->notification.setRadius(3);
        this->notification.setFillColor(sf::Color::Red);

    }
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
    void collision() override;
    bool isActive() override;
    void drawApp(sf::RenderWindow& window) override;


private:
    float centerX;
    float centerY;
    sf::RectangleShape windowScreen;
    sf::Sprite icon;
    sf::Sprite teams_window_activity;
    sf::Sprite teams_window_chat;
    sf::Sprite teams_window_teams;
    sf::Sprite teams_window_assignments;
    sf::CircleShape notification;
    sf::Sprite teams;
    int id = 2;
    bool playerSawAssignment = false;
    bool active = false;
    bool teams_Activity = false;
    bool teams_Chats = false;
    bool teams_Teams = false;
    bool teams_Assignments = false;



};




