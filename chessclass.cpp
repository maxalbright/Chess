#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "chess.h"
using namespace std;

// Constructors; this is probably not the best way to do this

Rook::Rook(int row, int col, char let) : ChessPiece(row, col, let) {

}
Knight::Knight(int row, int col, char let) : ChessPiece(row, col, let) {

}
Bishop::Bishop(int row, int col, char let) : ChessPiece(row, col, let) {

}
Queen::Queen(int row, int col, char let) : ChessPiece(row, col, let) {

}
King::King(int row, int col, char let) : ChessPiece(row, col, let) {

}
Pawn::Pawn(int row, int col, char let) : ChessPiece(row, col, let) {

}


//Move Function: Check if the suggested move is plausible for that piece=
// If it isn't, print something and allow the player to move again

bool Rook::move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) {
	// If one of your pieces is already in that square, return false
	if (BoardArray[fr][fc]->isWhite == isWhite || fr < 0 || fr > 7 || fc < 0 || fc > 7 || whitesturn != isWhite) {
		return false;
	}

	// If it's not a straight line move or if it's not a move, return false

	if ((fr != rownum && fc != colnum) || (fr == rownum && fc == colnum)) {
		return false;
	}

	// If there is something in it's way of getting there, return false

	if (fr == rownum) {
		// Check to see if there is anything in that row before fr
		if (fc > colnum) {
			// Going from left to right
			for (int colindex = colnum + 1; colindex < fc; colindex++) {
				if (BoardArray[rownum][colindex]->letterforprinting != '-') {
					return false;
				}
			}
		}
		else {
			// Going from right to left
			for (int colindex = fc + 1; colindex < colnum; colindex++) {
				if (BoardArray[rownum][colindex]->letterforprinting != '-') {
					return false;
				}
			}

		}
	}
	else {
		// Check to see if there is anything in that column before fc
		if (fr > rownum) {
			// Going from top to bottom
			for (int rowindex = rownum + 1; rowindex < fr; rowindex++) {
				if (BoardArray[rowindex][colnum]->letterforprinting != '-') {
					return false;
				}
			}
		}
		else {
			// Going from bottom to top
			for (int rowindex = fr + 1; rowindex < rownum; rowindex++) {
				if (BoardArray[rowindex][colnum]->letterforprinting != '-') {
					return false;	
				}			
			}
		}

	}

	// At this point, it is a valid move; 
	// The following code works regardless of whether it is taking an empty square
	// or an opponent's piece

	delete [] BoardArray[fr][fc];
	int temprow = rownum;
	int tempcol = colnum;
	rownum = fr;
	colnum = fc;
	BoardArray[fr][fc] = this;
	BoardArray[temprow][tempcol] = new ChessPiece(temprow, tempcol, '-');
	BoardArray[temprow][tempcol]->isWhite = 2;

	return true;
}

bool Knight::move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) {
	// If one of your pieces is already in that square, return false
	if (BoardArray[fr][fc]->isWhite == isWhite || fr < 0 || fr > 7 || fc < 0 || fc > 7 || whitesturn != isWhite) {
		return false;
	}

	// Pythagorean Theorem to determine valid moves
	if (((fr - rownum) * (fr - rownum) + (fc - colnum) * (fc - colnum)) != 5) {
		return false;
	}

	// At this point, it is a valid move; 
	// The following code works regardless of whether it is taking an empty square
	// or an opponent's piece

	delete [] BoardArray[fr][fc];
	int temprow = rownum;
	int tempcol = colnum;
	rownum = fr;
	colnum = fc;
	BoardArray[fr][fc] = this;
	BoardArray[temprow][tempcol] = new ChessPiece(temprow, tempcol, '-');
	BoardArray[temprow][tempcol]->isWhite = 2;

	return true;
}


