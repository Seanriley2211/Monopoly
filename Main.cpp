#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "board.cpp"
#include "cell.cpp"

using namespace std;

const int BOARDSIZE = 11;
const char EMPTY_MARK = '.';
const int NUM_PLAYERS = 2;
const int MARKS_LEN = NUM_PLAYERS + 1;
const int CONFIG_POS = MARKS_LEN - 1;


int main() {
		
	Board<string> gameBoard(string(MARKS_LEN, EMPTY_MARK), MARKS_LEN, BOARDSIZE);

	gameBoard.setCellValue();
}