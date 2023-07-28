#ifndef TERMINAL_H
#define TERMINAL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Terminal {
    sf::Shader crtShader;
public:
    Terminal(sf::RenderWindow& window, const sf::Font& font);

    void draw();
    void draw(const sf::Shader& shader);
    
    void handleInput();

    void handleKeyPress(sf::Uint32 keyCode);

    void update();

private:
    sf::RenderWindow& window;
    const sf::Font& font;
    sf::Text text;
};

#endif // TERMINAL_H
