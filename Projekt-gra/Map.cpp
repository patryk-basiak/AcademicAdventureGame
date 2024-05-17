//
// Created by UseR on 14.05.2024.
//

#include <random>
#include "Map.h"
#include "ranges"
#include <cfloat>
#include <fmt/ranges.h>
#include "objects/Pistol.h"
#include "objects/Coin.h"
#include "objects/Wall.h"
#include "objects/JumpPad.h"
#include "Equipment.h"
#include "ResourceManager.h"


static int tempID = 0;

Map::Map(int enemies_number, int npc_number, MapTypes::types mainType, int subtype) {
    this->mainType = mainType;
    this->subType = subtype;
    this->id = tempID++;
    this->enemies_number = enemies_number;
    this->npc_number = npc_number;
    this->map_vec = this->generateMap(14,25);
    this->entity_vec = tansformEntities(map_vec[2]);
    this->items_vec = transformObjects(map_vec[1]);
    this->walls_vec = transformWalls(map_vec[0]);
    this->backgroundTexture.setTexture(ResourceManager::getTexture("../graphics/CountrySide.png"));

}

std::vector<std::vector<std::vector<int>>> Map::generateMap(int x, int y) const {

    if(x < 2 or y < 2){
       x = 10;
       y = 10;
    }
    auto vec = std::vector<std::vector<std::vector<int>>>();
    if(mainType == MapTypes::STARTING){
        auto map = std::vector<std::vector<int>>();
        map = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1},
    };
        vec.push_back(map);
        auto items = std::vector<std::vector<int>>();
        items = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 3,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,2, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
        };
        vec.push_back(items);
        vec.push_back({{0}});
        return vec;

    }




//    if(mainType == MapTypes::FOREST){
//
//    }
//
//    if(mainType == MapTypes::CITY){
//
//    }
//    if(mainType == MapTypes::PJATK){
//
//    }
//    if(mainType == MapTypes::ENDING){
//
//    }

    int ground = 2;
    // source: https://stackoverflow.com/questions/22923551/generating-number-0-1-using-mersenne-twister-c
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine

    std::uniform_int_distribution<> dist(0, 3);

    std::uniform_int_distribution<> distDoor(ground + 1, y - 3);
    std::uniform_int_distribution<> xoidGen(3, y-5);
    std::uniform_int_distribution<> platformLength(2, 4);
    std::uniform_int_distribution<> spawn(0, 5);
    std::uniform_int_distribution<> enemy(0, 4);

    int random = dist(gen);
    int platfLength = platformLength(gen);

    int column = distDoor(gen);
    int platform = distDoor(gen);
    int platformY = distDoor(gen);
    int platformN = distDoor(gen);
    int platformY2 = distDoor(gen);
    if(platform == platformN){
        platformN = distDoor(gen);
    }

    int xoid = xoidGen(gen);
    int door = distDoor(gen);
    std::vector<std::vector<int>> walls = std::vector<std::vector<int>>();
    int items = 4;
    std::vector<std::vector<int>> vec_items = std::vector<std::vector<int>>();
    std::vector<std::vector<int>> vec_enemies = std::vector<std::vector<int>>();
    for(int i = 0; i<y; ++i){
        std::vector temp = std::vector<int>();
        std::vector temporaryItems = std::vector<int>();
        std::vector temporaryEnemy = std::vector<int>();
        for(int j = 0; j<x; ++j){
            if(j == x -1 and (i == door or i == door -1)){
                temp.push_back(99);
                temporaryItems.push_back(0);
                temporaryEnemy.push_back(0);
            }
            else if( (i == door + 3 and j == x - 6) or (i == door + 4 and j > x - 8 and j <= x - dist(gen))){
                temp.push_back(1);
            }
            else if(j == 0 or j == x-1){
                temp.push_back(1);
                temporaryItems.push_back(0);
                temporaryEnemy.push_back(0);
            }else if(j >= x-3 and i == door +1) {
                temp.push_back(1);
                temporaryItems.push_back(0);
                temporaryEnemy.push_back(0);
            }
            else if(j >= xoid and j < xoid + 4 and i >= y - ground){
                temp.push_back(0);
                temporaryItems.push_back(3);
                temporaryEnemy.push_back(0);
            }
            else if(j >= xoid and j < xoid + platfLength and i == y - ground - 3){
                temp.push_back(1);
                temporaryItems.push_back(0);
                temporaryEnemy.push_back(0);
            }
            else if(i == y - ground - 2){
                temporaryItems.push_back(0);
                temp.push_back(0);
                temporaryEnemy.push_back(enemy(gen));
            }
            else if(j >= platform and j <platform + platfLength and i == platformY){
                temp.push_back(0);
                temporaryItems.push_back(3);
                temporaryEnemy.push_back(0);
            }
            else if(j == column and i <= y - ground - 1 and i >= y - ground - platfLength){
                temp.push_back(1);
                temporaryItems.push_back(0);
                temporaryEnemy.push_back(0);
            }
            else if(i >= y - ground){
                temp.push_back(1);
                temporaryItems.push_back(0);
                temporaryEnemy.push_back(0);
            }
            else{
                temporaryEnemy.push_back(0);
                temp.push_back(0);
                int rand = spawn(gen);
                if( rand != 0 and items > 0 and j % 6 == 0){
                    temporaryItems.push_back(rand);
                    items--;
                }

            }

        }
        if(!temporaryItems.empty()){
            vec_items.push_back(temporaryItems);
        }
        vec_enemies.push_back(temporaryEnemy);
        walls.push_back(temp);
    }
    vec.push_back(walls);
    vec.push_back(vec_items);
    vec.push_back(vec_enemies);
    return vec;

}

