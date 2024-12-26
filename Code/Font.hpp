#ifndef TITLETEXT_HPP
#define TITLETEXT_HPP

#include "include.hpp"

class TitleText {
public:
    TitleText(sf::RenderWindow& window, const std::string& title, int fontSize, const sf::Vector2f& position);

    void draw(sf::RenderWindow& window);
    void setTitle(const std::string& newTitle);

private:
    sf::Font font;
    sf::Text text;
    sf::Text shadow;
};

#endif // TITLETEXT_HPP
