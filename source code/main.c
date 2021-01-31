#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include "ahmed hamdi ahmed_19017253_mariam mohamed ahmed_19017274 chess_executable_moves.h"
#define letters 9

//castling counters
extern int king_counter;
extern int King_counter;
extern int Lr_square_counter;
extern int Rr_square_counter;
extern int LR_square_counter;
extern int RR_square_counter;
extern char Lr_square;
extern char Rr_square;
extern char LR_square;
extern char RR_square;


int counter = -1; //define a counter to keep track of the turns of the players
int isredo = 0;// to check if there are elements in the redo stack
int isundo = 0;// to check if there are elements in the undo stack
bool isquit = false;

int valid_input(char input[]);
int use_input(char input[]);
int promotion(int i, int j, int x, int y, char z);

//board
char board[9][9] = {{'0', '0', '0', '0','0', '0', '0','0'},
    {'0', 'R', 'N', 'B','Q','K', 'B','N','R'},
    {'0', 'P', 'P', 'P','P','P', 'P','P','P'},
    {'0', '-', '.', '-','.','-', '.','-','.'},
    {'0', '.', '-', '.','-','.', '-','.','-'},
    {'0', '-', '.', '-','.','-', '.','-','.'},
    {'0', '.', '-', '.','-','.', '-','.','-'},
    {'0', 'p', 'p', 'p','p','p', 'p','p','p'},
    {'0', 'r', 'n', 'b','q','k', 'b','n','r'}
};
//captured
char captured[4][8] = {{' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '}
};
char input[1000];//increased the size to control the input of malicious users

//for undo and redo we will use the following structs and functions
struct Node
{
    char board[9][9];
    char captured[4][8];
    struct Node *next;
};
struct package
{
    char bo[9][9];
    char ca[4][8];
};
struct Node *top = NULL;
struct Node *top2 = NULL;
struct package push_undo(char board[9][9], char captured[4][8]);
struct package pop_undo();
struct package push_redo();
struct package pop_redo();

//for the GUI
void process_image();
//entry and the builder
GtkBuilder *builder;
GtkEntry *e;
//windows
GtkWidget *window;
GtkWidget *window_endgame;
GtkWidget *window_error;
GtkWidget *window_save;
//buttons
GtkWidget *undo;
GtkWidget *redo;
GtkWidget *quit;
GtkWidget *enter;
GtkWidget *entry;
GtkWidget *button_endgame;
GtkWidget *button_error;
GtkWidget *button_save_yes;
GtkWidget *button_save_no;
GtkWidget *button_s;
//labels
GtkWidget *label_endgame;
GtkWidget *label_error;
GtkWidget *label_save;
GtkWidget *label_info;
GtkWidget *label_turn;
//images
struct labels
{
    GtkWidget *image;
};
struct labels laboard[64];
struct labels cap[32];


int main(void)
{
    char name[7];

    gtk_init(NULL, NULL);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder,"exp.glade", NULL);
    entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
    //windows
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    window_error = GTK_WIDGET(gtk_builder_get_object(builder, "window_error"));
    window_endgame = GTK_WIDGET(gtk_builder_get_object(builder, "window_endgame"));
    window_save = GTK_WIDGET(gtk_builder_get_object(builder, "window_save"));
    //buttons
    undo = GTK_WIDGET(gtk_builder_get_object(builder, "undo"));
    redo = GTK_WIDGET(gtk_builder_get_object(builder, "redo"));
    quit = GTK_WIDGET(gtk_builder_get_object(builder, "quit"));
    enter = GTK_WIDGET(gtk_builder_get_object(builder, "enter"));
    button_endgame = GTK_WIDGET(gtk_builder_get_object(builder, "button_endgame"));
    button_error = GTK_WIDGET(gtk_builder_get_object(builder, "button_error"));
    button_save_no = GTK_WIDGET(gtk_builder_get_object(builder, "button_save_no"));
    button_save_yes = GTK_WIDGET(gtk_builder_get_object(builder, "button_save_yes"));
    button_s = GTK_WIDGET(gtk_builder_get_object(builder, "button_s"));
    //labels
    label_error = GTK_WIDGET(gtk_builder_get_object(builder, "label_error"));
    label_save = GTK_WIDGET(gtk_builder_get_object(builder, "label_save"));
    label_endgame = GTK_WIDGET(gtk_builder_get_object(builder, "label_endgame"));
    label_info = GTK_WIDGET(gtk_builder_get_object(builder, "label_info"));
    label_turn = GTK_WIDGET(gtk_builder_get_object(builder, "label_turn"));
    //build the images of the board
    for(int i = 0; i < 64; i++)
    {
        sprintf(name,"image%i",i+1);
        laboard[i].image = GTK_WIDGET(gtk_builder_get_object(builder, name));
    }
    //build the images of the captured
    for(int i = 0; i < 32; i++)
    {
        sprintf(name,"cap%i",i+1);
        cap[i].image = GTK_WIDGET(gtk_builder_get_object(builder, name));
    }
    //check if a saved file is found or not
    if(access("saved.txt", F_OK) == 0)
    {
        //if found ask if the user wants to load it
        gtk_widget_show(window_save);
        gtk_label_set_label(label_save, "Do you want to reload saved game?");
        isquit = false;
    }
    else
    {
        //show the board
        process_image();
    }
    gtk_builder_connect_signals(builder, NULL);
    gtk_main();
    return 0;
}