bool Bishop::move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) {
	// If one of your pieces is already in that square, return false
	if (BoardArray[fr][fc]->isWhite == isWhite || fr < 0 || fr > 7 || fc < 0 || fc > 7 || whitesturn != isWhite) {
		return false;
	}
	if ((abs(rownum - fr) != abs(colnum - fc)) || (fr == rownum && fc == colnum)) {
		return false;
	}

	if (fr > rownum && fc > colnum) {
		// Going from top left to bottom right
		int colindex = colnum + 1;
		for (int rowindex = rownum + 1; rowindex < fr; rowindex++) {
			if (BoardArray[rowindex][colindex]->letterforprinting != '-') {
				return false;
			}
			colindex++;
		}

	}
	else if (fr < rownum && fc < colnum) {
		// Going from bottom right to top left
		int colindex = fc + 1;
		for (int rowindex = fr + 1; rowindex < rownum; rowindex++) {
			if (BoardArray[rowindex][colindex]->letterforprinting != '-'){
				return false;
			}
			colindex++;

		}
		
	}

	else if (fr < rownum && fc > colnum) {
		// Going from bottom left to top right
		int colindex = fc - 1;
		for (int rowindex = fr + 1; rowindex < rownum; rowindex++) {
			if (BoardArray[rowindex][colindex]->letterforprinting != '-'){
				return false;
			}
			colindex--;
		}
		
	}
	else {
		// Going from top right to bottom left
		int colindex = colnum - 1;
		for (int rowindex = rownum + 1; rowindex < fr; rowindex++) {
			if (BoardArray[rowindex][colindex]->letterforprinting != '-') {
				return false;
			}
			colindex--;
		}

	}

	// At this point, it is a valid move;
	// The following code works regardless of whether it is taking an empty square
	// or an opponent's piece

	delete [] BoardArray[fr][fc];
	int temprow = rownum;
	int tempcol = colnum;
	rownum = fr;
	colnum = fc;
	BoardArray[fr][fc] = this;
	BoardArray[temprow][tempcol] = new ChessPiece(temprow, tempcol, '-');
	BoardArray[temprow][tempcol]->isWhite = 2;


	return true;
}



bool Queen::move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) {
	// If one of your pieces is already in that square, return false
	if (BoardArray[fr][fc]->isWhite == isWhite || fr < 0 || fr > 7 || fc < 0 || fc > 7 || whitesturn != isWhite) {
		return false;
	}
	if (fr == rownum && fc == colnum) {
		return false;
	}

	if (  (fr != rownum && fc != colnum)  &&  ((abs(rownum - fr) != abs(colnum - fc))) ){
		return false;
	}

	// Check if there is something blocking the Rook-Like Motion
	if (fr == rownum) {
		// Check to see if there is anything in that row before fr
		if (fc > colnum) {
			// Going from left to right
			for (int colindex = colnum + 1; colindex < fc; colindex++) {
				if (BoardArray[rownum][colindex]->letterforprinting != '-') {
					return false;
				}
			}
		}
		else {
			// Going from right to left
			for (int colindex = fc + 1; colindex < colnum; colindex++) {
				if (BoardArray[rownum][colindex]->letterforprinting != '-') {
					return false;
				}
			}

		}
	}
	else if (fc == colnum) {
		// Check to see if there is anything in that column before fc
		if (fr > rownum) {
			// Going from top to bottom
			for (int rowindex = rownum + 1; rowindex < fr; rowindex++) {
				if (BoardArray[rowindex][colnum]->letterforprinting != '-') {
					return false;
				}
			}
		}
		else {
			// Going from bottom to top
			for (int rowindex = fr + 1; rowindex < rownum; rowindex++) {
				if (BoardArray[rowindex][colnum]->letterforprinting != '-') {
					return false;	
				}			
			}
		}

	}
	else {
		// Check if there is something blocking the Bishop-Like Motion
		if (fr > rownum && fc > colnum) {
			// Going from top left to bottom right
			int colindex = colnum + 1;
			for (int rowindex = rownum + 1; rowindex < fr; rowindex++) {
				if (BoardArray[rowindex][colindex]->letterforprinting != '-') {
					return false;
				}
				colindex++;
			}

		}
		else if (fr < rownum && fc < colnum) {
			// Going from bottom right to top left
			int colindex = fc + 1;
			for (int rowindex = fr + 1; rowindex < rownum; rowindex++) {
				if (BoardArray[rowindex][colindex]->letterforprinting != '-'){
					return false;
				}
				colindex++;

			}
			
		}

		else if (fr < rownum && fc > colnum) {
			// Going from bottom left to top right
			int colindex = fc - 1;
			for (int rowindex = fr + 1; rowindex < rownum; rowindex++) {
				if (BoardArray[rowindex][colindex]->letterforprinting != '-'){
					return false;
				}
				colindex--;
			}
			
		}
		else {
			// Going from top right to bottom left
			int colindex = colnum - 1;
			for (int rowindex = rownum + 1; rowindex < fr; rowindex++) {
				if (BoardArray[rowindex][colindex]->letterforprinting != '-') {
					return false;
				}
				colindex--;
			}

		}

	}

	delete [] BoardArray[fr][fc];
	int temprow = rownum;
	int tempcol = colnum;
	rownum = fr;
	colnum = fc;
	BoardArray[fr][fc] = this;
	BoardArray[temprow][tempcol] = new ChessPiece(temprow, tempcol, '-');
	BoardArray[temprow][tempcol]->isWhite = 2;
	return true;
}

