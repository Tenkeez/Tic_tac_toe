#ifndef ___STATUS_H___
#define ___STATUS_H___

#include"field.h"


enum class Status { WIN_X, WIN_O, DRAW, TURN_PLAYER_X, TURN_PLAYER_O };

class statusOfGame
{
	statusOfGame();

	const Status& checkStatus() const;
	void changeStatus(Status status);

private:
	Status status_;
};



#endif