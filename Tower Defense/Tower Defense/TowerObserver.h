#ifndef TOWER_OBSERVER_H
#define TOWER_OBSERVER_H

#include "Tower.h"
#include <SFML/Graphics.hpp>

class TowerObserver
{
public:
    TowerObserver(Tower &tower, sf::RenderWindow &window);
    void updateView();

private:
    Tower &tower;
    sf::RenderWindow &window;
};

#endif