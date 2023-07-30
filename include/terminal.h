#ifndef TERMINAL_H
#define TERMINAL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Terminal {
public:
    Terminal(sf::RenderWindow& window, const sf::Font& font);

    void draw();
    void draw(const std::string& message);
    
    void handleInput();

    void handleKeyPress(sf::Uint32 keyCode);

    void update();

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Shader crtShader;
    sf::Text text;
    bool shaderLoaded;
};

#endif // TERMINAL_H
