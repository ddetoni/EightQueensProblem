#include <cstdlib>
#include <iostream>

using namespace std;

class ChessBoard {
private:
    int *board;

public:
    ChessBoard(int *board);
    void print_board_row(int i);
};

ChessBoard::ChessBoard(int *board) {
    this->board = board;
}

void ChessBoard::print_board_row(int i) {
    cout << this->board[i] << endl;
}
