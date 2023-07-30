#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/terminal.h"
    
bool shaderLoaded = false;

    Terminal::Terminal(sf::RenderWindow& window, const sf::Font& font)
        : window(window), font(font)
    {
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
    text.setPosition(10.f, 10.f);

    float curvatureX = 3.0f;
    float curvatureY = 3.0f;
    float scanLineOpacityX = 1.0f;
    float scanLineOpacityY = 1.0f;
    float vignetteOpacity = 1.0f;
    float brightness = 4.0f;
    float vignetteRoundness = 2.0f;

    bool disableShader = false;

    if (disableShader || !crtShader.loadFromFile("./src/assets/vertex_shader.vert", "./src/assets/crt_shader.frag")) {
        if (disableShader) {
            std::cout << "Shader disabled." << std::endl;
        } else {
            std::cout << "Error loading shader." << std::endl;
        }
        shaderLoaded = false;
        } else {
            crtShader.setUniform("textureSampler", sf::Shader::CurrentTexture);
            crtShader.setUniform("curvature", sf::Vector2f(3.0f, 3.0f));
            crtShader.setUniform("screenResolution", sf::Vector2f(window.getSize().x, window.getSize().y));
            crtShader.setUniform("scanLineOpacity", sf::Vector2f(1.0f, 1.0f));
            crtShader.setUniform("vignetteOpacity", 1.0f);
            crtShader.setUniform("brightness", 4.0f);
            crtShader.setUniform("vignetteRoundness", 2.0f);
            shaderLoaded = true;
    }
    if (disableShader || !sceneTexture.create(window.getSize().x, window.getSize().y)) {
        if (disableShader) {
            std::cout << "Shader disabled." << std::endl;
        } else {
            std::cout << "Error loading shader." << std::endl;
        }
        // Handle error...
    } else {
        sceneSprite.setTexture(sceneTexture.getTexture());
        sceneSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    }
}

void Terminal::draw() {
    sceneTexture.clear(sf::Color::Black);
    
    sceneTexture.draw(text);
    sceneTexture.display();

    window.clear(sf::Color::Black);
    if (shaderLoaded) {
        sf::RenderStates states;
        states.shader = &crtShader;
        window.draw(sceneSprite, states);
    } else {
        window.draw(sceneSprite);
    }
}

void Terminal::write(const std::string& message) {
    text.setString(message);
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