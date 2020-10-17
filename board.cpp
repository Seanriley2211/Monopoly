#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "board.h"
//#include "cell.cpp"
using namespace std;

template<class T>
Board<T>::Board(const T &initVal, int padWidth, int bs)
{
	//number of columns
	boardSize = bs;

	//allocate first dimension
	grid = new T*[boardSize];

	//allocate second dimension
	for (int i = 0; i < boardSize; i++)
	{
		grid[i] = new T[boardSize];
	}

	initialValue = initVal;
	paddingWidth = padWidth;

	reset();  // set all positions with initial value passed

}

//Copy 
template<class T>
Board<T>::Board(const Board<T> &other) {

	//copy non-dynamic members
	boardSize = other.boardSize;

	//allocate 1st dimension
	grid = new T*[boardSize];

	//copy 1st dimension
	for (int i = 0; i < boardSize; i++)
	{
		grid[i] = new T[boardSize];
	}

	//allocate and copy 2nd dimension
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			grid[i][j] = other.grid[i][j];
		}
	}
}

//Assignment 
template<class T>
Board<T> &Board<T>::operator=(const Board<T> &other) {

	//check for self-assignment
	if (this != &other) {

		//copy non-dynamic
		boardSize = other.boardSize;

		//deallocate old 
		for (int i = 0; i < boardSize; i++)
		{
			//deallocate 2nd (inside)
			delete[] grid[i];
		}
		//deallocate 1st (outside)
		delete[] grid;

		//allocate new array for copy
		//allocate 1st dimension
		grid = new T*[boardSize];

		//copy 1st dimension
		for (int i = 0; i < boardSize; i++)
		{
			grid[i] = new T[boardSize];
		}

		//allocate and copy 2nd dimension
		for (int i = 0; i < boardSize; i++)
		{
			for (int j = 0; j < boardSize; j++)
			{
				grid[i][j] = other.grid[i][j];
			}
		}
	}
	//return self
	return *this;
}

//Destructor
template<class T>
Board<T>::~Board() {

	//deallocate
	for (int i = 0; i < boardSize; i++)
	{
		delete[] grid[i];
	}

	delete[] grid;

	//reset member variables
	boardSize = 0;

}

//Get board size
template<class T>
int Board<T>::getSize() const
{
	return boardSize;
}

//Display board
template<class T>
void Board<T>::display() const
{
	int i, j;

	//Give col numbers
	cout << "   ";
	for (j = 0; j < boardSize; j++)
		cout << "|" << setw(paddingWidth) << (j + 1);
	cout << endl;

	for (i = 0; i < boardSize; i++)
	{
		cout << setw(2) << setfill('0') << (i + 1) << " ";  // display row number

		for (j = 0; j < boardSize; j++)
		{
			if ((i > 0 && i < 10) && (j > 0 && j < 10)) {
				cout << "|" << setw(paddingWidth) << "   ";
			}
			else
			{
				// Display value at position.
				cout << "|" << setw(paddingWidth) << grid[i][j];
			}
		}

		cout << endl;  // each row on own line
	}
}

//Get position
template<class T>
T Board<T>::getPos(int row, int col) const
{
	//check for array out of bounds
	return (row > 0) ? grid[row - 1][col - 1] : grid[0][col - 1];

}

//Set position
template<class T>
void Board<T>::setPos(int row, int col, const T &val)
{
	// Place value at specified position on the board.
	grid[row - 1][col - 1] = val;
}

//Reset board
template<class T>
void Board<T>::reset()
{
	// Set all positions to the initial value.
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			grid[i][j] = initialValue;
}

//Player information
template<class T>
void Board<T>::playerInfo(int player) {

	cout << endl;
	cout << "Player " << player + 1 << " info: " << endl;

}

//Set the cell values
template<class T>
void Board<T>::setCellValue() {

	//allocate
	cells = new Cell*[boardSize];

	//allocate second dimension
	for (int i = 0; i < boardSize; i++)
	{
		cells[i] = new Cell[boardSize];
	}

	//open file
	ifstream inFile;
	string line;
	inFile.open("CellValues.txt");

	//Check for Error
	if (inFile.fail()) {
		cerr << "File does not exist!";
		exit(1);
	}

	int index = 0, max_num = 0;
	string type, name;

	istringstream inStream;
	while (getline(inFile, line)) {
		inStream.clear();
		inStream.str(line);

		inStream >> type >> index >> max_num >> name;

		for (int i = 0; i < boardSize; i++)
		{
			for (int j = 0; j < boardSize; j++)
			{
				if (cells[i, j] != NULL) {
					//cells[i, j] = new Cell();
					cells[i, j] = new Cell(index, max_num);
				}
			}
		}
	}

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			//cout << cells[i, j].getId();
		}
	}
}

#endif