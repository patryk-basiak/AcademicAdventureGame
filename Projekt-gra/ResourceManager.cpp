
#include <map>
#include "ResourceManager.h"
#include "SFML/Graphics/Texture.hpp"
#include "fmt/core.h"
// created based on https://stackoverflow.com/questions/41559116/understanding-how-to-add-data-to-a-map-with-sfml-functions
std::map<std::string, sf::Texture> ResourceManager::textures;

sf::Texture &ResourceManager::getTexture(const std::string &filename) {
    auto it = textures.find(filename);
    if (it == textures.end()) {
        sf::Texture tex;
        if (tex.loadFromFile(filename)) {
            auto inserted = textures.insert(std::make_pair(filename, std::move(tex)));
            return inserted.first->second;
        } else {
            fmt::println("Error: unable to read image");
        }
    }
    return it->second;
}
