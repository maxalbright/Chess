#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class ChessPiece {
  public:

  	int isWhite;
    // -1 for black, 1 for white, 0 for empty square
  	char letterforprinting;
  	
  	ChessPiece(int row, int col, char let) {rownum = row; 
  		colnum = col; isAlive = true; letterforprinting = let;}

  	virtual bool move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn) { return false;}
  	

  protected:
  	
  	bool isAlive;
  	int rownum;
  	int colnum;	
};

class ChessGame {
  public:
    /*
    void begin();
    void newturn();
    void gameover();
    */
    ChessGame() {gamenotover = true;}
    void initializeBoard(ChessPiece* BoardArray[][8]);
    void printChessboard(ChessPiece* BoardArray[][8]);
    bool gamenotover;

};


class Rook : public ChessPiece, public ChessGame{
  public:
  	Rook(int, int, char);
    bool move (int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn);

};


class Knight : public ChessPiece, public ChessGame {
  public:
  	Knight(int, int, char);
    bool move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn);


};

class Pawn : public ChessPiece, public ChessGame {

  public:
  	Pawn(int, int, char);
    bool move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn);


};


class Bishop : public ChessPiece, public ChessGame {
  public:
  	Bishop(int, int, char);
    bool move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn);


};


class Queen : public ChessPiece, public ChessGame{
  public:
  	Queen(int, int, char);
    bool move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn);

};

class King : public ChessPiece, public ChessGame {
  public:
  	King(int, int, char);
    bool move(int fr, int fc, ChessPiece* BoardArray[][8], int whitesturn);

};

void deallocateBoardArray(ChessPiece* BoardArray[][8]);


