#pragma once

#include <vector>
#include <memory>
#include "objects/Collectable.h"

template <typename T>
class ThrowableContainer {
public:

    static void addItems(const T& item) {
        vector.push_back(std::make_unique<T>(item));
    }

    ThrowableContainer& operator=(ThrowableContainer&& eq) noexcept {
        if (this != &eq) {  // Protect against self-assignment
            if (!eq.vector.empty()) {
                this->vector = std::move(eq.vector);
            }
        }
        return *this;
    }

private:
    static std::vector<std::unique_ptr<Collectable>> vector;

};
