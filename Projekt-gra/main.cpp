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
#include "Menu.h"


auto main() -> int {
    sf::RenderWindow window = sf::RenderWindow(
            sf::VideoMode({1600, 900}), "Academic Rush: Sunday Quest",
            sf::Style::Default, sf::ContextSettings(0, 0, 8));

    game = false;
    menuX = true;
    Menu menuClass;
    FPS fps1;
    Player player;
    Equipment eq;
    HUD hud;
    Game gameClass;
    debugMode = false;
    sf::Clock clock;
    sf::Clock timer;
    while (window.isOpen()) {
        while (menuX) {
            clock.restart();
            sf::Event event = sf::Event();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            gameClass.loadGraphics();
            window.clear(sf::Color::Black);
            menuClass.update(window, gameClass, player, eq, timer);
            menuClass.draw(window);
            window.display();
        }
        while (game) {
            sf::Time deltaTime = clock.restart();
            sf::Time time = timer.getElapsedTime();
            window.clear(sf::Color::White);
            gameClass.update(window, player, eq, timer, hud, fps1, deltaTime);
            gameClass.gameRules(window, player, eq, deltaTime, hud);
            player.update(deltaTime);
            player.draw(window);
            eq.update(window, player, time);
            fps1.update();
            window.display();

        }
        while (died) {
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


