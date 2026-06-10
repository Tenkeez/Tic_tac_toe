#include"field.h"
#include<iostream>

Field::Field()
{
	cells_.resize(9);

	for (size_t i = 0; i < 9; i++)
	{
		Cell cell;
		cells_[i] = cell;
	}

}

const Cell& Field::getCell(int r, int c) const
{
	if (r < 0 || r>= 3 || c < 0 || c>=3)
	{
		throw std::out_of_range("Out of range\n");
		
	}
	else
	{
		return cells_[c * 3 + r];
	}

}

void Field::setCell(int r, int c, typeCell type)
{
	if (r < 0 || r >= 3 || c < 0 || c >= 3)
	{
		throw std::out_of_range("Out of range\n");

	}
	else
	{
		cells_[c * 3 + r].setType(type);
	}

}


void Field::clear()
{
	for (size_t i = 0; i < cells_.size(); i++)
	{
		cells_[i].setType(typeCell::EMPTY);
	}
}