#include <iostream>
#include "controller/gameController.h"


void pField(Field& f)
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << "[";
			f.getCell(i, j).printType();
			std::cout << "]";
			if (j == 2)
				std::cout << std::endl;
		}
	}

	std::cout << std::endl;
}


int main(int argc, char* argv[])
{
	Field f;
	GameController c(f);
	pField(f);
	c.click_Processing(0,0);
	pField(f);
	c.click_Processing(2, 0);
	pField(f);
	c.click_Processing(1, 1);
	c.click_Processing(2, 2);
	c.click_Processing(1, 2);
	c.click_Processing(2, 1);

	pField(f);
	c.click_Processing(1,0);
	pField(f);
}