#ifndef BOARDLOAD_HPP
#define BOARDLOAD_HPP

#include "include.hpp"

// Объявляем перечисление GameState
enum GameState {
    MainMenu,
    GamePlay,
    GameOver
};

class _BoardRender_ {
public:
    sf::Texture boardTexture;
    sf::Sprite boardSprite;

    // Конструктор
    _BoardRender_(sf::RenderWindow& window) {
        // Загружаем текстуру доски
        if (!boardTexture.loadFromFile("assets/board.png")) {
            std::cerr << "Error: Could not load board texture from 'assets/board.png'" << std::endl;
            return;
        }

        // Устанавливаем текстуру и масштабируем
        boardSprite.setTexture(boardTexture);
        adjustBoardScale(window);
    }

    // Масштабирование доски под размер окна
    void adjustBoardScale(sf::RenderWindow& window) {
        sf::Vector2u textureSize = boardTexture.getSize();
        sf::Vector2u windowSize = window.getSize();

        double scale = std::min(
            static_cast<double>(windowSize.x) / textureSize.x,
            static_cast<double>(windowSize.y) / textureSize.y
        );

        boardSprite.setScale(scale, scale);
        boardSprite.setOrigin(textureSize.x / 2.0, textureSize.y / 2.0);
        boardSprite.setPosition(windowSize.x / 2.0, windowSize.y / 2.0);
    }

    // Отрисовка доски
    void draw(sf::RenderWindow& window) {
        window.draw(boardSprite);
    }
};

class _BoardArr_ {
private:
    int board[3][3];
    bool turnoX;
    bool empate;
    int n[9];

    sf::Text winnerText;
    sf::Font font;

    sf::Texture textureX;
    sf::Texture textureO;

    sf::Sprite spriteX;
    sf::Sprite spriteO;

    double offsetX;

public:
    _BoardArr_() : turnoX(true), empate(false), offsetX(170.0) {
        // Инициализируем пустую доску
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 0;
            }
        }

        for (int i = 0; i < 9; ++i) {
            n[i] = 1;
        }

        if (!textureX.loadFromFile("assets/x.png")) {
            std::cerr << "Failed to load X texture" << std::endl;
        }
        if (!textureO.loadFromFile("assets/o.png")) {
            std::cerr << "Failed to load O texture" << std::endl;
        }

        spriteX.setTexture(textureX);
        spriteO.setTexture(textureO);

        if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
        }

        winnerText.setFont(font);
        winnerText.setCharacterSize(50);
        winnerText.setFillColor(sf::Color::Red);  // Цвет текста победителя
    }

    void handleClick(int x, int y, GameState& currentState) {
        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            if (board[y][x] == 0) {
                board[y][x] = turnoX ? 1 : 2; // 1 — крестик, 2 — нолик
                turnoX = !turnoX; // Переключаем ход

                if (checkWinner()) {
                    std::cout << (turnoX ? "O" : "X") << " wins!" << std::endl;
                    currentState = GameOver;
                }
            }
        }
    }

    void draw(sf::RenderWindow& window, int cellSize, int gap) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                double xPos = j * (cellSize + gap) + gap / 2.0 + offsetX;
                double yPos = i * (cellSize + gap) + gap / 2.0 - 50.0;

                if (board[i][j] == 1) {
                    spriteX.setPosition(xPos + (cellSize - spriteX.getGlobalBounds().width) / 2, yPos + (cellSize - spriteX.getGlobalBounds().height) / 2);
                    window.draw(spriteX);
                }
                else if (board[i][j] == 2) {
                    spriteO.setPosition(xPos + (cellSize - spriteO.getGlobalBounds().width) / 2, yPos + (cellSize - spriteO.getGlobalBounds().height) / 2);
                    window.draw(spriteO);
                }
            }
        }
    }

    void resetBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 0;
            }
        }
        turnoX = true;
        empate = false;
        winnerText.setString("");  // Скрыть текст победителя при сбросе
    }

    bool checkWinner() {
        // Проверка горизонталей
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
        }

        // Проверка вертикалей
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return true;
            }
        }

        // Проверка диагоналей
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }

        return false;
    }
};

#endif // BOARDLOAD_HPP
