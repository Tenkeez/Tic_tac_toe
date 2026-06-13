#ifndef ___SIMPLE_AI_H___
#define ___SIMPLE_AI_H___

#include<vector>

class SimpleAI
{
public:
	SimpleAI() {};

	std::pair<int, int> makeMove(const std::vector<std::pair<int, int>> &AvailableMoves);

private:

};


#endif
