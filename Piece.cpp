#include <iostream>
#include <string>
#include <cassert>
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


// Constructor to initialize pawn
Pawn::Pawn(int idx_in, bool w) : Piece(WHITE "Pawn", WHITE "P", idx_in, 1) {}

Pawn::Pawn(int idx_in) : Piece(WHITE "Pawn", CYAN "P", idx_in, 0) {}

void Pawn::move(Board *board, int new_idx) {

    int old_idx = get_index();
    set_index(new_idx);

    board->move_piece(old_idx, new_idx, get_abvr_name());
}

// Constructor to initialize rook
Rook::Rook(int idx_in, bool w) : Piece(WHITE "Rook", WHITE "R", idx_in, 1) {}

Rook::Rook(int idx_in) : Piece(WHITE "Rook", CYAN "R", idx_in, 0) {}

void Rook::move(Board *board, int new_idx) {

    // assert that it only moves in a straight line
    int old_row = get_row();
    int old_col = get_col();
    int old_idx = get_index();
    set_index(new_idx);
    int new_row = get_row();
    int new_col = get_col();

    // Checks if the move is valid
    assert(old_row == new_row || old_col == new_col);

    board->move_piece(old_idx, new_idx, get_abvr_name());
}

// Constructor to initialize knight
Knight::Knight(int idx_in, bool w) : Piece(WHITE "Knight", WHITE "N", idx_in, 1) {}

Knight::Knight(int idx_in) : Piece(WHITE "Knight", CYAN "N", idx_in, 0) {}

void Knight::move(Board *board, int new_idx) {

    int old_idx = get_index();
    set_index(new_idx);

    board->move_piece(old_idx, new_idx, get_abvr_name());
}

// Constructor to initialize bishop
Bishop::Bishop(int idx_in, bool w) : Piece(WHITE "Bishop", WHITE "B", idx_in, 1) {}

Bishop::Bishop(int idx_in) : Piece(WHITE "Bishop", CYAN "B", idx_in, 0) {}

void Bishop::move(Board *board, int new_idx) {

    int old_idx = get_index();
    set_index(new_idx);

    board->move_piece(old_idx, new_idx, get_abvr_name());
}

// Constructor to initialize queen
Queen::Queen(int idx_in, bool w) : Piece(WHITE "Queen", WHITE "Q", idx_in, 1) {}

Queen::Queen(int idx_in) : Piece(WHITE "Queen", CYAN "Q", idx_in, 0) {}

void Queen::move(Board *board, int new_idx) {

    int old_idx = get_index();
    set_index(new_idx);

    board->move_piece(old_idx, new_idx, get_abvr_name());
}

// Constructor to initialize king
King::King(int idx_in, bool w) : Piece(WHITE "King", WHITE "K", idx_in, 1) {}

King::King(int idx_in) : Piece(WHITE "King", CYAN "K", idx_in, 0) {}

void King::move(Board *board, int new_idx) {

    int old_idx = get_index();
    set_index(new_idx);

    board->move_piece(old_idx, new_idx, get_abvr_name());
}