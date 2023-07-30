#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/terminal.h"
    
bool shaderLoaded = false;

Terminal::Terminal(sf::RenderWindow& window, const sf::Font& font)
    : window(window), font(font), shaderLoaded(false) {
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
    text.setPosition(10.f, 10.f);

    float curvatureX = 3.0f;
    float curvatureY = 3.0f;
    float screenResX = 640.0f;
    float screenResY = 480.0f;
    float scanLineOpacityX = 1.0f;
    float scanLineOpacityY = 1.0f;
    float vignetteOpacity = 1.0f;
    float brightness = 4.0f;
    float vignetteRoundness = 2.0f;

    if (!crtShader.loadFromFile("./src/assets/vertex_shader.vert", "./src/assets/crt_shader.frag")) {
        std::cout << "Error loading shader." << std::endl;
    } else {
        crtShader.setUniform("textureSampler", sf::Shader::CurrentTexture);
        crtShader.setUniform("curvature", sf::Vector2f(curvatureX, curvatureY));
        crtShader.setUniform("screenResolution", sf::Vector2f(screenResX, screenResY));
        crtShader.setUniform("scanLineOpacity", sf::Vector2f(scanLineOpacityX, scanLineOpacityY));
        crtShader.setUniform("vignetteOpacity", vignetteOpacity);
        crtShader.setUniform("brightness", brightness);
        crtShader.setUniform("vignetteRoundness", vignetteRoundness);
        shaderLoaded = true;
    }
}

void Terminal::draw() {
    window.clear(sf::Color::Blue);
    if (shaderLoaded) {
        window.draw(text, &crtShader);
    } else {
        window.draw(text);
    }
    window.display();
}

void Terminal::draw(const std::string& message) {
    text.setString(message);
    window.clear(sf::Color::Blue);
    if (shaderLoaded) {
        window.draw(text, &crtShader);
    } else {
        window.draw(text);
    }
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