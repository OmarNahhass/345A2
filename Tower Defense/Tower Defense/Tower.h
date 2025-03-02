#ifndef TOWER_H
#define TOWER_H

#include "Critter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <functional>

class Critter;

class Tower
{
protected:
    int cost;
    int refundValue;
    int range;
    int power;
    int rateOfFire;
    int level;
    float lastShotTime;

    // List of observers
    std::list<std::function<void()>> observers;

public:
    sf::Vector2i position; // Position in the grid
    sf::Sprite sprite;     // Tower sprite

    Tower(int x, int y, int cost, int refundValue, int range, int power, float rateOfFire, sf::Texture &texture);
    virtual ~Tower(); // Virtual destructor

    virtual void shoot(std::vector<Critter> &target, float currentTime);
    void upgrade();
    int sell();

    void attachObserver(const std::function<void()> &observer);
    void notifyObservers();
};

#endif
