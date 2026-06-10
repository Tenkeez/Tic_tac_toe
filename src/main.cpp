#include <iostream>
#include <model/field.h>
#include<model/logic.h>
int main(int argc, char* argv[])
{
	Field f;
	f.setCell(1, 2, typeCell::X);
	f.setCell(0, 2, typeCell::O);
	f.setCell(2, 2, typeCell::O);

	gameLogic l;
	Cell c;

	c.setType(l.checkWin(f));
	c.printType();

	f.clear();
	f.setCell(1, 0, typeCell::O);
	f.setCell(1, 1, typeCell::X);
	f.setCell(1, 2, typeCell::X);
	c.setType(l.checkWin(f));
	c.printType();

	f.clear();

	f.setCell(0, 0, typeCell::EMPTY);
	f.setCell(1, 1, typeCell::O);
	f.setCell(2, 2, typeCell::O);

	c.setType(l.checkWin(f));
	c.printType();

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << i << "," << j <<" = ";
			f.getCell(i, j).printType();
		}
	}

}