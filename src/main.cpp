#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

#include "ChessBoard.cpp"
#include "Solver.cpp"


using namespace std;

int main(int argc, char** argv) {

    srand (time(NULL));

<<<<<<< HEAD
    int pos = rand()%8+1;
    vector<int>board = {pos,0,0,0,0,0,0,0};
=======
    int pos = rand()%8;
    vector<int> board(8);
    board[0] = pos;
>>>>>>> 5d89b867ede29fcfc422b75785f1c7dd5056f597
    vector<ChessBoard> list_cb;

    ChessBoard cb (board, 0);

    list_cb = cb.get_neighbors();
    list_cb = list_cb[0].get_neighbors();
    list_cb = list_cb[3].get_neighbors();
    list_cb = list_cb[5].get_neighbors();
    list_cb = list_cb[1].get_neighbors();
    list_cb = list_cb[4].get_neighbors();
    list_cb = list_cb[7].get_neighbors();

    for(int i=0; i<8; i++){
        list_cb.at(i).print_board();
        //cout << list_cb[i].get_level() << endl;
    }

    cout << endl;

    for(int i=0; i<8; i++){
        cout << list_cb.at(i).num_attack() << endl;
    }

	//Solver solv;
	//solv.HillClimbing(&cb);
    return 0;
}
