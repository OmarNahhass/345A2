#include <stdio.h>
#include "Map.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>


int main() {
    // Initialize and display the map creation screen
    /*menuScreen();*/
    initializeMap();
    displayMap();

    if (isValidMap())
        startGame();

    return 0;
}
