//
// Created by UseR on 07.06.2024.
//

#include "ThrowableContainer.h"
#include "objects/Bullet.h"
#include "objects/CarWinch.h"
#include "objects/smallComputers.h"

std::vector<std::unique_ptr<Collectable>> ThrowableContainer::vector;
std::vector<std::unique_ptr<Interactable>> ThrowableContainer::vector_interact;
std::vector<std::unique_ptr<Entity>> ThrowableContainer::vector_entity;
void ThrowableContainer::addItem(int id, float x, float y) {
    if (id == 3) {
        vector.push_back(std::make_unique<Coin>(x, y));
    }
    if (id == 5) {
        vector.push_back(std::make_unique<UniCard>(x, y));
    }
    if (id == 11) {
        vector.push_back(std::make_unique<CarWinchItem>(x, y));
    }
}void ThrowableContainer::addItem(int id, float x, float y, float add) {
    if (id == 4) {
        vector.push_back(std::make_unique<Bullet>(x, y, add));
    }
}
ThrowableContainer& ThrowableContainer::operator=(ThrowableContainer&& eq) noexcept {
    if (this != &eq) {
        if (vector.empty()) {
            vector = std::move(ThrowableContainer::vector);
        }
    }
    return *this;
}

std::vector<std::unique_ptr<Collectable>> &ThrowableContainer::getVector() {
    return vector;
}

std::vector<std::unique_ptr<Interactable>> &ThrowableContainer::getInteractVector() {
    return vector_interact;
}

void ThrowableContainer::addItemInteract(int id, float x, float y) {
    if (id == 301) {
        vector_interact.push_back(std::make_unique<CarWinch>(x, y));
    }
}

void ThrowableContainer::addItemInteract(int id, float x, float y, float add) {
//TODO
}

void ThrowableContainer::addItem(int id, float x, float y, float add, float n, float m) {
    if (id == 4) {
        vector.push_back(std::make_unique<Bullet>(x, y, add, n, m));
    }
}

void ThrowableContainer::addItemEntity(int id, float x, float y, float add) {
    if(id == 7){
        vector_entity.push_back(std::make_unique<SmallComputers>(x,y));
    }
}

void ThrowableContainer::addItemEntity(int id, float x, float y, float add, float n, float m) {
//TODO
}

std::vector<std::unique_ptr<Entity>> &ThrowableContainer::getEntityVector() {
    return vector_entity;
}
