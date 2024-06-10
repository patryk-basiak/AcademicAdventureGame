#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"
#include "fmt/core.h"
#include <thread>
#include "Player.h"
#include "Equipment.h"
#include "ResourceManager.h"
#include "FPS.h"
#include "HUD.h"
#include "Game.h"


auto main() -> int {
    sf::RenderWindow window = sf::RenderWindow(
            sf::VideoMode({1600, 900}), "Adventure",
            sf::Style::Default, sf::ContextSettings(0, 0, 8));
    // set frame limit
//    window.setFramerateLimit(144);
    // game initialize bool
    game = false;
    // lvl
    bool menu = true;
    bool pause = false;
    //background image


    // creating background image
    sf::Texture worldBackground = sf::Texture();
    sf::Sprite worldBack = sf::Sprite();
    worldBack.setTexture(ResourceManager::getTexture("../graphics/backgroundCity.png"));
    worldBack.scale(0.78125, 0.78125);

    FPS fps1;
    // initialize player and eq
    Player player;
    Equipment eq;
    HUD hud;
    Game gameClass;
    bool debug = false;
    debugMode = false;
    eq.addItem(2);
    eq.addItem(3);
    eq.addItem(5);
    eq.addItem(12);
    eq.addItem(13);
    eq.addItem(20);
    sf::Clock clock;
    sf::Clock timer;
    while (window.isOpen()) {
        while (menu) {
            gameClass.loadGraphics();
            sf::Event event = sf::Event();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        game = true;
                        menu = false;
                    }
                }
                window.clear(sf::Color::Black);
                window.display();
            }
        }
            while (game) {
                sf::Time deltaTime = clock.restart();
                sf::Time time = timer.getElapsedTime();
                window.clear(sf::Color::White);
                gameClass.update(window, player, eq, time, hud, fps1, deltaTime);
                gameClass.gameRules(window,player,eq,deltaTime,hud);
                player.update(deltaTime);
                player.draw(window);
                eq.update(window, player);
                fps1.update();
                window.display();

            }
            while(died){
                gameClass.loadGraphics();
                sf::Event event = sf::Event();
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Enter) {
                            died = false;
                            window.close();
                        }
                    }
                    window.clear(sf::Color::Blue);
                    window.display();
                }


            }
    }

}

