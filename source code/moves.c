#include <stdio.h>
#include <math.h>
#include<stdbool.h>
int x_king = 8;
int y_king = 5;
int king_counter = 0;

int x_King = 1;
int y_King = 5;
int King_counter = 0;

char Lr_square = 'r';
int Lr_square_counter = 0;

char Rr_square = 'r';
int Rr_square_counter = 0;

char LR_square = 'R';
int LR_square_counter = 0;

char RR_square = 'R';
int RR_square_counter = 0;


/**
* function to check if the rooks moved
* parameters: - board an array contain the characters of the pieces and square colors
*/
void Trace_rSquares(char board[][9])
{
    if (board[8][1] != Lr_square)
    {
        Lr_square_counter++;
        Lr_square = board[8][1];
    }
    if (board[8][8] != Rr_square)
    {
        Rr_square_counter++;
        Rr_square = board[8][8];

    }
    if (board[1][1] != LR_square)
    {
        LR_square_counter++;
        LR_square = board[1][1];
    }
    if (board[1][8] != RR_square)
    {
        RR_square_counter++;
        RR_square = board[1][8];

    }
    return;
}
/**
* function to check if the rooks moved after undo
* parameters: - board an array contain the characters of the pieces and square colors
*/
void Trace_rSquares_Undo(char board[][9])
{
    if (board[8][1] != Lr_square)
    {
        Lr_square_counter--;
        Lr_square = board[8][1];
    }
    if (board[8][8] != Rr_square)
    {
        Rr_square_counter--;
        Rr_square = board[8][8];

    }
    if (board[1][1] != LR_square)
    {
        LR_square_counter--;
        LR_square = board[1][1];
    }
    if (board[1][8] != RR_square)
    {
        RR_square_counter--;
        RR_square = board[1][8];

    }
    return;
}
/**
* function to check if the rooks moved after redo
* parameters: - board an array contain the characters of the pieces and square colors
*/
void Trace_rSquares_Redo(char board[][9])
{
    if (board[8][1] != Lr_square)
    {
        Lr_square_counter++;
        Lr_square = board[8][1];
    }
    if (board[8][8] != Rr_square)
    {
        Rr_square_counter++;
        Rr_square = board[8][8];

    }
    if (board[1][1] != LR_square)
    {
        LR_square_counter++;
        LR_square = board[1][1];
    }
    if (board[1][8] != RR_square)
    {
        RR_square_counter++;
        RR_square = board[1][8];
    }
    return;
}
/**
* function to check if the kings moved after undo
* parameters: - board an array contain the characters of the pieces and square colors
*/
void Trace_Kings_Undo(char board[][9])
{
    bool king_change = true;
    bool King_change = true;
    int new_x_postion = 0;
    int new_y_postion = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == 'k')
            {
                if(x_king == i && y_king == j)
                {
                    king_change = false;
                }
                else
                {
                    new_x_postion = i;
                    new_y_postion = j;
                }
            }
            if(board[i][j] == 'K')
            {
                if(x_King == i && y_King == j)
                {
                    King_change = false;
                }
                else
                {
                    new_x_postion = i;
                    new_y_postion = j;
                }
            }
        }
    }
    if(king_change)
    {
        king_counter--;
        x_king = new_x_postion;
        y_king = new_y_postion;
    }
    if(King_change)
    {
        King_counter--;
        x_King = new_x_postion;
        y_King = new_y_postion;

    }
    return;
}
/**
* function to check if the kings moved after redo
* parameters: - board an array contain the characters of the pieces and square colors
*/
void Trace_Kings_Redo(char board[][9])
{
    bool king_change = true;
    bool King_change = true;
    int new_x_postion = 0;
    int new_y_postion = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == 'k')
            {
                if(x_king == i && y_king == j)
                {
                    king_change = false;
                }
                else
                {
                    new_x_postion = i;
                    new_y_postion = j;
                }
            }
            if(board[i][j] == 'K')
            {
                if(x_King == i && y_King == j)
                {
                    King_change = false;
                }
                else
                {
                    new_x_postion = i;
                    new_y_postion = j;
                }
            }
        }
    }
    if(king_change)
    {
        king_counter++;
        x_king = new_x_postion;
        y_king = new_y_postion;
    }
    if(King_change)
    {
        King_counter++;
        x_King = new_x_postion;
        y_King = new_y_postion;

    }
    return;
}
/**
* function to trace if the kings
* parameters: - board an array contain the characters of the pieces and square colors
*/
void king_position(char board[][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == 'k')
            {
                x_king = i;
                y_king = j;
            }
            if(board[i][j] == 'K')
            {
                x_King = i;
                y_King = j;
            }
        }
    }
    return;
}
/**
* function to check if there is a check on the white king
* parameters: - board an array contain the characters of the pieces and square colors
* return: true if there is a check on the white king
          false if there is no check on the black king
*/
bool check_white(char board[][9])
{
    king_position(board);
    //rook and queen
    int x = x_king;
    int y = y_king;
    //Down
    while(x != 8)
    {
        x++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'R' || board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Up
    x = x_king;
    y = y_king;

    while(x != 1)
    {
        x--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'R' || board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Right
    x = x_king;
    y = y_king;
    while(y != 8)
    {
        y++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'R' || board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //left
    x = x_king;
    y = y_king;
    while(y != 1)
    {
        y--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'R'|| board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Bishop and queen
    x = x_king;
    y = y_king;
    //UP right
    while( x != 1 && y != 8)
    {
        x--;
        y++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'B'|| board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }

    //Up left
    x = x_king;
    y = y_king;
    while(x != 1 && y != 1)
    {
        x--;
        y--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'B'|| board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }

    //Down right
    x = x_king;
    y = y_king;
    while(x != 8 && y != 8)
    {
        x++;
        y++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'B'|| board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }

    //Down left
    x = x_king;
    y = y_king;
    while(x != 8 && y != 1)
    {
        x++;
        y--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'B'|| board[x][y] == 'Q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Knight
    x = x_king;
    y = y_king;
    if (((x + 2 <= 8) && (y + 1 <= 8)) && (board[x + 2][y + 1] =='N' ))
    {
        return true;
    }
    if (((x + 2 <= 8) && (y - 1 >= 1)) && (board[x + 2][y - 1] =='N' ))
    {
        return true;
    }
    if (((x - 2 >= 1) && (y + 1 <= 8)) && (board[x - 2][y + 1] =='N' ))
    {
        return true;
    }
    if (((x - 2 >= 1) && (y - 1 >= 1)) && (board[x - 2][y - 1] =='N' ))
    {
        return true;
    }
    if (((x + 1 <= 8) && (y + 2 <= 8)) && (board[x + 1][y + 2] =='N' ))
    {
        return true;
    }
    if (((x + 1 <= 8) && (y - 2 >= 1)) && (board[x + 1][y - 2] =='N' ))
    {
        return true;
    }
    if (((x - 1 >= 1) && (y + 2 <= 8)) && (board[x - 1][y + 2] =='N' ))
    {
        return true;
    }
    if (((x - 1 >= 1) && (y - 2 >= 1)) && (board[x - 1][y - 2] =='N' ))
    {
        return true;
    }
    //King
    if ((x + 1 <= 8) && board[x + 1][y] == 'K')
    {
        return true;
    }
    if ((x - 1 >= 1) && board[x - 1][y] == 'K')
    {
        return true;
    }
    if ((y + 1 <= 8) && board[x][y + 1] == 'K')
    {
        return true;
    }
    if ((y - 1 <= 8) && board[x][y - 1] == 'K')
    {
        return true;
    }
    if (((x + 1 <= 8) && (y + 1 <= 8)) && board[x + 1][y + 1] == 'K')
    {
        return true;
    }
    if (((x + 1 <= 8) && (y - 1 >= 1)) && board[x + 1][y - 1] == 'K')
    {
        return true;
    }
    if (((x - 1 >= 1) && (y + 1 <= 8)) && board[x - 1][y + 1] == 'K')
    {
        return true;
    }
    if (((x - 1 >= 1) && (y - 1 >= 1)) && board[x - 1][y - 1] == 'K')
    {
        return true;
    }

    // Pawn
    if (((x - 1 >= 1) && (y + 1 <= 8)) && board[x - 1][y + 1] == 'P')
    {
        return true;
    }
    if (((x - 1 >= 1) && (y - 1 >= 1)) && board[x - 1][y - 1] == 'P')
    {
        return true;
    }
    return false;

}

/**
* function to check if there is a check on the black king
* parameters: - board an array contain the characters of the pieces and square colors
* return: true if there is a check on black king
          false if there is no check on the black
*/
bool check_black(char board[][9])
{
    king_position(board);

    //rook and queen
    int x = x_King;
    int y = y_King;
    //Down
    while(x != 8)
    {
        x++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'r' || board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Up
    x = x_King;
    y = y_King;

    while(x != 1)
    {
        x--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'r' || board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Right
    x = x_King;
    y = y_King;
    while(y != 8)
    {
        y++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'r' || board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //left
    x = x_King;
    y = y_King;
    while(y != 1)
    {
        y--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'r'|| board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Bishop and queen
    x = x_King;
    y = y_King;
    //UP right
    while( x != 1 && y != 8)
    {
        x--;
        y++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'b'|| board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Up left
    x = x_King;
    y = y_King;
    while(x != 1 && y != 1)
    {
        x--;
        y--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'b'|| board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }

    //Down right
    x = x_King;
    y = y_King;
    while(x != 8 && y != 8)
    {
        x++;
        y++;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'b'|| board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }

    //Down left
    x = x_King;
    y = y_King;
    while(x != 8 && y != 1)
    {
        x++;
        y--;
        if( board[x][y] != '.' && board[x][y] != '-' )
        {
            if (board[x][y] == 'b'|| board[x][y] == 'q')
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    //Knight
    x = x_King;
    y = y_King;
    if (((x + 2 <= 8) && (y + 1 <= 8)) && (board[x + 2][y + 1] == 'n' ))
    {
        return true;
    }
    if (((x + 2 <= 8) && (y - 1 >= 1)) && (board[x + 2][y - 1] =='n' ))
    {
        return true;
    }
    if (((x - 2 >= 1) && (y + 1 <= 8)) && (board[x - 2][y + 1] =='n' ))
    {
        printf("Check\n");
        return true;
    }
    if (((x - 2 >= 1) && (y - 1 >= 1)) && (board[x - 2][y - 1] =='n' ))
    {
        return true;
    }
    if (((x + 1 <= 8) && (y + 2 <= 8)) && (board[x + 1][y + 2] =='n' ))
    {
        return true;
    }
    if (((x + 1 <= 8) && (y - 2 >= 1)) && (board[x + 1][y - 2] =='n' ))
    {
        return true;
    }
    if (((x - 1 >= 1) && (y + 2 <= 8)) && (board[x - 1][y + 2] =='n' ))
    {
        return true;
    }
    if (((x - 1 >= 1) && (y - 2 >= 1)) && (board[x - 1][y - 2] =='n'))
    {
        return true;
    }
    //King
    if ((x + 1 <= 8) && board[x + 1][y] == 'k')
    {
        return true;
    }
    if ((x - 1 >= 1) && board[x - 1][y] == 'k')
    {
        return true;
    }
    if ((y + 1 <= 8) && board[x][y + 1] == 'k')
    {
        return true;
    }
    if ((y - 1 <= 8) && board[x][y - 1] == 'k')
    {
        return true;
    }
    if (((x + 1 <= 8) && (y + 1 <= 8)) && board[x + 1][y + 1] == 'k')
    {
        return true;
    }
    if (((x + 1 <= 8) && (y - 1 >= 1)) && board[x + 1][y - 1] == 'k')
    {
        return true;
    }
    if (((x - 1 >= 1) && (y + 1 <= 8)) && board[x - 1][y + 1] == 'k')
    {
        return true;
    }
    if (((x - 1 >= 1) && (y - 1 >= 1)) && board[x - 1][y - 1] == 'k')
    {
        return true;
    }

    // Pawn
    if (((x + 1 <= 8) && (y + 1 <= 8)) && board[x + 1][y + 1] == 'p')
    {
        return true;
    }
    if (((x + 1 <= 8) && (y - 1 >= 1)) && board[x + 1][y - 1] == 'p')
    {
        return true;
    }
    return false;

}

/**
* function to validate the castling king side move of king then moving it
* parameters: i number of row that the king in
            j number of column that the king in
            x number of the row that the king will move to
            y number of the column that the king will move to
            board an array contain the characters of the pieces and square colors
* return: 1  if the castling kingside is valid
        0  if the castling kingside is not valid
*/
int Castle_KingSide(int i, int j, int x, int y, char board[][9])
{
    if( x == i && y == j + 2)
    {
        if(board[i][j] == 'k' && king_counter == 0 && Rr_square_counter == 0)
        {
            if((!check_white(board)) && (board[i][j+1] == '.' || board[i][j+1] == '-') && (board[i][j+2] == '.' || board[i][j+2] == '-'))
            {
                char temp = board[i][j+1];
                board[i][j]= '.';
                board[i][j+1] = 'k';
                if(check_white(board))
                {
                    board[i][j] = 'k';
                    board[i][j+1] = temp;
                    return 0;
                }
                board[i][j+1] = temp;
                char temp2 = board[i][j+2];
                board[i][j+2] = 'k';
                if(check_white(board))
                {
                    board[i][j] = 'k';
                    board[i][j+2] = temp2;
                    return 0;
                }
                king_counter ++;
                board[i][j+1] = 'r';
                board[8][8] = '-';
                if((i+j)%2 == 1)
                {
                    board[i][j] = '.';
                }
                else
                {
                    board[i][j] = '-';
                }

                return 1;
            }
        }

        if(board[i][j] == 'K' && King_counter == 0 && RR_square_counter == 0)
        {
            if((!check_black(board))&& (board[i][j+1] == '.' || board[i][j+1] == '-') && (board[i][j+2] == '.' || board[i][j+2] == '-'))
            {
                char temp = board[i][j+1];
                board[i][j]= '.';
                board[i][j+1] = 'K';
                if(check_black(board))
                {
                    board[i][j] = 'K';
                    board[i][j+1] = temp;
                    return 0;
                }
                board[i][j+1] = temp;
                char temp2 = board[i][j+2];
                board[i][j+2] = 'K';
                if(check_black(board))
                {
                    board[i][j] = 'K';
                    board[i][j+2] = temp2;
                    return 0;
                }
                King_counter ++;
                board[i][j+1] = 'R';
                board[1][8] = '.';
                if((i+j)%2 == 1)
                {
                    board[i][j] = '.';
                }
                else
                {
                    board[i][j] = '-';
                }
                printf("Castling\n");
                return 1;
            }
        }
    }
    return 0;
}
/**
* function to validate the castling king side move of king then moving it
* parameters: i number of row that the king in
            j number of column that the king in
            x number of the row that the king will move to
            y number of the column that the king will move to
            board an array contain the characters of the pieces and square colors
* return: 1  if the castling queenside is valid
        0  if the castling queenside is not valid
*/
int Castle_QueenSide(int i, int j, int x, int y, char board[][9])
{
    if(x == i && y == j - 2)
    {

        if(board[i][j] == 'k' && king_counter == 0 && Lr_square_counter == 0)
        {
            if((!check_white(board)) && (board[i][j-1] == '.' || board[i][j-1] == '-') && (board[i][j-2] == '.' || board[i][j-2] == '-') && (board[i][j-3] == '.' || board[i][j-3] == '-'))
            {
                char temp = board[i][j-1];
                board[i][j]= '.';
                board[i][j-1] = 'k';
                if(check_white(board))
                {
                    board[i][j] = 'k';
                    board[i][j-1] = temp;
                    return 0;
                }
                board[i][j-1] = temp;
                char temp2 = board[i][j-2];
                board[i][j-2] = 'k';
                if(check_white(board))
                {
                    board[i][j] = 'k';
                    board[i][j-2] = temp2;
                    return 0;
                }
                king_counter ++;
                board[i][j-1] = 'r';
                board[8][1] = '.';
                if((i+j)%2 == 1)
                {
                    board[i][j] = '.';
                }
                else
                {
                    board[i][j] = '-';
                }
                return 1;
            }
        }

        if(board[i][j] == 'K' && King_counter == 0 && LR_square_counter == 0)
        {
            if((!check_black(board))&& (board[i][j-1] == '.' || board[i][j-1] == '-') && (board[i][j-2] == '.' || board[i][j-2] == '-') && (board[i][j-2] == '.' || board[i][j-2] == '-'))
            {
                char temp = board[i][j-1];
                board[i][j]= '.';
                board[i][j-1] = 'K';
                if(check_black(board))
                {
                    board[i][j] = 'K';
                    board[i][j-1] = temp;
                    return 0;
                }
                board[i][j-1] = temp;
                char temp2 = board[i][j-2];
                board[i][j-2] = 'K';
                if(check_black(board))
                {
                    board[i][j] = 'K';
                    board[i][j-2] = temp2;
                    return 0;
                }
                King_counter ++;
                board[i][j-1] = 'R';
                board[1][1] = '-';
                if((i+j)%2 == 1)
                {
                    board[i][j] = '.';
                }
                else
                {
                    board[i][j] = '-';
                }
                return 1;
            }
        }
    }
    return 0;

}


//Other Draw cases
int Draw(char b[][9])
{
    int wBishop_square_color = 10;
    int bBishop_square_color = 4;
    char draw_pieces[4] = {'.','.','.','.'};
    int draw_index = 0;
    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            if(b[i][j] != '.' && b[i][j] != '-')
            {
                if (b[i][j] == 'b')
                {
                    wBishop_square_color = (i+j) % 2;
                }
                if(b[i][j] == 'B')
                {
                    bBishop_square_color = (i+j) % 2;
                }
                draw_pieces[draw_index]= b[i][j];
                draw_index++;
                if(draw_index == 5)
                {
                    return 0;
                }
            }
        }
    }
    //King vs king
    if (draw_index == 2)
    {
        return 1;
    }

    //King and Bishop vs King or king and Knight vs king
    if(draw_index == 3)
    {
        for(int i = 0; i < 3; i++)
        {
            if(draw_pieces[i] == 'n' || draw_pieces[i] == 'N' || draw_pieces[i] == 'B' || draw_pieces[i] == 'b')
            {
                return 1;
            }
        }
        return 0;
    }

    //King and bishop vs king and bishop
    if(draw_index == 4)
    {
        int checker = 0;
        for(int i = 0; i < 4; i++)
        {
            if(draw_pieces[i] == 'K' || draw_pieces[i] == 'k' || draw_pieces[i] == 'B' || draw_pieces[i] == 'b')
            {
                checker++;
            }
        }
        if(checker == 4 && (wBishop_square_color == bBishop_square_color))
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }

}


/**
* function to check if there is a check after a piece move to validate the move
* parameters: - board an array contain the characters of the pieces and square colors
* return: 0 if there is a check
          1 if there is no check
*/
int ischeck(int i, int j,int x, int y, char board[][9])
{
    char piece = board[i][j];
    char temp = board[x][y];
    board[x][y] = board[i][j];
    if((i + j ) %2 == 1)
    {
        board[i][j]= '.';
    }
    else
    {
        board[i][j]= '-';
    }
    bool check = false;
    if (piece >= 'a' && piece <= 'z')
    {
        check = check_white(board);
    }
    else
    {
        check = check_black(board);
    }
    if (check)
    {
        board[x][y] = temp;
        board[i][j]= piece;
        if (piece  == 'r' || piece == 'R')
        {
            return 0;
        }
        if (piece  == 'p' || piece == 'P')
        {
            return 0;
        }
        if (piece  == 'q' || piece == 'Q')
        {
            return 0;
        }
        if (piece  == 'b' || piece == 'B')
        {
            return 0;
        }
        if (piece  == 'n' || piece == 'N')
        {
            return 0;
        }
        return 0;
    }
    else
    {
        board[i][j] = piece;
        board[x][y] = temp;
        return 1;
    }
}
/**
* function to check if there is no legal move for the white king
* parameters: - board an array contain the characters of the pieces and square colors
* return: true if there is no legal move for the white king
         false if there is a legal move for the white king
*/
bool illegal_wking(char board[][9])
{
    king_position(board);
    int i = x_king;
    int j = y_king;
    bool illegal = true;
    int pre_x_king = x_king;
    int pre_y_king = y_king;


    //Down
    if(i+1 <= 8 && (board[i+1][j]== '.' || board[i+1][j]== '-' || (board[i+1][j] >= 'A' && board[i+1][j]<='Z')))
    {
        char square_content = board[i+1][j];
        board[i][j] = '.';
        board[i+1][j] ='k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i+1][j] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i+1][j] = square_content;
        board[i][j] = 'k';
    }
    //Up
    if(i-1 >= 1 && (board[i-1][j]== '.'|| board[i-1][j]== '-' ||(board[i-1][j] >= 'A' && board[i-1][j]<='Z')))
    {
        char square_content = board[i-1][j];
        board[i][j] = '.';
        board[i-1][j] ='k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i-1][j] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i-1][j] = square_content;
        board[i][j] = 'k';
    }
    //Right
    if(j+1 <= 8 && (board[i][j+1]== '.'|| board[i][j+1]== '-' ||(board[i][j+1] >= 'A' && board[i][j+1]<='Z')))
    {
        char square_content = board[i][j+1];
        board[i][j] = '.';
        board[i][j+1] = 'k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i][j+1] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i][j+1] = square_content;
        board[i][j] = 'k';
    }
    //left
    if(j-1 >= 1 && (board[i][j-1]== '.'|| board[i][j-1]== '-' ||(board[i][j-1] >= 'A' && board[i][j-1]<='Z')))
    {
        char square_content = board[i][j-1];
        board[i][j] = '.';
        board[i][j-1] = 'k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i][j-1] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i][j-1] = square_content;
        board[i][j] = 'k';
    }
    //Down Right
    if((i+1 <= 8 && j+1 <= 8) && (board[i+1][j+1]== '.'|| board[i+1][j+1]== '-' ||(board[i+1][j+1] >= 'A' && board[i+1][j+1]<='Z')))
    {
        char square_content = board[i+1][j+1];
        board[i][j] = '.';
        board[i+1][j+1] = 'k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i+1][j+1] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i+1][j+1] = square_content;
        board[i][j] = 'k';
    }
    //Down left
    if((i+1 <= 8 && j-1 >= 1) && (board[i+1][j-1]== '.'|| board[i+1][j-1]== '-' ||(board[i+1][j-1] >= 'A' && board[i+1][j-1]<='Z')))
    {
        char square_content = board[i+1][j-1];
        board[i][j] = '.';
        board[i+1][j-1] = 'k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i+1][j-1] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i+1][j-1] = square_content;
        board[i][j] = 'k';
    }
    //Up right
    if((i-1 >= 1 && j+1 <= 8) && (board[i-1][j+1]== '.'|| board[i-1][j+1]== '-' ||(board[i-1][j+1] >= 'A' && board[i-1][j+1]<='Z')))
    {
        char square_content = board[i-1][j+1];
        board[i][j] = '.';
        board[i-1][j+1] = 'k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i-1][j+1] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i-1][j+1] = square_content;
        board[i][j] = 'k';
    }
    //Down left
    if((i-1 >= 1 && j-1 >= 1) && ((board[i-1][j-1]== '.'|| board[i-1][j-1]== '-') || (board[i-1][j-1] >= 'A' && board[i-1][j-1]<='Z')))
    {
        char square_content = board[i-1][j-1];
        board[i][j] = '.';
        board[i-1][j-1] = 'k';
        illegal = check_white(board);
        if(!illegal)
        {
            x_king = pre_x_king;
            y_king = pre_y_king;
            board[i-1][j-1] = square_content;
            board[i][j] = 'k';
            return false;
        }
        board[i-1][j-1] = square_content;
        board[i][j] = 'k';
    }
    x_king = pre_x_king;
    y_king = pre_y_king;
    return true;
}

/**
* function to check if there is no legal move for the black king
* parameters: - board an array contain the characters of the pieces and square colors
* return: true if there is no legal move for the black king
         false if there is a legal move for the black king
*/
bool illegal_bking(char board[][9])
{
    king_position(board);
    int i = x_King;
    int j = y_King;
    bool illegal = true;
    int pre_x_King = x_King;
    int pre_y_King = y_King;

    //Down
    if(i+1 <= 8 && (board[i+1][j]== '.' || board[i+1][j]== '-' || (board[i+1][j] >= 'a' && board[i+1][j]<='z')))
    {
        char square_content = board[i+1][j];
        board[i][j] = '.';
        board[i+1][j] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i+1][j] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i+1][j] = square_content;
        board[i][j] = 'K';
    }
    //Up
    if(i-1 >= 1 && (board[i-1][j]== '.'|| board[i-1][j]== '-' ||(board[i-1][j] >= 'a' && board[i-1][j]<='z')))
    {
        char square_content = board[i-1][j];
        board[i][j] = '.';
        board[i-1][j] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i-1][j] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i-1][j] = square_content;
        board[i][j] = 'K';
    }
    //Right
    if(j+1 <= 8 && (board[i][j+1]== '.'|| board[i][j+1]== '-' ||(board[i][j+1] >= 'a' && board[i][j+1]<='z')))
    {
        char square_content = board[i][j+1];
        board[i][j] = '.';
        board[i][j+1] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i][j+1] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i][j+1] = board[i][j];
        board[i][j] = 'K';
    }
    //left
    if(j-1 >= 1 && (board[i][j-1]== '.'|| board[i][j-1]== '-' ||(board[i][j-1] >= 'a' && board[i][j-1]<='z')))
    {
        char square_content = board[i][j-1];
        board[i][j] = '.';
        board[i][j-1] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i][j-1] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i][j-1] = square_content;
        board[i][j] = 'K';
    }
    //Down Right
    if((i+1 <= 8 && j+1 <= 8) && (board[i+1][j+1]== '.'|| board[i+1][j+1]== '-' ||(board[i+1][j+1] >= 'a' && board[i+1][j+1]<='z')))
    {
        char square_content = board[i+1][j+1];
        board[i][j] = '.';
        board[i+1][j+1] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i+1][j+1] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i+1][j+1] = square_content;
        board[i][j] = 'K';
    }
    //Down left
    if((i+1 <= 8 && j-1 >= 1) && (board[i+1][j-1]== '.'|| board[i+1][j-1]== '-' ||(board[i+1][j-1] >= 'a' && board[i+1][j-1]<='Z')))
    {
        char square_content = board[i+1][j-1];
        board[i][j] = '.';
        board[i+1][j-1] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i+1][j-1] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i+1][j-1] = square_content;
        board[i][j] = 'K';
    }
    //Up right
    if((i-1 >= 1 && j+1 <= 8) && (board[i-1][j+1]== '.'|| board[i-1][j+1]== '-' ||(board[i-1][j+1] >= 'a' && board[i-1][j+1]<='z')))
    {
        char square_content = board[i-1][j+1];
        board[i][j] = '.';
        board[i-1][j+1] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i-1][j+1] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i-1][j+1] = square_content;
        board[i][j] = 'K';
    }
    //Down left
    if((i-1 >= 1 && j-1 >= 1) && ((board[i-1][j-1]== '.'|| board[i-1][j-1]== '-') || (board[i-1][j-1] >= 'a' && board[i-1][j-1]<='z')))
    {
        char square_content = board[i-1][j-1];
        board[i][j] = '.';
        board[i-1][j-1] = 'K';
        illegal = check_black(board);
        if(!illegal)
        {
            x_King = pre_x_King;
            y_King = pre_y_King;
            board[i-1][j-1] = square_content;
            board[i][j] = 'K';
            return false;
        }
        board[i-1][j-1] = square_content;
        board[i][j] = 'K';
    }
    x_King = pre_x_King;
    y_King = pre_y_King;
    return true;
}
/**
* function to validate the move of the white pawn then moving it
* parameters: i number of row that the white pawn in
             j number of column that the white pawn in
             x number of the row that the white pawn will move to
             y number of the column that the white pawn will move to
             board an array contain the characters of the pieces and square colors
* return: 1  if the move is valid
         0  if the move is not valid
*/
int pawn_white(int i, int j, int x, int y,char board[][9], char captured[][8])
{
    if(i != x+1)
    {
        //check for the case that the first pawn's move can be two squares
        if(i == 7 && x == 5)
        {
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = 'p';
            if((i + j) % 2 == 1)
            {
                board[i][j] = '.';
            }
            else
            {
                board[i][j] = '-';
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (((j != y) && (j != y-1)) && j != y+1)
    {
        return 0;
    }
    if(j == y+1 || j == y-1)
    {
        if(board[x][y] == '.' || board[x][y] == '-')
        {
            return 0;
        }
        else
        {
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = 'p';
            if((i + j) % 2 == 1)
            {
                board[i][j] = '.';
            }
            else
            {
                board[i][j] = '-';
            }
            return 1;
        }
    }
    if(y == j)
    {
        if(board[x][y] != '.' && board[x][y] != '-')
        {
            return 0;
        }
        else
        {
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = 'p';
            if((i + j) % 2 == 1)
            {
                board[i][j] = '.';
            }
            else
            {
                board[i][j] = '-';
            }
            return 1;
        }
    }
    return 0;
}
/**
* function to validate the move of the white pawn then moving it
* parameters: i number of row that the white pawn in
             j number of column that the white pawn in
             x number of the row that the white pawn will move to
             y number of the column that the white pawn will move to
             board an array contain the characters of the pieces and square colors
* return: 1  if the move is valid
         0  if the move is not valid
*/int pawn_black(int i, int j, int x, int y,char board[][9], char captured[][8])
{
    if(i != x-1)
    {
        //check for the case that the first pawn's move can be two squares
        if (i == 2 && x == 4)
        {
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = 'P';
            if((i + j) % 2 == 1)
            {
                board[i][j] = '.';
            }
            else
            {
                board[i][j] = '-';
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (((j != y) && (j != y-1)) && j != y+1)
    {
        return 0;
    }
    if(j == y+1 || j == y-1)
    {
        if(board[x][y] == '.' || board[x][y] == '-')
        {
            return 0;
        }
        else
        {
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = 'P';
            if((i + j) % 2 == 1)
            {
                board[i][j] = '.';
            }
            else
            {
                board[i][j] = '-';
            }
            return 1;
        }
    }
    if(y == j)
    {
        if(board[x][y] != '.' && board[x][y] != '-')
        {
            return 0;
        }
        else
        {
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = 'P';
            if((i + j) % 2 == 1)
            {
                board[i][j] = '.';
            }
            else
            {
                board[i][j] = '-';
            }
            return 1;
        }
    }
    return 0;
}

/**
* function to validate the move of the rook then moving it
* parameters: i number of row that the rook in
             j number of column that the rook in
             x number of the row that the rook will move to
             y number of the column that the rook will move to
             board an array contain the characters of the pieces and square colors
* return: 1  if the move is valid
         0  if the move is not valid
*/
int moveR(int i, int j, int x, int y, char board[][9], char captured[][8])
{
    if (i == x & y > j)
    {
        for (int k = j+1 ; k <= y-1 ; k++)
        {
            if (board[i][k]!= '-' && board[i][k]!= '.')
            {
                return 0;
            }
        }
        // Check for check
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';

        }
        return 1;
    }
    if(i == x & y < j)
    {
        for (int k = j-1 ; k >= y+1 ; k--)
        {
            if (board[i][k]!= '-' && board[i][k]!= '.')
            {
                return 0;
            }
        }
        //Check for check
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i < x & y == j)
    {
        for (int k = i+1 ; k <= x-1 ; k++)
        {
            if (board[k][j]!= '-' && board[k][j]!= '.')
            {
                return 0;
            }
        }
        //check for check
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j) % 2 == 1)
        {
            board[i][j] = '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i > x & y == j)
    {
        for (int k = i-1 ; k >= x+1 ; k--)
        {
            if (board[k][j]!= '-' && board[k][j]!= '.')
            {
                return 0;
            }
        }
        //check for check
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }

    else
    {
        return 0;
    }

}
/**
* function to validate the move of the bishop then moving it
* parameters: i number of row that the bishop in
             j number of column that the bishop in
             x number of the row that the bishop will move to
             y number of the column that the bishop will move to
             board an array contain the characters of the pieces and square colors
* return: true if there is no legal move for the white king
         false if there is a legal move for the white king
*/
int moveB(int i, int j, int x, int y, char board[][9], char captured[][8])
{
    if (abs(i - x) != abs(y - j))
    {
        return 0;
    }
    if (i > x && j < y)
    {
        int i_indx = i;
        int j_indx = j;
        for(int k = 1 ; k < abs(x-i); k++)
        {
            i_indx--;
            j_indx++;
            if (board[i_indx][j_indx]!= '-' && board[i_indx][j_indx]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i > x && j > y)
    {
        int i_indx = i;
        int j_indx= j;
        for(int k = abs(x - i) ; k > 1; k--)
        {
            i_indx--;
            j_indx--;
            if (board[i_indx][j_indx] != '-' && board[i_indx][j_indx]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i < x && j > y)
    {
        int i_indx = i;
        int j_indx= j;
        for(int k = abs(x - i) ; k > 1; k--)
        {
            i_indx++;
            j_indx--;
            if (board[i_indx][j_indx] != '-' && board[i_indx][j_indx]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i < x && j < y)
    {
        int i_indx = i;
        int j_indx= j;
        for(int k = abs(x - i) ; k > 1; k--)
        {
            i_indx++;
            j_indx++;
            if (board[i_indx][j_indx] != '-' && board[i_indx][j_indx]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    else
    {
        return 0;
    }

}
/**
* function to validate the move of the queen then moving it
* parameters: i number of row that the queen in
             j number of column that the queen in
             x number of the row that the queen will move to
             y number of the column that the queen will move to
             board an array contain the characters of the pieces and square colors
* return: 1  if the move is valid
         0  if the move is not valid
*/
int moveQ(int i, int j, int x, int y, char board[][9], char captured[][8])
{
    if (i == x && y > j)
    {
        for (int k = j+1 ; k <= y-1 ; k++)
        {
            if (board[i][k]!= '-' && board[i][k]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if(i == x && y < j)
    {
        for (int k = j-1 ; k >= y+1 ; k--)
        {
            if (board[i][k]!= '-' && board[i][k]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i < x & y == j)
    {
        for (int k = i+1 ; k <= x-1 ; k++)
        {
            if (board[k][j]!= '-' && board[k][j]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j) % 2 == 1)
        {
            board[i][j] = '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if (i > x & y == j)
    {
        for (int k = i-1 ; k >= x+1 ; k--)
        {
            if (board[k][j]!= '-' && board[k][j]!= '.')
            {
                return 0;
            }
        }
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    if ( abs(x-i)== abs(y-j))
    {
        if (i > x && j < y)
        {
            int i_indx = i;
            int j_indx = j;
            for(int k = 1 ; k < abs(x-i); k++)
            {
                i_indx--;
                j_indx++;
                if (board[i_indx][j_indx]!= '-' && board[i_indx][j_indx]!= '.')
                {
                    return 0;
                }
            }
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = board[i][j];
            if((i + j ) %2 == 1)
            {
                board[i][j]= '.';
            }
            else
            {
                board[i][j]= '-';
            }
            return 1;
        }
        if (i > x && j > y)
        {
            int i_indx = i;
            int j_indx= j;
            for(int k = abs(x - i) ; k > 1; k--)
            {
                i_indx--;
                j_indx--;
                if (board[i_indx][j_indx] != '-' && board[i_indx][j_indx]!= '.')
                {
                    return 0;
                }
            }
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = board[i][j];
            if((i + j ) %2 == 1)
            {
                board[i][j]= '.';
            }
            else
            {
                board[i][j]= '-';
            }
            return 1;
        }
        if (i < x && j > y)
        {
            int i_indx = i;
            int j_indx= j;
            for(int k = abs(x - i) ; k > 1; k--)
            {
                i_indx++;
                j_indx--;
                if (board[i_indx][j_indx] != '-' && board[i_indx][j_indx]!= '.')
                {
                    return 0;
                }
            }
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = board[i][j];
            if((i + j ) %2 == 1)
            {
                board[i][j]= '.';
            }
            else
            {
                board[i][j]= '-';
            }
            return 1;
        }
        if (i < x && j < y)
        {
            int i_indx = i;
            int j_indx= j;
            for(int k = abs(x - i) ; k > 1; k--)
            {
                i_indx++;
                j_indx++;
                if (board[i_indx][j_indx] != '-' && board[i_indx][j_indx]!= '.')
                {
                    return 0;
                }
            }
            int isCheck = ischeck(i, j, x, y, board);
            if(isCheck == 0)
            {
                return 0;
            }
            knocked(i,j,x,y);
            board[x][y] = board[i][j];
            if((i + j ) %2 == 1)
            {
                board[i][j]= '.';
            }
            else
            {
                board[i][j]= '-';
            }
            return 1;
        }
    }
    else
    {
        return 0;
    }

}

/**
* function to validate the move of the king then moving it
* parameters: i number of row that the king in
            j number of column that the king in
            x number of the row that the king will move to
            y number of the column that the king will move to
            board an array contain the characters of the pieces and square colors
* return: 1  if the move is valid
        0  if the move is not valid
*/
int moveK(int i, int j, int x, int y, char board[][9], char captured[][8])
{
    if ((x == i && y == j+1)|(x == i && y == j-1)|(x == i+1 && y == j)|(x == i-1 && y == j)|(x == i+1 && y == j+1)|(x == i+1 && y == j-1)|(x == i-1 && y == j+1)|(x == i-1 && y == j-1))
    {
        char square_content = board[x][y];
        char king_color = board[i][j];
        if (board[i][j] == 'k')
        {
            board[x][y] = 'k';
            board[i][j] = '.';
            king_counter++;
        }
        else
        {
            board[x][y] = 'K';
            board[i][j] = '.';
            King_counter++;
        }
        if (check_white(board) && board[x][y] == 'k')
        {
            king_counter--;
            board[i][j] = 'k';
            board[x][y] = square_content;
            king_position(board);

            return 0;
        }
        if (check_black(board) && board[x][y] == 'K')
        {
            King_counter--;
            board[i][j] = 'K';
            board[x][y] = square_content;
            king_position(board);
            return 0;
        }
        board[i][j] = king_color;
        board[x][y] = square_content;
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    //Casling
    else if(Castle_KingSide(i, j, x, y, board))
    {
        return 1;
    }
    else if (Castle_QueenSide(i, j, x, y, board))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
* function to validate the move of the knight then moving it
* parameters: i number of row that the knight in
             j number of column that the knight in
             x number of the row that the knight will move to
             y number of the column that the knight will move to
             board an array contain the characters of the pieces and square colors
* return: 1  if the move is valid
         0  if the move is not valid
*/
int moveN(int i, int j, int x, int y, char board[][9], char captured[][8])
{
    if((x == i+2 && y == j+1)||(x == i+2 && y == j-1)|(x == i-2 && y == j+1)|(x == i-2 && y == j-1)|(x == i+1 && y == j+2)|(x == i-1 && y == j+2)|(x == i+1 && y == j-2)|(x == i-1 && y == j-2))
    {
        int isCheck = ischeck(i, j, x, y, board);
        if(isCheck == 0)
        {
            return 0;
        }
        knocked(i,j,x,y);
        board[x][y] = board[i][j];
        if((i + j ) %2 == 1)
        {
            board[i][j]= '.';
        }
        else
        {
            board[i][j]= '-';
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

