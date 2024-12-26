#include "include.hpp"
#include "Ai.hpp"

enum GameState {
    MainMenu,
    GamePlay,
    GameOver
};

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(900, 600), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);
    window.setMouseCursorVisible(true);

    // Создание фона
    WindowRender background(window);

    // Доска
    BoardArr board(window);

    // Шрифт и заголовок
    sf::Font font;
    if (!font.loadFromFile("font/Parkinsans-Medium.ttf")) {
        std::cerr << "Error: Could not load font" << std::endl;
        return -1;
    }

    TitleText title(window, "Tic Tac Toe", 125, { window.getSize().x / 2.0f, 150.0f });

    GameState gameState = MainMenu;

    // Кнопки
    Button_ startButton(window, "Start", window.getSize().x / 2.0f, 350.0f, { 300.0f, 65.0f }, font);
    Button_ exitButton(window, "Exit", window.getSize().x / 2.0f, 490.0f, { 300.0f, 65.0f }, font);

    // Инициализация AI
    Ai ai;
    ai.init(2);  // AI играет за "O" (2)

    bool playerTurn = false;  // Переменная, чтобы отслеживать чей ход

    // Основной цикл игры
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (gameState == MainMenu) {
                    if (startButton.isClicked(mousePos)) {
                        gameState = GamePlay;
                    }
                    if (exitButton.isClicked(mousePos)) {
                        window.close();
                    }
                }

                // Если игра продолжается, игрок делает ход
                if (gameState == GamePlay && playerTurn) {
                    board.handleClick(mousePos);  // Игрок делает ход
                    int result = board.checkWin();  // Проверка состояния игры

                    if (result == 1) {  // Игрок X победил
                        std::cout << "Player X wins!" << std::endl;
                        gameState = GameOver;
                    }
                    else if (result == 2) {  // Игрок O победил
                        std::cout << "Player O wins!" << std::endl;
                        gameState = GameOver;
                    }
                    else if (result == 0) {  // Ничья
                        std::cout << "It's a draw!" << std::endl;
                        gameState = GameOver;
                    }

                    // Меняем ход на AI после того, как игрок сделал свой ход
                    if (gameState == GamePlay) {
                        playerTurn = false;  // Теперь ход ИИ
                    }
                }

                // Если ход ИИ, выполняем его ход
                if (gameState == GamePlay && !playerTurn) {
                    ai.performMove(board);  // AI делает ход
                    int result = board.checkWin();  // Проверка состояния игры после хода AI

                    if (result == 1) {  // Игрок X победил
                        std::cout << "Player X wins!" << std::endl;
                        gameState = GameOver;
                    }
                    else if (result == 2) {  // Игрок O победил
                        std::cout << "Player O wins!" << std::endl;
                        gameState = GameOver;
                    }
                    else if (result == 0) {  // Ничья
                        std::cout << "It's a draw!" << std::endl;
                        gameState = GameOver;
                    }

                    // Меняем ход на игрока после хода AI
                    if (gameState == GamePlay) {
                        playerTurn = true;  // Теперь ход игрока
                    }
                }
            }
        }

        // Отображение игры
        window.clear();

        if (gameState == MainMenu) {
            background.draw(window);
            startButton.draw(window);
            exitButton.draw(window);
            title.draw(window);
        }
        if (gameState == GamePlay) {
            background.draw(window);
            board.draw(window);
        }
        if (gameState == GameOver) {
            // Логика для отображения завершения игры
            TitleText gameOverText(window, "Game Over", 100, { window.getSize().x / 2.0f, window.getSize().y / 2.0f });
            gameOverText.draw(window);
        }

        window.display();
    }

    return 0;
}
