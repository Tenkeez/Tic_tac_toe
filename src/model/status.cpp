#include"status.h"


statusOfGame::Status statusOfGame::checkStatus() const
{
	return status_;
}

void statusOfGame::changeStatus(Status status)
{
	status_ = status;

}