#include "include.hpp"

void Ai::init(int aiPlayer) {
    _aiPlayer = aiPlayer;
    _humanPlayer = (_aiPlayer == 1) ? 2 : 1;  // Противник ИИ
}

void Ai::performMove(BoardArr& grid) {
    AiMove bestMove = getsBestMove(grid, _aiPlayer);  // Получаем лучший ход для ИИ
    std::cout << "AI moves to: " << bestMove.x << ", " << bestMove.y << std::endl;  // Отладка
    grid.setVal(bestMove.x, bestMove.y, _aiPlayer);  // Совершаем ход
}


AiMove Ai::getsBestMove(BoardArr& grid, int player) {

    // Проводим проверку на победу или ничью
     int result = grid.checkWin();
    if (result == _aiPlayer) {
        return AiMove(10);  // Если ИИ выиграл, возвращаем высокий балл
    }
    else if (result == _humanPlayer) {
        return AiMove(-10);  // Если игрок выиграл, возвращаем низкий балл
    }
    else if (result == -1) {
        return AiMove(0);  // Если ничья, возвращаем 0
    }

    std::vector<AiMove> moves;
    int bestMove = 0;

    // Генерируем все возможные ходы
    for (int y = 0; y < grid.getSize(); y++) {
        for (int x = 0; x < grid.getSize(); x++) {
            if (grid.getVal(x, y) == 0) {  // Если клетка пуста
                AiMove move;
                move.x = x;
                move.y = y;
                grid.setVal(x, y, player);  // Совершаем ход

                // Рекурсивный вызов для следующего игрока
                if (player == _aiPlayer) {
                    move.score = getsBestMove(grid, _humanPlayer).score;  // Ход ИИ
                }
                else {
                    move.score = getsBestMove(grid, _aiPlayer).score;  // Ход игрока
                }

                moves.push_back(move);
                grid.setVal(x, y, 0);  // Отменяем ход

                if (player == _aiPlayer) {
                    int bestScore = -1000000;
                    for (int i = 0; i < moves.size(); i++) {
                        if (moves[i].score > bestScore) {
                            bestMove = i;
                            bestScore = moves[i].score;
                        }
                    }
                }
            }
        }
    }

   return bestMove;
  
}
