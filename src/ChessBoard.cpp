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
    int get_level();
    void print_board();
    ChessBoard best_neighbor();
    vector<ChessBoard> get_neighbors();
};

ChessBoard::ChessBoard(int *board, int level) {
    this->board = board;
    this->level = level;
}

void ChessBoard::print_board() {
    for(int i=0; i<8; i++){
        cout << this->board[i] << " ";
    }
    cout << endl;
}


vector<ChessBoard> ChessBoard::get_neighbors() {

    vector<ChessBoard> list_board;
    int *aux_board;

    for(int i=0; i < 8; i++) {
        aux_board = this->board;
        aux_board[this->level+1] = i;

        ChessBoard cb (aux_board, this->level+1);
        list_board.push_back(cb);
    }

    return list_board;
}

int ChessBoard::get_level(){

    return this->level;
}
