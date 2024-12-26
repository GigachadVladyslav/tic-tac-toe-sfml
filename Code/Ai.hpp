#ifndef AI_HPP
#define AI_HPP

#include "include.hpp"

struct AiMove {
	AiMove() : x(-1), y(-1), score(0) {}  // Инициализация значениями по умолчанию
	AiMove(int Score) : x(-1), y(-1), score(Score) {}
	int x;
	int y;
	int score;
};


class Ai {
public:
	void init(int aiPlayer);
	void performMove(BoardArr& grid);

private:

	AiMove getsBestMove(BoardArr&, int player);

	int _aiPlayer;
	int _humanPlayer;



};
#endif