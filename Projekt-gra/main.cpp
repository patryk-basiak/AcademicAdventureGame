#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"
#include "fmt/core.h"
#include "fmt/ostream.h"
#include "fmt/ranges.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include "Player.h"
#include "Equipment.h"
#include "ResourceManager.h"
#include "Map.h"
#include "FPS.h"
#include "HUD.h"
#include "Game.h"

auto transform(std::vector<std::vector<int>>) -> std::vector<std::unique_ptr<Wall>>;
auto block_until_gained_focus(sf::Window& window) -> void;

auto main() -> int {
    sf::RenderWindow window = sf::RenderWindow(
            sf::VideoMode({1600, 900}), "Adventure",
            sf::Style::Default, sf::ContextSettings(0, 0, 8));
    // set frame limit
//    window.setFramerateLimit(144);
    // game initialize bool
    bool game = false;
    // lvl
    bool menu = true;
    bool pause = false;
    //background image
    sf::Font font;
    if (!font.loadFromFile("../graphics/arial.ttf")) {
        fmt::println("font loading error");
    }
    sf::Text textX = sf::Text("000", font, 30);
    textX.setPosition({1250, 150});
    textX.setFillColor(sf::Color::Black);

    sf::Text showLvlnumber = sf::Text("000", font, 30);
    showLvlnumber.setPosition({1250, 200});
    showLvlnumber.setFillColor(sf::Color::Black);

    sf::Text PauseText = sf::Text("Paused", font, 30);
    PauseText.setPosition({1250, 200});
    PauseText.setFillColor(sf::Color::Black);

    sf::Text fps = sf::Text("000", font, 30);
    fps.setPosition({1250, 250});
    fps.setFillColor(sf::Color::Black);

    sf::Text textY = sf::Text("000", font, 30);
    textY.setPosition({1250, 100});
    textY.setFillColor(sf::Color::Black);
    sf::Text health = sf::Text("Health: 000", font, 30);
    health.setPosition({150, 150});
    health.setFillColor(sf::Color::Black);

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

//            std::thread thread(&Game::loadGraphics, &gameClass);
//
//    thread.launch();
    sf::Clock clock;
    sf::Clock timer;
    while (window.isOpen()) {
        while (menu) {

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
            while (game) {
                sf::Time deltaTime = clock.restart();
                window.clear(sf::Color::White);
                gameClass.update(window, player, eq, deltaTime, hud);
                player.update(deltaTime);
                player.draw(window);
                hud.update(player, fps1, gameClass.getCurrentLvl());
                hud.draw(window, eq, player);
                eq.update(window, player);
                fps1.update();
                window.display();

            }
        }
    }

}

