#pragma once

#include <vector>
#include <memory>
#include "objects/Collectable.h"
#include "objects/Coin.h"
#include "objects/UniCard.h"
#include "objects/CarWinchItem.h"
#include "objects/Interactable.h"


class ThrowableContainer {
public:
    static void addItem(int id, float x, float y);
    static void addItemInteract(int id, float x, float y);
    static void addItem(int id, float x, float y, float add);
    static void addItemInteract(int id, float x, float y, float add);
    static std::vector<std::unique_ptr<Collectable>>& getVector();
    static std::vector<std::unique_ptr<Interactable>>& getInteractVector();

    ThrowableContainer& operator=(ThrowableContainer&& eq) noexcept;

private:
    static std::vector<std::unique_ptr<Collectable>> vector;
    static std::vector<std::unique_ptr<Interactable>> vector_interact;
};