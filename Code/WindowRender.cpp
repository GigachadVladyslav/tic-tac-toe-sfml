#include "include.hpp"

// Constructor for the WindowRender class
// It initializes the background texture and resizes it to fit the window.
WindowRender::WindowRender(sf::RenderWindow& window, const std::string& textureFile) {
    // Attempt to load the texture from the specified file
    if (!backgroundTexture.loadFromFile(textureFile)) {
        std::cerr << "Error: Could not load background texture from " << textureFile << std::endl;
        return; // Exit constructor if loading fails
    }

    // Get the size of the texture for later calculations
    textureSize = backgroundTexture.getSize();

    // Adjust the texture's scaling to fit the window size
    resize(window); // Initial scaling
}

// Function to draw the background on the window
void WindowRender::draw(sf::RenderWindow& window) {
    window.draw(background); // Render the background sprite on the given window
}

// Function to resize the background texture to fit the window
void WindowRender::resize(sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize(); // Get the current window size

    // Calculate the scaling factor to maintain aspect ratio
    float scale = std::min(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );

    background.setTexture(backgroundTexture); // Set the loaded texture to the sprite
    background.setScale(scale, scale);       // Apply the calculated scaling factor
}
