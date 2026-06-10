#ifndef ___LOGIC_H___
#define ___LOGIC_H___

#include"field.h"

class gameLogic
{
public:


	typeCell checkWin(const Field& f);

private:

	typeCell checkColumn(const Field& f) const ;
	typeCell checkRow(const Field& f)  const ;
	typeCell checkDiagonal(const Field& f) const;
};



#endif