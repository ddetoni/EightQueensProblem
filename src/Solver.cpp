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
	//teste inicial, a primeira coluna tera a primeira rainha
	//pos indica a coluna que ela esta
	vector<int> aux_board = {pos,0,0,0,0,0,0,0};
	int level = 1;
	//criado novo chessboard, com o seu estado e level
	ChessBoard next(aux_board, level);
	//print para teste
	next.print_board();
	int currentNumAttack = 2;
	while(1==1){
		//next recebe resultado da funcao que retorna o next a ser avaliado
		next = RetornandoPTeste();
		
		
		//next.print_board();
		
		int nextNumAttack = 3;
		
		
		if(nextNumAttack < currentNumAttack){
			cout << "achou ao menos um maximo local"<<endl;
			break;
			}
		cout << "passou";
		*current = next;
		currentNumAttack = 4; //para nao ficar no loop infinito
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
	




