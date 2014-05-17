//Class that solves the n queens problem

#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>



using namespace std;

class Solver{
	private:
		int heuristic_cost_estimate(ChessBoard cb, int goal);
		int lowest_f_score(vector<ChessBoard> set);
		bool exists(vector<ChessBoard> set, ChessBoard element);

	public:
		void HillClimbing(ChessBoard initial);
		void AStar(ChessBoard initial, int goal);
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

void Solver::AStar(ChessBoard initial, int goal) {
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
			break;
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

ChessBoard Solver::RetornandoPTeste(){
	vector<int> board = {6,0,0,0,0,0,0,0}; //para teste
	ChessBoard cb (board, 1);
	return cb;

	}

int Solver::NextValue(){
	return 4;

	}
