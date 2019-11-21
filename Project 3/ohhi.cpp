/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * Corey Dulin and Lucky Chowdury
 * cydulin and lmchow
 *
 * This holds the funtion definitions for Project 3 (the game Ohhi)
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

// Counts and returns the number of unknown squares in a board
int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int num_unknown = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(board[i][j] == UNKNOWN) {
                num_unknown++;
            }
        }
    }
    return num_unknown;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

// Checks that there are not 3 consecutive squares of the same color in a row
bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    
    for(int i = 0; i < size - 2; i++) {
        if(board[row][i] == color && board[row][i + 1] ==
           color && board[row][i + 2] == color) {
            return false;
        }
    }
    
    return true;
    
    
}

// Checks there are not 3 consecutive squares of the same color in a column
bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    
    for(int i = 0; i < size - 2; i++) {
        if (board[i][col] == color && board[i + 1][col] ==
            color && board[i + 2][col] == color) {
            return false;
        }
    }
    
    return true;
    
}

// Checks that there are no 3 identical squares right by each other
// (in a row or column)
bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        if(!row_has_no_threes_of_color(board, size, i, RED) ||
           !row_has_no_threes_of_color(board, size, i, BLUE)){
            return false;
        }
    }
    for(int i = 0; i < size; i++) {
        if(!col_has_no_threes_of_color(board, size, i, RED) ||
           !col_has_no_threes_of_color(board, size, i, BLUE)) {
            return false;
        }
    }
    return true;
}

// Checks that rows on a board are not identical
bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    for(int i = 0; i < size; i++) {
        if(((board[row1][i] == UNKNOWN) || (board[row2][i] == UNKNOWN))) {
            return true;
        }
        if (board[row1][i] != board[row2][i]) {
            return true;
        }
        
    }
    return false;
}

// Checks that columns on a board are not identical
bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    for(int i = 0; i < size; i++) {
        if(((board[i][col1] == UNKNOWN) || (board[i][col2] == UNKNOWN))) {
            return true;
        }
        if (board[i][col1] != board[i][col2]) {
            return true;
        }
        
    }
    return false;
}

// Checks that board has no duplicate columns or rows
bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for(int row = 0; row < size - 1; row++) {
        for(int col = row + 1; col < size; col++) {
            if(!rows_are_different(board, size, row, col)
               || (!cols_are_different(board, size, row, col))) {
                return false;
            }
        }
    }
    return true;
}

///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

// Inputs the opposite color for unknown (or blank) squares in a row
void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    for(int i = 0; i < size - 2; i++) {
        if(board[row][i] == board[row][i + 1]) {
            if(board[row][i] == RED && board[row][i + 2] == UNKNOWN) {
                mark_square_as(board, size, row, i + 2,
                               opposite_color(board[row][i]), announce);
            }
            else if(board[row][i] == BLUE && board[row][i + 2] == UNKNOWN) {
                mark_square_as(board, size, row, i + 2,
                               opposite_color(board[row][i]), announce);
            }
        }
        if(board[row][i + 1] == board[row][i + 2]) {
            if(board[row][i + 1] == RED && board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i,
                               opposite_color(board[row][i + 1]), announce);
            }
            else if (board[row][i + 1] == BLUE && board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i,
                               opposite_color(board[row][i + 1]), announce);
            }
        }
        if(board[row][i] == board[row][i + 2]) {
            if(board[row][i] == RED && board[row][i + 1] == UNKNOWN) {
                mark_square_as(board, size, row, i + 1,
                               opposite_color(board[row][i]), announce);
            }
            else if(board[row][i] == BLUE && board[row][i + 1] == UNKNOWN) {
                mark_square_as(board, size, row, i + 1,
                               opposite_color(board[row][i]), announce);
            }
        }
    }
}

// Inputs the opposite color for unknown (or blank) squares in a column
void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    for(int i = 0; i < size - 2; i++) {
        if(board[i][col] == board[i + 1][col]) {
            if(board[i][col] == RED && board[i + 2][col] == UNKNOWN) {
                mark_square_as(board, size, i + 2, col,
                               opposite_color(board[i][col]), announce);
            }
            else if(board[i][col] == BLUE && board[i + 2][col] == UNKNOWN) {
                mark_square_as(board, size, i + 2, col,
                               opposite_color(board[i][col]), announce);
            }
        }
        if(board[i + 1][col] == board[i + 2][col]) {
            if(board[i + 1][col] == RED && board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col,
                               opposite_color(board[i + 1][col]), announce);
            }
            else if (board[i + 1][col] == BLUE && board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col,
                               opposite_color(board[i + 1][col]), announce);
            }
        }
        if(board[i][col] == board[i + 2][col]) {
            if(board[i][col] == RED && board[i + 1][col] == UNKNOWN) {
                mark_square_as(board, size, i + 1, col,
                               opposite_color(board[i][col]), announce);
            }
            else if(board[i][col] == BLUE && board[i + 1][col] == UNKNOWN) {
                mark_square_as(board, size, i + 1, col,
                               opposite_color(board[i][col]), announce);
                
            }
        }
    }
}

// Colors all remaining unknown tiles in a row to the opposite color
void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int numRed = 0;
    int numBlue = 0;
    for(int i = 0; i < size; i++) {
        if(board[row][i] == RED) {
            numRed++;
        }
        if(board[row][i] == BLUE) {
            numBlue++;
        }
    }
    if(numRed == size / 2) {
        for(int i = 0; i < size; i++) {
            if(board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, BLUE, announce);
            }
        }
    } else if(numBlue == size / 2) {
        for(int i = 0; i < size; i++) {
            if(board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, RED, announce);
            }
        }
    }
}

// Colors all remaining unknown tiles in a column to the opposite color
void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int numRed = 0;
    int numBlue = 0;
    for(int i = 0; i < size; i++) {
        if(board[i][col] == RED) {
            numRed++;
        }
        if(board[i][col] == BLUE) {
            numBlue++;
        }
    }
    if(numRed == size / 2) {
        for(int i = 0; i < size; i++) {
            if(board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, BLUE, announce);
            }
        }
    } else if(numBlue == size / 2) {
        for(int i = 0; i < size; i++) {
            if(board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, RED, announce);
            }
        }
    }
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

// Returns true if the board has been solved and doesn't violate any rules
bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if(board_is_valid(board, size) && board_has_no_threes(board, size)
       && board_has_no_duplicates(board, size) &&
       count_unknown_squares(board, size) == 0) {
        return true;
    }
    return false;
}

//Checks that user input for row, column, and the color of a square is valid
// (if any of these are invalid, it prints an error message and returns false
bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    
    char upperCaseCol = toupper(col_input);
    char upperCaseColor = toupper(color_char);
    
    if(row_input >= 1 && row_input <= size &&
       ((upperCaseCol >= 'A' && upperCaseCol <= 'A' + size - 1))
       && (upperCaseColor == RED_LETTER || upperCaseColor == BLUE_LETTER ||
           color_char == UNKNOWN_LETTER)) {
           row = row_input - 1;
           col = upperCaseCol - 'A';
           return true;
       }
    else {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    return false;
}

// Returns true if the specified square was not set in the originals board
// and the given color in this square does not create an invalid board
bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    if (original_board[row][col] != UNKNOWN){
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    int new_board[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, new_board, size);
    new_board[row][col] = color;
    if (!board_is_valid(new_board, size)){
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }
    return true;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
}
