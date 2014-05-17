#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

#include "ChessBoard.cpp"

using namespace std;

int main(int argc, char** argv) {

    srand (time(NULL));

    int pos = rand()%8;
    vector<int>board = {pos,0,0,0,0,0,0,0};
    vector<ChessBoard> list_cb;

    ChessBoard cb (board, 0);
    list_cb = cb.get_neighbors();

    for(int i=0; i<8; i++){
        list_cb.at(i).print_board();
    }

    return 0;
}
