#include "include.hpp"

TitleText::TitleText(sf::RenderWindow& window, const std::string& title, int fontSize, const sf::Vector2f& position) {
    if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
        std::cerr << "Error: Could not load font" << std::endl;
    }

    // Main text
    text.setFont(font);
    text.setString(title);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    text.setPosition(position);

    // Shadow text
    shadow = text;
    shadow.setFillColor(sf::Color(0, 0, 0, 150)); // Semi-transparent black
    shadow.setPosition(text.getPosition().x + 3.0f, text.getPosition().y + 3.0f);

    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.0f);
}

void TitleText::draw(sf::RenderWindow& window) {
    window.draw(shadow); // Draw shadow first
    window.draw(text);   // Draw main text
}

void TitleText::setTitle(const std::string& newTitle) {
    text.setString(newTitle);
    shadow.setString(newTitle);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    shadow.setOrigin(text.getOrigin());
}
