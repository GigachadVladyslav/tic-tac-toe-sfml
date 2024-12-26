#ifndef BOARDArr_HPP
#define BOARDArr_HPP

#include "include.hpp"

class BoardArr {
public:
    BoardArr(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void handleClick(sf::Vector2i mousePos);
    int checkWin();


    void setVal(int x, int y, int value);  // Новый метод для установки значения клетки
    void setSize(sf::Vector2f newSize);    // Новый метод для установки размера клеток

    int getSize() const { return 3; }  // Возвращаем размер поля 3x3
    int getVal(int x, int y) const { return grid[y][x]; }  // Возвращаем значение в клетке

private:
    sf::RectangleShape cells[3][3];
    sf::Sprite sprites[3][3];
    sf::Texture xTexture, oTexture;
    sf::Vector2f cellSize;
    char grid[3][3];  // Игровое поле
    char currentPlayer;
};

#endif
