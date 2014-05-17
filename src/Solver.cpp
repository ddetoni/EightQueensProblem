//Class that solves the n queens problem

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>



using namespace std;

class Solver{

	public:
		void HillClimbing(ChessBoard initial);
		ChessBoard RetornandoPTeste();
		int NextValue();
	};


void Solver::HillClimbing(ChessBoard current){

	int currentNumAttack, nextNumAttack = 0;
    vector<int>board = {0,0,0,0,0,0,0,0};
    ChessBoard next (board, 0);

	cout << "print board current"<<endl;
	current.print_board();

	cout << "print board next" << endl;

	while(1){
		next = current.best_neighbor();

		currentNumAttack = current.get_total_attack();
		nextNumAttack = next.get_total_attack();

		cout << "current count" << endl;
		cout << currentNumAttack << endl;
		cout << "next count" << endl;
		cout << nextNumAttack << endl;
		if (nextNumAttack > currentNumAttack){
			current.print_board();
			break;
			}

		//aqui deve ta o erro, atribuir o current pro next
		current = next;
		}
	}


ChessBoard Solver::RetornandoPTeste(){
	vector<int> board = {6,0,0,0,0,0,0,0}; //para teste
	ChessBoard cb (board, 1);
	return cb;

	}




int Solver::NextValue(){
	return 4;

	}
