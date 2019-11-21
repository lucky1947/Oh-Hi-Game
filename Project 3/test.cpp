/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * <#Name(s)#> Lucky Chowdhury, Corey Dulin
 * <#uniqname(s)#> lmchow, cydulin
 *
 * <#A description of the project here#> We are testing all of the functions that
 * we use in project 3.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();


int main() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();
    
    
    return 0;
}

void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "Testing number of unknown squares" << endl;
    
    // test case 1
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"XX--",
        "O-OX",
        "--X-",
        "X---"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"X-----",
        "X----X",
        "--O--X",
        "--O---",
        "X-----",
        "---X--"};
    int size_3 = 6;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"--O---",
        "------",
        "X--XO-",
        "---X--",
        "X---O-",
        "XX-O--"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    cout << count_unknown_squares(board, size_4) << endl;
    
    // test case 5
    string test_board_5[] = {"-X--OX",
        "-OX--O",
        "------",
        "OX-XO-",
        "O-----",
        "----OO"};
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    cout << count_unknown_squares(board, size_5) << endl;
    
    // test case 6
    string test_board_6[] = {"O-XO-X-O",
        "X---OO--",
        "O-O--X-O",
        "XOX---OX",
        "--O--X--",
        "XO---O--",
        "XXOOX--O",
        "O--O-X--"};
    int size_6 = 8;
    read_board_from_string(board, test_board_6, size_6);
    cout << count_unknown_squares(board, size_6) << endl;
    
    // test case 7
    string test_board_7[] = {"----O---",
        "-O------",
        "X------O",
        "--X-O---",
        "-O-X-X-O",
        "--------",
        "--XX----",
        "-O------"};
    int size_7 = 8;
    read_board_from_string(board, test_board_7, size_7);
    cout << count_unknown_squares(board, size_7) << endl;
    
}

