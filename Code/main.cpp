#include "include.hpp"


int main() {
    RenderWindow window(VideoMode(1380, 920), "Tic Tac Toe", Style::Titlebar | Style::Close);
    window.setMouseCursorVisible(true);

    _BoardArr_ boardArr;
    _WindowRender_ windowRend(window);
    _FontTitul_ fontTitul(window);
    _Button_Start_ startButton(window);
    _Button_Exit_ exitButton(window);
    _BoardRender_ loadBoard(window);
    _Button_Reset replayButton; 

    GameState currentState = MainMenu;

    int gap = 20;
    int cellSize = (1000 - 2 * gap) / 3;

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (currentState == MainMenu) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (startButton.isClicked(mousePos)) {
                        currentState = GamePlay;
                    }
                    if (exitButton.isClicked(mousePos)) {
                        window.close();
                    }
                }
            }
            else if (currentState == GamePlay) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    int x = (mousePos.x - gap) / (cellSize + gap);
                    int y = (mousePos.y - gap) / (cellSize + gap);

                    boardArr.handleClick(x, y, currentState);
                }
            }

            else if (currentState == GameOver) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (replayButton.isClicked(mousePos)) {
                        boardArr.resetBoard();
                        currentState = GamePlay;
                    }
                }
            }
        }

        window.clear();

        if (currentState == MainMenu) {
            windowRend.draw(window);
            fontTitul.draw(window);
            startButton.draw(window);
            exitButton.draw(window);
        }
        else if (currentState == GamePlay) {
            windowRend.draw(window);
            loadBoard.draw(window);
            boardArr.draw(window, cellSize, gap);
            if (boardArr.checkWinner()) {
                currentState = GameOver;
            }
        }
        else if (currentState == GameOver) {
            replayButton.draw(window);  // Отрисовываем кнопку "Play Again"
        }

        window.display();
    }

    return 0;
}