std::vector<std::shared_ptr<Entity>> Map::tansformEntities(const std::vector<std::vector<int>>& vec) {
    auto trans = std::vector<std::shared_ptr<Entity>>();
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 3) {
                trans.push_back(std::make_shared<Entity>(x,y));
            }
            if (i == 2) {
            }
            x += 64;
            if (x >= 2000) {
                x = 0;
                y += 64;
            }
        }
    }
    return trans;
}

std::vector<std::shared_ptr<Collectable>> Map::transformObjects(std::vector<std::vector<int>> vec) {
    auto trans = std::vector<std::shared_ptr<Collectable>>();
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 3) {
                trans.push_back(std::make_shared<Coin>(x,y, 20));
            }
            if (i == 2) {
                trans.push_back(std::make_shared<Pistol>(x,y));
            }
            x += 64;
            if (x >= 1600) {
                x = 0;
                y += 64;
            }
        }
    }
    return trans;
}

std::vector<std::shared_ptr<Wall>> Map::transformWalls(std::vector<std::vector<int>> vec) {
    auto lvl0_trans = std::vector<std::shared_ptr<Wall>>{};
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 0) {
                ;
            } else if (i == 1) {
                lvl0_trans.emplace_back(std::make_shared<Wall>(x,y , 64,64, sf::Color{150,75,0, 255}));

            } if(i==2) {
                lvl0_trans.emplace_back(std::make_shared<JumpPad>(x,y));
            } if(i == 99){
                lvl0_trans.emplace_back(std::make_shared<Wall>(x,y, 64,64, sf::Color{64, 224, 208, 255}));
            }
            x += 64;
            if (x >= 1600) {
                x = 0;
                y += 64;
            }
        }
    }
    return lvl0_trans;
}


void Map::update(sf::RenderWindow& window, sf::Time time, Player& player, Equipment& eq){
    this->checkCollision(player);
    for(auto &e: entity_vec){
        this->checkCollisionEntity(reinterpret_cast<Entity &>(e));
    }
    for (auto it = items_vec.begin(); it != items_vec.end(); it++) {
        (*it)->update(window);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            eq.addItem(*it);
            (*it)->collision(player);
            it = items_vec.erase(it);
            it--;
        }
    }
    for( auto it = entity_vec.begin(); it != entity_vec.end(); it++){
        (*it)->update(time);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            (*it)->collision(player);
            it = entity_vec.erase(it);
            it--;
        }
    }
}

