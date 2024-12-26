#include "include.hpp"

sf::Font font;

Button_::Button_(sf::RenderWindow& window, const std::string& text, float posX, float posY, sf::Vector2f size, const sf::Font& font) {
    // Set button shape
    buttonShape.setSize(size);
    buttonShape.setFillColor(sf::Color(30, 58, 138));
    buttonShape.setPosition(posX - size.x / 2.0f, posY - size.y / 2.0f); // Center the button

    // Set button text
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(50);
    buttonText.setFillColor(sf::Color::White);


    // Center the text within the button
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    buttonText.setPosition(posX, posY);
}

void Button_::draw(sf::RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button_::isClicked(sf::Vector2i mousePos) const {
    return buttonShape.getGlobalBounds().contains(sf::Vector2f(mousePos));
}
