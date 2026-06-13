#ifndef ___STATUS_H___
#define ___STATUS_H___

#include"field.h"

class statusOfGame
{
public:
	statusOfGame();

	enum class Status { WIN_X, WIN_O, DRAW, TURN_PLAYER_X, TURN_PLAYER_O,GAMEOVER };

	Status checkStatus() const;
	void changeStatus(Status status);

private:
	Status status_;
};



#endif