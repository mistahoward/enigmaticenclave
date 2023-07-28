// game.h

#ifndef GAME_H
#define GAME_H

#include "terminal.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game(sf::RenderWindow& window, const sf::Font& font); // Accept window and font as parameters

    void run();

private:
    Terminal terminal;
};

#endif // GAME_H
