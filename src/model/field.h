#ifndef ___FIELD_H___
#define ___FIELD_H___

#include<vector>
#include"cell.h"

class Field
{
public:
	Field();
	const Cell& getCell(int r, int c) const ;
	void setCell(int r, int c, typeCell type);
	void clear();



private:
	std::vector<Cell> cells_;
};



#endif