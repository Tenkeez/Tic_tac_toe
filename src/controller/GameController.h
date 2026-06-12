#ifndef  ___GAMECONTROLLER_H___
#define  ___GAMECONTROLLER_H___

#include"model/logic.h"
#include"model/status.h"

class GameController
{
public:
	GameController(Field& field);

	void click_Processing(int r,int c);
	void reset();
private:
	Field& field_;

	statusOfGame game_status_;
	gameLogic logic_;

private:
	statusOfGame::Status nextTurn(statusOfGame::Status status);
};



#endif // ! ___GAMECONTROLLER_H___
