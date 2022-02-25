#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
class Piece;
/* Board.h
 *
 * Represents the board
 *
 * by Jake Block
 * block@umich.edu
 * 2022-2-24
 */

// will print out the board, with border and row/col numbers and pieces
// takes in array of current pieces on board. if array position is empty, print a black or white square
// if not empty, prints out the piece

#define WHITE "\x1b[38;5;15m"
#define BLACK "\x1b[30m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

class Board {
private:

    // Number of pieces/headers on board
    std::vector<std::string> board;

public:

    // Initializes board
    Board();

    // Prints the board to terminal
    void print_board() const;

    void piece_board_init(const Piece *piece);

    void move_piece(int old_idx, int new_idx, const std::string &abvr_name);


    virtual ~Board() {}
};

//std::vector<std::string> plain_board_init();

#endif