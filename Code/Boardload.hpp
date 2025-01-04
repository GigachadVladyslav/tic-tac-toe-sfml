#ifndef BOARDArr_HPP
#define BOARDArr_HPP

#include "include.hpp"

class BoardArr {
public:
    BoardArr(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void handleClick(sf::Vector2i mousePos);
    int checkWin();


    void setVal(int x, int y, int value);  
    void setSize(sf::Vector2f newSize);    

    int getSize() const { return 3; }  
    int getVal(int x, int y) const { return grid[y][x]; }  
    void getResetBoard();

private:
    sf::RectangleShape cells[3][3];
    sf::Sprite sprites[3][3];
    sf::Texture xTexture, oTexture;
    sf::Vector2f cellSize;
    char grid[3][3]; 
    char currentPlayer;
};

#endif