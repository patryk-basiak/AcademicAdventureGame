#pragma once

#include <vector>
#include <memory>
#include "objects/Entity.h"
#include "objects/Collectable.h"
#include "objects/Wall.h"
#include "Equipment.h"

class Map {

public:
    Map(int enemies_number, int npc_number);
    bool CheckCollision(float x, float y, float width, float height);
    static std::vector<std::vector<int>> generateMap(int x, int y);
    static std::vector<std::shared_ptr<Entity>> tansformEntities(std::vector<std::vector<int>>vec);
    static std::vector<std::shared_ptr<Collectable>> transformObjects(std::vector<std::vector<int>> vec);
    static std::vector<std::shared_ptr<Wall>> transformWalls(std::vector<std::vector<int>> vec);

    void checkCollision(Player& player);
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, sf::Time time, Player& player, Equipment& eq);


private:
    std::vector<std::shared_ptr<Entity>> entity_vec;
    std::vector<std::shared_ptr<Collectable>> items_vec;
    std::vector<std::shared_ptr<Wall>> walls_vec;
    std::vector<std::vector<int>> map_vec;
    int id;
    int enemies_number;
    int npc_number;

};

