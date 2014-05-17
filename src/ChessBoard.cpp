#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class ChessBoard {
private:
    vector<int>board;
    int level;

public:
    ChessBoard(vector<int>board, int level);
    int get_level();
    void print_board();
    ChessBoard best_neighbor();
    vector<ChessBoard> get_neighbors();
    int num_attack();
};

ChessBoard::ChessBoard(vector<int>board, int level) {
    this->board = board;
    this->level = level;
}


int ChessBoard::get_level(){

    return this->level;
}

void ChessBoard::print_board() {
    for(int i=0; i<8; i++){
        cout << this->board[i] << " ";
    }
    cout << endl;
}

vector<ChessBoard> ChessBoard::get_neighbors() {

    vector<ChessBoard> list_board;
    vector<int> aux_board;

    for(int i=1; i < 9; i++) {
        aux_board = this->board;
        aux_board[this->level+1] = i;

        ChessBoard cb = ChessBoard(aux_board, this->level+1);
        cb.print_board();
        list_board.push_back(cb);

    }

    return list_board;
}

int ChessBoard::num_attack() {
    int count = 0;
    int diag = 1;
    for(int i = this->level-1; i >= 0; i--) {
        if(this->board[this->level] == this->board[i]) count++;
        if(this->board[this->level] == this->board[i]+diag) count++;
        if(this->board[this->level] == this->board[i]-diag) count++;
        diag++;
    }

    return count;
}

ChessBoard ChessBoard::best_neighbor() {
    vector<ChessBoard> neighbors;
    vector<ChessBoard> the_bests;
    int smallest_attack = 10;
    int aux_attack = 0;

    neighbors = this->get_neighbors();

    for(int i=0; i<8; i++) {
        aux_attack = neighbors[i].num_attack();

        if(aux_attack < smallest_attack) smallest_attack = aux_attack;
    }

    for(int i=0; i<8; i++) {

        if(smallest_attack == neighbors[i].num_attack()) the_bests.push_back(neighbors[i]);
    }

    int total_bests = the_bests.size();

    srand (time(NULL));
    int pos = rand()%total_bests;

    return the_bests[pos];
}
