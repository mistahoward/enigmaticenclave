#ifndef TERMINAL_H
#define TERMINAL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Terminal {
public:
    Terminal(sf::RenderWindow& window, const sf::Font& font);

    void draw();

    void write(const std::string& message);
    
    void handleInput();

    void handleKeyPress(sf::Uint32 keyCode);

    void update();

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;
    sf::Shader crtShader;
    sf::RenderTexture sceneTexture;
    sf::Sprite sceneSprite;
};

#endif // TERMINAL_H
