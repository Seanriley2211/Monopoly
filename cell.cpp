#include <iostream>
#include <iomanip>
#include <string>
#include "cell.h"
using namespace std;

//Constructor
Cell::Cell(){
	//color = " ";
	index = 0;
	max = 0;
	//name = " ";
}

Cell::Cell(int i, int m) {
	index = i;
	max = m;
}

/*Cell(string color, int index, int max, string name){

	this.color = color;
	this.index = index;
	this.max = max;
	this.name = name;
}*/

//Get
int Cell::getID() {
	return index;
}
