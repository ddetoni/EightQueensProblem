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

    
//	double currentNumAttack ,nextNumAttack = 0;
	double temperature;
	double delta;
	double r;
	//double goal = 8.0; 
	double value;
	double next_temperature;
	temperature = ((8.0 - current.get_level())*(current.num_attack()+0.1));
	while(temperature > 0){
		
		next = current.random_neighbor();
		next.print_board();
		next_temperature = ((8.0 - next.get_level())*(next.num_attack()+0.1));
		cout << next.num_attack();
		delta = next.num_attack();
		cout << "delta" << endl;
		cout << delta << endl;
		//Se delta == 0, quer dizer que o proximo board continua sem ataque
		if (delta == 0){
			cout << "entrou delta = 0 " <<endl;
			current = next;
			} 
			else
				{ 
				cout << "else" <<endl;
				
				//int aux = rand()%100;
				//r = (double)aux/10;
				if(next_temperature < 4.2){ //trocar teste
					cout << "entrou no if" <<endl;
					cout << temperature << endl;
					current = next;
				}
		}
		temperature = ((8.0 - current.get_level())*(current.num_attack()+0.1));
	}
	current.print_board();
	cout << current.get_level()<< endl;
	cout << current.num_attack() << endl;
	
		
	/*//best neighbor in this case should be ramdomly generated
	next = current.random_neighbor();
	//currentNumAttack = current.get_total_attack();
	//nextNumAttack = next.get_total_attack();
	
	//gera r randomico

	delta = next.get_total_attack() - current.get_total_attack();
		
	if(delta == 0){
		current = next;
		
		}
	else{ 
		int aux = rand()%100;
		r = (double)aux/10;
		if(r < 5.0){ //trocar teste
			//cout << "entrou";
			current = next;
		}
	}
	//current.print_board();
	
	
	//currentNumAttack = current.get_total_attack();
	//nextNumAttack = next.get_total_attack();

	//cout << currentNumAttack<<endl;
		
	
	//current é o estado corrente
	//hi recebe funcao heuristica
	
	
	*/
	
	}

ChessBoard Solver::RetornandoPTeste(){
	vector<int> board = {6,0,0,0,0,0,0,0}; //para teste
	ChessBoard cb (board, 1);
	return cb;

	}




int Solver::NextValue(){
	return 4;

	}
