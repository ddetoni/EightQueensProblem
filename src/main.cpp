#include <cstdlib>
#include <iostream>
#include <time.h>

#include "ChessBoard.cpp"

using namespace std;

int main(int argc, char** argv) {

    srand (time(NULL));

    int pos = rand()%8;
    int board[8] = {pos,0,0,0,0,0,0,0};
    ChessBoard cb (board);
    cb.print_board_row(0);

    return 0;
}
