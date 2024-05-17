#pragma
#include <SFML/Graphics.hpp>
#include "../Player.h"

class Entity {

public:
    Entity(float x, float y, sf::Color color);
    Entity(float x, float y);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds();
    void update(sf::Time time);
    void collision(Player& player);
    sf::Vector2<float> getPosition();
    sf::Vector2<float> getSize();

    void setPosition(float d, float d1);

private:
    sf::RectangleShape entity;
    sf::Vector2<float> startPosition;
    bool toRight = true;


};
