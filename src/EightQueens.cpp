#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

class EightQueens {
private:
    int board[8] = {0, 0, 0, 0, 0, 0, 0};

    void print_board(int arg[], int lenght);

public:
    EightQueens();
    void hello();

};

EightQueens::EightQueens() {
    srand (time(NULL));
    int pos = rand() % 8;
    this->board[pos] = 1;
}

void EightQueens::hello(){
    this->print_board(this->board, 8);
}

void EightQueens::print_board(int arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}
