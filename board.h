#ifndef BOARD_H
#define BOARD_H
//#include "cell.h"

template<class T>
class Board {
public:

	//Constructors
	Board();

	Board(const T &val, int padWidth, int bs);

	//Copy
	Board(const Board<T> &other);

	//Assignment
	Board<T> &operator=(const Board<T> &other);

	//Destructor
	~Board();

	// Return size (same for both dimensions) of board.
	int getSize() const;
	void setSize(int s) {
		boardSize = s;
	}
	
	//Display board
	void display() const;

	//Get location on the board
	T getPos(int row, int col) const;
	
	//Set the position to a spot on the board
	void setPos(int row, int col, const T &val);
	
	//Reset the board
	void reset();

	void playerInfo(int player);
	void setCellValue();

private:
	//Initial values
	T initialValue;

	//Width of the board cell
	int paddingWidth;

	//declare array that is the board
	//declare array that is holds the cell values
	T **grid;
	Cell **cells;

	//board size
	int boardSize;
};

#endif
