#include <iostream>
#include <string>
#include <cmath>
#include "Piece.h"
#include "Board.h"


Piece::Piece(const std::string &name, const std::string &abrv_name, int idx_in, bool white)
    : name(name), abrv_name(abrv_name), index(idx_in), white(white) {}

bool Piece::is_white() {
    if (white) {return 1;}
    return 0;
}

void Piece::set_name(const std::string &name_in) {
    name = name_in;
}

void Piece::set_abvr_name(const std::string &abvr_name_in) {
    name = abvr_name_in;
}

std::string Piece::get_name() const {
    return name;
}

std::string Piece::get_abvr_name() const {
    return abrv_name;
}

int Piece::get_index() const {
    return index;
}

int Piece::get_temp_row(int idx) const {
    return 9 - floor(idx/11);
}

int Piece::get_temp_col(int idx) const {
    return (idx % 11) - 1;
}

void Piece::set_index(int idx_in) {
    index = idx_in;
}

int Piece::get_row() {
    row = 9 - floor(index/11);
    return row;
}

int Piece::get_col() {
    col = (index % 11) - 1;
    return col;
}

bool Piece::in_board(int row, int col) const {
    if (row < 1 || row > 8 || col < 1 || col > 8) {
        return 0;
    }
    return 1;
}

// returns if it moves onto its own team's piece. will not allow the move
// bool Piece::hits_own_piece

// Constructor to initialize pawn
Pawn::Pawn(int idx_in, bool w) : Piece(WHITE "Pawn", WHITE "P", idx_in, 1) {}

Pawn::Pawn(int idx_in) : Piece(WHITE "Pawn", RED "P", idx_in, 0) {}

bool Pawn::move(Board *board, int new_idx) {

    // assert that it only moves in a straight line
    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    int new_row = get_temp_row(new_idx);
    int new_col = get_temp_col(new_idx);
    
    if (!in_board(new_row, new_col)) {
        return 0;
    }

    // if it's white and on row 2, it can move 2 forward
    // if it's black and on row 7, it can move 2 forward
    // otherwise, moves only one forward or diagonally

    // need to implement diagonally. if there is a piece in the index, can move diagonally
    // also need to not allow forward moving if an opponent's piece is there
    if (is_white() && old_row == 2) {
        if (new_row - old_row == 2 || new_row - old_row == 1) {
            set_index(new_idx);
            board->move_piece(old_idx, new_idx, get_abvr_name());
            return 1;
        }
    }
    else if (!is_white() && old_row == 7) {
        if (old_row - new_row == 2 || old_row - new_row == 1) {
            set_index(new_idx);
            board->move_piece(old_idx, new_idx, get_abvr_name());
            return 1;
        }
    }
    else if (is_white() && new_col - old_col == 0 && new_row - old_row == 1) {
        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    else if (!is_white() && new_col - old_col == 0 && new_row - old_row == -1) {
        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    return 0;
}

// Constructor to initialize rook
Rook::Rook(int idx_in, bool w) : Piece(WHITE "Rook", WHITE "R", idx_in, 1) {}

Rook::Rook(int idx_in) : Piece(WHITE "Rook", RED "R", idx_in, 0) {}

bool Rook::move(Board *board, int new_idx) {

    // assert that it only moves in a straight line
    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    int new_row = get_temp_row(new_idx);
    int new_col = get_temp_col(new_idx);
    
    if (!in_board(new_row, new_col)) {
        return 0;
    }

    // Checks if rook moves in a straight line
    if (old_row == new_row || old_col == new_col) {

        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    return 0;
}

// Constructor to initialize knight
Knight::Knight(int idx_in, bool w) : Piece(WHITE "Knight", WHITE "N", idx_in, 1) {}

Knight::Knight(int idx_in) : Piece(WHITE "Knight", RED "N", idx_in, 0) {}

bool Knight::move(Board *board, int new_idx) {

    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    int new_row = get_temp_row(new_idx);
    int new_col = get_temp_col(new_idx);
    
    if (!in_board(new_row, new_col)) {
        return 0;
    }

    // 8 possible moves for the knight
    if ((old_row + 2 == new_row && old_col + 1 == new_col) ||
    (old_row + 2 == new_row && old_col - 1 == new_col) ||
    (old_row - 2 == new_row && old_col + 1 == new_col) ||
    (old_row - 2 == new_row && old_col - 1 == new_col) ||
    (old_row + 1 == new_row && old_col + 2 == new_col) ||
    (old_row + 1 == new_row && old_col - 2 == new_col) ||
    (old_row - 1 == new_row && old_col + 2 == new_col) ||
    (old_row - 1 == new_row && old_col - 2 == new_col)) {

        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    return 0;
}

// Constructor to initialize bishop
Bishop::Bishop(int idx_in, bool w) : Piece(WHITE "Bishop", WHITE "B", idx_in, 1) {}

Bishop::Bishop(int idx_in) : Piece(WHITE "Bishop", RED "B", idx_in, 0) {}

bool Bishop::move(Board *board, int new_idx) {

    // assert that it only moves in a straight line diagonally
    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    int new_row = get_temp_row(new_idx);
    int new_col = get_temp_col(new_idx);
    
    if (!in_board(new_row, new_col)) {
        return 0;
    }

    // Checks if the move is valid
    if (abs(new_row - old_row) == abs(new_col - old_col)) {

        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    return 0;
}

// Constructor to initialize queen
Queen::Queen(int idx_in, bool w) : Piece(WHITE "Queen", WHITE "Q", idx_in, 1) {}

Queen::Queen(int idx_in) : Piece(WHITE "Queen", RED "Q", idx_in, 0) {}

bool Queen::move(Board *board, int new_idx) {

    // assert that it only moves in a straight line
    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    int new_row = get_temp_row(new_idx);
    int new_col = get_temp_col(new_idx);
    
    if (!in_board(new_row, new_col)) {
        return 0;
    }

    // Checks if the move is valid
    if (abs(new_row - old_row) == abs(new_col - old_col) ||
        old_row == new_row || old_col == new_col) {

        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    return 0;
}

// Constructor to initialize king
King::King(int idx_in, bool w) : Piece(WHITE "King", WHITE "K", idx_in, 1) {}

King::King(int idx_in) : Piece(WHITE "King", RED "K", idx_in, 0) {}

bool King::move(Board *board, int new_idx) {

    // assert that it only moves one square
    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    int new_row = get_temp_row(new_idx);
    int new_col = get_temp_col(new_idx);
    
    if (!in_board(new_row, new_col)) {
        return 0;
    }

    // Checks if the move is valid
    if ((abs(new_row - old_row) <= 1) && (abs(new_col - old_col) <= 1)) {

        set_index(new_idx);
        board->move_piece(old_idx, new_idx, get_abvr_name());
        return 1;
    }
    return 0;
}