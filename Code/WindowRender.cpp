#include "include.hpp"

WindowRender::WindowRender(sf::RenderWindow& window, const std::string& textureFile) {
    if (!backgroundTexture.loadFromFile(textureFile)) {
        std::cerr << "Error: Could not load background texture from " << textureFile << std::endl;
        return;
    }

    textureSize = backgroundTexture.getSize();
    resize(window); // Initial scaling
}

void WindowRender::draw(sf::RenderWindow& window) {
    window.draw(background);
}

void WindowRender::resize(sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();
    float scale = std::min(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
    background.setTexture(backgroundTexture);
    background.setScale(scale, scale);
}
