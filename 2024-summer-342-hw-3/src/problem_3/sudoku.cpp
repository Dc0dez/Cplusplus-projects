#include "sudoku.h"

// I used the following video for reference: https://www.youtube.com/watch?v=FWAIf_EVUKE&ab_channel=takeUforward

Sudoku::~Sudoku() {
    delete[] challenge;
}

bool Sudoku::solve() {
    return solve(0,0);
}

bool Sudoku::solve(size_t row, size_t col) {
    for (row = 0; row < SUDOKU_BOARD_SIZE; ++row) { // traverses each matrix row
        for (col = 0; col < SUDOKU_BOARD_SIZE; ++col) { // traverses each matrix column
            if (*challenge_board(row, col) == 0) { // checks if the current cell has a value set to 0
                for (int i = 1; i <= 9; ++i) { // loops through 1 to 9
                    if (is_valid(row, col, i)) { // on each iteration, checks if placing i in the current cell is valid
                        *challenge_board(row, col) = i; // sets the current cell in the matrix to i
                        if (solve()) { // recursively calls 'solve' to solve the puzzle
                            return true; // if recursion solves the puzzle, return true
                        } else { // if solve returns false, backtracks
                            *challenge_board(row, col) = 0; // resets the current cell to 0
                        }
                    }
                }
                return false; // returns false if no valid entries can be found for the current cell and triggers backtracking
            }
        }
    }
    return true; // if no more cells in the matrix can be filled, returns true since puzzle is solved
}

bool Sudoku::is_valid(size_t row, size_t col, int num ) {
    // Loops through the array
    for (int i = 0; i < SUDOKU_BOARD_SIZE; ++i) {
        if (*challenge_board(i, col) == num || *challenge_board(row,i) == num) { // checks if the value 'num' is present in the row or column
            return false; // returns false if the value is found in the row or column
        }

        /*
         * I got help from GPT with this part
         * My original implementation was similar, but it did not work with *challenge board
         */

        size_t sub_grid_row = 3 * (row / 3) + i / 3; // calculates the row index within sub-matrix
        size_t sub_grid_col = 3 * (col / 3) + i % 3; // calculates the column index within the sub-matrix

        if (*challenge_board(sub_grid_row, sub_grid_col) == num) { // checks if the value 'num' is present inside the sub-matrix
            return false; // returns false if the value is found in the sub-matrix
        }
    }
    return true; // returns true if the value is valid and not found within the current row, column, or sub-matrix
}

