#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"


class Game {
private:
    Board *board;
    std::vector<Piece*> pieces;
    bool exit = 0;
    int counter = 1;
    std::string input_old;
    int idx_old;
    int idx_moving;
    int idx_new;
    std::string input_new;

public:

    Game() : board(board_init(piece_init())), pieces(piece_init()) {}


    std::vector<Piece*> piece_init() {
        
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

        std::vector<Piece*> pieces = {wp1,wp2,wp3,wp4,wp5,wp6,wp7,wp8,wr1,wr2,wn1,wn2,wb1,
            wb2,wq,wk,bp1,bp2,bp3,bp4,bp5,bp6,bp7,bp8,br1,br2,bn1,bn2,bb1,bb2,bq,bk};

        return pieces;
    }

    Board *board_init(const std::vector<Piece*> &pieces) {
        Board *board = new Board();

        for (int i = 0; i < 32; ++i) {
            board->piece_board_init(pieces[i]);
        }

        return board;
    }

    void print_board() {

        // If white's turn, print normal. If black's, flip it
        if (counter % 2 == 1) {
            board->print_board();
        }
        else board->print_flipped_board();
    }

    bool get_exit() {
        return exit;
    }

    // Takes input of square the user wishes to move from
    void input_from() {
        
        if (counter % 2 == 1) {
            std::cout << "White: Please select a square to move from: ";
        }
        else std::cout << "Black: Please select a square to move from: ";
        
        std::cin >> input_old;

        if (input_old == "exit") {
            std::cout << "The game has ended" << std::endl;
            exit = 1;
            return;
        }

        //verify input is capital letter
        // or can just verify it's capital or lowercase based on the range (64 vs 48) and accept both inputs

        // Converts inputs to rows and columns
        int col_old = int(input_old[0]) - 64;
        int row_old = int(input_old[1]) - 48;

        idx_old = (9 - row_old) * 11 + col_old + 1;

        verify_input_from();
    }

    void set_idx_moving(int idx) {
        idx_moving = idx;
    }

    // Checks if there is a) a piece and b) the right color on the selected square
    void verify_input_from() {

        int idx_moving = -1;
        // find same color piece at idx_old
        for (int i = 0; i < pieces.size(); ++i) {
            if (pieces[i]->get_index() == idx_old && pieces[i]->is_white() == counter % 2) {
                idx_moving = i;
                break;
            }
        }
        
        // If input is invalid, restarts loop
        if (idx_moving == -1) {
            std::cout << "Please select a square with a ";
            if (counter % 2 == 1) {
                std::cout << "white ";
            }
            else std::cout <<"black ";
            std::cout << "piece" << std::endl;
            return;
        }
        //WHY MUST I DO THIS? OTHERWISE IT DOES NOT UPDATE OUTSIDE THE FUNCTION FOR SOME REASON. WEIRD
        set_idx_moving(idx_moving);
        input_to();
    }

    void input_to() {

        std::cout << "Please select a square to move to: ";

        std::cin >> input_new;

        if (input_new == "exit") {
            std::cout << "The game has ended" << std::endl;
            exit = 1;
            return;
        }
        
        int col_new = int(input_new[0]) - 64;
        int row_new = int(input_new[1]) - 48;
        idx_new = (9 - row_new) * 11 + col_new + 1;

        verify_input_to();
    }

    void verify_input_to() {
        if (hits_own_piece()) {
            std::cout << "Invalid move. Try again" << std::endl;
            return;
        }

        // implement some capture system, moving through other pieces

        // Checks if move is in board and is a valid move for the piece.
        if (!pieces[idx_moving]->move(board, idx_new)) {
            std::cout << "Invalid move. Try again" << std::endl;
            return;
        }

        // Flips board, undoes counter to print correct black/white, advances counter
        ++counter;
        print_board();
        --counter;
        move_describe();
        ++counter;
    }

    // Returns true if a piece lands on top of a piece of the same color. Error
    bool hits_own_piece() {

        for (size_t i = 0; i < pieces.size(); ++i) {
            if (pieces[i]->get_index() == idx_new &&
                pieces[idx_moving]->is_white() == pieces[i]->is_white()) {
                    return 1;
                }
        }
        return 0;
    }

    void move_describe() {

        if (pieces[idx_moving]->is_white()) {
            std::cout << "White ";
        }
        else std::cout << "Black ";

        std::cout << pieces[idx_moving]->get_name() << " moved from " << 
                    input_old << " to " << input_new << std::endl;

        capture();
    }


    // Returns true if capturing a piece. Also removes that piece from the vector
    bool capture() {

        for (int i = 0; i < pieces.size(); ++i) {
            if (pieces[i]->get_index() == idx_new && 
                pieces[idx_moving]->is_white() != pieces[i]->is_white()) {
                    
                if (pieces[i]->is_white()) {
                    std::cout << "White ";
                }
                else std::cout << "Black ";

                std::cout << pieces[i]->get_name() << " captured by ";

                if (pieces[idx_moving]->is_white()) {
                    std::cout << "White " << pieces[idx_moving]->get_name() << std::endl;
                }
                else std::cout << "Black " << pieces[idx_moving]->get_name() << std::endl;
                
                pieces.erase(pieces.begin() + i);          
                return 1;
            }
        }
        return 0;
    }


    // Possibly use destructor?
    void delete_game() {
        for (int i = 0; i < 32; ++i) {
            delete pieces[i];
        }
        delete board;
    }

};



void instructions() {
    std::cout << "welcome";
    // how to use A2
    // how to exit
}




// Driver Code
int main() {

    Game game;

    game.print_board();

    while (game.get_exit() == 0) {
        game.input_from();
    }

    game.delete_game();

    //implement piece capture and remove from vector when captured
}