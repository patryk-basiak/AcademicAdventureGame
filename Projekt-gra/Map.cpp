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
#include "objects/Car.h"
#include "objects/Shop.h"
#include "objects/Grass.h"
#include "objects/Dirt.h"
#include "objects/Brick.h"
#include "objects/woodBlock.h"
#include "objects/woodSlab.h"
#include "objects/street.h"
#include "objects/stone.h"
#include "objects/CarEnemy.h"
#include "objects/CarWinchItem.h"
#include "ThrowableContainer.h"
#include "objects/classroomDoor.h"
#include "objects/Elevator.h"

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
    this->spawnPoint = {0,0};
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

std::vector<std::vector<std::vector<int>>> Map::generateMap(int x, int y) {

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
                                            {0, 5, 5, 5, 5, 5,   5, 5, 5, 5, 5,   5, 5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 0, 0, 102, 0, 0, 0, 0, 101, 0, 5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 7, 7, 7,   7, 7, 7, 7, 7,   7, 5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 5, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {3, 6, 2, 6, 6, 6,   6, 6, 6, 6, 6,   6, 6,  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                                            {4, 4, 4, 4, 4, 4,   4, 4, 4, 4, 4,   4, 4,  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                                            {4, 4, 4, 4, 4, 4,   4, 4, 4, 4, 4,   4, 4,  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                                            {4, 4, 4, 4, 4, 4,   4, 4, 4, 4, 4,   4, 4,  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
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
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
                                                 {0, 0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 103, 0,   0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
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
            spawnPoint = std::vector<float>{4, 590};
            endPoint; // TODO
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
                        temp.push_back(3);
                        items.push_back(0);
                    } else if (j == x - 1 and i != door and i != door - 1) {
                        temp.push_back(4);
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
                    } else if (i == y - 3 and it == treeTrunks.end() and tempDistance <= 3 and tempDistance > 1) {
                        temp.push_back(2);
                        items.push_back(0);
                    } else if (i == y - 4 and j < 4) {
                        temp.push_back(3);
                        items.push_back(0);
                    } else if (i == y - 3) {
                        if(j<4){
                            temp.push_back(4);
                            items.push_back(0);
                        }
                        else{
                            temp.push_back(3);
                            items.push_back(0);
                        }
                    } else if (i > y - 3) {
                        temp.push_back(4);
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
            spawnPoint = std::vector<float>{23, 718};
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
                        temp.push_back(4);
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
                                temp.push_back(3);
                                enemies.push_back(0);
                                collect.push_back(0);
                            }
                        }
                        if (j == jPos + r) {
                            temp.push_back(2);
                            enemies.push_back(0);
                            collect.push_back(0);
                        } else {
                            temp.push_back(3);
                            enemies.push_back(0);
                            collect.push_back(0);
                        }
                    } else if (i > y - 2) {
                        temp.push_back(4);
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
                                temp.push_back(3);
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
            spawnPoint = std::vector<float>{86, 654};
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
                        temp.push_back(3);
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
                            temp.push_back(3);
                            entites.push_back(0);
                            interact.push_back(0);
                        }
                    }else if (i > y - 3) {
                        temp.push_back(4);
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
                spawnPoint = {10, 206};
                auto map = std::vector<std::vector<int>>();
                auto items = std::vector<std::vector<int>>();
                auto ENEMY = std::vector<std::vector<int>>();
                auto inter = std::vector<std::vector<int>>();
                for (int i = 0; i < y; ++i)
                {
                    std::vector temp = std::vector<int>();
                    std::vector interact = std::vector<int>();
                    std::vector collect = std::vector<int>();
                    std::vector enemy = std::vector<int>();
                    for (int j = 0; j < x; ++j)
                    {
                        if(i == 4 and j % 4 == 0){
                            temp.push_back(9);
                            enemy.push_back(0);
                            interact.push_back(0);
                        }
                        else if(i == y -5 and (j == 3 or j == 15 or j == 18)){
                            temp.push_back(0);
                            enemy.push_back(5);
                            interact.push_back(0);
                        }
                        else if(i == y - 3){
                            temp.push_back(8);
                            enemy.push_back(0);
                            interact.push_back(0);
                        }
                        else if (i > y - 3) {
                            temp.push_back(9);
                            enemy.push_back(0);
                            interact.push_back(0);
                        } else {
                            temp.push_back(0);
                            enemy.push_back(0);
                            interact.push_back(0);
                        }
                    }
                    map.push_back(temp);
                    inter.push_back(interact);
                    ENEMY.push_back(enemy);
                }
                    vec.push_back(map);
                    vec.push_back({{0}});
                    vec.push_back(ENEMY);
                    vec.push_back(inter);
                    return vec;

            }
            if(subType == 1)
            {
                spawnPoint = {8, 654};
                std::uniform_int_distribution<> chestPos(3, 11);
                auto chP = chestPos(gen);
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
                        if(j == x - 1)
                        {
                            if( i == y - 4 or i == y - 5)
                            {
                                temp.push_back(0);
                                interact.push_back(0);
                            }
                            else
                            {
                                temp.push_back(9);
                                interact.push_back(0);
                            }
                        }
                        else if(i % 4 == 0 and i < y - 5 and j < x - 4 and j % 4 != 1 and i != 0 and j != 0)
                        {
                            temp.push_back(7);
                            interact.push_back(0);
                        }else if(i % 4 == 2 and i < y - 5 and j < x - 4)
                        {
                            if(j == x - 7 and i < y -10)
                            {
                                temp.push_back(0);
                                interact.push_back(301);
                            }
                            else if(j % 4 == 2)
                            {
                                temp.push_back(0);
                                interact.push_back(300);
                            }
                            else{
                                temp.push_back(0);
                                interact.push_back(0);
                            }
                        }
                        else if(i == y - 3 and j % 4 == 1)
                        {
                            temp.push_back(2);
                            interact.push_back(0);
                        }
                        else if(j == x - 4 and i == y - 5)
                        {
                            {
                                temp.push_back(300);
                                interact.push_back(0);
                            }
                        }
                        else if (i == y - 3)
                        {
                            temp.push_back(8);
                            interact.push_back(0);
                        } else if (i > y - 3)
                        {
                            temp.push_back(9);
                            interact.push_back(0);
                        } else
                        {
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
        }
    if(mainType == MapTypes::PJATK){
        if(subType == 0){
            spawnPoint = {852, 718};

            auto map = std::vector<std::vector<int>>();
            auto items = std::vector<std::vector<int>>();
            auto ENEMY = std::vector<std::vector<int>>();
            auto inter = std::vector<std::vector<int>>();
            for (int i = 0; i < y; ++i)
            {
                std::vector temp = std::vector<int>();
                std::vector interact = std::vector<int>();
                std::vector collect = std::vector<int>();
                std::vector enemy = std::vector<int>();
                int xTemp = 0;
                for (int j = 0; j < x; ++j)
                {
                    if(j == x - 2 and i == y - 6){
                        temp.push_back(0);
                        enemy.push_back(0);
                        interact.push_back(99);
                    }
                    else if((j == x - 2 or j == x -1) and i == y - 5){
                        temp.push_back(0);
                        enemy.push_back(0);
                        interact.push_back(0);
                    }
                    else if(j < 5 or j > x - 3 )
                    {
                        temp.push_back(1);
                        enemy.push_back(0);
                        interact.push_back(0);
                    }
                    else if(i ==y/2 - 2 or i == y/2 - 4 or i == y/2 -3 )
                    {
                        temp.push_back(1);
                        enemy.push_back(0);
                        interact.push_back(0);
                    }
                    else if(j > x -6 and j < x-2 and i == y -3 or (i == y - 4 and (j == x -3 or j == x-4))){
                            temp.push_back(1);
                            enemy.push_back(0);
                            interact.push_back(0);
                    }

                    else if (i > y - 3) {
                        temp.push_back(9);
                        enemy.push_back(0);
                        interact.push_back(0);
                    } else {
                        temp.push_back(0);
                        enemy.push_back(0);
                        interact.push_back(0);
                    }
                }
                map.push_back(temp);
                inter.push_back(interact);
                ENEMY.push_back(enemy);
            }
            vec.push_back(map);
            vec.push_back({{0}});
            vec.push_back(ENEMY);
            vec.push_back(inter);
            return vec;

        }if(subType == 1){
            spawnPoint = {852, 718};
            std::uniform_int_distribution<> doorPos(5, 8);
            std::uniform_int_distribution<> doorDistance(3, 8);
            std::vector<float> doorLocations;
            auto firstDoor = (float)doorPos(gen);
            doorLocations.push_back(firstDoor);
            for(int i = 0; i < 4; ++i){
                firstDoor += (float) doorDistance(gen);
                if(firstDoor < x){
                    doorLocations.push_back(firstDoor);
                }
            }
            auto map = std::vector<std::vector<int>>();
            auto items = std::vector<std::vector<int>>();
            auto ENEMY = std::vector<std::vector<int>>();
            auto inter = std::vector<std::vector<int>>();
            for (int i = 0; i < y; ++i)
            {
                std::vector temp = std::vector<int>();
                std::vector interact = std::vector<int>();
                std::vector collect = std::vector<int>();
                std::vector enemy = std::vector<int>();
                int xTemp=0;
                for (int j = 0; j < x; ++j)
                {
                    if(i % 4 == 1 and i != 0 and i < y - 3) {
                        temp.push_back(7);
                        enemy.push_back(0);
                        interact.push_back(0);
                    }
                    else if((i % 4 == 3 or i == y - 4) and j == 2 and i < y -3){
                        temp.push_back(0);
                        enemy.push_back(0);
                        interact.push_back(401);
                    }
                    else if((i % 4 == 3 or i == y - 4) and i < y - 3 and j == (int)doorLocations.at(xTemp)){
                        temp.push_back(0);
                        enemy.push_back(0);
                        interact.push_back(400);
                        if(xTemp < doorLocations.size() - 1) {
                            xTemp++;
                        }
                    }
                    else if (i > y - 3) {
                        temp.push_back(6);
                        enemy.push_back(0);
                        interact.push_back(0);
                    } else {
                        temp.push_back(0);
                        enemy.push_back(0);
                        interact.push_back(0);
                    }

                }
                map.push_back(temp);
                inter.push_back(interact);
                ENEMY.push_back(enemy);
                doorLocations.clear();
                firstDoor = (float)doorPos(gen);
                doorLocations.push_back(firstDoor);
                for(int g = 0; g < 4; ++g){
                    firstDoor += (float) doorDistance(gen);
                    if(firstDoor < x){
                        doorLocations.push_back(firstDoor);
                    }
                }
            }
            vec.push_back(map);
            vec.push_back({{0}});
            vec.push_back(ENEMY);
            vec.push_back(inter);
            return vec;

        }
        }
    }
//    if(mainType == MapTypes::ENDING){
//
//    }

std::vector<std::unique_ptr<Entity>> Map::transformEntities(const std::vector<std::vector<int>>& vec) {
    auto trans = std::vector<std::unique_ptr<Entity>>();
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 2) {
                trans.push_back(std::make_unique<WildBoar>(x,y));
            }if (i == 3) {
                trans.push_back(std::make_unique<Entity>(x,y));
            }if (i == 4) {
                trans.push_back(std::make_unique<Wizard>(x,y));
            }if (i == 5) {
                trans.push_back(std::make_unique<CarEnemy>(x,y));
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
            }if(i == 11){
                trans.push_back(std::make_unique<CarWinchItem>(x,y));
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
            }
            if(i==3)
            {
                lvl0_trans.emplace_back(std::make_unique<Grass>(x,y));
            }if(i==4)
            {
                lvl0_trans.emplace_back(std::make_unique<Dirt>(x,y));
            }if(i==5)
            {
                lvl0_trans.emplace_back(std::make_unique<Brick>(x,y));
            }if(i==6)
            {
                lvl0_trans.emplace_back(std::make_unique<WoodBlock>(x,y));
            }if(i==7)
            {
                lvl0_trans.emplace_back(std::make_unique<WoodSlab>(x,y));
            }if(i==8)
            {
                lvl0_trans.emplace_back(std::make_unique<Street>(x,y));
            }if(i==9)
            {
                lvl0_trans.emplace_back(std::make_unique<Stone>(x,y));
            }
            if(i == 101){
                lvl0_trans.emplace_back(std::make_unique<Bed>(x,y));
            }
            if(i == 200){
                lvl0_trans.emplace_back(std::make_unique<OakTree>(x,y));
            }if(i == 201){
                lvl0_trans.emplace_back(std::make_unique<OakLeaves>(x,y));
            }if(i == 300){
                lvl0_trans.emplace_back(std::make_unique<Car>(x,y));
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
            if(i == 99){
                lvl0_trans.emplace_back(std::make_unique<Door>(x,y));
            }if(i == 98){
                lvl0_trans.emplace_back(std::make_unique<Door>(x+50,y));
            }
            if(i == 102){
                lvl0_trans.emplace_back(std::make_unique<Computer>(x,y));
            }
            if(i == 103){
                lvl0_trans.emplace_back(std::make_unique<Wardrobe>(x,y));
            }if(i == 201){
                lvl0_trans.emplace_back(std::make_unique<Kiosk>(x,y));
            }if(i == 300){
                lvl0_trans.emplace_back(std::make_unique<Shop>(x,y));
            }if(i == 301){
                lvl0_trans.emplace_back(std::make_unique<Shop>(x,y, 0));
            }if(i == 400){
                lvl0_trans.emplace_back(std::make_unique<ClassroomDoor>(x,y));
            }if(i == 401){
                lvl0_trans.emplace_back(std::make_unique<Elevator>(x,y));
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


void Map::update(sf::RenderWindow& window, sf::Time deltatime, Player& player, Equipment& eq, sf::Time time){
    this->checkCollision(player, window);
    this->checkCollisionInteract(player, window);

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
        checkCollisionEntity((*it), window);
        (*it)->update(deltatime, player);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            (*it)->collision(player);
            if(!(*it)->isFriendly()) {
                entity_vec.erase(it);
                it--;
                return;
            }
        }
        if( ((*it)->getPosition().x < -10 or (*it)->getPosition().x > 1610 )and (*it)->diesOutsideScreen()){
            entity_vec.erase(it);
            it--;
            return;
        }
        if(!(*it)->isFriendly()) {
            for (auto bullets = ThrowableContainer::getVector().begin(); bullets != ThrowableContainer::getVector().end(); bullets++) {
                if ((*bullets)->getGlobalBounds().intersects((*it)->getGlobalBounds())) {
                    (*it)->setHealth((*it)->getHealth()-1);
                    ThrowableContainer::getVector().erase(bullets);
                    bullets--;
                    if((*it)->getHealth() <= 0){
                        entity_vec.erase(it);
                        it--;
                    }
                    return;
                }
            }
        }

    }
        for( auto its = ThrowableContainer::getVector().begin(); its != ThrowableContainer::getVector().end(); its++) {
            if ((*its)->getPosition().x > window.getSize().x) {
                (*its)->collision(player);
                ThrowableContainer::getVector().erase(its);
                its--;
            }
        }
    for (auto const &e: ThrowableContainer::getInteractVector()) {
        e->update(window,player, eq, time, deltatime);
    }
    for (auto const &e: interactable_vec) {
        e->update(window,player, eq, time, deltatime);
    }
    for (auto const &e: ThrowableContainer::getVector()) {
        e->update(window,player);
    }for (auto const &e: walls_vec) {
        e->update();
    }
}

void Map::draw(sf::RenderWindow& window) {
    window.draw(backgroundTexture);
    for (auto &it: items_vec) {
        it->draw(window);
    }
    for (auto &it: entity_vec) {
        it->draw(window);
    }
    for (auto const &e: walls_vec) {
        e->draw(window);
    }
    for (auto const &e: interactable_vec) {
        e->draw(window);
    }
    for (auto const &e: ThrowableContainer::getVector()) {
        e->draw(window);
    }
    for (auto const &e: ThrowableContainer::getInteractVector()) {
        e->draw(window);
        for (auto &x: walls_vec) {
            e->check(x);
        }
    }
}


void Map::checkCollision(Player& player, sf::RenderWindow &window) {
// sources: https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects //TODO read more

        float playerBottom = player.getPosition().y + player.getSize()[1];
        float playerTop = player.getPosition().y;
        float playerLeft = player.getPosition().x;
        float playerRight = player.getPosition().x + player.getSize()[0];

        for (const auto &wall : walls_vec) {
            float wallTop = wall->getPosition().y;
            float wallLeft = wall->getPosition().x;
            float wallRight = wall->getPosition().x + wall->getSize().x;
            float wallBottom = wall->getPosition().y + wall->getSize().y;

            if (playerRight > wallLeft && playerLeft < wallRight && playerBottom > wallTop && playerTop < wallBottom) {
                float overlapLeft = playerRight - wallLeft;
                float overlapRight = wallRight - playerLeft;
                float overlapTop = playerBottom - wallTop;
                float overlapBottom = wallBottom - playerTop;

                bool fromLeft(std::abs(overlapLeft) < std::abs(overlapRight));
                bool fromTop(std::abs(overlapTop) < std::abs(overlapBottom));

                float minOverlapX = fromLeft ? overlapLeft : overlapRight;
                float minOverlapY = fromTop ? overlapTop : overlapBottom;

                if (std::abs(minOverlapX) < std::abs(minOverlapY)) {
                    if (fromLeft) {
                        // Collision from the left
                        wall->collisionLeft(player,window);
                    } else {
                        // Collision from the right
                        wall->collisionRight(player,window);
                    }
                } else {
                    if (fromTop) {
                        // Collision from the top
                        wall->collision(player, window);
                    } else {
                        // Collision from the bottom
                        wall->collisionBottom(player,window);
                    }
                }
            }
        }
    }



void Map::checkCollisionEntity(std::unique_ptr<Entity>& entity, sf::RenderWindow &window){
    float entityBottom = entity->getPosition().y + entity->getSize().y;
    float entityTop = entity->getPosition().y;
    float entityLeft = entity->getPosition().x;
    float entityRight = entity->getPosition().x + entity->getSize().x;

    for (const auto &wall : walls_vec) {
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
//                entity->setVerticalVelocity(0);
//
//                fmt::print("Collision with the bottom ({}, {})\n", wall->getPosition().x,
//                           wall->getPosition().y);
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

    for (const auto &wall : interactable_vec) {
        float wallTop = wall->getPosition().y;
        float wallLeft = wall->getPosition().x;
        float wallRight = wall->getPosition().x + wall->getSize().x;
        float wallBottom = wall->getPosition().y + wall->getSize().y;

        if (playerRight > wallLeft && playerLeft < wallRight && playerBottom > wallTop && playerTop < wallBottom) {
            float overlapLeft = playerRight - wallLeft;
            float overlapRight = wallRight - playerLeft;
            float overlapTop = playerBottom - wallTop;
            float overlapBottom = wallBottom - playerTop;

            bool fromLeft(std::abs(overlapLeft) < std::abs(overlapRight));
            bool fromTop(std::abs(overlapTop) < std::abs(overlapBottom));

            float minOverlapX = fromLeft ? overlapLeft : overlapRight;
            float minOverlapY = fromTop ? overlapTop : overlapBottom;

            if (std::abs(minOverlapX) < std::abs(minOverlapY)) {
                if (fromLeft) {
                    // Collision from the left
                    wall->collisionLeft(player,window);
                } else {
                    // Collision from the right
                    wall->collisionRight(player,window);
                }
            } else {
                if (fromTop) {
                    // Collision from the top
                    wall->collision(player, window);
                } else {
                    // Collision from the bottom
                    wall->collisionBottom(player,window);
                }
            }
        }
        else{
            wall->setColl(false);
        }
    }

}

int Map::getNumberOfEnemies()
{
    return entity_vec.size();
}

int Map::getSubType() {
    return subType;
}

MapTypes::types Map::getMainType() {
    return mainType;
}

std::vector<float> Map::getSpawnPoint() {
    return spawnPoint;
}



