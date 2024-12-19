#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "include.hpp"  

namespace game {

    class _FontTitul_ {
    public:
        sf::Font font;
        sf::Text titul;
        sf::Text shadow;

        _FontTitul_(sf::RenderWindow& window) {
            if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
                std::cerr << "Error: Could not load font" << std::endl;
            }

            titul.setFont(font);
            titul.setString("Tic Tac Toe");
            titul.setCharacterSize(125);
            titul.setFillColor(sf::Color::White);

            sf::FloatRect textBounds = titul.getLocalBounds();
            titul.setOrigin(textBounds.left + textBounds.width / 2.0, textBounds.top + textBounds.height / 2.0);
            titul.setPosition(window.getSize().x / 2.0, 200.0);

            shadow = titul;
            shadow.setFillColor(sf::Color(0, 0, 0, 150));
            shadow.setPosition(titul.getPosition().x + 3.0, titul.getPosition().y + 3.0);

            titul.setOutlineColor(sf::Color::Black);
            titul.setOutlineThickness(2.0);
        }

        void draw(sf::RenderWindow& window) {
            window.draw(shadow);
            window.draw(titul);
        }
    };

    class _Button_Start_ {
    public:
        sf::Font font;
        sf::Text buttonText;
        sf::RectangleShape button;

        _Button_Start_(sf::RenderWindow& window) {
            if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
                std::cerr << "Error: Could not load font" << std::endl;
            }

            buttonText.setFont(font);
            buttonText.setString("Start");
            buttonText.setCharacterSize(50);
            buttonText.setFillColor(sf::Color::Black);


            sf::FloatRect textBounds = buttonText.getLocalBounds();
            buttonText.setOrigin(textBounds.left + textBounds.width / 2.0, textBounds.top + textBounds.height / 2.0);
            buttonText.setPosition(window.getSize().x / 2.0, 400.0);

            button.setSize(sf::Vector2f(300.0, 75.0));
            button.setFillColor(sf::Color(30, 58, 138));
            buttonText.setFillColor(sf::Color::White);
            button.setPosition(window.getSize().x / 2.0 - 150.0, 360.0);
        }

        void draw(sf::RenderWindow& window) {
            window.draw(button);
            window.draw(buttonText);
        }

        bool isClicked(sf::Vector2i mousePos) {
            sf::FloatRect bounds = button.getGlobalBounds();
            return bounds.contains(sf::Vector2f(mousePos));
        }
    };

    class _Button_Exit_ {
    public:
        sf::Font font;
        sf::Text buttonText_ex;
        sf::RectangleShape button;

        _Button_Exit_(sf::RenderWindow& window) {
            if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
                std::cerr << "Error: Could not load font" << std::endl;
            }

            buttonText_ex.setFont(font);
            buttonText_ex.setString("Exit");
            buttonText_ex.setCharacterSize(50);
            buttonText_ex.setFillColor(sf::Color::Black);

            sf::FloatRect textBounds_2 = buttonText_ex.getLocalBounds();
            buttonText_ex.setOrigin(textBounds_2.left + textBounds_2.width / 2.0, textBounds_2.top + textBounds_2.height / 2.0);
            buttonText_ex.setPosition(window.getSize().x / 2.0, 550.0);

            button.setSize(sf::Vector2f(300.0, 75.0));
            button.setFillColor(sf::Color(30, 58, 138));
            buttonText_ex.setFillColor(sf::Color::White);
            button.setPosition(window.getSize().x / 2.0 - 150.0, 510.0);
        }

        void draw(sf::RenderWindow& window) {
            window.draw(button);
            window.draw(buttonText_ex);
        }

        bool isClicked(sf::Vector2i mousePos) {
            sf::FloatRect bounds = button.getGlobalBounds();
            return bounds.contains(sf::Vector2f(mousePos));
        }
    };

    class _Button_Reset {
    private:
        sf::RectangleShape buttonShape;
        sf::Text buttonText;
        sf::Font font;

    public:
        _Button_Reset() {
            if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
                std::cerr << "Failed to load font" << std::endl;
            }

            buttonText.setFont(font);
            buttonText.setString("Play Again");
            buttonText.setCharacterSize(50);
            buttonText.setFillColor(sf::Color::White);

            buttonShape.setSize(sf::Vector2f(300.0f, 75.0f));
            buttonShape.setFillColor(sf::Color(30, 58, 138)); // Цвет фона кнопки
            buttonText.setPosition(500.0f, 510.0f);  // Центрирование кнопки
        }

        void draw(sf::RenderWindow& window) {
            window.draw(buttonShape);
            window.draw(buttonText);
        }

        bool isClicked(sf::Vector2i mousePos) {
            return buttonShape.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y));
        }
    };




    class _WindowRender_ {
    public:

        sf::Texture backgroundTexture;
        sf::Sprite background;
        sf::Vector2u textureSize;
        sf::Vector2u windowSize;

        _WindowRender_(sf::RenderWindow& window) {
            if (!backgroundTexture.loadFromFile("assets/background.jpg")) {
                std::cerr << "Error: Could not load background texture from 'assets/background.jpg'" << std::endl;
                return;
            }

            textureSize = backgroundTexture.getSize();
            windowSize = window.getSize();

            double scale = std::min(static_cast<double>(windowSize.x) / textureSize.x, static_cast<double>(windowSize.y) / textureSize.y);
            background.setTexture(backgroundTexture);
            background.setScale(scale, scale);

        };

        void draw(sf::RenderWindow& window) {
            window.draw(background);
        }
    };

   
}

#endif // GAMEMENU_H
