#include "include.hpp"

void Ai::init(int aiPlayer) {
    _aiPlayer = aiPlayer;
    _humanPlayer = (_aiPlayer == 1) ? 2 : 1;  // ��������� ��
}

void Ai::performMove(BoardArr& grid) {
    AiMove bestMove = getsBestMove(grid, _aiPlayer);  // �������� ������ ��� ��� ��
    std::cout << "AI moves to: " << bestMove.x << ", " << bestMove.y << std::endl;  // �������
    grid.setVal(bestMove.x, bestMove.y, _aiPlayer);  // ��������� ���
}


AiMove Ai::getsBestMove(BoardArr& grid, int player) {

    // �������� �������� �� ������ ��� �����
     int result = grid.checkWin();
    if (result == _aiPlayer) {
        return AiMove(10);  // ���� �� �������, ���������� ������� ����
    }
    else if (result == _humanPlayer) {
        return AiMove(-10);  // ���� ����� �������, ���������� ������ ����
    }
    else if (result == -1) {
        return AiMove(0);  // ���� �����, ���������� 0
    }

    std::vector<AiMove> moves;
    int bestMove = 0;

    // ���������� ��� ��������� ����
    for (int y = 0; y < grid.getSize(); y++) {
        for (int x = 0; x < grid.getSize(); x++) {
            if (grid.getVal(x, y) == 0) {  // ���� ������ �����
                AiMove move;
                move.x = x;
                move.y = y;
                grid.setVal(x, y, player);  // ��������� ���

                // ����������� ����� ��� ���������� ������
                if (player == _aiPlayer) {
                    move.score = getsBestMove(grid, _humanPlayer).score;  // ��� ��
                }
                else {
                    move.score = getsBestMove(grid, _aiPlayer).score;  // ��� ������
                }

                moves.push_back(move);
                grid.setVal(x, y, 0);  // �������� ���

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
