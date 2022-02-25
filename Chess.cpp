#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"


void instructions() {
    std::cout << "welcome";
    // how to use A2
    // how to exit
}


void take_input(Board *board, std::vector<Piece*> pieces, bool &exit) {
    
    std::cout << "Please select a square to move from (ex. \"A2\"): ";
    
    std::string input_old;
    std::cin >> input_old;

    if (input_old == "exit") {
        std::cout << "The game has ended" << std::endl;
        exit = 1;
        return;
    }

    //verify input is capital letter

    // Converts inputs to rows and columns
    int col_old = int(input_old[0]) - 64;
    int row_old = int(input_old[1]) - 48;

    int idx_old = (9 - row_old) * 11 + col_old + 1;

    std::cout << "Please select a square to move to: ";

    std::string input_new;
    std::cin >> input_new;

    if (input_new == "exit") {
        std::cout << "The game has ended" << std::endl;
        exit = 1;
        return;
    }

    int piece_idx = -1;
    // find piece at idx_old
    for (int i = 0; i < pieces.size(); ++i) {
        if (pieces[i]->get_index() == idx_old) {
            piece_idx = i;
            break;
        }
    }
    
    // Recursion if input is invalid
    if (piece_idx == -1) {
        std::cout << "Please select a square with a piece" << std::endl;
        take_input(board, pieces, exit);
    }
    
    int col_new = int(input_new[0]) - 64;
    int row_new = int(input_new[1]) - 48;
    int idx_new = (9 - row_new) * 11 + col_new + 1;

    pieces[piece_idx]->move(board, idx_new);

    board->print_board();

    if (pieces[piece_idx]->is_white()) {
        std::cout << "White ";
    }
    else std::cout << "Black ";

    std::cout << pieces[piece_idx]->get_name() << " moved from " << 
                input_old << " to " << input_new << std::endl;
}



// Driver Code
int main() {

    Board *b = new Board();

    Pawn *wp1 = new Pawn(79,1);
    Pawn *wp2 = new Pawn(80,1);
    Pawn *wp3 = new Pawn(81,1);
    Pawn *wp4 = new Pawn(82,1);
    Pawn *wp5 = new Pawn(83,1);
    Pawn *wp6 = new Pawn(84,1);
    Pawn *wp7 = new Pawn(85,1);
    Pawn *wp8 = new Pawn(86,1);
    Rook *wr1 = new Rook(90,1);
    Rook *wr2 = new Rook(97,1);
    Knight *wn1 = new Knight(91,1);
    Knight *wn2 = new Knight(96,1);
    Bishop *wb1 = new Bishop(92,1);
    Bishop *wb2 = new Bishop(95,1);
    Queen *wq = new Queen(93,1);
    King *wk = new King(94,1);

    Pawn *bp1 = new Pawn(24);
    Pawn *bp2 = new Pawn(25);
    Pawn *bp3 = new Pawn(26);
    Pawn *bp4 = new Pawn(27);
    Pawn *bp5 = new Pawn(28);
    Pawn *bp6 = new Pawn(29);
    Pawn *bp7 = new Pawn(30);
    Pawn *bp8 = new Pawn(31);
    Rook *br1 = new Rook(13);
    Rook *br2 = new Rook(20);
    Knight *bn1 = new Knight(14);
    Knight *bn2 = new Knight(19);
    Bishop *bb1 = new Bishop(15);
    Bishop *bb2 = new Bishop(18);
    Queen *bq = new Queen(16);
    King *bk = new King(17);

    b->piece_board_init(wp1);
    b->piece_board_init(wp2);
    b->piece_board_init(wp3);
    b->piece_board_init(wp4);
    b->piece_board_init(wp5);
    b->piece_board_init(wp6);
    b->piece_board_init(wp7);
    b->piece_board_init(wp8);
    b->piece_board_init(wr1);
    b->piece_board_init(wr2);
    b->piece_board_init(wn1);
    b->piece_board_init(wn2);
    b->piece_board_init(wb1);
    b->piece_board_init(wb2);
    b->piece_board_init(wq);
    b->piece_board_init(wk);

    b->piece_board_init(bp1);
    b->piece_board_init(bp2);
    b->piece_board_init(bp3);
    b->piece_board_init(bp4);
    b->piece_board_init(bp5);
    b->piece_board_init(bp6);
    b->piece_board_init(bp7);
    b->piece_board_init(bp8);
    b->piece_board_init(br1);
    b->piece_board_init(br2);
    b->piece_board_init(bn1);
    b->piece_board_init(bn2);
    b->piece_board_init(bb1);
    b->piece_board_init(bb2);
    b->piece_board_init(bq);
    b->piece_board_init(bk);

    b->print_board();

    std::vector<Piece*> pieces = {wp1,wp2,wp3,wp4,wp5,wp6,wp7,wp8,wr1,wr2,wn1,wn2,wb1,
            wb2,wq,wk,bp1,bp2,bp3,bp4,bp5,bp6,bp7,bp8,br1,br2,bn1,bn2,bb1,bb2,bq,bk};

    bool exit = 0;

    while (exit == 0) {
        take_input(b, pieces, exit);
    }

    //implement piece capture and remove from vector when captured
}