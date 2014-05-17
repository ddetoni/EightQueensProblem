#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class ChessBoard {
private:
    int *board;
    int level;

public:
    ChessBoard(int *board, int level);
    ~ChessBoard();
    int get_level();
    void print_board_row(int i);
    ChessBoard best_neighbor();
    std::vector<ChessBoard> get_neighbors();
};

ChessBoard::ChessBoard(int *board, int level) {
    this->board = board;
    this->level = level;
}

ChessBoard::~ChessBoard(){
    delete this;
}

void ChessBoard::print_board_row(int i) {
    cout << this->board[i] << endl;
}

/*
std::vector<ChessBoard> ChessBoard::get_neighbors() {

    std::vector<ChessBoard*> list_board;
    int *aux_board;

    for(int i=0; i < 8; i++) {
        aux_board = this->board;
        aux_board[this->level+1] = i;

        ChessBoard cb (aux_board, this->level+1);
        list_board.push_back(cb);
    }

    return &list_board;
}
*/
int ChessBoard::get_level(){

    return this->level;
}
