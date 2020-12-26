#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "chess.h"
using namespace std;

int main(int argc, char* argv[]) {
	ChessGame match;
	ChessPiece* BoardArray[8][8];
	match.initializeBoard(BoardArray);
	match.printChessboard(BoardArray);

	int whitesturn = 1; // 1 when it is white's turn, -1 when it is black's

	// Main loop
	while (match.gamenotover) {
		cout << endl;
		// move returns true if it worked, so this loop should continue
		// until a proper move was played
		int ir, ic, fr, fc;
		do 
		{
		cout << "What is your next move in the form 'initialrow initialcol finalrow finalcol' : " << endl;
		
		cin >> ir >> ic >> fr >> fc;} while (!(BoardArray[ir][ic]->move(fr, fc, BoardArray, whitesturn)));

		whitesturn *= -1;
		match.printChessboard(BoardArray);
	}
	

	match.printChessboard(BoardArray);
	deallocateBoardArray(BoardArray);
	return 1;
}

void deallocateBoardArray(ChessPiece* BoardArray [][8]) {
	for (int i=0; i < 8; i++) {
		for (int y = 0; y < 8; y++) {
			delete [] BoardArray[i][y];
		}
	}
}