// FIX: I have tons of test cases, but it doesn't catch any of the bugs
void test_row_has_no_threes_of_color() {
    cout << "Testing row has no threes of color : " << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1, for RED (should return true, 1)
    string test_board_1[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    
    // test case 2, for RED (should return true, 1)
    string test_board_2[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 2, RED) << endl;
    
    // test case 3, for RED (should return false, 0)
    string test_board_3[] = {"----",
        "XXX-",
        "-XO-",
        "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, 1, RED) << endl;
    
    // test case 4, for BLUE (should return true, 1)
    string test_board_4[] = {"----",
        "XX--",
        "-OO-",
        "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << row_has_no_threes_of_color(board, size_4, 2, BLUE) << endl;
    
    // test case 5, for BLUE (should return true, 1)
    string test_board_5[] = {"----",
        "XX--",
        "--O-",
        "-OO-"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << row_has_no_threes_of_color(board, size_5, 3, BLUE) << endl;
    
    // test case 6, for BLUE (should return false, 0)
    string test_board_6[] = {"----",
        "XX--",
        "--O-",
        "OOO-"};
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << row_has_no_threes_of_color(board, size_6, 3, BLUE) << endl;
    
    // test case 7, for RED (should return false, 0)
    string test_board_7[] = {"XXX---",
        "X----X",
        "--O--X",
        "--O---",
        "X-----",
        "---X--"};
    int size_7 = 6;
    read_board_from_string(board, test_board_7, size_7);
    cout << row_has_no_threes_of_color(board, size_7, 0, RED) << endl;
    
    // test case 8, for RED (should return false, 0)
    string test_board_8[] = {"X-----",
        "X----X",
        "--O--X",
        "--O---",
        "X-----",
        "---XXX"};
    int size_8 = 6;
    read_board_from_string(board, test_board_8, size_8);
    cout << row_has_no_threes_of_color(board, size_8, 5, RED) << endl;
    
    // test case 9, for RED (should return false, 0)
    string test_board_9[] = {"X-----",
        "X----X",
        "--OXXX",
        "--O---",
        "X-----",
        "---XXX"};
    int size_9 = 6;
    read_board_from_string(board, test_board_9, size_9);
    cout << row_has_no_threes_of_color(board, size_9, 2, RED) << endl;
    
    // test case 10, for RED (should return false, 0)
    string test_board_10[] = {"X-----",
        "X----X",
        "--O---",
        "XXX---",
        "X-----",
        "---XXX"};
    int size_10 = 6;
    read_board_from_string(board, test_board_10, size_10);
    cout << row_has_no_threes_of_color(board, size_10, 3, RED) << endl;
    
    // test case 11, for RED (should return false, 0)
    string test_board_11[] = {"X-----",
        "X----X",
        "--O---",
        "--XXX-",
        "X-----",
        "-----X"};
    int size_11 = 6;
    read_board_from_string(board, test_board_11, size_11);
    cout << row_has_no_threes_of_color(board, size_11, 3, RED) << endl;
    
    // test case 12, for BLUE (should return false, 0)
    string test_board_12[] = {"OOO---",
        "X----X",
        "--O--X",
        "--O---",
        "X-----",
        "---X--"};
    int size_12 = 6;
    read_board_from_string(board, test_board_12, size_12);
    cout << row_has_no_threes_of_color(board, size_12, 0, BLUE) << endl;
    
    // test case 13, for BLUE (should return false, 0)
    string test_board_13[] = {"X-----",
        "X----X",
        "--O--X",
        "--O---",
        "X-----",
        "---OOO"};
    int size_13 = 6;
    read_board_from_string(board, test_board_13, size_13);
    cout << row_has_no_threes_of_color(board, size_13, 5, BLUE) << endl;
    
    // test case 14, for BLUE (should return false, 0)
    string test_board_14[] = {"X-----",
        "X----X",
        "---OOO",
        "--O---",
        "X-----",
        "---XXX"};
    int size_14 = 6;
    read_board_from_string(board, test_board_14, size_14);
    cout << row_has_no_threes_of_color(board, size_14, 2, BLUE) << endl;
    
    // test case 15, for BLUE (should return false, 0)
    string test_board_15[] = {"X-----",
        "X----X",
        "-OOO--",
        "XXX---",
        "X-----",
        "---XXX"};
    int size_15 = 6;
    read_board_from_string(board, test_board_15, size_15);
    cout << row_has_no_threes_of_color(board, size_15, 2, RED) << endl;
    
    // test case 16, for BLUE (should return false, 0)
    string test_board_16[] = {"OOO---",
        "X----X",
        "--O---",
        "--XXX-",
        "X-----",
        "-----X"};
    int size_16 = 6;
    read_board_from_string(board, test_board_16, size_16);
    cout << row_has_no_threes_of_color(board, size_16, 0, BLUE) << endl;
    
    // test case 17, for BLUE (should return false, 0)
    string test_board_17[] = {"OOO---",
        "X----X",
        "--O---",
        "--XXX-",
        "X-----",
        "-----X"};
    int size_17 = 6;
    read_board_from_string(board, test_board_17, size_17);
    cout << row_has_no_threes_of_color(board, size_17, 6, BLUE) << endl;
    
    // test case 18, for RED (should return true, 1)
    string test_board_18[] = {"------",
        "------",
        "------",
        "------",
        "------",
        "------"};
    int size_18 = 6;
    read_board_from_string(board, test_board_18, size_18);
    cout << row_has_no_threes_of_color(board, size_18, 5, RED) << endl;
    
    // test case 19, for BLUE (should return true, 1)
    string test_board_19[] = {"------",
        "------",
        "------",
        "------",
        "------",
        "------"};
    int size_19 = 6;
    read_board_from_string(board, test_board_19, size_19);
    cout << row_has_no_threes_of_color(board, size_19, 4, BLUE) << endl;
    
    // test case 20, for RED (should return true, 1)
    string test_board_20[] = {"----",
        "----",
        "----",
        "----"};
    int size_20 = 4;
    read_board_from_string(board, test_board_20, size_20);
    cout << row_has_no_threes_of_color(board, size_20, 3, RED) << endl;
    
    // test case 21, for BLUE (should return true, 1)
    string test_board_21[] = {"----",
        "----",
        "----",
        "----"};
    int size_21 = 4;
    read_board_from_string(board, test_board_21, size_21);
    cout << row_has_no_threes_of_color(board, size_21, 0, BLUE) << endl;
    
    // test case 22, for RED (should return true, 1)
    string test_board_22[] = {"--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------"};
    int size_22 = 8;
    read_board_from_string(board, test_board_22, size_22);
    cout << row_has_no_threes_of_color(board, size_22, 6, RED) << endl;
    
    // test case 23, for BLUE (should return true, 1)
    string test_board_23[] = {"--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------"};
    int size_23 = 8;
    read_board_from_string(board, test_board_23, size_23);
    cout << row_has_no_threes_of_color(board, size_23, 7, BLUE) << endl;
    
    //test cse 24, for BLUE (should return true, 1)
    string test_board_24[] = {"XXX-",
        "----",
        "----",
        "---X"};
    int size_24 = 4;
    read_board_from_string(board, test_board_24, size_24);
    cout << row_has_no_threes_of_color(board, size_24, 0, BLUE) << endl;
    
    //test case 25, for BLUE (should return true, 1)
    string test_board_25[] = {"XXX-",
        "----",
        "----",
        "XX-O"};
    int size_25 = 4;
    read_board_from_string(board, test_board_25, size_25);
    cout << row_has_no_threes_of_color(board, size_25, 3, BLUE) << endl;
    
    // test case 26, for RED (should return true, 1)
    string test_board_26[] = {"XO",
        "OX"};
    int size_26 = 2;
    read_board_from_string(board, test_board_26, size_26);
    cout << row_has_no_threes_of_color(board, size_26, 1, RED) << endl;
    
    // test case 27, for BLUE (should return true, 1)
    string test_board_27[] = {"OXXO",
        "XOXO",
        "OXOX",
        "XOOX"};
    int size_27 = 4;
    read_board_from_string(board, test_board_27, size_27);
    cout << row_has_no_threes_of_color(board, size_27, 3, BLUE) << endl;
    
    // test case 28, for RED (should return true, 1)
    string test_board_28[] = {"--",
        "--"};
    int size_28 = 2;
    read_board_from_string(board, test_board_28, size_28);
    cout << row_has_no_threes_of_color(board, size_28, 1, RED) << endl;
    
    // test case 29, for BLUE (should return false, 0)
    string test_board_29[] = {"XO---X",
        "-----O",
        "------",
        "OOOOOO",
        "------",
        "-----X"};
    int size_29 = 6;
    read_board_from_string(board, test_board_29, size_29);
    cout << row_has_no_threes_of_color(board, size_29, 3, BLUE) << endl;
    
    // test case 30, for BLUE (should return false, 0)
    string test_board_30[] = {"XO---X",
        "OOOOOO",
        "------",
        "OOOOOO",
        "OOOOOO",
        "XXXXXX"};
    int size_30 = 6;
    read_board_from_string(board, test_board_30, size_30);
    cout << row_has_no_threes_of_color(board, size_30, 4, BLUE) << endl;
    
    // test case 31, for RED (should return false, 0)
    string test_board_31[] = {"XO---X",
        "OOOOOO",
        "------",
        "OOOOOO",
        "OOOOOO",
        "XXXXXX"};
    int size_31 = 6;
    read_board_from_string(board, test_board_31, size_31);
    cout << row_has_no_threes_of_color(board, size_31, 5, RED) << endl;
    
    //test case 32, for BLUE (should return true, 1)
    string test_board_32[] = {"OO",
        "OO"};
    int size_32 = 2;
    read_board_from_string(board, test_board_32, size_32);
    cout << row_has_no_threes_of_color(board, size_32, 1, RED) << endl;
    //=====
    // 1| O O |1
    // 2| O O |2
    // =====
    //A B
    
    
    
    
    
    
}
// Test for column has no threes of color function
void test_col_has_no_threes_of_color() {
    cout << "Testing column has no threes of color: " << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1, for RED (should return true, 1)
    string test_board_1[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    
    
    // test case 2, for RED (should return true, 1)
    string test_board_2[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, 2, RED) << endl;
    
    // test case 3, for BLUE (should return true, 1)
    string test_board_3[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, 1, BLUE) << endl;
    
    // test case 4, for BLUE (should return false, 0)
    string test_board_4[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, 2, BLUE) << endl;
    
    // test case 5, for RED (should return false, 0)
    string test_board_5[]{"X-----",
        "X----X",
        "--O--X",
        "--O--X",
        "X-----",
        "---X--"};
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    cout << col_has_no_threes_of_color(board, size_5, 2, RED) << endl;
    
    // test case 6, for BLUE (should return false, 0)
    string test_board_6[]{"X-----",
        "X-O--X",
        "--O--X",
        "--O---",
        "X-----",
        "---X--"};
    int size_6 = 6;
    read_board_from_string(board, test_board_6, size_6);
    cout << col_has_no_threes_of_color(board, size_6, 2, BLUE) << endl;
    
    // test case 7, for BLUE (should return false)
    string test_board_7[]{"X-----",
        "X----X",
        "-----X",
        "--O---",
        "X-O---",
        "--OX--"};
    int size_7 = 6;
    read_board_from_string(board, test_board_7, size_7);
    cout << col_has_no_threes_of_color(board, size_6, 4, BLUE) << endl;
    
    // test case 8, for RED (should return false)
    string test_board_8[] = {"----O---",
        "-OX-----",
        "X-X----O",
        "--X-O---",
        "-O-X-X--",
        "--------",
        "--XX----",
        "-O------"};
    int size_8 = 8;
    read_board_from_string(board, test_board_8, size_8);
    cout << col_has_no_threes_of_color(board, size_8, 2, RED) << endl;
    
    // test case 9, for BLUE (should return false)
    string test_board_9[] = {"----O---",
        "-O------",
        "X------O",
        "--X-O--O",
        "-O-X-X-O",
        "--------",
        "--XX----",
        "-O------"};
    int size_9 = 8;
    read_board_from_string(board, test_board_9, size_9);
    cout << col_has_no_threes_of_color(board, size_9, 3, BLUE) << endl;
    
    
}

// Test for board has no threes of color function
void test_board_has_no_threes() {
    cout << "Testing board has no threes: " << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1, should return false, 0
    string test_board_1[] = {"----",
        "XXO-",
        "-XO-",
        "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1) << endl;
    
    // test case 2, should return false, 0
    string test_board_2[] = {"----",
        "XXO-",
        "-X--",
        "-XO-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << endl;
    
    // test case 3, should return true, 1
    string test_board_3[] = {"----",
        "XXO-",
        "-X--",
        "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3) << endl;
    
}
void test_rows_are_different() {
    cout << "Testing rows are different: " << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    
    // test case 1, should return true (1)
    string test_board_1[] = {"XX--",
        "OO--",
        "OO--",
        "XX--"};
    
    
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 0, 1) << endl;
    
    // test case 2, should return false (0)
    string test_board_2[] = {"XX--",
        "OOOO",
        "OOOO",
        "XX--"};
    
    
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, 1, 2) << endl;
}
void test_cols_are_different() {
    cout << "Testing columns are different: " << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    
    // test case 1, should return false (0)
    string test_board_1[] = {"XX--",
        "OO--",
        "OO--",
        "XX--"};
    
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 0, 1) << endl;
    
    // test case 2, should return true (1)
    string test_board_2[] = {"XX--",
        "OO--",
        "----",
        "----"};
    
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1) << endl;
    
    // test case 3, should return true (1)
    string test_board_3[] = {"----",
        "----",
        "----",
        "----"};
    
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board, size_3, 2, 3) << endl;
    
    // test case 4, should return true (1)
    string test_board_4[] = {"-XX-",
        "-OO-",
        "-OO-",
        "--X-"};
    
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << cols_are_different(board, size_4, 1, 2) << endl;
    
    // test case 5, should return true (1)
    string test_board_5[] = {"-X--",
        "-OO-",
        "-OO-",
        "--X-"};
    
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << cols_are_different(board, size_5, 1, 2) << endl;
    
    // test case 6, should return false (0)
    string test_board_6[] = {"-XX---",
        "-OO---",
        "-OO---",
        "-OO---",
        "-OO---",
        "-XX---"};
    
    int size_6 = 6;
    read_board_from_string(board, test_board_6, size_6);
    cout << cols_are_different(board, size_6, 1, 2) << endl;
    
    // test case 7, should return false (0)
    string test_board_7[] = {"X----X",
        "O----O",
        "X----X",
        "O----O",
        "X----X",
        "O----O"};
    
    int size_7 = 6;
    read_board_from_string(board, test_board_7, size_7);
    cout << cols_are_different(board, size_7, 0, 5) << endl;
    
    // test case 8, should return false (0)
    string test_board_8[] = {"X-OO-X",
        "O-XX-O",
        "X-OO-X",
        "O-XX-O",
        "X-OO-X",
        "O-XX-O"};
    
    int size_8 = 6;
    read_board_from_string(board, test_board_8, size_8);
    cout << cols_are_different(board, size_8, 2, 3) << endl;
    
    // test case 9, should return true (1)
    string test_board_9[] = {"------",
        "------",
        "------",
        "------",
        "------",
        "------"};
    
    int size_9 = 6;
    read_board_from_string(board, test_board_9, size_9);
    cout << cols_are_different(board, size_9, 2, 3) << endl;
    
    // test case 10, should return true (1)
    string test_board_10[] = {"-X--X-",
        "-O--O-",
        "-X--X-",
        "-O--O-",
        "-O--O-",
        "-X----"};
    
    int size_10 = 6;
    read_board_from_string(board, test_board_10, size_10);
    cout << cols_are_different(board, size_10, 1, 4) << endl;
    
    // test case 11, should return true (1)
    string test_board_11[] = {"----X-",
        "-O--O-",
        "-X--X-",
        "-O--O-",
        "-O--O-",
        "-X----"};
    
    int size_11 = 6;
    read_board_from_string(board, test_board_11, size_11);
    cout << cols_are_different(board, size_11, 1, 4) << endl;
    
    // test case 12, should return true (1)
    string test_board_12[] = {"--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------"};
    
    int size_12 = 8;
    read_board_from_string(board, test_board_12, size_12);
    cout << cols_are_different(board, size_12, 1, 4) << endl;
    
    // test case 13, should return true (1)
    string test_board_13[] = {"X------X",
        "--------",
        "--------",
        "O------O",
        "O------O",
        "--------",
        "--------",
        "X------X"};
    
    int size_13 = 8;
    read_board_from_string(board, test_board_13, size_13);
    cout << cols_are_different(board, size_13, 0, 7) << endl;
    
    // test case 14, should return false (0)
    string test_board_14[] = {"XO-----O",
        "-X-----X",
        "-X-----X",
        "OO-----O",
        "OO-----O",
        "-X-----X",
        "-O-----O",
        "XX-----X"};
    
    int size_14 = 8;
    read_board_from_string(board, test_board_14, size_14);
    cout << cols_are_different(board, size_14, 1, 7) << endl;
    
}
void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing board has no duplicates: " << endl;
    
    // test case 1, should return true (1)
    string test_board_1[] = {"OO--",
        "XXOO",
        "XXO-",
        "O-X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    
    // test case 2, should return false (0)
    string test_board_2[] = {"OO--",
        "XXOO",
        "XXOO",
        "O-O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;
    
    // test case 3, should return false (0)
    string test_board_3[] = {"OOXX",
        "XX--",
        "XX--",
        "OOXX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, size_3) << endl;
    
    // test case 4, should return false (0)
    string test_board_4[] = {"X---",
        "OXXO",
        "OXXO",
        "--X-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_duplicates(board, size_4) << endl;
    
    // test case 5, should return false (0)
    string test_board_5[] = {"OXXO",
        "O---",
        "--X-",
        "OXXO"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_duplicates(board, size_5) << endl;
    
    // test case 6, should return true (1)
    string test_board_6[] = {"-XX-",
        "O---",
        "-XX-",
        "OXXO"};
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << board_has_no_duplicates(board, size_6) << endl;
    
    // test case 7, should return true (1)
    string test_board_7[] = {"XOX---",
        "------",
        "------",
        "XOX---",
        "------",
        "---XOX"};
    int size_7 = 6;
    read_board_from_string(board, test_board_7, size_7);
    cout << board_has_no_duplicates(board, size_7) << endl;
    
    // test case 8, should return true (1)
    string test_board_8[] = {"------",
        "------",
        "------",
        "------",
        "------",
        "------"};
    int size_8 = 6;
    read_board_from_string(board, test_board_8, size_8);
    cout << board_has_no_duplicates(board, size_8) << endl;
    
    // test case 9, should return true (1)
    string test_board_9[] = {"------",
        "------",
        "-----X",
        "O----O",
        "------",
        "-X----"};
    int size_9 = 6;
    read_board_from_string(board, test_board_9, size_9);
    cout << board_has_no_duplicates(board, size_9) << endl;
    
    // test case 10, should return true (1)
    string test_board_10[] = {"--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------"};
    int size_10 = 8;
    read_board_from_string(board, test_board_10, size_10);
    cout << board_has_no_duplicates(board, size_10) << endl;
    
    // test case 11, should return true (1)
    string test_board_11[] = {"--------",
        "----XO--",
        "----XO--",
        "--------",
        "X-------",
        "------O-",
        "--------",
        "XO------"};
    int size_11 = 8;
    read_board_from_string(board, test_board_11, size_11);
    cout << board_has_no_duplicates(board, size_11) << endl;
    
    // test case 12, should return false (0)
    string test_board_12[] = {"XOXOXOXO",
        "XOXOXOXO",
        "O-O-----",
        "O-O-----",
        "X-X-----",
        "O-O---O-",
        "X-X-----",
        "O-O-----"};
    int size_12 = 4;
    read_board_from_string(board, test_board_12, size_12);
    cout << board_has_no_duplicates(board, size_12) << endl;
    
    // test case 13
    string test_board_13[] = {"-X--",
        "----",
        "----",
        "---O"};
    int size_13 = 4;
    read_board_from_string(board, test_board_13, size_13);
    cout << board_has_no_duplicates(board, size_13) << endl;
    
    
}
void test_solve_three_in_a_row(){
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing solve three in a row: " << endl;
    
    // test case 1
    string test_board_1[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, 1, true);
    
    /*
     *                     ----              ----
     *                     XX--   becomes    XXO-
     *                     -XX-              -XX-
     *                     --X-              --X-
     */
    // test case 2
    string test_board_2[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, 2, true);
    
    
    /*
     *                     ----              ----
     *                     XX--   becomes    XX--
     *                     -XX-              OXXO
     *                     --X-              --X-
     */
    
    
    // test case 3
    string test_board_3[] = {"----",
        "XX--",
        "-XX-",
        "-OO-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, 3, true);
    
    // test case 4
    string test_board_4[] = {"----",
        "XX--",
        "-XX-",
        "-OOO"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_row(board, size_4, 3, true);
    
    // test case 5
    string test_board_5[] = {"------",
        "------",
        "------",
        "------",
        "------",
        "X-X---"};
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_row(board, size_5, 5, true);
    
    // test case 6
    string test_board_6[] = {"------",
        "------",
        "------",
        "------",
        "----OO",
        "X-X---"};
    int size_6 = 6;
    read_board_from_string(board, test_board_6, size_6);
    solve_three_in_a_row(board, size_6, 4, true);
    
    // test case 7
    string test_board_7[] = {"------",
        "------",
        "-O-O--",
        "------",
        "----OO",
        "X-X---"};
    int size_7 = 6;
    read_board_from_string(board, test_board_7, size_7);
    solve_three_in_a_row(board, size_7, 2, true);
    
    // test case 8
    string test_board_8[] = {"X-X-X-",
        "------",
        "-O-O--",
        "------",
        "----OO",
        "X-X---"};
    int size_8 = 6;
    read_board_from_string(board, test_board_8, size_8);
    solve_three_in_a_row(board, size_8, 0, true);
    
    // test case 9
    cout << "Test case 9" << endl;
    
    string test_board_9[] = {"O-OX",
        "-OO-",
        "-OX-",
        "----"};
    int size_9 = 4;
    read_board_from_string(board, test_board_9, size_9);
    solve_three_in_a_row(board, size_9, 0, true);
    
    
    
}
void test_solve_three_in_a_column(){
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing solve three in a column: " << endl;
    
    // test case 1
    string test_board_1[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, 1, true);
    
    // test case 2
    string test_board_2[] = {"----",
        "X-X-",
        "----",
        "--X-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, 2, true);
    
    /*           Example: if col == 1
     *                     ----              -O--
     *                     XX--   becomes    XX--
     *                     -XX-              -XX-
     *                     --X-              -OX-
     *
     *           Example: if col == 2
     *                     ----              ----
     *                     X-X-   becomes    X-X-
     *                     ----              --O-
     *                     --X-              --X-
     */
    
    // test case 3
    string test_board_3[] = {"----",
        "X-X-",
        "----",
        "--X-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board, size_3, 2, true);
    
    // test case 4
    string test_board_4[] = {"-----X",
        "------",
        "-----X",
        "-----X",
        "------",
        "------"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_column(board, size_4, 5, true);
    
    // test case 5
    string test_board_5[] = {"-----X",
        "--O---",
        "-----X",
        "--X--X",
        "--X---",
        "------"};
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_column(board, size_5, 2, true);
    
    
    
}
void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing solve balance row: " << endl;
    
    // test case 1
    string test_board_1[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, 1, true);
    /**
     *
     *           Example: if row == 1
     *                     ----              ----
     *                     XX--   becomes    XXOO
     *                     -XX-              -XX-
     *                     --X-              --X-
     */
    
    // test case 2
    string test_board_2[] = {"O---",
        "XX--",
        "-XX-",
        "O-X-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, 0, true);
    
    // test case 3
    string test_board_3[] = {"O--X",
        "XX-X",
        "-XX-",
        "O-X-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, 3, true);
    /**
     
     *           Example: if row == 2
     *                     ----              ----
     *                     XX--   becomes    XX--
     *                     -XX-              OXXO
     *                     --X-              --X-
     */
    
    // test case 4
    string test_board_4[] = {"O--X",
        "XX--",
        "-XX-",
        "O-X-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board, size_4, 2, true);
    
    // test case 5
    string test_board_5[] = {"O--X",
        "XX--",
        "-XX-",
        "O--O"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_row(board, size_5, 3, true);
    
    // test case 6
    string test_board_6[] = {"------",
        "------",
        "------",
        "------",
        "------",
        "XX-X--"};
    int size_6 = 6;
    read_board_from_string(board, test_board_6, size_6);
    solve_balance_row(board, size_6, 5, true);
    
    // test case 7
    string test_board_7[] = {"------",
        "------",
        "------",
        "------",
        "O--OO-",
        "XX-X--"};
    int size_7 = 6;
    read_board_from_string(board, test_board_7, size_7);
    solve_balance_row(board, size_7, 4, true);
    
    // test case 8
    string test_board_8[] = {"--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "X--XX--X"};
    int size_8 = 8;
    read_board_from_string(board, test_board_8, size_8);
    solve_balance_row(board, size_8, 7, true);
    
    // test case 9
    string test_board_9[] = {"--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "--------",
        "O-O--O-O",
        "X--XX--X"};
    int size_9 = 8;
    read_board_from_string(board, test_board_9, size_9);
    solve_balance_row(board, size_9, 6, true);
    
    
    
}
void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing solve balance column: " << endl;
    
    // test case 1
    string test_board_1[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, 1, true);
    /**
     *
     *           Example: if col == 1
     *                     ----              -O--
     *                     XX--   becomes    XX--
     *                     -XX-              -XX-
     *                     --X-              -OX-
     */
    // test case 2
    string test_board_2[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_column(board, size_2, 2, true);
    
    
    /**
     *
     *           Example: if col == 2
     *                     ----              --O-
     *                     XX--   becomes    XXO-
     *                     -XX-              -XX-
     *                     --X-              --X-
     * Note    : You MUST use mark_square_as() to assign a color to a square.
     *           It will take care of printing out the appropriate message.
     * Used In : solve()
     */
    
}
void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing board is solved: " << endl;
    
    // test case 1, should return false (0)
    string test_board_1[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    board_is_solved(board, size_1);
    // bool check_valid_input(int size, int row_input, char col_input,
    // char color_char, int &row, int &col);
    
}
void test_check_valid_input() {
    int board[MAX_SIZE][MAX_SIZE];
    int r = 0;
    int c = 0;
    cout << "Testing valid input: " << endl;
    
    // test case 1, should return true (1)
    string test_board_1[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_1 = 4;
    print_board(board, 4);
    read_board_from_string(board, test_board_1, size_1);
    
    
    // int size, int row input (user picks which row), char col_input (which
    // column ('A', 'b' 'c' 'd'...), int &row (checks row in the board to see
    // if the input was valid), int &col)
    cout << check_valid_input(4, 1,'F', RED_LETTER, r, c) << endl;
    
    
    // test case 2, should return false (0)
    string test_board_2[] = {"----",
        "XX--",
        "-XX-",
        "--X-"};
    int size_2 = 4;
    print_board(board, 4);
    read_board_from_string(board, test_board_2, size_2);
    
    cout << check_valid_input(4, 1,'f', RED_LETTER, r, c) << endl;
    
    
    
    
}

void test_check_valid_move() {
    int original_board[MAX_SIZE][MAX_SIZE];
    int current_board[MAX_SIZE][MAX_SIZE];
    
    
    //test case 1, Should return false (0)
    string original_board_1[] = {"----",
        "XXO-",
        "-XO-",
        "--X-"};
    
    string current_board_1[] = {"---X",
        "XXOO",
        "XXO-",
        "--X-"};
    int size_1 = 4;
    read_board_from_string(original_board, original_board_1,size_1);
    read_board_from_string(current_board, current_board_1, size_1);
    check_valid_move(original_board, current_board,
                     4, 3, 2, 2);
    
    // bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
    // const int current_board[MAX_SIZE][MAX_SIZE],
    //int size, int row, int col, int color);
    /**
     * Requires: size <= MAX_SIZE and size is a positive even integer,
     *           0 <= row && row < size && 0 <= col && col < size.
     * Modifies: cout
     * Effects : Returns true if and only if the specified square was not
     *           set in the original board, and placing the given color in
     *           the given square of the current board does not create an
     *           invalid board. Prints messages informing the user that
     *           original squares cannot be changed if appropriate. If
     *           that doesn't apply, prints out that a move violates a
     *           rule if appropriate.
     *
     *           Example:  original  current
     *                       ----     ---X
     *                       XXO-     XXOO
     *                       -XO-     XXO-
     *                       --X-     --X-
     *
     *                     row, col, color: 3, 2, BLUE
     *                     Prints "Sorry, original squares...", returns false.
     *
     *                     row, col, color: 2, 3, BLUE
     *                     Prints "Sorry, that move violates...", returns false.
     *
     *                     row, col, color: 0, 0, BLUE
     *                     Returns true.
     *
     *                     row, col, color: 1, 3, UNKNOWN
     *                     Returns true.
     *
     *                     row, col, color: 0, 3, BLUE
     *                     Returns true.
     * Used In : make_move()
     * Note    : The following messages are printed as appropriate:
     *           "Sorry, original squares cannot be changed."
     *           "Sorry, that move violates a rule."
     */
}

