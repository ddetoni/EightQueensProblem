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
    vector<int>board = {pos,0,0,0,0,0,0,0};
    ChessBoard cb (board, 0);

    ChessBoard cb2 = cb.best_neighbor();

    cout << endl;
    cb2.print_board();
    cout << endl;

    cb = cb2.best_neighbor();

    cout << endl;
    cb.print_board();
    cout << endl;

    cb2 = cb.best_neighbor();

    cout << endl;
    cb2.print_board();

<<<<<<< HEAD
	Solver solv;
	solv.HillClimbing(&cb);
=======
>>>>>>> 024910996d8049012b9a5c1e64797ccbf89796b3
    return 0;
}
