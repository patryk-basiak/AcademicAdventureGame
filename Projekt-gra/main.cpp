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
#include "Player.h"
#include "Equipment.h"
#include "ResourceManager.h"
#include "Map.h"
#include "FPS.h"

auto transform(std::vector<std::vector<int>>) -> std::vector<std::unique_ptr<Wall>>;
auto block_until_gained_focus(sf::Window& window) -> void;

auto main() -> int {
    sf::RenderWindow window = sf::RenderWindow(
            sf::VideoMode({1600, 900}), "Adventure",
            sf::Style::Default, sf::ContextSettings(0, 0, 8));
    // set frame limit
//    window.setFramerateLimit(144);
    // game initialize bool
    bool game = true;
    // lvl
    bool menu = false;
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

    bool debug = false;

    std::vector<Map> maps = std::vector<Map>{
//        Map(0,0, MapTypes::TESTING, 0),
        Map(0,0, MapTypes::STARTING, 0),
        Map(0,0, MapTypes::STARTING, 0),
        Map(3,0, MapTypes::FOREST, 0),
        Map(5,1, MapTypes::FOREST, 1),
        Map(1,10, MapTypes::CITY, 0),
        Map(0,6, MapTypes::CITY, 1),
        Map(1,3, MapTypes::PJATK, 0),
        Map(2,14, MapTypes::PJATK, 1),
        Map(0,6, MapTypes::CITY, 2),
        Map(2,4, MapTypes::FOREST, 2),
        Map(2,4, MapTypes::ENDING, 0),
        };

    unsigned int lastLvl = maps.size(); //
    int current_Lvl = 0;
    Map currentMap = maps[current_Lvl];
    sf::Clock clock;
    sf::Clock timer;

    maps[0].getMapSeed();
    while (window.isOpen()) {
        while (game) {
            sf::Time deltaTime = clock.restart();
            textX.setString("X pos: " + std::to_string(((int) player.getPosition().x)));
            showLvlnumber.setString("Current lvl: " + std::to_string(((int)current_Lvl)));
            health.setString("Health: " + std::to_string(player.getHealth()));
            fps.setString("FPS: " + std::to_string((int)std::round(fps1.getFPS())));
            textY.setString("Y pos: " + std::to_string(((int) player.getPosition().y)));
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
                        if(pause){
                            movable = true;
                            pause = false;
                        }
                        else{
                            movable = false;
                            pause = true;
                        }

                    }
                    if (event.key.code == sf::Keyboard::SemiColon) {
                        if (debug) {
                            debug = false;
                        } else {
                            debug = true;
                        }
                    }
                }
//                if(event.type == sf::Event::LostFocus){
//                    // source https://stackoverflow.com/questions/73884580/sfml-lostfocus-gainedfocus-cpu-usage
////                    block_until_gained_focus(window);
//                }
                if(event.type == sf::Event::GainedFocus){
                    // resume
                }
                if(event.type == sf::Event::MouseWheelScrolled){
                    if (event.mouseWheelScroll.delta > 0)
                    {
                        eq.movedMouse();
                    }
                    else if (event.mouseWheelScroll.delta < 0)
                    {
                        eq.movedMouseDown();
                    }

                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    eq.useItemInHand();
                }

            }
            if (player.getPosition().x >=  (float)(window.getSize().x - 30)) {
                player.setPosition(0.f, player.getSurface());
                if (current_Lvl != lastLvl)
                    player.setStartPosition();
                    current_Lvl += 1;
                    currentMap = maps[current_Lvl];


            }
            if (player.getPosition().x < -40) {
                player.setPosition((float)(window.getSize().x - 30), player.getSurface());
                if (current_Lvl != 0)
                    player.setEndPosition();
                    current_Lvl -= 1;
                    currentMap = maps[current_Lvl];

                if (current_Lvl == 0) {
                    player.setPosition(-10.f, player.getSurface());
                }
            }
            window.clear(sf::Color::White);
            currentMap.update(window,deltaTime, player, eq);
            currentMap.draw(window);
            if(debug){
                window.draw(textX);
                window.draw(showLvlnumber);
                window.draw(fps);
                window.draw(textY);
            }
            if(pause){
                PauseText.setString("Paused");
                window.draw(PauseText);
            }
            window.draw(health);
            player.update(deltaTime);
            player.draw(window);
            eq.update(window, player);
            fps1.update();
            window.display();
        }
    }
}

void block_until_gained_focus(sf::Window& window) {
    sf::Event event{};
    while (true) {
        if (window.waitEvent(event) && event.type == sf::Event::GainedFocus) {
            return;
        }
    }
}
