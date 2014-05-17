#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

#include "ChessBoard.cpp"
#include "Solver.cpp"


using namespace std;

int main(int argc, char** argv) {

    srand (time(NULL));

    int pos = rand()%8+1;
    vector<int>board = {7,1,3,8,6,4,2,1};
    ChessBoard cb (board, 7);

    cb.print_board();
    cout << cb.num_attack() << endl;

    //vector<int> teste(64);
    //teste.at(0) = 1;
    //cout << teste[0] << endl;

	//Solver solv;
	//solv.AStar(cb, 8);

    return 0;
}
