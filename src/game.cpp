#include "../include/game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window, const sf::Font& font) : terminal(window, font) {
    // Constructor implementation (initialize game variables, etc.)
}
void Game::run()
{
    std::cout << "Welcome to The Enigmatic Enclave: Survival Unveiled!" << std::endl;
    // Main game loop implementation
}
