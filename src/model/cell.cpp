#include"cell.h"
#include<iostream>

bool Cell::isEmpty() const
{
	if (type_ == typeCell::EMPTY)
		return true;
}

void Cell::setType(typeCell type)
{
	type_ = type;
}

typeCell Cell::getType() const
{
	return type_;
}

void Cell::printType() const
{
	switch (type_)
	{
	case typeCell::EMPTY:
		std::cout << "EMPTY";
		break;
	case typeCell::X:
		std::cout << "X";
		break;
	case typeCell::O:
		std::cout << "O";
		break;
	default:
		break;
	}

}