void process_image()
{
    //needed colors
    GdkColor color_white;
    color_white.red = 0xffff;
    color_white.green = 0xffff;
    color_white.blue = 0xffff;

    GdkColor color_brown;
    color_brown.red = 0x8B00;
    color_brown.green = 0x4500;
    color_brown.blue = 0x1300;

    GdkColor color_back;
    color_back.red = 0xF400;
    color_back.green = 0xA400;
    color_back.blue = 0x0060;

    GdkColor color_peru;
    color_peru.red = 0xCD00;
    color_peru.green = 0x8500;
    color_peru.blue = 0x3F00;

    //load the images and set the background
    for(int i = 0; i < 64; i++)
    {
        gtk_widget_show(laboard[i].image);
    }
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i+1][j+1] == 'k')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/king.png");
            }
            else if(board[i+1][j+1] == 'p')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/pawn.png");
            }
            else if(board[i+1][j+1] == 'r')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/rook.png");
            }
            else if(board[i+1][j+1] == 'q')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/queen.png");
            }
            else if(board[i+1][j+1] == 'n')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/knight.png");
            }
            else if(board[i+1][j+1] == 'b')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/bishop.png");
            }
            else if(board[i+1][j+1] == 'K')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/king_b.png");
            }
            else if(board[i+1][j+1] == 'P')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/pawn_b.png");
            }
            else if(board[i+1][j+1] == 'R')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/rook_b.png");
            }
            else if(board[i+1][j+1] == 'Q')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/queen_b.png");
            }
            else if(board[i+1][j+1] == 'N')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/knight_b.png");
            }
            else if(board[i+1][j+1] == 'B')
            {
                gtk_image_set_from_file(laboard[i*8+j].image, "icons/bishop_b.png");
            }
            else
            {
                gtk_image_set_from_file(laboard[i*8+j].image, NULL);
            }
        }
    }


    int count = -1;
    for(int i = 0; i < 64; i++)
    {
        if(i%8 == 0)
        {
            count++;
        }
        if(count%2 == 0)
        {
            if(i%2 == 0)
            {
                gtk_widget_modify_bg(GTK_WIDGET(laboard[i].image), GTK_STATE_NORMAL, &color_white);
            }
            else
            {
                gtk_widget_modify_bg(GTK_WIDGET(laboard[i].image), GTK_STATE_NORMAL, &color_brown);
            }
        }
        else
        {
            if(i%2 == 1)
            {
                gtk_widget_modify_bg(GTK_WIDGET(laboard[i].image), GTK_STATE_NORMAL, &color_white);
            }
            else
            {
                gtk_widget_modify_bg(GTK_WIDGET(laboard[i].image), GTK_STATE_NORMAL, &color_brown);
            }
        }

    }

    for(int i = 0; i < 32; i++)
    {
        gtk_widget_modify_bg(GTK_WIDGET(cap[i].image), GTK_STATE_NORMAL, &color_peru);
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(captured[i][j] == 'k')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/king.png");
            }
            else if(captured[i][j] == 'p')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/pawn.png");
            }
            else if(captured[i][j] == 'r')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/rook.png");
            }
            else if(captured[i][j] == 'q')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/queen.png");
            }
            else if(captured[i][j] == 'n')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/knight.png");
            }
            else if(captured[i][j] == 'b')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/bishop.png");
            }
            else if(captured[i][j] == 'K')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/king_b.png");
            }
            else if(captured[i][j] == 'P')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/pawn_b.png");
            }
            else if(captured[i][j] == 'R')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/rook_b.png");
            }
            else if(captured[i][j] == 'Q')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/queen_b.png");
            }
            else if(captured[i][j] == 'N')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/knight_b.png");
            }
            else if(captured[i][j] == 'B')
            {
                gtk_image_set_from_file(cap[i*8+j].image, "icons/bishop_b.png");
            }
            else
            {
                gtk_image_set_from_file(cap[i*8+j].image, NULL);
            }
        }
    }
    //display the turns of the players
    if((counter + 1)%2 == 0)
    {
        gtk_label_set_label(label_turn, "Player 1 turn");
    }
    else
    {
        gtk_label_set_label(label_turn, "Player 2 turn");
    }
    gtk_widget_show(window);
    gtk_widget_modify_bg(GTK_WIDGET(window), GTK_STATE_NORMAL, &color_back);
}

