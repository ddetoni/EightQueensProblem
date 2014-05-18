//Class that solves the n queens problem

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <time.h>



using namespace std;

class Solver{
	private:
		int heuristic_cost_estimate(ChessBoard cb, int goal);
		int lowest_f_score(vector<ChessBoard> set);
		bool exists(vector<ChessBoard> set, ChessBoard element);

	public:
		vector<ChessBoard> HillClimbing();
		vector<ChessBoard> AStar(ChessBoard initial, int goal);
		void TemperaSimulada(ChessBoard current);
		ChessBoard RetornandoPTeste();
		int NextValue();
	};


vector<ChessBoard> Solver::HillClimbing(){
	srand (time(NULL));

	int pos = rand()%8+1;
	vector<int>board = {pos,0,0,0,0,0,0,0};
	ChessBoard current (board, 0);

	cout << "Hill Climbing - Solving... " << endl;
	cout << "Initial state:" << endl;
	current.print_board();

	vector<ChessBoard> visited_states;
	int currentNumAttack, nextNumAttack = 0;

	while(1){
		ChessBoard next = current.best_neighbor();

		currentNumAttack = current.get_total_attack();
		nextNumAttack = next.get_total_attack();

		if (nextNumAttack == 0 && next.num_queens()==8)
		{
			cout << "\nSolution:" <<endl;
			next.print_board();
			visited_states.push_back(next);

			return visited_states;
		}
		else if(next.get_level() == 7 || nextNumAttack != 0)
		{
			ChessBoard initial (board, 0);
			next = initial;
		}

		visited_states.push_back(next);
		current = next;
	}
}

vector<ChessBoard> Solver::AStar(ChessBoard initial, int goal) {
	cout << "A* - Solving... " << endl;
	cout << "Initial state:" << endl;
	initial.print_board();

	vector<ChessBoard> closedset;
	vector<ChessBoard> openset;

	initial.set_f_score(heuristic_cost_estimate(initial, goal));

	openset.push_back(initial);

	while(!openset.empty()) {
		int current_id = lowest_f_score(openset);
		ChessBoard current = openset.at(current_id);

		if ((current.num_queens() == goal) && (current.num_attack()==0)) {
			cout << "\nSolution:" <<endl;
			current.print_board();
			closedset.push_back(current);
			return closedset;
		}

		openset.erase(openset.begin() + current_id);
		closedset.push_back(current);

		vector<ChessBoard> neighbors = current.get_neighbors();
		for(int i=0; i<neighbors.size(); i++) {
			if(exists(closedset, neighbors[i])) {
				continue;
			}

			if(!exists(openset, neighbors[i]) ){
				neighbors[i].set_f_score(heuristic_cost_estimate(neighbors[i], goal));
				openset.push_back(neighbors[i]);
			}
		}
	}
}

bool Solver::exists(vector<ChessBoard> set, ChessBoard element){
	for(int i=0; i<set.size(); i++){
		if(element.get_board() == set[i].get_board()) return true;
	}
	return false;
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
}

int Solver::heuristic_cost_estimate(ChessBoard cb, int goal) {
	return (goal - cb.num_queens())*(cb.num_attack()+0.1);
}

int Solver::lowest_f_score(vector<ChessBoard> set) {

	int lowest_score = 99999999;
	int id = 0;

	for(int i=0; i<set.size(); i++) {

		if(set[i].get_f_score() < lowest_score) {
			lowest_score = set[i].get_f_score();
			id = i;
		}
	}

	return id;
}
