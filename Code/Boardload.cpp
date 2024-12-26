#include "include.hpp"

BoardArr::BoardArr(sf::RenderWindow& window) {
    // ������������� �������� ����
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col] = ' ';  // ������ ������
        }
    }

    currentPlayer = 'X';
    cellSize = { window.getSize().x / 3.0f, window.getSize().y / 3.0f };

    // ������������� ������� ������
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cells[row][col].setSize(cellSize);
            cells[row][col].setPosition(col * cellSize.x, row * cellSize.y);
            cells[row][col].setOutlineThickness(4.0f);
            cells[row][col].setOutlineColor(sf::Color::Black);
        }
    }

    if (!xTexture.loadFromFile("assets/x.png") || !oTexture.loadFromFile("assets/o.png")) {
        std::cerr << "Error: Could not load assets" << std::endl;
        exit(1);
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            sprites[row][col].setPosition(cells[row][col].getPosition());
        }
    }
}

void BoardArr::draw(sf::RenderWindow& window) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            window.draw(cells[row][col]);  // ������ ������
            if (grid[row][col] != ' ') {
                window.draw(sprites[row][col]);  // ������ ������, ���� ���� �����
            }
        }
    }
}

void BoardArr::handleClick(sf::Vector2i mousePos) {
    int col = mousePos.x / cellSize.x;
    int row = mousePos.y / cellSize.y;

    // ���������, ��� ���� ������ �������� ���� � ������ �����
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
        grid[row][col] = currentPlayer;

        // ���������� �������� ��� ���������������� �������
        if (currentPlayer == 'X') {
            sprites[row][col].setTexture(xTexture);
        }
        else {
            sprites[row][col].setTexture(oTexture);
        }

        // �������������� ������ ��� ������ ������
        sprites[row][col].setScale(
            cellSize.x / xTexture.getSize().x,
            cellSize.y / xTexture.getSize().y
        );

        // ����������� ������
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void BoardArr::setVal(int x, int y, int value) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        grid[y][x] = (value == 1) ? 'X' : (value == 2) ? 'O' : ' ';  // ����������� ����� � �������
    }
}

void BoardArr::setSize(sf::Vector2f newSize) {
    cellSize = newSize;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cells[row][col].setSize(newSize);
        }
    }
}

int BoardArr::checkWin() {
    // �������� �����
    for (int row = 0; row < 3; ++row) {
        if (grid[row][0] != ' ' && grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]) {
            return grid[row][0] == 'X' ? 1 : 2;  // X = 1, O = 2
        }
    }

    // �������� ��������
    for (int col = 0; col < 3; ++col) {
        if (grid[0][col] != ' ' && grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col]) {
            return grid[0][col] == 'X' ? 1 : 2;  // X = 1, O = 2
        }
    }

    // �������� ����������
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return grid[0][0] == 'X' ? 1 : 2;
    }
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return grid[0][2] == 'X' ? 1 : 2;
    }

    // �������� �� �����
    bool isDraw = true;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row][col] == ' ') {
                isDraw = false;
                break;
            }
        }
    }
    if (isDraw) {
        return 0; // �����
    }

    // ���� ������������
    return -1;
}
