#include "include.hpp"

// Enum to manage game states
enum GameState {
    MainMenu,   // Main menu state
    GamePlay,   // Gameplay state
    GameOver    // Game over state
};

int main() {
    // Create the window with specified size and title
    RenderWindow window(VideoMode(900, 600), "Tic Tac Toe", Style::Titlebar | Style::Close);
    window.setMouseCursorVisible(true);  // Make sure the mouse cursor is visible

    // Create background object
    WindowRender background(window);

    // Create the game board
    BoardArr board(window);

    // Load font for the text on buttons
    sf::Font font;
    if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
        std::cerr << "Error: Could not load font" << std::endl;
        return -1;
    }

    // Title text and messages for Game Over screen
    TitleText title(window, "Tic Tac Toe", 125, { window.getSize().x / 2.0f, 150.0f });
    TitleText gameOverText(window, "Game Over", 100, { window.getSize().x / 2.0f, window.getSize().y / 5.0f });
    TitleText playerXtext(window, "Player X win", 50, { window.getSize().x / 2.0f, window.getSize().y / 2.6f });
    TitleText playerYtext(window, "Player O win", 50, { window.getSize().x / 2.0f, window.getSize().y / 2.6f });
    TitleText playerDtext(window, "Draw", 50, { window.getSize().x / 2.0f, window.getSize().y / 2.6f });

    // Set the initial game state to MainMenu
    GameState gameState = MainMenu;

    // Create buttons for the main menu
    Button_ startButton(window, "Start", window.getSize().x / 2.0f, 350.0f, { 300.0f, 65.0f }, font);
    Button_ exitButton(window, "Exit", window.getSize().x / 2.0f, 490.0f, { 300.0f, 65.0f }, font);

    // Create buttons for the game over screen
    Button_ restartButton(window, "Restart", window.getSize().x / 2.0f, 350.0f, { 300.0f, 65.0f }, font);
    Button_ exitButtonGameOver(window, "Exit", window.getSize().x / 2.0f, 450.0f, { 300.0f, 65.0f }, font);

    // Variable to store the result of the game (-1 for ongoing, 0 for draw, 1 for Player X win, 2 for Player O win)
    int totalRes = -1;

    // Main game loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            // Close the window when the close event is triggered
            if (event.type == Event::Closed) {
                window.close();
            }

            // MainMenu state logic
            if (gameState == MainMenu) {
                if (event.type == Event::MouseButtonPressed) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    // Start the game if the Start button is clicked
                    if (startButton.isClicked(mousePos)) {
                        gameState = GamePlay;
                    }
                    // Exit the game if the Exit button is clicked
                    if (exitButton.isClicked(mousePos)) {
                        window.close();
                    }
                }
            }

            // GamePlay state logic
            else if (gameState == GamePlay) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    board.handleClick(mousePos);  // Handle player move
                    int result = board.checkWin();  // Check game status

                    // Update the result and switch to GameOver state if there's a winner or draw
                    if (result == 1) {  // Player X wins
                        std::cout << "Player X wins!" << std::endl;
                        totalRes = 1;
                        gameState = GameOver;
                    }
                    else if (result == 2) {  // Player O wins
                        std::cout << "Player O wins!" << std::endl;
                        totalRes = 2;
                        gameState = GameOver;
                    }
                    else if (result == 0) {  // Draw
                        std::cout << "It's a draw!" << std::endl;
                        totalRes = 0;
                        gameState = GameOver;
                    }
                }
            }

            // GameOver state logic
            else if (gameState == GameOver) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    // Restart the game if the Restart button is clicked
                    if (restartButton.isClicked(mousePos)) {
                        gameState = GamePlay;
                        board.getResetBoard();  // Reset the board for the next game
                    }
                    // Exit the game if the Exit button is clicked
                    if (exitButtonGameOver.isClicked(mousePos)) {
                        window.close();
                    }
                }
            }
        }

        // Rendering the game window
        window.clear();  // Clear the window for the next frame

        // Draw elements based on the current game state
        if (gameState == MainMenu) {
            background.draw(window);  // Draw background
            title.draw(window);  // Draw title
            startButton.draw(window);  // Draw start button
            exitButton.draw(window);  // Draw exit button
        }
        else if (gameState == GamePlay) {
            background.draw(window);  // Draw background
            board.draw(window);  // Draw the game board
        }
        else if (gameState == GameOver) {
            background.draw(window);  // Draw background
            gameOverText.draw(window);  // Draw game over text
            // Show appropriate message based on the game result
            if (totalRes == 1) {
                playerXtext.draw(window);  // Show Player X win message
            }
            else if (totalRes == 2) {
                playerYtext.draw(window);  // Show Player O win message
            }
            else if (totalRes == 0) {
                playerDtext.draw(window);  // Show draw message
            }

            restartButton.draw(window);  // Draw restart button
            exitButtonGameOver.draw(window);  // Draw exit button on game over screen
        }

        // Display the updated content on the window
        window.display();
    }

    return 0;
}
