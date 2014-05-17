#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class ChessBoard {
private:
    vector<int>board;
    int level;
    int total_attack;

public:
    ChessBoard(vector<int>board, int level);
    int get_total_attack();
    int get_level();
    void print_board();
    ChessBoard best_neighbor();
    vector<ChessBoard> get_neighbors();
    int num_attack();
};

ChessBoard::ChessBoard(vector<int>board, int level) {
    this->board = board;
    this->level = level;
    this->total_attack = 0;
}


int ChessBoard::get_level(){

    return this->level;
}

void ChessBoard::print_board() {
    cout << " ___ ___ ___ ___ ___ ___ ___ ___" << endl;
    for(int i=1; i<9; i++){
        for(int j=0; j<8; j++){
            if(this->board[j] == i) cout << "|_0_";
            else cout << "|___";
        }
        cout << "|" << endl;
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
        //cb.print_board();
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
        neighbors[i].total_attack = aux_attack;

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

int ChessBoard::get_total_attack() {
    return this->total_attack;
}
