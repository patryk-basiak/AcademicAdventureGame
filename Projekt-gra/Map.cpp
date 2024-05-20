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

    if(x < 2 or y < 2){
       x = 10;
       y = 10;
    }
    auto vec = std::vector<std::vector<std::vector<int>>>();

    if(mainType == MapTypes::TESTING){
        auto map = std::vector<std::vector<int>>();
        map = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},

        };
        vec.push_back(map);
        vec.push_back({{0}});
        vec.push_back({{0}});
        vec.push_back({{0}});
        return vec;

    }

    if(mainType == MapTypes::STARTING){
        auto map = std::vector<std::vector<int>>();
        map = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {0, 1, 0, 0, 0, 102, 0, 0, 0, 0,101, 0, 1, 0,0,0,0,0,0,0,0,0,0,0,0},
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
                                                  {0, 0, 0, 3, 0, 0, 0, 0, 0, 0,2, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                  {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
        };
        vec.push_back(items);
        auto entity = std::vector<std::vector<int>>();
        entity = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,2, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
        };
        vec.push_back(entity);
        auto interact = std::vector<std::vector<int>>();
        interact = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 102, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0, 0, 0, 103, 0, 0, 0, 0, 0, 0,5, 0, 99, 0,0,0,0,0,0,0,0,0,3,0,0},
                                                     {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
        };
        vec.push_back(interact);
        return vec;

    }




    if(mainType == MapTypes::FOREST){

        int ground = 2;
        // source: https://stackoverflow.com/questions/22923551/generating-number-0-1-using-mersenne-twister-c
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine

        std::uniform_int_distribution<> dist(2, 5);

        std::uniform_int_distribution<> treeNumbers(5, 11);
        std::uniform_int_distribution<> distanceBeetwenTrees(3, 5);
        std::uniform_int_distribution<> treeSize(0, 2);
        std::uniform_int_distribution<> jumpPadRespawn(1, 6);


        int amountOfThrees = treeNumbers(gen);
        std::vector<int> treeTrunks = std::vector<int>();
        int start = 3;
        for(int i = 0; i<amountOfThrees; i++){
            if(start < 22){
                treeTrunks.push_back(start);
            }
            start += distanceBeetwenTrees(gen);
        }
        int door = dist(gen);
        fmt::println("door is {}", door);

        int currentTree = 0;
        auto tempDistance = 0;
        auto map = std::vector<std::vector<int>>();
        for(int i = 0; i<y; ++i){
            std::vector temp = std::vector<int>();
            for(int j = 0; j<x; ++j) {
                auto it = std::find(treeTrunks.begin(),treeTrunks.end(),j);
                if(it != treeTrunks.end()){
                    tempDistance++;
                }
                auto distance =  std::distance(treeTrunks.begin(), it);
                if(j >= x - 3 and i == door + 1){
                    temp.push_back(1);
                }
                else if(j == x -1 and  i != door and i!=door -1){
                    temp.push_back(1);
                }
                else if( i >= y -4 - distance - treeSize(gen) and i <= y - 3 and it != treeTrunks.end()){
                    temp.push_back(200);
                }
                else if( i > y -3 and it == treeTrunks.end() and tempDistance > 3){
                    temp.push_back(0);
                }
                else if( i == y -2 and it == treeTrunks.end() and tempDistance <= 3  and tempDistance > 1 ){
                    temp.push_back(2);
                }
                else if(i == y - 3 and j < 3){
                    temp.push_back(1);
                }
                else if(i > y -3){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(0);
                }
            }
            map.push_back(temp);
            tempDistance = 0;
        }



        vec.push_back(map);
        auto items = std::vector<std::vector<int>>();
        items = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,3,0,0,0,0,0,0},
                                                    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3,0, 0, 0, 0,0,0,0,0,0,0,3,0,0,0,0},
                                                    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {0, 0, 0, 3, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
                                                    {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
                                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
        };
        vec.push_back(items);
//        auto entity = std::vector<std::vector<int>>();
//        entity = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 1, 1, 1, 1, 1, 1, 1,1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 99, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,2, 0, 99, 0,0,0,0,0,0,0,0,0,3,0,0},
//                                                     {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//                                                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//                                                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//                                                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//        };
        vec.push_back({{0}});
        auto interact = std::vector<std::vector<int>>();
//        interact = std::vector<std::vector<int>>{      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0},
//                                                       {1, 1, 2, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//                                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//                                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//                                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,0},
//        };
        vec.push_back({{0}});
        return vec;

    }
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

std::vector<std::shared_ptr<Entity>> Map::transformEntities(const std::vector<std::vector<int>>& vec) {
    auto trans = std::vector<std::shared_ptr<Entity>>();
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 3) {
                trans.push_back(std::make_shared<Entity>(x,y));
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
                lvl0_trans.emplace_back(std::make_shared<Door>(x,y));
            }
            if(i == 101){
                lvl0_trans.emplace_back(std::make_shared<Bed>(x,y));
            }
            if(i == 200){
                lvl0_trans.emplace_back(std::make_shared<OakTree>(x,y));
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

std::vector<std::shared_ptr<Interactable>> Map::transformInteractable(std::vector<std::vector<int>> vec) {
    auto lvl0_trans = std::vector<std::shared_ptr<Interactable>>{};
    float x = 0;
    float y = 4;
    for(auto & j : vec) {
        for (int i : j) {
            if (i == 5) {
                lvl0_trans.emplace_back(std::make_shared<Chest>(x,y));
            }
            if(i == 102){
                lvl0_trans.emplace_back(std::make_shared<Computer>(x,y));
            }
            if(i == 103){
                lvl0_trans.emplace_back(std::make_shared<Wardrobe>(x,y));
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
    this->checkCollision(player, window);
    this->checkCollisionInteract(player, window);
//    for(auto &e: entity_vec){
//        this->checkCollisionEntity(reinterpret_cast<Entity &>(e));
//    }
    for (auto it = items_vec.begin(); it != items_vec.end(); it++) {
        (*it)->update(window);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            eq.addItem(*it);
            (*it)->collision(player);
            items_vec.erase(it);
            it--;
        }
    }
    for( auto it = entity_vec.begin(); it != entity_vec.end(); it++){
        (*it)->update(time);
        if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            (*it)->collision(player);
            entity_vec.erase(it);
            it--;
        }
    }
    for (auto const &e: interactable_vec) {
        e->update(window,player, eq);
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


