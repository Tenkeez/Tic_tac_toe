#ifndef  ___GAMECONTROLLER_H___
#define  ___GAMECONTROLLER_H___

#include"model/field"
#include"model/status.h"

class GameController
{
	GameController();

private:
	Field& field_;
	statusOfGame& status_;
};



#endif // ! ___GAMECONTROLLER_H___
