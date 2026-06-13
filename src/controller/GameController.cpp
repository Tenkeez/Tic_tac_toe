#include"gameController.h"

GameController::GameController(Field& field):
	field_(field),
	logic_(),
	game_status_(),
	ai_()
{
	isVsAI_ = false;
}

void GameController::click_Processing(int r, int c)
{

	//если игра окончена
	statusOfGame::Status currentStatus = game_status_.checkStatus();
	if (currentStatus == statusOfGame::Status::WIN_X ||
		currentStatus == statusOfGame::Status::WIN_O ||
		currentStatus == statusOfGame::Status::DRAW) {
		return;
	}


	if (logic_.isValidMove(field_, r, c) == false)
		return;

	if (currentStatus == statusOfGame::Status::TURN_PLAYER_X)
	{
		field_.setCell(r, c, typeCell::X);
	}
	if (currentStatus == statusOfGame::Status::TURN_PLAYER_O)
	{
		field_.setCell(r, c, typeCell::O);
	}
	
	typeCell winner = logic_.checkWin(field_);
	if (winner == typeCell::X)
	{
		game_status_.changeStatus(statusOfGame::Status::WIN_X);
		return;
	}
	else if (winner == typeCell::O)
	{
		game_status_.changeStatus(statusOfGame::Status::WIN_O);
		return;
	}
	if (logic_.isDraw(field_))
	{
		game_status_.changeStatus(statusOfGame::Status::DRAW);
		return;
	}
		
	game_status_.changeStatus(nextTurn(game_status_.checkStatus()));

}

void GameController::makeMoveAI()
{
	if (!isVsAI_)
		return;

	int r = ai_.makeMove(logic_.getAvailableMoves(field_)).first;
	int c = ai_.makeMove(logic_.getAvailableMoves(field_)).second;
	click_Processing(r, c);

}

void GameController::reset()
{
	field_.clear();
	game_status_.changeStatus(statusOfGame::Status::TURN_PLAYER_X);
}

void GameController::changeGameMode(bool mode)
{
	isVsAI_ = mode;
}

statusOfGame::Status GameController::nextTurn(statusOfGame::Status status)
{
	if (status == statusOfGame::Status::TURN_PLAYER_X)
	{
		status = statusOfGame::Status::TURN_PLAYER_O;
	}
	else if (status == statusOfGame::Status::TURN_PLAYER_O)
	{
		status = statusOfGame::Status::TURN_PLAYER_X;
	}
	return status;
}