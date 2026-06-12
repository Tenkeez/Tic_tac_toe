#include <iostream>
#include <model/field.h>
#include<model/logic.h>


int main(int argc, char* argv[])
{
	Field f;

	gameLogic l;
	

	f.setCell(0, 0, typeCell::X);
	f.setCell(0, 1, typeCell::O);
	f.setCell(0, 2, typeCell::X);

	f.setCell(1, 0, typeCell::X);
	f.setCell(1, 1, typeCell::EMPTY);
	f.setCell(1, 2, typeCell::O);

	f.setCell(2, 0, typeCell::X);
	f.setCell(2, 1, typeCell::X);
	f.setCell(2, 2, typeCell::EMPTY);


	Cell c;
	std::cout<<l.isDraw(f)<<std::endl;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << "[";
			f.getCell(i, j).printType();
			std::cout << "]";

			if (j == 2)
			{
				std::cout << std::endl;
			}

		}
	}

	std::vector moves = l.getAvailableMoves(f);
	for (size_t i = 0; i < moves.size(); i++)
	{
		std::cout << moves[i].first << moves[i].second << std::endl;
	}


}