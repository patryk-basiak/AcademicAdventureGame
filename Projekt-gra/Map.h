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
    std::vector<std::vector<std::vector<int>>> generateMap(int x, int y);
    static std::vector<std::unique_ptr<Entity>> transformEntities(const std::vector<std::vector<int>>&vec);
    static std::vector<std::unique_ptr<Collectable>> transformObjects(std::vector<std::vector<int>> vec);
    static std::vector<std::unique_ptr<Wall>> transformWalls(std::vector<std::vector<int>> vec);
    static std::vector<std::unique_ptr<Interactable>> transformInteractable(std::vector<std::vector<int>> vec);

    void checkCollision(Player& player, sf::RenderWindow &window);
    void checkCollisionInteract(Player& player, sf::RenderWindow &window);
    void checkCollisionEntity(std::unique_ptr<Entity>& entity, sf::RenderWindow &window);
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, sf::Time deltatime, Player& player, Equipment& eq, sf::Time Time);
    void getMapSeed();

    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    Map(Map&&) = default;
    Map& operator=(Map&&) = default;
    int getNumberOfEnemies();
    int getSubType();
    MapTypes::types getMainType();
    std::vector<float> getSpawnPoint();

private:
    sf::Sprite backgroundTexture;
    MapTypes::types mainType;
    int subType;
    std::vector<std::unique_ptr<Entity>> entity_vec;
    std::vector<std::unique_ptr<Interactable>> interactable_vec;
    std::vector<std::unique_ptr<Collectable>> items_vec;
    std::vector<std::unique_ptr<Wall>> walls_vec;
    std::vector<std::vector<std::vector<int>>> map_vec;
    int id;
    int enemies_number;
    int npc_number;
    std::vector<float> spawnPoint;
    std::vector<float> endPoint;
    std::vector<sf::Sprite> images;
    bool drawStaticImages = true;
};