G_MODULE_EXPORT void on_entry_changed(GtkEntry *e, gpointer user_data)
{
    sprintf(input, "%s", gtk_entry_get_text(e));
}

G_MODULE_EXPORT void on_enter_clicked(GtkButton *enter, gpointer user_data)
{
    if(!valid_input(input))
    {
        gtk_widget_show(window_error);
        gtk_label_set_label(label_error, "Invalid input");
        gtk_widget_set_sensitive (window, FALSE);
        gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
        return;
    }
    struct package tmp;
    memcpy(tmp.bo, board, sizeof(tmp.bo));
    memcpy(tmp.ca, captured, sizeof(tmp.ca));
    counter++;
    if(use_input(input) == 1)
    {
        counter--;
        gtk_widget_show(window_error);
        gtk_label_set_label(label_error, "Invalid move");
        gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
        return;
    }
    else
    {
        process_image();
        //push the stored board
        push_undo(tmp.bo, tmp.ca);
        //trace rooks
        Trace_rSquares(board);
        // in case a move is done the redo stack have to be cleared
        struct Node *tempo = NULL;
        while(top2 != NULL)
        {
            tempo = top2;
            top2 = top2->next;
            free(tempo);
        }
        if(Stalemate_Black(counter+1, board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Stalemate.Game Over. You can only undo or quit.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            gtk_widget_hide(window_save);
            return;
        }
        if(Stalemate_White(counter+1, board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Stalemate.Game Over. You can only undo or quit.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            gtk_widget_hide(window_save);
            return;
        }
        if(Draw(board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Draw. Game Over You can only undo or quit.");
            gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            return;
        }
        if(Checkmate_white(board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Checkmate. player 2 wins.");
            gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            return;
        }
        if(Checkmate_black(board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Checkmate. player 1 wins.");
            gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            return;
        }
        if (check_black(board))
        {
            gtk_label_set_label(label_info, "Check black");
        }
        else if (check_white(board))
        {
            gtk_label_set_label(label_info, "Check white");
        }
        else
        {
            gtk_label_set_label(label_info, " ");
        }
        gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
    }
}

G_MODULE_EXPORT void on_button_save_yes_clicked()
{
    if(isquit == true)
    {
        struct package tmp;
        FILE *file = fopen("saved.txt", "w");
        if(file == NULL)
        {
            printf("Error\n");
        }
        memcpy(tmp.bo, board, sizeof(tmp.bo));
        memcpy(tmp.ca, captured, sizeof(tmp.ca));
        fwrite(&tmp, sizeof(tmp), 1,file);
        putw(counter, file);
        putw(king_counter, file);
        putw(King_counter, file);
        putw(LR_square_counter, file);
        putw(Lr_square_counter, file);
        putw(RR_square_counter, file);
        putw(Rr_square_counter, file);
        fwrite(&LR_square, sizeof(char), 1, file);
        fwrite(&Lr_square, sizeof(char), 1, file);
        fwrite(&RR_square, sizeof(char), 1, file);
        fwrite(&Rr_square, sizeof(char), 1, file);
        fclose(file);
        struct Node *head = NULL;
        while(top != NULL)
        {
            head = top;
            top = top->next;
            free(head);
        }
        gtk_main_quit();
    }
    else
    {
        struct package tmp;
        FILE *file = fopen("saved.txt", "r");
        if(file == NULL)
        {
            printf("Error\n");
        }
        fread(&tmp, sizeof(tmp), 1,file);
        counter = getw(file);
        king_counter = getw(file);
        King_counter = getw(file);
        LR_square_counter = getw(file);
        Lr_square_counter = getw(file);
        RR_square_counter = getw(file);
        Rr_square_counter = getw(file);
        fread(&LR_square, sizeof(char), 1, file);
        fread(&Lr_square, sizeof(char), 1, file);
        fread(&RR_square, sizeof(char), 1, file);
        fread(&Rr_square, sizeof(char), 1, file);
        fclose(file);
        memcpy(board, tmp.bo, sizeof(board));
        memcpy(captured, tmp.ca, sizeof(captured));
        Trace_rSquares(board);
        king_position(board);
        process_image();
        if(Stalemate_Black(counter+1, board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Stalemate.Game Over. You can only undo or quit.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            gtk_widget_hide(window_save);
            return;
        }
        if(Stalemate_White(counter+1, board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Stalemate.Game Over. You can only undo or quit.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            gtk_widget_hide(window_save);
            return;
        }
        if(Draw(board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Draw. Game Over You can only undo or quit.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            gtk_widget_hide(window_save);
            return;
        }
        if(Checkmate_white(board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Checkmate. player 2 wins.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            return;
        }
        if(Checkmate_black(board) == 1)
        {
            gtk_widget_show(window_endgame);
            gtk_label_set_label(label_endgame,"Checkmate. player 1 wins.");
            gtk_widget_set_sensitive (entry, FALSE);
            gtk_widget_set_sensitive (enter, FALSE);
            gtk_widget_set_sensitive (redo, FALSE);
            return;
        }
        if (check_black(board))
        {
            gtk_label_set_label(label_info, "Check black");
        }
        else if (check_white(board))
        {
            gtk_label_set_label(label_info, "Check white");
        }
        else
        {
            gtk_label_set_label(label_info, " ");
        }
        gtk_widget_hide(window_save);
    }
}

G_MODULE_EXPORT void on_button_save_no_clicked()
{
    if(isquit == true)
    {
        struct Node *head = NULL;
        while(top != NULL)
        {
            head = top;
            top = top->next;
            free(head);
        }
        gtk_main_quit();
    }
    else
    {
        process_image();
        Trace_rSquares(board);
        gtk_widget_hide(window_save);
    }
}

G_MODULE_EXPORT void on_button_error_clicked()
{
    gtk_widget_hide(window_error);
    gtk_widget_set_sensitive (window, TRUE);
    isquit = true;
}

G_MODULE_EXPORT void on_button_endgame_clicked()
{
    gtk_widget_hide(window_endgame);
}

G_MODULE_EXPORT void on_undo_clicked()
{
    gtk_widget_set_sensitive (entry, TRUE);
    gtk_widget_set_sensitive (enter, TRUE);
    gtk_widget_set_sensitive (redo, TRUE);
    struct package tmp = pop_undo();
    if(isundo == 1)
    {
        return;
    }
    counter--;
    memcpy(board, tmp.bo, sizeof(board));
    memcpy(captured, tmp.ca, sizeof(captured));
    Trace_Kings_Undo(board);
    king_position(board);
    process_image();
    Trace_rSquares_Undo(board);
    if (check_black(board))
    {
        gtk_label_set_label(label_info, "Check black");
    }
    else if (check_white(board))
    {
        gtk_label_set_label(label_info, "Check white");
    }
    else
    {
        gtk_label_set_label(label_info, " ");
    }
}

G_MODULE_EXPORT void on_redo_clicked()
{
    struct package tmp = pop_redo();
    if(isredo == 1)
    {
        return;
    }
    counter++;
    memcpy(board, tmp.bo, sizeof(board));
    memcpy(captured, tmp.ca, sizeof(captured));
    Trace_Kings_Redo(board);
    king_position(board);
    process_image();
    Trace_rSquares_Redo(board);
    if(Stalemate_Black(counter+1, board) == 1)
    {
        gtk_widget_show(window_endgame);
        gtk_label_set_label(label_endgame,"Stalemate.Game Over. You can only undo or quit.");
        gtk_widget_set_sensitive (entry, FALSE);
        gtk_widget_set_sensitive (enter, FALSE);
        gtk_widget_set_sensitive (redo, FALSE);
        gtk_widget_hide(window_save);
        return;
    }
    if(Stalemate_White(counter+1, board) == 1)
    {
        gtk_widget_show(window_endgame);
        gtk_label_set_label(label_endgame,"Stalemate.Game Over. You can only undo or quit.");
        gtk_widget_set_sensitive (entry, FALSE);
        gtk_widget_set_sensitive (enter, FALSE);
        gtk_widget_set_sensitive (redo, FALSE);
        gtk_widget_hide(window_save);
        return;
    }
    if(Draw(board) == 1)
    {
        gtk_widget_show(window_endgame);
        gtk_label_set_label(label_endgame,"Draw. Game Over You can only undo or quit.");
        gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
        gtk_widget_set_sensitive (entry, FALSE);
        gtk_widget_set_sensitive (enter, FALSE);
        gtk_widget_set_sensitive (redo, FALSE);
        return;
    }
    if(Checkmate_white(board) == 1)
    {
        gtk_widget_show(window_endgame);
        gtk_label_set_label(label_endgame,"Checkmate. player 2 wins.");
        gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
        gtk_widget_set_sensitive (entry, FALSE);
        gtk_widget_set_sensitive (enter, FALSE);
        gtk_widget_set_sensitive (redo, FALSE);
        return;
    }
    if(Checkmate_black(board) == 1)
    {
        gtk_widget_show(window_endgame);
        gtk_label_set_label(label_endgame,"Checkmate. player 1 wins.");
        gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
        gtk_widget_set_sensitive (entry, FALSE);
        gtk_widget_set_sensitive (enter, FALSE);
        gtk_widget_set_sensitive (redo, FALSE);
        return;
    }
    if (check_black(board))
    {
        gtk_label_set_label(label_info, "Check black");
    }
    else if (check_white(board))
    {
        gtk_label_set_label(label_info, "Check white");
    }
    else
    {
        gtk_label_set_label(label_info, " ");
    }
}

G_MODULE_EXPORT void on_quit_clicked()
{
    gtk_widget_show(window_save);
    gtk_label_set_label(label_save, "Do you want to save the game before exit? ");
    gtk_widget_set_sensitive (window, FALSE);
    isquit = true;
}

// if save button is clicked
G_MODULE_EXPORT void on_button_s_clicked()
{
    struct package tmp;
    FILE *file = fopen("saved.txt", "w");
    if(file == NULL)
    {
        printf("Error\n");
    }
    memcpy(tmp.bo, board, sizeof(tmp.bo));
    memcpy(tmp.ca, captured, sizeof(tmp.ca));
    fwrite(&tmp, sizeof(tmp), 1,file);
    putw(counter, file);
    putw(king_counter, file);
    putw(King_counter, file);
    putw(LR_square_counter, file);
    putw(Lr_square_counter, file);
    putw(RR_square_counter, file);
    putw(Rr_square_counter, file);
    fwrite(&LR_square, sizeof(char), 1, file);
    fwrite(&Lr_square, sizeof(char), 1, file);
    fwrite(&RR_square, sizeof(char), 1, file);
    fwrite(&Rr_square, sizeof(char), 1, file);
    fclose(file);
}
// when the close window "x" button is clicked
G_MODULE_EXPORT void on_window1_destroy()
{
    gtk_main_quit();
}

//a function to validate the input from the user
int valid_input(char input[])
{
    if(strlen(input) == 1)
    {
        if(input[0] == 'U' || input[0] == 'R' || input[0] == 'E')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    char s[letters] = " ABCDEFGH";
    char p[4] = "RNBQ";
    int counter3 = 0, counter1 = 0, counter2 = 0;
    if(strlen(input)>5)
    {
        return 0;
    }
    // in case of promotion
    if(strlen(input) == 5)
    {
        for(int i = 0; i < 4; i++)
        {
            if(input[4] == p[i])
            {
                counter3++;
            }
        }
        if(counter3 != 1)
        {
            return 0;
        }
    }
    //check the validity of the input
    if(!isdigit(input[1]) || !isdigit(input[3]))
    {
        return 0;
    }
    if(input[1] <= 48 || input[3] <= 48)
    {
        return 0;
    }
    if(input[1] > 56 || input[3] > 56)
    {
        return 0;
    }

    for(int i = 1; i < letters; i++)
    {
        if(input[0] == s[i])
        {
            counter1++;
        }
        if(input[2] == s[i])
        {
            counter2++;
        }
    }
    if(counter1 != 1 || counter2 != 1)
    {
        return 0;
    }
    return 1;

}
// a function to use the input from the user and call other functions to make the move
int use_input(char input[])
{
    int vals[strlen(input)];
    char s[letters] = " ABCDEFGH";
    // convert the input to number to be used in the array
    for(int i = 1; i < letters; i++)
    {
        if(input[0] == s[i])
        {
            input[0] = i+'0';
        }
        if(input[2] == s[i])
        {
            input[2] = i+'0';
        }
    }
    for(int i = 0; i < strlen(input); i++)
    {
        vals[i] = (int)input[i] - 48;
    }
    vals[1] = letters - vals[1];
    vals[3] = letters - vals[3];
    // condition to make each player move only his pieces
    if(isupper(board[vals[1]][vals[0]]) && counter%2 == 0)
    {
        return 1;
    }
    if(islower(board[vals[1]][vals[0]]) && counter%2 != 0)
    {
        return 1;
    }
    // make sure that player can't knock his own pieces
    if(islower(board[vals[3]][vals[2]]) && counter%2 == 0)
    {
        return 1;
    }
    if(isupper(board[vals[3]][vals[2]]) && counter%2 != 0)
    {
        return 1;
    }
    // make sure that the player is not choosing a white or black empty spot
    if(board[vals[1]][vals[0]] == '.' || board[vals[1]][vals[0]] == '-')
    {
        return 1;
    }
    // making the move
    switch(board[vals[1]][vals[0]])
    {
    // if the chosen piece is a pawn
    case 'p':
        //in case of promotion
        if(strlen(input) == 5)
        {
            if(promotion(vals[1], vals[0], vals[3], vals[2], input[4]) == 1)
            {
                return 1;
            }
            else
            {
                break;
            }
        }
        //in case the pawn in a square before the last one he must promote
        if(vals[1] == 2 && strlen(input) == 4)
        {
            return 1;
        }
        if(!pawn_white(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    //for black pawn
    case 'P':
        // in case of promorion
        if(strlen(input) == 5)
        {
            if(promotion(vals[1], vals[0], vals[3], vals[2], input[4]) == 1)
            {
                return 1;
            }
            else
            {
                break;
            }
        }
        //in case the pawn in a square before the last one he must promote
        if(vals[1] == 7 && strlen(input) == 4)
        {
            return 1;
        }
        if(!pawn_black(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    // if the chosen piece is a rook
    case 'r':
        if(!moveR(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    case 'R':
        if(!moveR(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    //   if the chosen piece is a bishop
    case 'b':
        if(!moveB(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    case 'B':
        if(!moveB(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    // if the chosen piece is a queen
    case 'q':
        if(!moveQ(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    case 'Q':
        if(!moveQ(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    // if the chosen piece is a king
    case 'k':
        if(!moveK(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    case 'K':
        if(!moveK(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    // if the chosen piece is a knight
    case 'n':
        if(!moveN(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    case 'N':
        if(!moveN(vals[1], vals[0], vals[3], vals[2], board, captured))
        {
            return 1;
        }
        break;
    }
    return 0;
}
// a function knockout pieces and add them to capture list
void knocked(int i, int j, int x, int y)
{
    if (board[x][y] == '.' || board[x][y] == '-')
    {
        return;
    }
    if(islower(board[x][y]))
    {
        // search for a empty spot
        for(int i = 0; i<2; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(captured[i][j] == ' ')
                {
                    captured[i][j] = board[x][y];
                    return;
                }
            }
        }
    }
    else
    {
        for(int i = 2; i<4; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(captured[i][j] == ' ')
                {
                    captured[i][j] = board[x][y];
                    return;
                }
            }
        }
    }
    return;
}
// a function to promote pawns
int promotion(int i, int j, int x, int y, char z)
{
    if(j == y && (board[x][y] != '.' && board[x][y] != '-'))
    {
        return 1;
    }
    if(j == y+1 || j == y-1)
    {
        knocked(i,j,x,y);
    }
    if(islower(board[i][j]))
    {
        if(i != 2 || x != 1)
        {
            return 1;
        }
        z = tolower(z);
        board[x][y] = z;
        if((i + j) % 2 == 1)
        {
            board[i][j] = '.';
        }
        else
        {
            board[i][j] = '-';
        }
        gtk_widget_show(window_error);
        gtk_label_set_label(label_error, "Promotion");
        return 0;
    }
    else
    {
        if(i != 7 || x != 8)
        {
            return 1;
        }
        board[x][y] = z;
        if((i + j) % 2 == 1)
        {
            board[i][j] = '.';
        }
        else
        {
            board[i][j] = '-';
        }
        gtk_widget_show(window_error);
        gtk_label_set_label(label_error, "Promotion");
        return 0;
    }
    return 1;
}
// push to the undo stack
struct package push_undo(char board[9][9], char captured[4][8])
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        printf("Heap Overflow\n");
        free(temp);
        return;
    }
    memcpy(temp->board, board, sizeof(temp->board));
    memcpy(temp->captured, captured, sizeof(temp->captured));
    temp->next = top;
    top = temp;
    struct package pack;
    memcpy(pack.bo, temp->board, sizeof(pack.bo));
    memcpy(pack.ca, temp->captured, sizeof(pack.ca));
    return pack;
}
//pop the first element from the undo stack
struct package pop_undo()
{
    //check if the stack is empty
    if(top == NULL)
    {
        isundo = 1;
        gtk_widget_show(window_error);
        gtk_label_set_label(label_error, "No moves entered to be undone.");
        gtk_widget_set_sensitive (window, FALSE);
        return;
    }
    push_redo();
    struct Node *temp;
    struct package pack;
    memcpy(pack.bo, top->board, sizeof(pack.bo));
    memcpy(pack.ca, top->captured, sizeof(pack.ca));
    temp = top;
    top = top->next;
    free(temp);
    isundo = 0;
    return pack;
}
// push to the redo stack
struct package push_redo()
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        printf("Heap Overflow\n");
        free(temp);
        return;
    }
    memcpy(temp->board, board, sizeof(temp->board));
    memcpy(temp->captured, captured, sizeof(temp->captured));
    temp->next = top2;
    top2 = temp;
    struct package pack;
    memcpy(pack.bo, temp->board, sizeof(pack.bo));
    memcpy(pack.ca, temp->captured, sizeof(pack.ca));
    return pack;
}
//pop the first element from the redo stack
struct package pop_redo()
{
    //check if the stack is empty
    if(top2 == NULL)
    {
        isredo = 1;
        gtk_widget_show(window_error);
        gtk_label_set_label(label_error, "No redoes left.");
        gtk_widget_set_sensitive (window, FALSE);
        return;
    }
    push_undo(board, captured);
    struct package pack;
    memcpy(pack.bo, top2->board, sizeof(pack.bo));
    memcpy(pack.ca, top2->captured, sizeof(pack.ca));
    struct Node *temp;
    temp = top2;
    top2 = top2->next;
    free(temp);
    isredo = 0;
    return pack;
}
