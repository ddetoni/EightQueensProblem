#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

#include "ChessBoard.cpp"

using namespace std;

int main(int argc, char** argv) {

    srand (time(NULL));

    int pos = rand()%8;
    int board[] = {pos,0,0,0,0,0,0,0};
    vector<ChessBoard> list_cb;

    ChessBoard cb (board, 0);


    cout << "Teste" << endl;
    //list_cb = cb.get_neighbors();

    //list_cb.push_back(cb);

    return 0;
}
