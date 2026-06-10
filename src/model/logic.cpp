#include"logic.h"
#include<iostream>


typeCell gameLogic::checkWin(const Field& f)
{
	typeCell result = checkColumn(f);
	if (result != typeCell::EMPTY)
		return result;

	result = checkRow(f);
	if (result != typeCell::EMPTY)
		return result;

	result = checkDiagonal(f);
	if (result != typeCell::EMPTY)
		return result;
	
	
	return typeCell::EMPTY;
}

typeCell gameLogic::checkColumn(const Field& f) const
{

	for (size_t i = 0; i < 3; i++)
	{
		Cell c0 = f.getCell(0, i);
		Cell c1 = f.getCell(1, i);
		Cell c2 = f.getCell(2, i);
		if (c0.getType() != typeCell::EMPTY &&
			c0.getType() == c1.getType() &&
			c0.getType() == c2.getType())
		{
			return c0.getType();
		}
	}
	return typeCell::EMPTY;
}

typeCell gameLogic::checkRow(const Field& f) const
{

	for (size_t i = 0; i < 3; i++)
	{
		Cell c0 = f.getCell(i, 0);
		Cell c1 = f.getCell(i, 1);
		Cell c2 = f.getCell(i, 2);
		if (c0.getType() != typeCell::EMPTY &&
			c0.getType() == c1.getType() &&
			c0.getType() == c2.getType())
		{
			return c0.getType();
		}
	}
	return typeCell::EMPTY;

}

typeCell gameLogic::checkDiagonal(const Field& f) const
{
	Cell c0 = f.getCell(0, 0);
	Cell c1 = f.getCell(1, 1);
	Cell c2 = f.getCell(2, 2);

	Cell c3 = f.getCell(0, 2);
	Cell c4 = f.getCell(2, 0);

	if (c1.getType() != typeCell::EMPTY &&
		((c1.getType() == c0.getType() 
		&& c1.getType() == c2.getType())
		||(c1.getType() == c3.getType() 
		&& c1.getType() == c4.getType()))
		)
	{
		return c1.getType();
	}

	return typeCell::EMPTY;

}
