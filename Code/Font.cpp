#include "include.hpp"

// Constructor for TitleText class
TitleText::TitleText(sf::RenderWindow& window, const std::string& title, int fontSize, const sf::Vector2f& position) {
    // Load font for the title text
    if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
        std::cerr << "Error: Could not load font" << std::endl;
    }

    // Main text setup
    text.setFont(font);                // Set the font for the main text
    text.setString(title);             // Set the title string
    text.setCharacterSize(fontSize);  // Set the font size
    text.setFillColor(sf::Color::White);  // Set the color to white

    // Calculate the bounds of the text to center it
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);  // Set the origin to the center of the text
    text.setPosition(position);        // Set the position of the text

    // Shadow text setup (for creating a shadow effect)
    shadow = text;                     // Copy the main text object
    shadow.setFillColor(sf::Color(0, 0, 0, 150));  // Set the shadow color to a semi-transparent black
    shadow.setPosition(text.getPosition().x + 3.0f, text.getPosition().y + 3.0f);  // Offset the shadow by (3, 3) pixels

    // Set outline for the main text
    text.setOutlineColor(sf::Color::Black);  // Set the outline color to black
    text.setOutlineThickness(2.0f);          // Set the outline thickness to 2 pixels
}

// Function to draw the text and its shadow on the window
void TitleText::draw(sf::RenderWindow& window) {
    window.draw(shadow);  // Draw the shadow first (behind the main text)
    window.draw(text);    // Draw the main text on top
}

// Function to update the title text
void TitleText::setTitle(const std::string& newTitle) {
    text.setString(newTitle);   // Update the main text string
    shadow.setString(newTitle); // Update the shadow text string

    // Recalculate the bounds of the new text to keep it centered
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);  // Recenter the text
    shadow.setOrigin(text.getOrigin());  // Align the shadow's origin with the main text's origin
}
