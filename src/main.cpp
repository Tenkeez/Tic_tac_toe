#include <iostream>
#include <model/field.h>
int main(int argc, char* argv[])
{
	Field f;

	if (f.getCell(1, 1).getType() == typeCell::X)
	{
		std::cout << "x";
	}

}