//Class that solves the n queens problem

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>



using namespace std;

class Solver{
	
	public:
		void HillClimbing(ChessBoard *initial);
		ChessBoard RetornandoPTeste();
		int NextValue();
	};


void Solver::HillClimbing(ChessBoard *current){
	//initial->print_board_row(0);
	//ChessBoard *current = &initial;
	//current->print_board_row(0);
	
	//pos vai receber
	int pos = NextValue(); //para teste
	vector<int> aux_board = {pos,0,0,0,0,0,0,0};
	ChessBoard next(aux_board,1);
	next.print_board();
	while(1==1){
		next = RetornandoPTeste();
		next.print_board();
		//if(next.getNumAttack < current.getNumAttack){
			cout << "print current"<<endl;
			break;
			}
		//point p current recebe next
		}
	
	
		
ChessBoard Solver::RetornandoPTeste(){
	vector<int> board = {6,0,0,0,0,0,0,0}; //para teste
	ChessBoard cb (board, 1);
	return cb;
	
	}
	
	
	
	
int Solver::NextValue(){
	return 4;
	
	}
	