void Map::draw(sf::RenderWindow& window) {
    window.draw(backgroundTexture);
    for (auto &it: items_vec) {
        it->draw(window);
    }
    for (auto & it : entity_vec) {
        it->draw(window);
    }
    for (auto const &e: walls_vec) {
        e->draw(window);
    }
}

void Map::checkCollision(Player& player) {
    float playerBottom = player.getPosition().y + player.getSize()[1];
    float playerTop = player.getPosition().y;
    float playerLeft = player.getPosition().x;
    float playerRight = player.getPosition().x + player.getSize()[0];
    for (const auto &wall: walls_vec) {

        float wallTop = wall->getPosition().y;
        float wallLeft = wall->getPosition().x;
        float wallRight = wall->getPosition().x + wall->getSize().x;
        float wallBottom = wall->getPosition().y + wall->getSize().y;

        if (playerRight > wallLeft && playerLeft < wallRight && playerBottom > wallTop && playerTop < wallBottom) {
            if (playerBottom > wallTop && playerTop < wallTop) {
                wall->collision(player);
                // Top
                player.setPosition(player.getPosition().x, wallTop - player.getSize()[1]);
                player.setVerticalVelocity(0);
            }
            if (playerTop < wallBottom && playerBottom > wallBottom){
                // Bottom
                player.setVerticalVelocity(0);
                player.setPosition(player.getPosition().x, wallBottom);
                fmt::print("Collision with the bottom ({}, {})\n", wall->getPosition().x,
                           wall->getPosition().y);
            }
            if (playerRight > wallLeft && playerLeft < wallLeft && playerBottom < wallTop && playerTop > wallTop ) {
                // Left
                player.setVelocity(0);
                player.setPosition(wallLeft - player.getSize()[0], player.getPosition().y);
                fmt::print("Collision with the left ({}, {}) ({},{})\n", wallRight,
                           wallLeft, playerRight, playerLeft);
            }
            if (playerLeft < wallRight && playerRight > wallRight && playerBottom < wallTop && playerTop > wallTop ) {
                // Right
                player.setVelocity(0);
                player.setPosition(wallRight + 10, player.getPosition().y);
                fmt::print("Collision with the right ({}, {})\n", wall->getPosition().x,
                           wall->getPosition().y);
            }

        }
    }
}

void Map::checkCollisionEntity(Entity& entity){
    float playerBottom = entity.getPosition().y + entity.getSize().y;
    float playerTop = entity.getPosition().y;
    float playerLeft = entity.getPosition().x;
    float playerRight = entity.getPosition().x + entity.getSize().x;
    for (const auto &wall: walls_vec) {

        float wallTop = wall->getPosition().y;
        float wallLeft = wall->getPosition().x;
        float wallRight = wall->getPosition().x + wall->getSize().x;
        float wallBottom = wall->getPosition().y + wall->getSize().y;

        if (playerRight > wallLeft && playerLeft < wallRight && playerBottom > wallTop && playerTop < wallBottom) {
            if (playerRight > wallLeft && playerLeft < wallLeft && playerBottom < wallTop && playerTop > wallTop ) {
                // Left
                entity.setPosition(wallLeft - entity.getSize().x, entity.getPosition().y);
                fmt::print("Collision with the left ({}, {}) ({},{})\n", wallRight,
                           wallLeft, playerRight, playerLeft);
            }
            if (playerLeft < wallRight && playerRight > wallRight && playerBottom < wallTop && playerTop > wallTop ) {
                // Right
                entity.setPosition(wallRight + 10, entity.getPosition().y);
                fmt::print("Collision with the right ({}, {})\n", wall->getPosition().x,
                           wall->getPosition().y);
            }

        }
    }
}

void Map::getMapSeed() {
    for(auto i : map_vec){
        fmt::println("{}", fmt::join(i, "\n"));
        fmt::println("==============================");
    }

}


