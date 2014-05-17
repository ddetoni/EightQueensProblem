//Class that solves the n queens problem

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>



using namespace std;

class Solver{
	private:
		int heuristic_cost_estimate(ChessBoard cb);
		ChessBoard lowest_score(vector<ChessBoard> set, vector<int> score);

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
	vector<ChessBoard> closedset;
	vector<ChessBoard> openset;
	openset.push_back(initial);

	vector<int> g_score;
	vector<int> f_score;

	g_score.push_back(0);
	f_score.push_back(g_score[0] + heuristic_cost_estimate(initial));

	while(!openset.empty()) {
		ChessBoard current = lowest_score(openset, f_score);

		current.print_board();
		break;
	}

}

int Solver::heuristic_cost_estimate(ChessBoard cb) {

	return (cb.num_queens()*cb.num_attack())/100;

}

ChessBoard Solver::lowest_score(vector<ChessBoard> set, vector<int> score) {

	int lowest_id = 0;

	for(int i=0; i<score.size(); i++) {

		if(score[i] < score[lowest_id]) lowest_id = i;

	}

	return set[lowest_id];
}

ChessBoard Solver::RetornandoPTeste(){
	vector<int> board = {6,0,0,0,0,0,0,0}; //para teste
	ChessBoard cb (board, 1);
	return cb;

	}

int Solver::NextValue(){
	return 4;

	}
