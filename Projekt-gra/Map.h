#pragma once

#include <vector>
#include <memory>
#include "objects/Entity.h"
#include "objects/Collectable.h"
#include "objects/Wall.h"
#include "Equipment.h"
#include "MapTypes.h"
#include "objects/Interactable.h"

class Map {

public:
    Map(int enemies_number, int npc_number, MapTypes::types mainType, int subtype);
    bool CheckCollision(float x, float y, float width, float height);
    std::vector<std::vector<std::vector<int>>> generateMap(int x, int y) const;
    static std::vector<std::shared_ptr<Entity>> transformEntities(const std::vector<std::vector<int>>&vec);
    static std::vector<std::shared_ptr<Collectable>> transformObjects(std::vector<std::vector<int>> vec);
    static std::vector<std::unique_ptr<Wall>> transformWalls(std::vector<std::vector<int>> vec);
    static std::vector<std::unique_ptr<Interactable>> transformInteractable(std::vector<std::vector<int>> vec);

    void checkCollision(Player& player, sf::RenderWindow &window);
    void checkCollisionInteract(Player& player, sf::RenderWindow &window);
    void checkCollisionEntity(std::shared_ptr<Entity> entity);
    void draw(sf::RenderWindow& window);

    void update(sf::RenderWindow& window, sf::Time time, Player& player, Equipment& eq);
    void getMapSeed();

    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    Map(Map&&) = default;
    Map& operator=(Map&&) = default;


    int getNumberOfEnemies();

private:
    sf::Sprite backgroundTexture;
    MapTypes::types mainType;
    int subType;
    std::vector<std::shared_ptr<Entity>> entity_vec;
    std::vector<std::unique_ptr<Interactable>> interactable_vec;
    std::vector<std::shared_ptr<Collectable>> items_vec;
    std::vector<std::shared_ptr<Collectable>> throwable;
    std::vector<std::unique_ptr<Wall>> walls_vec;
    std::vector<std::vector<std::vector<int>>> map_vec;
    int id;
    int enemies_number;
    int npc_number;

};

