#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "ChessBoard.cpp"
#include "Solver.cpp"


using namespace std;

int main(int argc, char** argv) {

    srand (time(NULL));

    int pos = rand()%8+1;
    vector<int>board = {pos,0,0,0,0,0,0,0};
    ChessBoard cb (board, 0);
    vector<ChessBoard> ret;

    //vector<int> teste(64);
    //teste.at(0) = 1;
    //cout << teste[0] << endl;

	Solver solv;
    ret = solv.AStar(cb, 8);

    cout << ret.size() << endl;
    ret[ret.size()-1].print_board();
    return 0;
}
