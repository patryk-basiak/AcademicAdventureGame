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
#include "objects/Door.h"
#include "objects/Bed.h"
#include "objects/Computer.h"
#include "objects/Wardrobe.h"
#include "objects/Chest.h"
#include "objects/OakTree.h"
#include "objects/OakLeaves.h"
#include "objects/UniCard.h"
#include "objects/WildBoar.h"
#include "objects/Kiosk.h"
#include "objects/Wizard.h"

static double dotProduct( std::vector<double> v1, std::vector<double> v2) {
    double result = 0;
    for (int i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}



static int tempID = 0;

Map::Map(int enemies_number, int npc_number, MapTypes::types mainType, int subtype) {
    this->mainType = mainType;
    this->subType = subtype;
    this->id = tempID++;
    this->enemies_number = enemies_number;
    this->npc_number = npc_number;
    this->map_vec = this->generateMap(25,14);
    this->walls_vec = transformWalls(map_vec[0]);
    this->items_vec = transformObjects(map_vec[1]);
    this->entity_vec = transformEntities(map_vec[2]);
    this->interactable_vec = transformInteractable(map_vec[3]);
    this->backgroundTexture.setTexture(ResourceManager::getTexture("../graphics/CountrySide.png"));

}

std::vector<std::vector<std::vector<int>>> Map::generateMap(int x, int y) const {

    if (x < 2 or y < 2) {
        x = 10;
        y = 10;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    auto vec = std::vector<std::vector<std::vector<int>>>();
    if (mainType == MapTypes::TESTING) {
        auto map = std::vector<std::vector<int>>();
        map = std::vector<std::vector<int>>{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        };
        vec.push_back(map);
        vec.push_back({{0}});
        vec.push_back({{0}});
        vec.push_back({{0}});
        return vec;

    }
    if(mainType == MapTypes::STARTING) {
        auto map = std::vector<std::vector<int>>();
        map = std::vector<std::vector<int>>{{0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 1, 1, 1, 1,   1, 1, 1, 1, 1,   1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 102, 0, 0, 0, 0, 101, 0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 1, 1, 1,   1, 1, 1, 1, 1,   1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {1, 1, 2, 1, 1, 1,   1, 1, 1, 1, 1,   1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {1, 1, 1, 1, 1, 1,   1, 1, 1, 1, 1,   1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {1, 1, 1, 1, 1, 1,   1, 1, 1, 1, 1,   1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {1, 1, 1, 1, 1, 1,   1, 1, 1, 1, 1,   1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
        vec.push_back(map);
        auto items = std::vector<std::vector<int>>();
        items = std::vector<std::vector<int>>{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 13, 0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0,  0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 99, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},};
        vec.push_back(items);
        auto entity = std::vector<std::vector<int>>();
        entity = std::vector<std::vector<int>>{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        };
        vec.push_back(entity);
        auto interact = std::vector<std::vector<int>>();
        interact = std::vector<std::vector<int>>{{0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   0,   0, 0, 5, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 1, 1,   1,   1, 1, 1, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   102, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 1,   1,   1, 1, 1, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 103, 0,   0, 0, 0, 0, 0, 5, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
                                                 {1, 1, 2, 1,   1,   1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                                 {1, 1, 1, 1,   1,   1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                                 {1, 1, 1, 1,   1,   1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                                 {1, 1, 1, 1,   1,   1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        };
        vec.push_back(interact);
        return vec;

    }
    if (mainType == MapTypes::FOREST) {
        if (subType == 0) {
            // source: https://stackoverflow.com/questions/22923551/generating-number-0-1-using-mersenne-twister-c
            std::uniform_int_distribution<> dist(3, 5);
            std::uniform_int_distribution<> treeNumbers(5, 11);
            std::uniform_int_distribution<> distanceBeetwenTrees(3, 5);
            std::uniform_int_distribution<> treeSize(0, 2);
            std::uniform_int_distribution<> jumpPadRespawn(1, 6);
            std::uniform_int_distribution<> spawnCoins(0, 1);


            int amountOfThrees = treeNumbers(gen);
            std::vector<int> treeTrunks = std::vector<int>();
            int start = 3;
            for (int i = 0; i < amountOfThrees; i++) {
                if (start < 22) {
                    treeTrunks.push_back(start);
                }
                start += distanceBeetwenTrees(gen);
            }
            int door = dist(gen);

            auto tempDistance = 0;
            auto map = std::vector<std::vector<int>>();
            auto collect = std::vector<std::vector<int>>();
            for (int i = 0; i < y; ++i) {
                std::vector temp = std::vector<int>();
                std::vector items = std::vector<int>();
                for (int j = 0; j < x; ++j) {
                    auto it = std::find(treeTrunks.begin(), treeTrunks.end(), j);
                    auto before = std::find(treeTrunks.begin(), treeTrunks.end(), j + 1);
                    auto after = std::find(treeTrunks.begin(), treeTrunks.end(), j - 1);
                    if (it != treeTrunks.end()) {
                        tempDistance++;
                    }
                    auto distance = std::distance(treeTrunks.begin(), it);
                    if (j >= x - 3 and i == door + 1) {
                        temp.push_back(1);
                        items.push_back(0);
                    } else if (j == x - 1 and i != door and i != door - 1) {
                        temp.push_back(1);
                        items.push_back(0);
                    } else if (i == y - 6 - distance and i <= y - 4 and it != treeTrunks.end()) {
                        int tempCoin = spawnCoins(gen);
                        fmt::println("coin: {}", tempCoin);
                        if (tempCoin == 1) {
                            items.push_back(3);
                        } else {
                            items.push_back(0);
                        }
                        temp.push_back(0);
                    } else if (i == y - 5 - distance and it != treeTrunks.end()) {
                        temp.push_back(201);
                        items.push_back(0);
                    } else if (i >= y - 4 - distance and i <= y - 4 and it != treeTrunks.end()) {
                        temp.push_back(200);
                        items.push_back(0);
                    }
//                else if (i >= y - distance - 3 and  i < y - distance - tempDistance  and (before != treeTrunks.end() or after != treeTrunks.end()) and tempDistance > 2){
//                    temp.push_back(201);
//                } // TODO
                    else if (i > y - 4 and it == treeTrunks.end() and tempDistance > 3) {
                        temp.push_back(0);
                        items.push_back(0);
                    } else if (i == y - 4 and it == treeTrunks.end() and tempDistance <= 3 and tempDistance > 1) {
                        temp.push_back(2);
                        items.push_back(0);
                    } else if (i == y - 4 and j < 4) {
                        temp.push_back(1);
                        items.push_back(0);
                    } else if (i > y - 4) {
                        temp.push_back(1);
                        items.push_back(0);
                    } else {
                        temp.push_back(0);
                        items.push_back(0);
                    }
                }
                map.push_back(temp);
                collect.push_back(items);
                tempDistance = 0;
            }
            vec.push_back(map);
            vec.push_back(collect);
            vec.push_back({{0}});
            vec.push_back({{0}});
            return vec;
        }
        if (subType == 1) {
            int copyEnemyNumber = enemies_number;
             // Mersenne Twister engine
            std::uniform_int_distribution<> enemy(5, 20);
            std::uniform_int_distribution<> isEnemy(0, 2);
            std::uniform_int_distribution<> platform(0, 1);
            std::uniform_int_distribution<> jumpPadPos(2, 12);
            std::uniform_int_distribution<> randomRange(2, 4);
            int copyNumbersEnemy = 5;
            auto map = std::vector<std::vector<int>>();
            auto items = std::vector<std::vector<int>>();
            auto ENEMY = std::vector<std::vector<int>>();
            auto inter = std::vector<std::vector<int>>();
            int jPos = jumpPadPos(gen);
            int next = 0;
            int r = randomRange(gen);
            for (int i = 0; i < y; ++i) {
                std::vector temp = std::vector<int>();
                std::vector enemies = std::vector<int>();
                std::vector collect = std::vector<int>();
                for (int j = 0; j < x; ++j) {
                    if (j == x - 1 and (i == y - 4 or i == y - 3)) {
                        temp.push_back(99);
                        enemies.push_back(0);
                        collect.push_back(0);
                    } else if (j == x - 1) {
                        temp.push_back(1);
                        enemies.push_back(0);
                        collect.push_back(0);
                    } else if (i == y - 2) {
                        if (j == jPos) {
                            if (next == 0) {
                                temp.push_back(2);
                                jPos = jumpPadPos(gen);
                                next = 1;
                                enemies.push_back(0);
                                collect.push_back(0);
                            } else {
                                temp.push_back(1);
                                enemies.push_back(0);
                                collect.push_back(0);
                            }
                        }
                        if (j == jPos + r) {
                            temp.push_back(2);
                            enemies.push_back(0);
                            collect.push_back(0);
                        } else {
                            temp.push_back(1);
                            enemies.push_back(0);
                            collect.push_back(0);
                        }
                    } else if (i > y - 2) {
                        temp.push_back(1);
                        enemies.push_back(0);
                        collect.push_back(0);
                    } else if (i % 3 == 1) {
                        int tmp = isEnemy(gen);
                        if (tmp > 1 and copyNumbersEnemy > 0) {
                            enemies.push_back(2);
                            copyNumbersEnemy--;
                        } else {
                            enemies.push_back(0);
                        }
                        temp.push_back(0);
                        collect.push_back(0);
                    } else if (i % 3 == 0) {
                        int n = platform(gen);
                        if (j == jPos) {
                            if (next == 0) {
                                temp.push_back(2);
                                jPos = jumpPadPos(gen);
                                next = 1;
                            } else {
                                temp.push_back(0);
                            }
                            enemies.push_back(0);
                        } else {
                            if (n == 1) {
                                temp.push_back(1);
                            }
                            if (n != 1) {
                                temp.push_back(0);
                            }
                            enemies.push_back(0);
                            collect.push_back(0);
                        }
                    } else {
                        temp.push_back(0);
                        enemies.push_back(0);

                        int ran = enemy(gen);
                        if (ran < 7) {
                            collect.push_back(3);
                        } else {
                            collect.push_back(0);
                        }
                    }
                }
                map.push_back(temp);
                ENEMY.push_back(enemies);
                items.push_back(collect);
                r = randomRange(gen);
                next = 0;
            }
            vec.push_back(map);
            vec.push_back(items);
            vec.push_back(ENEMY);
            vec.push_back({{0}});

            fmt::println("vec {}", vec);
            return vec;
        }

        if (subType == 2)
        {
            std::uniform_int_distribution<> wizardPos(x/2, x-3);

            auto wizPos = wizardPos(gen);
            auto map = std::vector<std::vector<int>>();
            auto items = std::vector<std::vector<int>>();
            auto ENEMY = std::vector<std::vector<int>>();
            auto inter = std::vector<std::vector<int>>();
            for (int i = 0; i < y; ++i) {
                std::vector temp = std::vector<int>();
                std::vector interact = std::vector<int>();
                std::vector collect = std::vector<int>();
                std::vector entites = std::vector<int>();
                for (int j = 0; j < x; ++j) {
                    if ((j > x / 2 - 3 and j < x / 2 + 3) and i == y - 6) {
                        temp.push_back(1);
                        interact.push_back(0);
                        entites.push_back(0);
                    } else if (j == x / 2 and i == y - 7) {
                        temp.push_back(0);
                        interact.push_back(201);
                    }else if(i == y - 4){
                        if(j == wizPos){
                            entites.push_back(4);
                            temp.push_back(0);
                            interact.push_back(0);
                        }else{
                            entites.push_back(0);
                            temp.push_back(0);
                            interact.push_back(0);
                        }
                    }
                    else if (i == y - 3) {
                        if (j == x / 2 - 3 or j == x / 2 + 3) {
                            temp.push_back(2);
                            entites.push_back(0);
                            interact.push_back(0);
                        }
                        else
                        {
                            temp.push_back(1);
                            entites.push_back(0);
                            interact.push_back(0);
                        }
                    } else if (i > y - 4) {
                        temp.push_back(1);
                        entites.push_back(0);
                        interact.push_back(0);
                    } else {
                        temp.push_back(0);
                        interact.push_back(0);
                        entites.push_back(0);
                    }
                }
                map.push_back(temp);
                inter.push_back(interact);
                ENEMY.push_back(entites);
            }
            vec.push_back(map);
            vec.push_back({{0}});
            vec.push_back(ENEMY);
            vec.push_back(inter);
            return vec;

        }
    }
        if(mainType == MapTypes::CITY)
        {
            if (subType == 0) {
                auto map = std::vector<std::vector<int>>();
                auto items = std::vector<std::vector<int>>();
                auto ENEMY = std::vector<std::vector<int>>();
                auto inter = std::vector<std::vector<int>>();
                for (int i = 0; i < y; ++i)
                {
                    std::vector temp = std::vector<int>();
                    std::vector interact = std::vector<int>();
                    std::vector collect = std::vector<int>();
                    for (int j = 0; j < x; ++j)
                    {
                        if (i > y - 4) {
                            temp.push_back(1);
                            interact.push_back(0);
                        } else {
                            temp.push_back(0);
                            interact.push_back(0);
                        }
                    }
                    map.push_back(temp);
                    inter.push_back(interact);
                }
                    vec.push_back(map);
                    vec.push_back({{0}});
                    vec.push_back({{0}});
                    vec.push_back(inter);
                    return vec;

            }
            if(subType == 1)
            {
             // TODO
            }
        }
    //

//    if(mainType == MapTypes::PJATK){
//
//    }
//    if(mainType == MapTypes::ENDING){
//
//    }

}
std::vector<std::unique_ptr<Entity>> Map::transformEntities(const std::vector<std::vector<int>>& vec) {
    auto trans = std::vector<std::unique_ptr<Entity>>();
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 2) {
                fmt::println("wild boar added");
                trans.push_back(std::make_unique<WildBoar>(x,y));
            }if (i == 3) {
                trans.push_back(std::make_unique<Entity>(x,y));
            }if (i == 4) {
                trans.push_back(std::make_unique<Wizard>(x,y));
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

std::vector<std::unique_ptr<Collectable>> Map::transformObjects(std::vector<std::vector<int>> vec) {
    auto trans = std::vector<std::unique_ptr<Collectable>>();
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 3) {
                trans.push_back(std::make_unique<Coin>(x,y));
            }
            if (i == 2) {
                trans.push_back(std::make_unique<Pistol>(x,y));
            }
            if(i == 5){
                trans.push_back(std::make_unique<UniCard>(x,y));
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

std::vector<std::unique_ptr<Wall>> Map::transformWalls(std::vector<std::vector<int>> vec) {
    auto lvl0_trans = std::vector<std::unique_ptr<Wall>>{};
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 0) {
                ;
            } else if (i == 1) {
                lvl0_trans.emplace_back(std::make_unique<Wall>(x,y , 64,64, sf::Color{150,75,0, 255}));

            } if(i==2) {
                lvl0_trans.emplace_back(std::make_unique<JumpPad>(x,y));
            } if(i == 99){
                lvl0_trans.emplace_back(std::make_unique<Door>(x,y));
            }
            if(i == 101){
                lvl0_trans.emplace_back(std::make_unique<Bed>(x,y));
            }
            if(i == 200){
                lvl0_trans.emplace_back(std::make_unique<OakTree>(x,y));
            }if(i == 201){
                lvl0_trans.emplace_back(std::make_unique<OakLeaves>(x,y));
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

std::vector<std::unique_ptr<Interactable>> Map::transformInteractable(std::vector<std::vector<int>> vec) {
    auto lvl0_trans = std::vector<std::unique_ptr<Interactable>>{};
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 5) {
                lvl0_trans.emplace_back(std::make_unique<Chest>(x,y));
            }
            if(i == 102){
                lvl0_trans.emplace_back(std::make_unique<Computer>(x,y));
            }
            if(i == 103){
                lvl0_trans.emplace_back(std::make_unique<Wardrobe>(x,y));
            }if(i == 201){
                lvl0_trans.emplace_back(std::make_unique<Kiosk>(x,y));
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
    if(!eq.throwable.empty()){
        this->throwable = eq.throwable;
    }
    this->checkCollision(player, window);
    this->checkCollisionInteract(player, window);
    for(auto &e: entity_vec){
        checkCollisionEntity(e);
    }


    for (auto it = items_vec.begin(); it != items_vec.end(); it++) {
        (*it)->update(window, player);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            eq.addItem((*it)->getId());
            (*it)->collision(player);
            items_vec.erase(it);
            it--;
        }
    }
    for( auto it = entity_vec.begin(); it != entity_vec.end(); it++) {
        (*it)->update(time, player);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            (*it)->collision(player);
            if(!(*it)->isFriendly()) {
                entity_vec.erase(it);
                it--;
            }
        }
        if(!(*it)->isFriendly()) {
            for (auto its = throwable.begin(); its != throwable.end(); its++) {
                if ((*its)->getGlobalBounds().intersects((*it)->getGlobalBounds())) {
//                throwable.erase(its);
//                its--;
                    entity_vec.erase(it);
                    it--;
                }
            }
        }
        if( (*it)->getPosition().x < -10 or (*it)->getPosition().x > 1610){
            entity_vec.erase(it);
            it--;
        }// TODO check it

    }

        for( auto its = throwable.begin(); its != throwable.end(); its++) {
            if ((*its)->getPosition().x > window.getSize().x) {
                (*its)->collision(player);
                throwable.erase(its);
                its--;

            }
        }
    for (auto const &e: interactable_vec) {
        e->update(window,player, eq);
    }
    for (auto const &e: throwable) {
        e->update(window,player);
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
    for (auto const &e: interactable_vec) {
        e->draw(window);
    }
    for (auto const &e: throwable) {
        e->draw(window);\
    }
}


void Map::checkCollision(Player& player, sf::RenderWindow &window) {
    // Separating Axis Theorem
    // source: https://code.tutsplus.com/collision-detection-using-the-separating-axis-theorem--gamedev-169t


//    std::vector<float> PlayerLeftCorner = std::vector<float>{player.getPosition().x, player.getPosition().y};
//    std::vector<double> PlayerCenter = std::vector<double>{player.getPosition().x + (player.getSize()[0]*0.5), player.getPosition().y + (player.getSize()[1]*0.5)};
//    std::vector<float> PlayerRightCorner = std::vector<float>{player.getPosition().x + player.getSize()[0], player.getPosition().y};
//    std::vector<float> PlayerLeftDownCorner = std::vector<float>{player.getPosition().x, player.getPosition().y + player.getSize()[1]};
//    std::vector<float> PlayerRightDownCorner = std::vector<float>{player.getPosition().x + player.getSize()[0], player.getPosition().y + player.getSize()[1]};
//
//    for (const auto &wall: walls_vec){
//
//        std::vector<float> WallLeftCorner     = std::vector<float>{wall->getPosition().x,  wall->getPosition().y};
//        std::vector<float> WallRightCorner    = std::vector<float>{wall->getPosition().x + wall->getSize().x,      wall->getPosition().y};
//        std::vector<double> WallCenter    = std::vector<double>{wall->getPosition().x + (wall->getSize().x*0.5),      wall->getPosition().y + (wall->getSize().y*0.5)};
//        std::vector<float> WallLeftDownCorner = std::vector<float>{wall->getPosition().x,  wall->getPosition().y + wall->getSize().y};
//        std::vector<float> WallRightDownCorner= std::vector<float>{wall->getPosition().x + wall->getSize().x,      wall->getPosition().y + wall->getSize().y};
//
//
//        std::vector<double> axis = std::vector<double>{
//            1,-1
//        };
//
//        std::vector<double> CenterVec = std::vector<double>{
//            WallCenter[0] - PlayerCenter[0],
//            WallCenter[1] - PlayerCenter[1]
//        };
//        std::vector<double> WallCenterToLeftUpVec = std::vector<double>{
//            WallLeftCorner[0] - WallCenter[0],
//            WallLeftCorner[1] - WallCenter[1]
//        };
//        std::vector<double> PlayerCenterToRightUpVec = std::vector<double>{
//            PlayerRightCorner[0] - PlayerCenter[0],
//            PlayerRightCorner[1] - PlayerCenter[1]
//        };
//
//        float projC = dotProduct(CenterVec, axis);
//        float projA = dotProduct(WallCenterToLeftUpVec, axis);
//        float projB = dotProduct(PlayerCenterToRightUpVec, axis);
//
//        float gap = projC - projA + projB;
//
//        if(gap > 0){
//            fmt::println("It s a big gap beetwen boxes");
//        }
//        else if(gap == 0){
//            fmt::println("Boxes are touching each other");
//        }
//        else {
//            fmt::println("Objects are pen each other");
//        }
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
                wall->collision(player, window);
//                player.setSurface(wallTop);
                // Top

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


void Map::checkCollisionEntity(std::unique_ptr<Entity>& entity){
    float entityBottom = entity->getPosition().y + entity->getSize().y;
    float entityTop = entity->getPosition().y;
    float entityLeft = entity->getPosition().x;
    float entityRight = entity->getPosition().x + entity->getSize().x;

    for (const auto &wall: walls_vec) {

        float wallTop = wall->getPosition().y;
        float wallLeft = wall->getPosition().x;
        float wallRight = wall->getPosition().x + wall->getSize().x;
        float wallBottom = wall->getPosition().y + wall->getSize().y;

        if (entityRight > wallLeft && entityLeft < wallRight && entityBottom > wallTop && entityTop < wallBottom) {
            if (entityBottom > wallTop && entityTop < wallTop) {
                entity->setVerticalVelocity(0);
                entity->setPosition(entity->getPosition().x, wall->getPosition().y - entity->getSize().y);
            }
            if (entityTop < wallBottom && entityBottom > wallBottom){
                // Bottom
                entity->setVerticalVelocity(0);

                fmt::print("Collision with the bottom ({}, {})\n", wall->getPosition().x,
                           wall->getPosition().y);
            }
            if (entityRight > wallLeft && entityLeft < wallLeft && entityBottom < wallTop && entityTop > wallTop ) {
                // Left

                fmt::print("Collision with the left ({}, {}) ({},{})\n", wallRight,
                           wallLeft, entityRight, entityLeft);
            }
            if (entityLeft < wallRight && entityRight > wallRight && entityBottom < wallTop && entityTop > wallTop ) {
                // Right
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

void Map::checkCollisionInteract(Player &player, sf::RenderWindow &window) {
    float playerBottom = player.getPosition().y + player.getSize()[1];
    float playerTop = player.getPosition().y;
    float playerLeft = player.getPosition().x;
    float playerRight = player.getPosition().x + player.getSize()[0];
    for (const auto &interact: interactable_vec) {

        float interactTop = interact->getPosition().y;
        float interactLeft = interact->getPosition().x;
        float interactRight = interact->getPosition().x + interact->getSize()[0];
        float interactBottom = interact->getPosition().y + interact->getSize()[1];

        if (playerRight > interactLeft && playerLeft < interactRight && playerBottom > interactTop && playerTop < interactBottom) {
            if (playerBottom > interactTop && playerTop < interactTop) {
                interact->collision(player, window);
//                player.setSurface(interactTop);
                // Top

            }
            if (playerTop < interactBottom && playerBottom > interactBottom){
                // Bottom
                interact->collision(player, window);
                fmt::print("Collision with the bottom ({}, {})\n", interact->getPosition().x,
                           interact->getPosition().y);
            }
            if (playerRight > interactLeft && playerLeft < interactLeft && playerBottom < interactTop && playerTop > interactTop ) {
                interact->collision(player, window);
                // Left
                fmt::print("Collision with the left ({}, {}) ({},{})\n", interactRight,
                           interactLeft, playerRight, playerLeft);
            }
            if (playerLeft < interactRight && playerRight > interactRight && playerBottom < interactTop && playerTop > interactTop ) {
                interact->collision(player, window);
                // Right
                fmt::print("Collision with the right ({}, {})\n", interact->getPosition().x,
                           interact->getPosition().y);
            }

        }
    }

}

int Map::getNumberOfEnemies() {
    return entity_vec.size();
}



