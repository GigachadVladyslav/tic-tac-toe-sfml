#include "include.hpp"

// Constructor for BoardArr class
BoardArr::BoardArr(sf::RenderWindow& window) {
    // Initialize grid with empty spaces
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col] = ' ';
        }
    }

    currentPlayer = 'X';  // Set the starting player
    cellSize = { window.getSize().x / 3.0f, window.getSize().y / 3.0f };  // Calculate cell size based on window size

    // Set up cells' positions and sizes
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cells[row][col].setSize(cellSize);  // Set size of the cell
            cells[row][col].setPosition(col * cellSize.x, row * cellSize.y);  // Set position of the cell
            cells[row][col].setOutlineThickness(4.0f);  // Set outline thickness
            cells[row][col].setOutlineColor(sf::Color::Black);  // Set outline color to black
        }
    }

    // Load textures for 'X' and 'O'
    if (!xTexture.loadFromFile("assets/x.png") || !oTexture.loadFromFile("assets/o.png")) {
        std::cerr << "Error: Could not load assets" << std::endl;
        exit(1);
    }

    // Set initial positions for the sprites
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            sprites[row][col].setPosition(cells[row][col].getPosition());
        }
    }
}

// Function to draw the board and its elements
void BoardArr::draw(sf::RenderWindow& window) {
    // Draw each cell and the sprite if there's an 'X' or 'O'
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            window.draw(cells[row][col]);  // Draw the cell
            if (grid[row][col] != ' ') {
                window.draw(sprites[row][col]);  // Draw 'X' or 'O' sprite if there is a value in the cell
            }
        }
    }
}

// Function to handle mouse click and update the board
void BoardArr::handleClick(sf::Vector2i mousePos) {
    int col = mousePos.x / cellSize.x;  // Determine the column based on mouse position
    int row = mousePos.y / cellSize.y;  // Determine the row based on mouse position

    // Only proceed if the click is inside the grid and the cell is empty
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
        grid[row][col] = currentPlayer;  // Set the current player's symbol in the grid

        // Set the sprite texture based on the current player
        if (currentPlayer == 'X') {
            sprites[row][col].setTexture(xTexture);
        }
        else {
            sprites[row][col].setTexture(oTexture);
        }

        // Scale the sprite to fit the cell size
        sprites[row][col].setScale(
            cellSize.x / xTexture.getSize().x,
            cellSize.y / xTexture.getSize().y
        );

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Function to manually set a value in a specific cell (used for resetting the board)
void BoardArr::setVal(int x, int y, int value) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        grid[y][x] = (value == 1) ? 'X' : (value == 2) ? 'O' : ' ';  // Set 'X', 'O', or empty space
    }
}

// Function to resize the cells (useful for resizing the board)
void BoardArr::setSize(sf::Vector2f newSize) {
    cellSize = newSize;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cells[row][col].setSize(newSize);  // Update cell size
        }
    }
}

// Function to reset the board to its initial state
void BoardArr::getResetBoard() {
    // Clear the grid and reset the textures
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col] = ' ';  // Reset the grid to empty
            sprites[row][col].setTexture(sf::Texture());  // Clear the sprite textures
        }
    }
    // Reset the current player to 'X'
    currentPlayer = 'X';
}

// Function to check for a winner or a draw
int BoardArr::checkWin() {
    // Check for a win in rows
    for (int row = 0; row < 3; ++row) {
        if (grid[row][0] != ' ' && grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]) {
            return grid[row][0] == 'X' ? 1 : 2;  // Return 1 if X wins, 2 if O wins
        }
    }

    // Check for a win in columns
    for (int col = 0; col < 3; ++col) {
        if (grid[0][col] != ' ' && grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col]) {
            return grid[0][col] == 'X' ? 1 : 2;  // Return 1 if X wins, 2 if O wins
        }
    }

    // Check for a win in diagonals
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return grid[0][0] == 'X' ? 1 : 2;
    }
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return grid[0][2] == 'X' ? 1 : 2;
    }

    // Check for a draw (if all cells are filled)
    bool isDraw = true;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row][col] == ' ') {
                isDraw = false;  // There are still empty spaces, so it's not a draw
                break;
            }
        }
    }
    if (isDraw) {
        return 0;  // Return 0 for a draw
    }

    return -1;  // Return -1 if the game is not over yet
}
