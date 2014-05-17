//Class that solves the n queens problem

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>



using namespace std;

class Solver{

	public:
		void HillClimbing(ChessBoard initial);
		void TemperaSimulada(ChessBoard initial);
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
		current = next;
		}
	}


void Solver::TemperaSimulada(ChessBoard current){
	vector<int>board = {0,0,0,0,0,0,0,0};
    ChessBoard next (board, 0);
	srand (time(NULL));

    
	double currentNumAttack ,nextNumAttack = 0;
	double temperature;
	double delta;
	double r;
	//best neighbor in this case should be ramdomly generated
	next = current.best_neighbor();
	
	//double probability;
	//double rand;
	//get total attack = getCost  n rainhas + n ataque / 
	currentNumAttack = current.get_total_attack();
	nextNumAttack = next.get_total_attack();
	//temperature = current;
	delta = nextNumAttack - currentNumAttack;
	current.print_board();
	int aux = rand()%100;
	r = (double)aux/100;
	cout << "r"<<endl;
	cout << r <<endl;
	delta = 1;
	if(delta == 0){
		current = next;
		cout << "delta"<<endl;
		cout << delta<<endl;
		}
	else 
		if(r < 1.0){
			cout << "entrou";
		
		}
	current.print_board();
	
	
	//currentNumAttack = current.get_total_attack();
	//nextNumAttack = next.get_total_attack();

	//cout << currentNumAttack<<endl;
		
	
	//current é o estado corrente
	//hi recebe funcao heuristica
	
	
	
	
	}

ChessBoard Solver::RetornandoPTeste(){
	vector<int> board = {6,0,0,0,0,0,0,0}; //para teste
	ChessBoard cb (board, 1);
	return cb;

	}




int Solver::NextValue(){
	return 4;

	}
