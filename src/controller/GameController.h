#ifndef  ___GAMECONTROLLER_H___
#define  ___GAMECONTROLLER_H___

#include"model/logic.h"
#include"model/status.h"
#include"model/simpleAI.h"
#include<functional>

class GameController
{
public:
	GameController(Field& field);

	void click_Processing(int r,int c);
	void makeMoveAI();
	void reset();
	void changeGameMode(bool mode);
	statusOfGame checkStatus();
	bool checkGameMode();

public:

	std::function<void()> changedBoard;
	std::function<void(statusOfGame::Status)> changedStatus;

private:
	Field& field_;

	statusOfGame game_status_;
	gameLogic logic_;

	SimpleAI ai_;
	bool isVsAI_;

private:
	statusOfGame::Status nextTurn(statusOfGame::Status status);
};



#endif // ! ___GAMECONTROLLER_H___
