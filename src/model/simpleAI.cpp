#include"simpleAI.h"
#include<ctime>

std::pair<int, int> SimpleAI::makeMove(const std::vector<std::pair<int, int>> &AvailableMove)
{
	
	srand(time(nullptr));

	std::pair<int, int> move = AvailableMove[0 + rand() % AvailableMove.size()];

	return move;
}