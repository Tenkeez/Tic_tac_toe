#include"cell.h"


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
