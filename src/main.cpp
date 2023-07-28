#include "../include/game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fake Terminal");
    sf::Font font;
    if (!font.loadFromFile("./assets/space_mono.ttf")) {
        std::cout << "Error loading font." << std::endl;
        return 1;
    }

    Game game(window, font);

    game.run();

    return 0;
}
