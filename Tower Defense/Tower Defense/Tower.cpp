#include "Tower.h"
#include "Map.h"
#include <iostream>
#include <cmath>

// Constructor
Tower::Tower(int x, int y, int cost, int refundValue, int range, int powerAmount, float rateOfFire, sf::Texture &texture)
    : position(x, y), cost(cost), refundValue(refundValue), range(range),
      power(powerAmount), rateOfFire(rateOfFire), level(1), lastShotTime(0)
{
    sprite.setTexture(texture);

    int cellSize = WINDOWSIZE / ROWS;
    sprite.setPosition(x * cellSize, y * cellSize);
    sprite.setScale(
        static_cast<float>(cellSize) / sprite.getTexture()->getSize().x,
        static_cast<float>(cellSize) / sprite.getTexture()->getSize().y);
}

Tower::~Tower() {}

void Tower::shoot(std::vector<Critter> &critters, float currentTime)
{
    if (currentTime - lastShotTime < (1.0f / rateOfFire))
        return;

    int CELL_SIZE = WINDOWSIZE / ROWS;

    for (auto &critter : critters)
    {
        int critterGridX = critter.getPosition().x / CELL_SIZE;
        int critterGridY = critter.getPosition().y / CELL_SIZE;

        float dx = critterGridX - position.x;
        float dy = critterGridY - position.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= range)
        {
            lastShotTime = currentTime;
            critter.takeDamage(power, currentTime);
            break;
        }
    }

    critters.erase(std::remove_if(critters.begin(), critters.end(), [](const Critter &c)
                                  { return c.hitPoints <= 0; }),
                   critters.end());

    // Notify observer
    notifyObservers();
}

void Tower::upgrade()
{
    level++;
    power += 10;
    range += 1;

    // Notify observe
    notifyObservers();
}

int Tower::sell()
{
    notifyObservers();
    return refundValue * level;
}

void Tower::attachObserver(const std::function<void()> &observer)
{
    observers.push_back(observer);
}

void Tower::notifyObservers()
{
    for (const auto &observer : observers)
    {
        observer();
    }
}
