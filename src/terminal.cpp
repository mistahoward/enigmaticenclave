#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/terminal.h"

const std::string shaderCode = R"(
	#include "./assets/crt_shader.frag"
	)";
    
Terminal::Terminal(sf::RenderWindow& window, const sf::Font& font)
    : window(window), font(font) {
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
    text.setPosition(10.f, 10.f);
    if (!crtShader.loadFromMemory(shaderCode, sf::Shader::Fragment)) {
        std::cout << "Error loading shader." << std::endl;
    }
}

void Terminal::draw() {
    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();
}

void Terminal::draw(const sf::Shader& shader) {
    // Apply CRT shader effect to the whole window
    window.draw(text, &shader);
    window.display();
}

void Terminal::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
                handleKeyPress(event.text.unicode);
            }
        }
    }
}

void Terminal::handleKeyPress(sf::Uint32 keyCode) {
    // Handle the key press here.
    // For example, add the character to a buffer and process commands.
}

void Terminal::update() {
    // Update the terminal state here.
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fake Terminal");
    sf::Font font;
    if (!font.loadFromFile("../assets/space_mono.ttf")) {
        std::cout << "Error loading font." << std::endl;
        return 1;
    }

    Terminal terminal(window, font);

    while (window.isOpen()) {
        terminal.handleInput();
        terminal.update();
        terminal.draw();
    }

    return 0;
}
