#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "ahmed hamdi ahmed_19017253_mariam mohamed ahmed_19017274 chess_executable_moves.h"
#include <math.h>

/**
* function to to check if moving the white rook or the white queen down will remove the check on the white king
* parameters: white_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_down_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    // white piece found
    while( x != 8)
    {
        x++;
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if (((x-1) + y) % 2  == 1)
            {
                board[x-1][y] = '.';
            }
            else
            {
                board[x-1][y] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        // black piece found
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x-1) + y) % 2  == 1)
            {
                board[x-1][y] = '.';
            }
            else
            {
                board[x-1][y] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            // check is removed after knocking the piece
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            //check is not removed after knocking the piece
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        //empty square
        if (((x-1) + y) % 2  == 1)
        {
            board[x-1][y] = '.';
        }
        else
        {
            board[x-1][y] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;
}
/**
* function to to check if moving the white rook or the white queen up will remove the check on the white king
* parameters: white_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_up_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 1)
    {
        x--;
        //white piece found
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if (((x+1) + y) % 2  == 1)
            {
                board[x+1][y] = '.';
            }
            else
            {
                board[x+1][y] = '-';
            }
            //printf("white piece\n");
            board[i][j] = white_piece;
            return 1;
        }
        //black piece found
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x+1) + y) % 2  == 1)
            {
                board[x+1][y] = '.';
            }
            else
            {
                board[x+1][y] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            //check is removed after knocking the black piece
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                printf("black piece not check\n");
                return 0;
            }
            //check is not removed after knocking the black piece
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                //printf("black piece check\n");
                return 1;
            }
        }
        // empty square found
        if (((x+1) + y) % 2  == 1)
        {
            board[x+1][y] = '.';
            //printf("white squre\n");
        }
        else
        {
            board[x+1][y] = '-';
            //printf("black square\n");
        }
        board[x][y] = white_piece;
        //check is removed after putting the white piece in that empty square
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
                //printf("white square check is removed\n");

            }
            else
            {
                board[x][y] = '-';
                //printf("black square check is removed\n");
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;

}
/**
* function to to check if moving the white rook or the white queen right will remove the check on the white king
* parameters: white_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_right_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( y != 8)
    {
        y++;
        //white piece found
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if ((x +(y-1)) % 2  == 1)
            {
                board[x][y-1] = '.';
            }
            else
            {
                board[x][y-1] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        //black piece found
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            char piece = board[x][y];
            if ((x + (y-1)) % 2  == 1)
            {
                board[x][y-1] = '.';
            }
            else
            {
                board[x][y-1] = '-';
            }
            board[x][y] = white_piece;
            board[i][j] = '.';
            if(!check_white(board))
            {
                if ((x + (y-1)) % 2  == 1)
                {
                    board[x][y-1] = '.';
                }
                else
                {
                    board[x][y-1] = '-';
                }
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            else
            {
                if ((x + (y-1)) % 2  == 1)
                {
                    board[x][y-1] = '.';
                }
                else
                {
                    board[x][y-1] = '-';
                }
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        if ((x + (y-1)) % 2  == 1)
        {
            board[x][y-1] = '.';
        }
        else
        {
            board[x][y-1] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;
}
/**
* function to to check if moving the white rook or the white queen left will remove the check on the white king
* parameters: white_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_left_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( y != 1)
    {
        y--;
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if ((x +(y+1)) % 2  == 1)
            {
                board[x][y+1] = '.';
            }
            else
            {
                board[x][y+1] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if ((x +(y+1)) % 2  == 1)
            {
                board[x][y+1] = '.';
            }
            else
            {
                board[x][y+1] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        if ((x +(y+1)) % 2  == 1)
        {
            board[x][y+1] = '.';
        }
        else
        {
            board[x][y+1] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;

}
/**
* function to to check if moving the white bishop or the white queen down right will remove the check on the white king
* parameters: white_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_down_right_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 8 && y != 8)
    {
        x++;
        y++;
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if (((x-1) + (y-1)) % 2  == 1)
            {
                board[x-1][y-1] = '.';
            }
            else
            {
                board[x-1][y-1] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x-1) + (y-1)) % 2  == 1)
            {
                board[x-1][y-1] = '.';
            }
            else
            {
                board[x-1][y-1] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        if (((x-1) + (y-1)) % 2  == 1)
        {
            board[x-1][y-1] = '.';
        }
        else
        {
            board[x-1][y-1] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;
}
/**
* function to to check if moving the white bishop or the white queen up right will remove the check on the white king
* parameters: white_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_up_right_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 1 && y != 8)
    {
        x--;
        y++;
        if(board[x][y] >= 'a' && board[x][y] <= 'z' && board[x][y] != '.' && board[x][y] != '-')
        {
            if (((x+1) + (y-1)) % 2  == 1)
            {
                board[x+1][y-1] = '.';
            }
            else
            {
                board[x+1][y-1] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x+1) + (y-1)) % 2  == 1)
            {
                board[x+1][y-1] = '.';
            }
            else
            {
                board[x+1][y-1] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        if (((x+1) + (y-1)) % 2  == 1)
        {
            board[x+1][y-1] = '.';
        }
        else
        {
            board[x+1][y-1] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;
}
/**
* function to to check if moving the white bishop or the white queen up left will remove the check on the white king
* parameters: white_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_up_left_white(char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 1 && y != 1)
    {
        x--;
        y--;
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if (((x+1) +(y+1)) % 2  == 1)
            {
                board[x+1][y+1] = '.';
            }
            else
            {
                board[x+1][y+1] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x+1) + (y+1)) % 2  == 1)
            {
                board[x+1][y+1] = '.';
            }
            else
            {
                board[x+1][y+1] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        if (((x+1) + (y+1)) % 2  == 1)
        {
            board[x+1][y+1] = '.';
        }
        else
        {
            board[x+1][y+1] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;
}
/**
* function to to check if moving the white bishop or the white queen down left will remove the check on the white king
* parameters: white_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_down_left_white( char white_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 8 && y != 1)
    {
        x++;
        y--;
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            if (((x-1) + (y+1)) % 2  == 1)
            {
                board[x-1][y+1] = '.';
            }
            else
            {
                board[x-1][y+1] = '-';
            }
            board[i][j] = white_piece;
            return 1;
        }
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x-1) + (y+1)) % 2  == 1)
            {
                board[x-1][y+1] = '.';
            }
            else
            {
                board[x-1][y+1] = '-';
            }
            char piece = board[x][y];
            board[x][y] = white_piece;
            board[i][j] = '.';
            if(!check_white(board))
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = white_piece;
                return 1;
            }
        }
        if (((x-1) + (y+1)) % 2  == 1)
        {
            board[x-1][y+1] = '.';
        }
        else
        {
            board[x-1][y+1] = '-';
        }
        board[x][y] = white_piece;
        if(!check_white(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = white_piece;
            return 0;
        }
    }
    if ((x + y) % 2  == 1)
    {
        board[x][y] = '.';
    }
    else
    {
        board[x][y] = '-';
    }
    board[i][j] = white_piece;
    return 1;
}
/**
* function to to check if there is a possible move for the white knight that can remove the check on the white king
* parameters: x number of row that the knight in
             y number of column the knight in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_wKnight(int i, int j, char board[][9])
{
    //up right
    if((i+2 <= 8 && j+1 <= 8) && !(board[i+2][j+1] >= 'a' && board[i+2][j+1] <= 'z'))
    {
        char square_content = board[i+2][j+1];
        board[i+2][j+1] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i+2][j+1] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i+2][j+1] = square_content;
            board[i][j] = 'n';
        }
    }
    //Down Left
    if((i+2 <= 8 && j-1 >= 1) && !(board[i+2][j-1] >= 'a' && board[i+2][j-1] <= 'z'))
    {
        char square_content = board[i+2][j-1];
        board[i+2][j-1] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i+2][j-1] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i+2][j-1] = square_content;
            board[i][j] = 'n';
        }
    }
    //Up right
    if((i-2 >= 1 && j+1 <= 8) && !(board[i-2][j+1] >= 'a' && board[i-2][j+1] <= 'z'))
    {
        char square_content = board[i-2][j+1];
        board[i-2][j+1] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i-2][j+1] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i-2][j+1] = square_content;
            board[i][j] = 'n';
        }
    }
    //Up left
    if((i-2 >= 1 && j-1 >= 1) && !(board[i-2][j-1] >= 'a' && board[i-2][j-1] <= 'z'))
    {
        char square_content = board[i-2][j-1];
        board[i-2][j-1] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i-2][j-1] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i-2][j-1] = square_content;
            board[i][j] = 'n';
        }
    }
    //Right down
    if((i+1 <= 8 && j+2 <= 8) && !(board[i+1][j+2] >= 'a' && board[i+1][j+2] <= 'z'))
    {
        char square_content = board[i+1][j+2];
        board[i+1][j+2] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i+1][j+2] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i+1][j+2] = square_content;
            board[i][j] = 'n';
        }
    }
    // left down
    if((i+1 <= 8 && j-2 >= 1) && (!(board[i+1][j-2] >= 'a' && board[i+1][j-2] <= 'z')))
    {
        char square_content = board[i+1][j-2];
        board[i+1][j-2] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i+1][j-2] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i+1][j-2] = square_content;
            board[i][j] = 'n';
        }
    }
    //Right Up
    if((i-1 >= 1 && j+2 <= 8) && !(board[i-1][j+2] >= 'a' && board[i-1][j+2] <= 'z'))
    {
        char square_content = board[i-1][j+2];
        board[i-1][j+2] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i-1][j+2] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i-1][j+2] = square_content;
            board[i][j] = 'n';
        }
    }
    //Left Up
    if((i-1 >= 1 && j-2 >= 1) && !(board[i-1][j-2] >= 'a' && board[i-1][j-2] <= 'z'))
    {
        char square_content = board[i-1][j-2];
        board[i-1][j-2] = 'n';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i-1][j-2] = square_content;
            board[i][j] = 'n';
            return 0;
        }
        else
        {
            board[i-1][j-2] = square_content;
            board[i][j] = 'n';
        }
    }
    return 1;
}
/**
* function to to check if there is a possible move for the white pawn that can remove the check on the white king
* parameters: x number of row that the pawn in
             y number of column the pawn in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_wPawn(int i, int j, char board[][9])
{
    if(i-1 >= 1 && (board[i-1][j] == '.' || board[i-1][j] == '-'))
    {
        char square_color = board[i-1][j];
        board[i-1][j] = 'p';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i - 1][j] = square_color;
            board[i][j] = 'p';
            return 0;
        }
        else
        {
            board[i - 1][j] = square_color;
            board[i][j] = 'p';
        }
    }
    if ((i - 1 >= 1) &&(j-1  >= 1)&& (board[i-1][j-1] >= 'A' && (board[i-1][j-1]) <= 'Z'))
    {
        char piece = board[i-1][j-1];
        board[i-1][j-1] = 'p';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i-1][j-1] = piece;
            board[i][j] = 'p';
            return 0;
        }
        else
        {
            board[i-1][j-1] = piece;
            board[i][j] = 'p';
        }
    }
    if((i - 1 >= 1) && (j+1 <= 8)&& (board[i-1][j+1] >= 'A' && (board[i-1][j+1]) <= 'Z'))
    {
        char piece = board[i-1][j+1];
        board[i-1][j+1] = 'p';
        board[i][j] = '.';
        if(!check_white(board))
        {
            board[i-1][j+1] = piece;
            board[i][j] = 'p';
            return 0;
        }
        else
        {
            board[i-1][j+1] = piece;
            board[i][j] = 'p';
        }
    }
    return 1;

}
/**
* function to to check if there is a possible move for the white rook that can remove the check on the white king
* parameters: x number of row that the rook in
             y number of column the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_wRook(int i, int j, char board[][9])
{
    int x = i;
    int y = j;
    //up
    int up = Check_up_white('r',x,y,board);
    if(up == 0)
    {
        return 0;
    }
    //down
    x = i;
    y = j;
    int down = Check_down_white('r',x,y,board);
    if (down == 0)
    {
        return 0;
    }
    //Right
    x = i;
    y = j;
    int right = Check_right_white('r',x,y,board);
    if (right == 0)
    {
        return 0;
    }
    //Left
    x = i;
    y = j;
    int left = Check_left_white('r',x,y,board);
    if (left == 0)
    {
        return 0;
    }
    return 1;
}
/**
* function to to check if there is a possible move for the white bishop that can remove the check on the white king
* parameters: x number of row that the bishop in
             y number of column the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_wBishop(int i, int j, char board[][9])
{
    int x = i;
    int y = j;
    //up_right
    int Up_right = Check_up_right_white('b',x,y,board);
    if(Up_right == 0)
    {
        return 0;
    }
    //Up left
    x = i;
    y = j;
    int Up_left = Check_up_left_white('b',x,y,board);
    if (Up_left == 0)
    {
        return 0;
    }
    //Down right
    x = i;
    y = j;
    int Down_right = Check_down_right_white('b',x,y,board);
    if (Down_right == 0)
    {
        return 0;
    }
    //Down left
    x = i;
    y = j;
    int Down_left = Check_down_left_white('b',x,y,board);
    if (Down_left == 0)
    {
        return 0;
    }

    return 1;

}
/**
* function to to check if there is a possible move for the white queen that can remove the check on the white king
* parameters: x number of row that the queen in
             y number of column the queen in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_wQueen(int i, int j,char board[][9])
{
    int x = i;
    int y = j;
    //up
    int up = Check_up_white('q',x,y,board);
    if(up == 0)
    {
        return 0;
    }
    //down
    x = i;
    y = j;
    int down = Check_down_white('q',x,y,board);
    if (down == 0)
    {
        return 0;
    }
    //Right
    x = i;
    y = j;
    int right = Check_right_white('q',x,y,board);
    if (right == 0)
    {
        return 0;
    }
    //Left
    x = i;
    y = j;
    int left = Check_left_white('q',x,y,board);
    if (left == 0)
    {
        return 0;
    }
    //up right
    int Up_right = Check_up_right_white('q',x,y,board);
    if(Up_right == 0)
    {
        return 0;
    }
    //Up left
    x = i;
    y = j;
    int Up_left = Check_up_left_white('q',x,y,board);
    if (Up_left == 0)
    {
        return 0;
    }
    //Down right
    x = i;
    y = j;
    int Down_right = Check_down_right_white('q',x,y,board);
    if (Down_right == 0)
    {
        return 0;
    }
    //Down left
    x = i;
    y = j;
    int Down_left = Check_down_left_white('q',x,y,board);
    if (Down_left == 0)
    {
        return 0;
    }
    return 1;
}
/**
* function to to check if there is a checkmate on the white king
* parameters: board an array contain the characters of the pieces and square colors
* return: 0  if there is no checkmate
         1  if there is a checkmate
*/
int Checkmate_white(char board[][9])
{
    if(illegal_wking(board) && check_white(board))
    {
        int isCheckmate = 1;
        for (int i = 1; i < 9; i++)
        {
            for(int j = 1; j <9; j++)
            {
                switch (board[i][j])
                {
                case 'p':
                    isCheckmate = Check_wPawn(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'n':
                    isCheckmate = Check_wKnight(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'r':
                    isCheckmate = Check_wRook(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'b':
                    isCheckmate = Check_wBishop(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'q':
                    isCheckmate = Check_wQueen(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                }
            }
        }
        return 1;
    }
    return 0;
}
 /**
* function to check if there is a stalemate by white
* parameters: counter the turn of the player
             board an array contain the characters of the pieces and square colors
* return: 0 if there is no stalemate
          1 if there is a stalemate
*/
int Stalemate_White(int counter ,char board[][9])
{
    if(counter % 2 == 0 && illegal_wking(board) && !check_white(board))
    {
        int isStalemate = 1;
        for (int i = 1; i < 9; i++)
        {
            for(int j = 1; j <9; j++)
            {
                switch (board[i][j])
                {
                case 'p':
                    isStalemate = Check_wPawn(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'n':
                    isStalemate = Check_wKnight(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'r':
                    isStalemate = Check_wRook(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'b':
                    isStalemate = Check_wBishop(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'q':
                    isStalemate = Check_wQueen(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        return 1;
    }
    return 0;
}



