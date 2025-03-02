#include "TowerObserver.h"

TowerObserver::TowerObserver(Tower &tower, sf::RenderWindow &window)
    : tower(tower), window(window)
{
    tower.attachObserver([this]()
                         { this->updateView(); });
}

void TowerObserver::updateView()
{
    window.clear();

    window.draw(tower.sprite);

    window.display();
}
