#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "Board.h"
#include "Piece.h"

// Initializes a checkerboard with appropriate letter and number labeling
std::vector<std::string> plain_board_init() {
    
    std::vector<std::string> board;

    int row_counter = 8;

    board.push_back(" ");
    for (int col = 1; col < 11; ++col) {
        board.push_back(BLUE "\u25A0" RESET);
    }

    for (int row = 1; row < 9; ++row) {

        board.push_back(std::to_string(row_counter));
        board.push_back(BLUE "\u25A0");
        if (row % 2 == 1) {
            for (int checker = 0; checker < 4; ++checker) {
                board.push_back(WHITE "\u25A0");
                board.push_back(BLACK "\u25A0");
            }
        }
        else if (row % 2 == 0) {
            for (int checker = 0; checker < 4; ++checker) {
                board.push_back(BLACK "\u25A0");
                board.push_back(WHITE "\u25A0");
            }
        }
        board.push_back(BLUE "\u25A0" RESET);
        --row_counter;
    }

    board.push_back(" ");
    for (int col = 1; col < 11; ++col) {
        board.push_back(BLUE "\u25A0");
    }

    board.push_back(" ");
    board.push_back(" ");
    board.push_back(WHITE "A");
    board.push_back(WHITE "B");
    board.push_back(WHITE "C");
    board.push_back(WHITE "D");
    board.push_back(WHITE "E");
    board.push_back(WHITE "F");
    board.push_back(WHITE "G");
    board.push_back(WHITE "H" RESET);

    return board;
}

// Initializes empty board [later, put pieces in starting config]
Board::Board() : board(plain_board_init()) {}

void Board::print_board() const {

    int index = 0;

    for (int row = 0; row < 11; ++row) {
        for (int col = 0; col < 11; ++col) {
            std::cout << board[index] << " ";
            ++index;
        }
        std::cout << std::endl;
    }
}

// Places piece at its index that was assigned upon creation
void Board::piece_board_init(const Piece *piece) {

    int index = piece->get_index();
    board[index] = piece->get_abvr_name();
}

// Puts name of piece at the new index and changes old index back to a white or black square
void Board::move_piece(int old_idx, int new_idx, const std::string &abvr_name) {
    
    // can assert that new index is not column 0 or -1 or 9, or that row is not 0 or 9

    // columns and rows go from 1 to 8. Line up with markings on board
    int col = (old_idx % 11) - 1;
    int row = 9 - floor(old_idx/11);

    // sets old index to black or white square
    if (row % 2 == 1 && col % 2 == 1) {
        board[old_idx] = BLACK "\u25A0" RESET;
    }
    else if (row % 2 == 0 && col % 2 == 0) {
        board[old_idx] = BLACK "\u25A0" RESET;
    }
    else {
        board[old_idx] = WHITE "\u25A0" RESET;
    }

    board[new_idx] = abvr_name;
}
