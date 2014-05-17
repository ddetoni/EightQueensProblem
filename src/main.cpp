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
	cb = cb.random_neighbor();
	//cout << "cb random" << endl;
	//cb.print_board();
    ChessBoard cb2 = cb.random_neighbor();
	//cb2.print_board();
/*    cout << endl;
    cb2.print_board();
    cout << endl;

    cb = cb2.best_neighbor();

    cout << endl;
    cb.print_board();
    cout << endl;

    cb2 = cb.best_neighbor();

    cout << endl;
    cb2.print_board();
*/

	//Solver solv;
	//solv.HillClimbing(cb);
	//solv.TemperaSimulada(cb);
    return 0;
}
