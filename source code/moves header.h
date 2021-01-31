#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED
#include<stdbool.h>


// white pawn move
int pawn_white(int i, int j, int x, int y,char b[][9], char c[][8]);
//black pawn move
int pawn_black(int i, int j, int x, int y,char b[][9], char c[][8]);
//rook move
int moveR(int i , int j , int x, int y, char b[][9], char c[][8]);
//bishop move
int moveB(int i , int j , int x, int y, char b[][9], char c[][8]);
// queen function
int moveQ(int i, int j, int x, int y, char b[][9], char c[][8]);
//king move
int moveK(int i , int j , int x, int y, char b[][9], char c[][8]);
//knight move
int moveN(int i, int j, int x, int y, char b[][9], char c[][8]);
//graveyard
void knocked(int i, int j, int x, int y);
// in case of undo or redo send king's position
void king_position(char[][9]);
//check
bool check_white(char b[][9]);
bool check_black(char b[][9]);
int ischeck(int i, int j ,int x, int y , char b[][9]);

bool illegal_wking(char b[][9]);
bool illegal_bking(char b[][9]);
//Stalemate
int Stalemate_Black(int counter ,char board[][9]);
int Stalemate_White(int counter ,char board[][9]);
//draw
int Draw(char b[][9]);
//checkmate
int Checkmate_white(char b[][9]);
int Checkmate_black(char b[][9]);

//Castling
void Trace_rSquares(char b[][9]);
void Trace_rSquares_Undo(char b[][9]);
void Trace_rSquares_Redo(char b[][9]);
void Trace_Kings_Undo(char b[][9]);
void Trace_Kings_Redo(char b[][9]);
#endif // MOVES_H_INCLUDED
