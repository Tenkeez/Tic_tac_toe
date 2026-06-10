#ifndef ___LOGIC_H___
#define ___LOGIC_H___

#include"field.h"
#include<vector>

class gameLogic
{
public:


	typeCell checkWin(const Field& f);
	bool isDraw(const Field& f);
	std::vector<std::pair<int, int>> getAvailableMoves(const Field& f);
	bool isGameOver(const Field& f);
	bool isValidMove(const Field& f,int r,int c);

private:

	typeCell checkColumn(const Field& f) const ;
	typeCell checkRow(const Field& f)  const ;
	typeCell checkDiagonal(const Field& f) const;
};



#endif