bool King::move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) {
	// If one of your pieces is already in that square, return false
	if (BoardArray[fr][fc]->isWhite == isWhite || fr < 0 || fr > 7 || fc < 0 || fc > 7 || whitesturn != isWhite) {
		return false;
	}
	if (fr == rownum && fc == colnum) {
		return false;
	}

	if (abs(fr - rownum) > 1 || abs(fc - colnum) > 1) {
		return false;
	}

	delete [] BoardArray[fr][fc];
	int temprow = rownum;
	int tempcol = colnum;
	rownum = fr;
	colnum = fc;
	BoardArray[fr][fc] = this;
	BoardArray[temprow][tempcol] = new ChessPiece(temprow, tempcol, '-');
	BoardArray[temprow][tempcol]->isWhite = 2;
	return true;
}

bool Pawn::move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) {
	// If one of your pieces is already in that square, return false
	if (BoardArray[fr][fc]->isWhite == isWhite || fr < 0 || fr > 7 || fc < 0 || fc > 7 || whitesturn != isWhite) {
		return false;
	}
	if (fr == rownum && fc == colnum) {
		return false;
	}

	if (whitesturn == 1) {
		// White Pawn Rules
		if (rownum == 6) {
			if (rownum - fr != 1 && rownum - fr != 2) {
				return false;
			}
		}
		else if (rownum - 1 != fr || !(abs(fc - colnum) < 2)) {
			return false;
		}

		if (abs(fc - colnum) == 1 && BoardArray[fr][fc]->isWhite != -1) {
			return false;
		}

	}
	else {
		// Black Pawn Rules
		if (rownum == 1) {
			if (fr - rownum != 1 && fr - rownum != 2) {
				return false;
			}
		}
		else if (fr - 1 != rownum || !(abs(fc - colnum) < 2)) {
			return false;
		}

		if (abs(fc - colnum) == 1 && BoardArray[fr][fc]->isWhite != 1) {
			return false;
		}

	}
	delete [] BoardArray[fr][fc];
	int temprow = rownum;
	int tempcol = colnum;
	rownum = fr;
	colnum = fc;
	BoardArray[fr][fc] = this;
	BoardArray[temprow][tempcol] = new ChessPiece(temprow, tempcol, '-');
	BoardArray[temprow][tempcol]->isWhite = 2;


	return true;
}
