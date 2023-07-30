#include "../include/game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window, const sf::Font& font) : window(window), terminal(window, font) {
    // Constructor implementation (initialize game variables, etc.)
}

void Game::run() {
    std::cout << "Welcome to The Enigmatic Enclave: Survival Unveiled!" << std::endl;

    // Main game loop implementation
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        terminal.draw("Hello, world!");
        window.display();
    }
}
