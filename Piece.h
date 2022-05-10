#ifndef PIECE_H
#define PIECE_H
#include <string>
class Board;
/* Piece.h
 *
 * Represents a piece in chess
 *
 * by Jake Block
 * block@umich.edu
 * 2022-2-24
 */

class Piece {
private:
    std::string name;
    //abbreviated name, outputted in one char to console
    std::string abrv_name;
    int index;
    // 1 if white, 0 if black
    bool white;
    int row = 0;
    int col = 0;

public:

    // Constructor to initialize piece
    Piece(const std::string &name, const std::string &abrv_name,
            int idx_in, bool white);

    // Returns 1 if piece is white
    bool is_white();

    // Changes name of piece
    void set_name(const std::string &name);

    void set_abvr_name(const std::string &name);

    // Returns the name of the piece
    std::string get_name() const;
    std::string get_abvr_name() const;

    // Returns the current position of the piece as an index of an array.
    int get_index() const;

    // Takes an index and computes the row and column. Used for error checking moves
    int get_temp_row(int idx) const;
    int get_temp_col(int idx) const;

    void set_index(int idx_in);

    // Converts the index to rows and columns, corresponding with the board
    // A = 1, H = 8
    int get_row();
    int get_col();

    // Moves the piece to the specified square. 
    // Validates the input to make sure the move is correct.
    // Calculate new index before moving.
    virtual bool move(Board *board, int new_idx) = 0;

    // Verifies input is within the 8x8 chess board
    bool in_board(int row, int col) const;

// vector<int> possible_moves const = 0;
// calculates a vector of whatever moves are possible for each piece. must take into account
// if it is hitting another piece
// can be used to determine check

    // Needed to avoid some compiler errors
    virtual ~Piece() {}
};

class Pawn : public Piece {
public:

    // Constructor to initialize pawn. If 2 args, make it white
    Pawn(int idx_in, bool w);

    // Constructor to initialize pawn. If 1 arg, make it black (yellow)
    Pawn(int idx_in);

    // Moves piece to desired index and updates board
    bool move(Board *board, int new_idx) override;
};

class Rook : public Piece {
public:

    // Constructor to initialize pawn. If 2 args, make it white
    Rook(int idx_in, bool w);

    // Constructor to initialize pawn. If 1 arg, make it black (yellow)
    Rook(int idx_in);

    // Moves piece to desired index and updates board
    bool move(Board *board, int new_idx) override;
};

class Knight : public Piece {
public:

    // Constructor to initialize pawn. If 2 args, make it white
    Knight(int idx_in, bool w);

    // Constructor to initialize pawn. If 1 arg, make it black (yellow)
    Knight(int idx_in);

    // Moves piece to desired index and updates board
    bool move(Board *board, int new_idx) override;
};

class Bishop : public Piece {
public:

    // Constructor to initialize pawn. If 2 args, make it white
    Bishop(int idx_in, bool w);

    // Constructor to initialize pawn. If 1 arg, make it black (yellow)
    Bishop(int idx_in);

    // Moves piece to desired index and updates board
    bool move(Board *board, int new_idx) override;
};

class Queen : public Piece {
public:

    // Constructor to initialize pawn. If 2 args, make it white
    Queen(int idx_in, bool w);

    // Constructor to initialize pawn. If 1 arg, make it black (yellow)
    Queen(int idx_in);

    // Moves piece to desired index and updates board
    bool move(Board *board, int new_idx) override;
};

class King : public Piece {
public:

    // Constructor to initialize pawn. If 2 args, make it white
    King(int idx_in, bool w);

    // Constructor to initialize pawn. If 1 arg, make it black (yellow)
    King(int idx_in);

    // Moves piece to desired index and updates board
    bool move(Board *board, int new_idx) override;
};


#endif