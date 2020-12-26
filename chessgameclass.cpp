#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "chess.h"
using namespace std;


void ChessGame::initializeBoard(ChessPiece* BoardArray[][8]) {
	ifstream myfile("defaultChessboard.txt");
	char letter;
	for (int row = 0; row <= 7; row++) {
		for (int col = 0; col <= 7; col++) {
			myfile >> letter;
			// It is a blank square
			if (letter == '-') {
				BoardArray[row][col] = new ChessPiece(row, col, letter);
				BoardArray[row][col]->isWhite = 0;

			}
			else {
				
				// Assign the pointer to a specific type of piece through polymorphism. 

				if (letter == 'r' || letter == 'R') {
					BoardArray[row][col] = new Rook(row, col, letter);
				}
				else if (letter == 'n' || letter == 'N') {
					BoardArray[row][col] = new Knight(row, col, letter);

				}
				else if (letter == 'b' || letter == 'B') {
					BoardArray[row][col] = new Bishop(row, col, letter);
					
				}
				else if (letter == 'q' || letter == 'Q') {
					BoardArray[row][col] = new Queen(row, col, letter);
					
				}
				else if (letter == 'k' || letter == 'K') {
					BoardArray[row][col] = new King(row, col, letter);
					
				}								

				else if (letter == 'p' || letter == 'P') {
					cout << "Here" << endl;
					BoardArray[row][col] = new Pawn(row, col, letter);				
				}

				// Fix Color

				if (letter < 97) {
					(BoardArray[row][col])->isWhite = 1;
				}
				else {
					(BoardArray[row][col])->isWhite = -1;
				}


			}
			
		}
	}
	cout << endl;
	myfile.close();

}

void ChessGame::printChessboard(ChessPiece* BoardArray[][8]) {
	cout << "   0 1 2 3 4 5 6 7" << endl;
	for (int row = 0; row <= 7; row++) {
		cout << row << "  ";
		for (int col = 0; col <= 7; col++) {
			cout << (BoardArray[row][col])->letterforprinting << " ";
		}
		cout << endl;
	}
}
