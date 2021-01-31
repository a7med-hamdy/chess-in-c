#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "ahmed hamdi ahmed_19017253_mariam mohamed ahmed_19017274 chess_executable_moves.h"
#include <math.h>


/**
* function to to check if moving the black rook or the black queen down will remove the check on the black king
* parameters: black_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_down_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 8)
    {
        x++;
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
            board[i][j] = black_piece;
            return 1;
        }
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
            char piece = board[x][y];
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 1;
            }
        }
        if (((x-1) + y) % 2  == 1)
        {
            board[x-1][y] = '.';
        }
        else
        {
            board[x-1][y] = '-';
        }
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;
}
/**
* function to to check if moving the black rook or the black queen up will remove the check on the black king
* parameters: black_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_up_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 1)
    {
        x--;
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
            board[i][j] = black_piece;
            return 1;
        }
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
            char piece = board[x][y];
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 1;
            }
        }
        if (((x+1) + y) % 2  == 1)
        {
            board[x+1][y] = '.';
        }
        else
        {
            board[x+1][y] = '-';
        }
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;

}
/**
* function to to check if moving the black rook or the black queen right will remove the check on the black king
* parameters: black_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_right_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( y != 8)
    {
        y++;
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if ((x + (y-1)) % 2  == 1)
            {
                board[x][y-1] = '.';
            }
            else
            {
                board[x][y-1] = '-';
            }
            board[i][j] = black_piece;
            return 1;
        }
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
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
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
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
                board[i][j] = black_piece;
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
                board[i][j] = black_piece;
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
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;
}
/**
* function to to check if moving the black rook or the black queen left will remove the check on the black king
* parameters: black_piece either Queen or Rook
             x number of row that the queen or the rook in
             y number of column the queen or the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_left_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( y != 1)
    {
        y--;
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
            board[i][j] = black_piece;
            return 1;
        }
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
            char piece = board[x][y];
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
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
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;

}
/**
* function to to check if moving the black bishop or the black queen down right will remove the check on the black king
* parameters: black_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_down_right_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 8 && y != 8)
    {
        x++;
        y++;
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
            board[i][j] = black_piece;
            return 1;
        }
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
            char piece = board[x][y];
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
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
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;
}
/**
* function to to check if moving the black bishop or the black queen up right will remove the check on the black king
* parameters: black_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_up_right_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 1 && y != 8)
    {
        x--;
        y++;
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
            board[i][j] = black_piece;
            return 1;
        }
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
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
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
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
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;
}
/**
* function to to check if moving the black bishop or the black queen up left will remove the check on the black king
* parameters: black_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_up_left_black(char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 1 && y != 1)
    {
        x--;
        y--;
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            if (((x+1) +(y+1)) % 2  == 1)
            {
                board[x+1][y+1] = '.';
            }
            else
            {
                board[x+1][y+1] = '-';
            }
            board[i][j] = black_piece;
            return 1;
        }
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
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
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
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
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;
}
/**
* function to to check if moving the black bishop or the black queen down left will remove the check on the black king
* parameters: black_piece either queen or bishop
             x number of row that the queen or the bishop in
             y number of column the queen or the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_down_left_black( char black_piece, int x, int y, char board[][9])
{
    int i = x;
    int j = y;
    while( x != 8 && y != 1)
    {
        x++;
        y--;
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
            board[i][j] = black_piece;
            return 1;
        }
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
            char piece = board[x][y];
            board[x][y] = black_piece;
            board[i][j] = '.';
            if(!check_black(board))
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
                return 0;
            }
            else
            {
                board[x][y] = piece;
                board[i][j] = black_piece;
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
        board[x][y] = black_piece;
        if(!check_black(board))
        {
            if ((x + y) % 2  == 1)
            {
                board[x][y] = '.';
            }
            else
            {
                board[x][y] = '-';
            }
            board[i][j] = black_piece;
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
    board[i][j] = black_piece;
    return 1;
}
/**
* function to to check if there is a possible move for the black knight that can remove the check on the black king
* parameters: x number of row that the knight in
             y number of column the knight in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_bKnight(int i, int j, char board[][9])
{
    if((i+2 <= 8 && j+1 <= 8) && !(board[i+2][j+1] >= 'A' && board[i+2][j+1] <= 'Z'))
    {
        char square_content = board[i+2][j+1];
        board[i+2][j+1] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+2][j+1] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i+2][j+1] = square_content;
            board[i][j] = 'N';
        }
    }
    //Down Left
    if((i+2 <= 8 && j-1 >= 1) && !(board[i+2][j-1] >= 'A' && board[i+2][j-1] <= 'Z'))
    {
        char square_content = board[i+2][j-1];
        board[i+2][j-1] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+2][j-1] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i+2][j-1] = square_content;
            board[i][j] = 'N';
        }
    }
    //Up right
    if((i-2 >= 1 && j+1 <= 8) && !(board[i-2][j+1] >= 'A' && board[i-2][j+1] <= 'Z'))
    {
        char square_content = board[i-2][j+1];
        board[i-2][j+1] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i-2][j+1] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i-2][j+1] = square_content;
            board[i][j] = 'N';
        }
    }
    //Up left
    if((i-2 >= 1 && j-1 >= 1) && !(board[i-2][j-1] >= 'A' && board[i-2][j-1] <= 'Z'))
    {
        char square_content = board[i-2][j-1];
        board[i-2][j-1] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i-2][j-1] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i-2][j-1] = square_content;
            board[i][j] = 'N';
        }
    }

    //Right down
    if((i+1 <= 8 && j+2 <= 8) && !(board[i+1][j+2] >= 'A' && board[i+1][j+2] <= 'Z'))
    {
        char square_content = board[i+1][j+2];
        board[i+1][j+2] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+1][j+2] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i+1][j+2] = square_content;
            board[i][j] = 'N';
        }
    }
    // left down
    if((i+1 <= 8 && j-2 >= 1) && (!(board[i+1][j-2] >= 'A' && board[i+1][j-2] <= 'Z')))
    {
        char square_content = board[i+1][j-2];
        board[i+1][j-2] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+1][j-2] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i+1][j-2] = square_content;
            board[i][j] = 'N';
        }
    }
    //Right Up
    if((i-1 >= 1 && j+2 <= 8) && !(board[i-1][j+2] >= 'A' && board[i-1][j+2] <= 'Z'))
    {
        char square_content = board[i-1][j+2];
        board[i-1][j+2] = 'N';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i-1][j+2] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i-1][j+2] = square_content;
            board[i][j] = 'N';
        }
    }
    //Left Up
    if((i-1 >= 1 && j-2 >= 1) && !(board[i-1][j-2] >= 'A' && board[i-1][j-2] <= 'Z'))
    {
        char square_content = board[i-1][j-2];
        board[i-1][j-2] = 'N';
        board[i][j] = '.';

        if(!check_black(board))
        {
            board[i-1][j-2] = square_content;
            board[i][j] = 'N';
            return 0;
        }
        else
        {
            board[i-1][j-2] = square_content;
            board[i][j] = 'N';
        }
    }
    return 1;
}
/**
* function to to check if there is a possible move for the black pawn that can remove the check on the black king
* parameters: x number of row that the pawn in
             y number of column the pawn in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_bPawn(int i, int j, char board[][9])
{
    if(i+1 <= 8 && (board[i+1][j] == '.' || board[i+1][j] == '-'))
    {
        char square_color = board[i+1][j];
        board[i+1][j] = 'P';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+1][j] = square_color;
            board[i][j] = 'P';
            return 0;
        }
        else
        {
            board[i+1][j] = square_color;
            board[i][j] = 'P';
        }
    }
    if((i+1 <= 8) &&(j-1 >= 1)&& (board[i+1][j-1] >= 'a' && (board[i+1][j-1]) <= 'z'))
    {

        char piece = board[i+1][j-1];
        board[i+1][j-1] = 'P';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+1][j-1] = piece;
            board[i][j] = 'P';
            return 0;
        }
        else
        {
            board[i+1][j-1] = piece;
            board[i][j] = 'P';
        }
    }
    if((i+1 <= 8) &&(j+1 <= 8)&& (board[i+1][j+1] >= 'a' && (board[i+1][j+1]) <= 'z'))
    {
        char piece = board[i+1][j+1];
        board[i+1][j+1] = 'P';
        board[i][j] = '.';
        if(!check_black(board))
        {
            board[i+1][j+1] = piece;
            board[i][j] = 'P';
            return 0;
        }
        else
        {
            board[i+1][j+1] = piece;
            board[i][j] = 'P';
        }
    }
    return 1;

}
/**
* function to to check if there is a possible move for the black rook that can remove the check on the black king
* parameters: x number of row that the rook in
             y number of column the rook in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_bRook(int i, int j, char board[][9])
{
    int x = i;
    int y = j;
    //up
    int up = Check_up_black('R',x,y,board);
    if(up == 0)
    {
        return 0;
    }
    //down
    x = i;
    y = j;
    int down = Check_down_black('R',x,y,board);
    if (down == 0)
    {
        return 0;
    }
    //Right
    x = i;
    y = j;
    int right = Check_right_black('R',x,y,board);
    if (right == 0)
    {
        return 0;
    }
    //Left
    x = i;
    y = j;
    int left = Check_left_black('R',x,y,board);
    if (left == 0)
    {
        return 0;
    }

    return 1;
}
/**
* function to to check if there is a possible move for the black bishop that can remove the check on the black king
* parameters: x number of row that the bishop in
             y number of column the bishop in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_bBishop(int i, int j, char board[][9])
{
    int x = i;
    int y = j;
    //up_right
    int Up_right = Check_up_right_black('B',x,y,board);
    if(Up_right == 0)
    {
        return 0;
    }
    //Up left
    x = i;
    y = j;
    int Up_left = Check_up_left_black('B',x,y,board);
    if (Up_left == 0)
    {
        return 0;
    }
    //Down right
    x = i;
    y = j;
    int Down_right = Check_down_right_black('B',x,y,board);
    if (Down_right == 0)
    {
        return 0;
    }
    //Down left
    x = i;
    y = j;
    int Down_left = Check_down_left_black('B',x,y,board);
    if (Down_left == 0)
    {
        return 0;
    }

    return 1;

}
/**
* function to to check if there is a possible move for the black queen that can remove the check on the black king
* parameters: x number of row that the queen in
             y number of column the queen in
             board an array contain the characters of the pieces and square colors
* return: 0  if the check is removed
         1  if the check is not removed
*/
int Check_bQueen(int i, int j,char board[][9])
{
    int x = i;
    int y = j;
    //up
    int up = Check_up_black('Q',x,y,board);
    if(up == 0)
    {
        return 0;
    }
    //down
    x = i;
    y = j;
    int down = Check_down_black('Q',x,y,board);
    if (down == 0)
    {
        return 0;
    }
    //Right
    x = i;
    y = j;
    int right = Check_right_black('Q',x,y,board);
    if (right == 0)
    {
        return 0;
    }
    //Left
    x = i;
    y = j;
    int left = Check_left_black('Q',x,y,board);
    if (left == 0)
    {
        return 0;
    }

    //up right
    int Up_right = Check_up_right_black('Q',x,y,board);
    if(Up_right == 0)
    {
        return 0;
    }
    //Up left
    x = i;
    y = j;
    int Up_left = Check_up_left_black('Q',x,y,board);
    if (Up_left == 0)
    {
        return 0;
    }
    //Down right
    x = i;
    y = j;
    int Down_right = Check_down_right_black('Q',x,y,board);
    if (Down_right == 0)
    {
        return 0;
    }
    //Down left
    x = i;
    y = j;
    int Down_left = Check_down_left_black('Q',x,y,board);
    if (Down_left == 0)
    {
        return 0;
    }
    return 1;
}
/**
* function to to check if there is a checkmate on the black king
* parameters: board an array contain the characters of the pieces and square colors
* return: 0  if there is no checkmate
         1  if there is a checkmate
*/
int Checkmate_black(char board[][9])
{
    if(illegal_bking(board) && check_black(board))
    {
        int isCheckmate = 1;
        for (int i = 1; i < 9; i++)
        {
            for(int j = 1; j <9; j++)
            {
                switch (board[i][j])
                {
                case 'P':
                    isCheckmate = Check_bPawn(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'N':
                    isCheckmate = Check_bKnight(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'R':
                    isCheckmate = Check_bRook(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'B':
                    isCheckmate = Check_bBishop(i,j,board);
                    if (isCheckmate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'Q':
                    isCheckmate = Check_bQueen(i,j,board);
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
* function to check if there is a stalemate by black
* parameters: counter the turn of the player
             board an array contain the characters of the pieces and square colors
* return: 0 if there is no stalemate
          1 if there is a stalemate
*/
int Stalemate_Black(int counter ,char board[][9])
{
    if(counter % 2 == 1 && illegal_bking(board) && !check_black(board))
    {
        int isStalemate = 1;
        for (int i = 1; i < 9; i++)
        {
            for(int j = 1; j <9; j++)
            {
                switch (board[i][j])
                {
                case 'P':
                    isStalemate = Check_bPawn(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'N':
                    isStalemate = Check_bKnight(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'R':
                    isStalemate = Check_bRook(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'B':
                    isStalemate = Check_bBishop(i,j,board);
                    if (isStalemate == 0)
                    {
                        return 0;
                    }
                    break;
                case 'Q':
                    isStalemate = Check_bQueen(i,j,board);
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
