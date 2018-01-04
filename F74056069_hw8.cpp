#include<iostream>
#include<iomanip>

#define MAX_VERTICES 9
#define inf 100000

using namespace std;

void allCosts(int[][MAX_VERTICES], int[][MAX_VERTICES]);

int main(){
	int cost[9][9] = {  0,  5,  4,  2,inf,inf,inf,inf,inf,
					  inf,  0,inf,inf,  3,inf,inf,inf,inf,
				  	  inf,  1,  0,inf,  2,  8,inf,inf,inf,
				 	  inf,inf,  1,  0,inf,  7,inf,inf,inf,
					  inf,inf,inf,inf,  0,inf,  7, 10, 15,
					  inf,inf,inf,inf,inf,  0,inf,  3,inf,
			     	  inf,inf,inf,inf,inf,inf,  0,inf,inf,
					  inf,inf,inf,inf,inf,inf,inf,  0,  5,
					  inf,inf,inf,inf,inf,inf,inf,inf,inf};
	int distance[9][9];
	int s, e;
	cin >> s >> e;
	allCosts(cost, distance);
	if(distance[s][e] > 1000){
		cout << "No solution" << endl;
		return 0;
	}
	else{
		cout << "Distance:" << distance[s][e] << endl;
		cout << "The route for the shortest path:" << endl;

	}
	
}

void allCosts(int cost[][MAX_VERTICES], int distance[][MAX_VERTICES]){
	for(int i = 0; i < MAX_VERTICES; i++)
		for(int j = 0; j < MAX_VERTICES; j++)
			distance[i][j] = cost[i][j];
	for(int k = 0; k < MAX_VERTICES; k++)
		for(int i = 0; i < MAX_VERTICES; i++)
			for(int j = 0; j < MAX_VERTICES; j++)
				if(distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
	for(int i = 0; i < MAX_VERTICES; i++){
		for(int j = 0; j < MAX_VERTICES; j++)
			cout << setw(10) << distance[i][j];
		cout << endl;
	}
}
