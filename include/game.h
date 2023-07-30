#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "terminal.h"

class Game {
public:
    Game(sf::RenderWindow& window, const sf::Font& font); // Accept window and font as parameters

    void run();

private:
    sf::RenderWindow& window;
    Terminal terminal;
};

#endif // GAME_H
