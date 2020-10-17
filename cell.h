#ifndef CELL_H
#define CELL_H
#include <string>

class Cell
{
public:

	Cell();
	Cell(int index, int max);
	//Cell(string color, int index, int max, string name);

	//Get
	int getID();

private:

	//string color;
	int index;
	int max;
	//string name;
};

#endif


