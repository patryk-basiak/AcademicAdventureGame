#include "TeamsIcon.h"
#include "../ResourceManager.h"
#include "fmt/core.h"
#include "../Settings.h"
#include <cmath>

void TeamsIcon::draw(sf::RenderWindow &window)  {
    window.draw(icon);
}

void TeamsIcon::update(sf::RenderWindow& window) {
    sf::Vector2 vec = sf::Mouse::getPosition(window);
    if (std::pow(vec.x - centerX, 2) + std::pow(vec.y - centerY, 2) <= 4096) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            active = true;
        }
    }
    if (std::pow(vec.x - 1175, 2) + std::pow(vec.y - 125, 2) <= 800 and active) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            active = false;
        }
    }
    if (active) {
        if (vec.x > 425 and vec.x < 450) {
            if (vec.y >= 150 and vec.y < 175) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    fmt::println("activity clicked");
                    teams_Activity = true;
                }
            }
            if (vec.y >= 175 and vec.y < 200) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    fmt::println("chat clicked");
                    teams_Chats = true;
                }
            }
            if (vec.y >= 200 and vec.y < 225) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    fmt::println("teams clicked");
                    teams_Teams = true;
                }
            }
            if (vec.y >= 225 and vec.y < 250) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    fmt::println("assignments clicked");
                    teams_Assignments = true;
                    playerSawAssignment = true;
                    stage_1 = true;
                }
            }
        }
        if (vec.x > 635 and vec.x < 650 and vec.y >= 125 and vec.y < 145) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if(teams_Activity){
                    teams_Activity = false;
                }
                if(teams_Chats){
                    teams_Chats = false;
                }
                if(teams_Teams){
                    teams_Teams = false;
                }
                if(teams_Assignments){
                    teams_Assignments = false;
                }
            }

        }
    }
}

        void TeamsIcon::collision() {
            Icons::collision();
        }

        bool TeamsIcon::isActive() {
            return active;
        }

        void TeamsIcon::drawApp(sf::RenderWindow &window) {
            window.draw(this->windowScreen);
            window.draw(teams);
            if (!playerSawAssignment) {
                window.draw(notification);
            }
            if (teams_Activity) {
                window.draw(teams_window_activity);
            }
            if (teams_Chats) {
                window.draw(teams_window_chat);
            }
            if (teams_Teams) {
                window.draw(teams_window_teams);
            }
            if (teams_Assignments) {
                window.draw(teams_window_assignments);
            }
        }

