//
// Created by UseR on 19.05.2024.
//

#include "Game.h"

void Game::update(sf::RenderWindow& window, Player& player, Equipment eq, sf::Time deltaTime, HUD& hud) {
    sf::Event event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            game = false;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                eq.show();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                if (pause) {
                    movable = true;
                    pause = false;
                } else {
                    movable = false;
                    pause = true;
                }

            }
            if (event.key.code == sf::Keyboard::SemiColon) {
                if (debug) {
                    debug = false;
                    hud.showDebug();
                } else {
                    hud.hideDebug();
                }
            }
        }
        if (event.type == sf::Event::GainedFocus) {
            // resume
        }
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0) {
                eq.movedMouse();
            } else if (event.mouseWheelScroll.delta < 0) {
                eq.movedMouseDown();
            }

        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            eq.useItemInHand();
        }
        if (player.getPosition().x >=  (float)(window.getSize().x - 30)) {
            player.setPosition(0.f, player.getSurface());
            if (currentLvl != lastLvl)
                player.setStartPosition();
            currentLvl += 1;
            currentMap = maps[currentLvl];


        }
        if (player.getPosition().x < -40) {
            player.setPosition((float)(window.getSize().x - 30), player.getSurface());
            if (currentLvl != 0)
                player.setEndPosition();
            currentLvl -= 1;
            currentMap = maps[currentLvl];

            if (currentLvl == 0) {
                player.setPosition(-10.f, player.getSurface());
            }
        }
        currentMap.update(window,deltaTime,player,eq);
        currentMap.draw(window);

    }
}