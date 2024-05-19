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
    sf::Font font;
    if (!font.loadFromFile("../graphics/arial.ttf")) {
        fmt::println("font loading error");
    }
    sf::Text textX = sf::Text("000", font, 30);
    sf::Text showLvlnumber = sf::Text("000", font, 30);
    sf::Text PauseText = sf::Text("Paused", font, 30);
    sf::Text fps = sf::Text("000", font, 30);
    sf::Text textY = sf::Text("000", font, 30);
    sf::Text health = sf::Text("Health: 000", font, 30);

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
                gameClass.gameRules(window,player,eq,deltaTime,hud);
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

