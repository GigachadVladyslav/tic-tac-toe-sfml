#ifndef BUTTON_HPP
#define BUTTON_HPP


#include "include.hpp"  

class Button_ {
public:
    Button_(sf::RenderWindow& window, const std::string& text, float posX, float posY, sf::Vector2f size, const sf::Font& font);

    void draw(sf::RenderWindow& window);
    bool isClicked(sf::Vector2i mousePos) const;

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
};

#endif // BUTTON_HPP
