//
// Created by UseR on 04.06.2024.
//

#include "TimeIncreaser.h"

void TimeIncreaser::setPosition(float x, float y)
{
    time.setPosition(x,y);

}

void TimeIncreaser::draw(sf::RenderWindow &window)
{
    window.draw(time);
}

sf::Vector2<float> TimeIncreaser::getSize()
{
    return Collectable::getSize(); //TODO
}

bool TimeIncreaser::isStackable() const
{
    return Stackable;
}

std::unique_ptr<Collectable> TimeIncreaser::clone() const
{
    return Collectable::clone();
}

int TimeIncreaser::getId()
{
    return id;
}

