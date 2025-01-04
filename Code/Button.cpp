#include "include.hpp"

// Global font object for button text
sf::Font font;

// Constructor for Button_ class
Button_::Button_(sf::RenderWindow& window, const std::string& text, float posX, float posY, sf::Vector2f size, const sf::Font& font) {
    // Set button shape
    buttonShape.setSize(size);  // Set the size of the button
    buttonShape.setFillColor(sf::Color(30, 58, 138));  // Set button color (dark blue)
    // Set button position, centering the button based on provided position (posX, posY)
    buttonShape.setPosition(posX - size.x / 2.0f, posY - size.y / 2.0f);

    // Set button text properties
    buttonText.setFont(font);  // Set the font for the text
    buttonText.setString(text);  // Set the string (label) of the button
    buttonText.setCharacterSize(50);  // Set the font size for the text
    buttonText.setFillColor(sf::Color::White);  // Set the text color (white)

    // Center the text within the button
    sf::FloatRect textBounds = buttonText.getLocalBounds();  // Get bounds of the text
    // Set the origin of the text to its center for proper alignment
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    // Position the text at the center of the button
    buttonText.setPosition(posX, posY);
}

// Function to draw the button on the window
void Button_::draw(sf::RenderWindow& window) {
    window.draw(buttonShape);  // Draw the button shape (rectangle)
    window.draw(buttonText);   // Draw the button text
}

// Function to check if the button is clicked based on the mouse position
bool Button_::isClicked(sf::Vector2i mousePos) const {
    // Check if the mouse position is within the bounds of the button
    return buttonShape.getGlobalBounds().contains(sf::Vector2f(mousePos));
}
