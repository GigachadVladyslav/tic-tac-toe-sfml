#ifndef WINDOW_RENDER_HPP
#define WINDOW_RENDER_HPP

#include "include.hpp"

class WindowRender {
public:
    WindowRender(sf::RenderWindow& window, const std::string& textureFile = "assets/background.jpg");

    void draw(sf::RenderWindow& window);
    void resize(sf::RenderWindow& window); 

private:
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Vector2u textureSize;
};

#endif // WINDOW_RENDER_HPP
