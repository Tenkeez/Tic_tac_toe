#ifndef ___CELL_H___
#define ___CELL_H___

enum class typeCell{EMPTY,X,O};

struct Cell
{
	bool isEmpty() const;
	void setType(typeCell type);
	typeCell getType() const;
	void printType() const;

private:
	typeCell type_ = typeCell::EMPTY;
};



#endif