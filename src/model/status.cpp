#include"status.h"


statusOfGame::statusOfGame()
{
	status_ = Status::TURN_PLAYER_X;
}

statusOfGame::Status statusOfGame::checkStatus() const
{
	return status_;
}

void statusOfGame::changeStatus(Status status)
{
	status_ = status;
}