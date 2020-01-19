#include<iostream>
#include<iomanip>

#define MAX_VERTICES 9
#define inf 100000

using namespace std;

void allCosts(int[][MAX_VERTICES], int[][MAX_VERTICES], int[][MAX_VERTICES]);
void printpath(int[][MAX_VERTICES], int, int);

int main(){
	int cost[9][9] = {  0,  5,  4,  2,inf,inf,inf,inf,inf,
					  inf,  0,inf,inf,  3,inf,inf,inf,inf,
				  	  inf,  1,  0,inf,  2,  8,inf,inf,inf,
				 	  inf,inf,  1,  0,inf,  7,inf,inf,inf,
					  inf,inf,inf,inf,  0,inf,  7, 10, 15,
					  inf,inf,inf,inf,inf,  0,inf,  3,inf,
			     	  inf,inf,inf,inf,inf,inf,  0,inf,  6,
					  inf,inf,inf,inf,inf,inf,inf,  0,  5,
					  inf,inf,inf,inf,inf,inf,inf,inf,  0};
	int distance[MAX_VERTICES][MAX_VERTICES], parent[MAX_VERTICES][MAX_VERTICES];
	int s, e;
	cin >> s >> e;
	allCosts(cost, distance, parent);
	if(distance[s][e] > 1000){
		cout << "No solution" << endl;
	}
	else{
		cout << "Distance:" << distance[s][e] << endl;
		cout << "The route for the shortest path:";
		printpath(parent, s, e);
		cout << endl;
	}
}

void allCosts(int cost[][MAX_VERTICES], int distance[][MAX_VERTICES], int parent[][MAX_VERTICES]){
	for(int i = 0; i < MAX_VERTICES; i++)
		for(int j = 0; j < MAX_VERTICES; j++){
			distance[i][j] = cost[i][j];
			parent[i][j] = -1;
		}
	for(int k = 0; k < MAX_VERTICES; k++){
		for(int i = 0; i < MAX_VERTICES; i++)
			for(int j = 0; j < MAX_VERTICES; j++){
				if(distance[i][k] + distance[k][j] < distance[i][j]){
					distance[i][j] = distance[i][k] + distance[k][j];
					parent[i][j] = parent[k][j];
				}
				else if(parent[i][j] == -1 && distance[i][j] < 1000)
					parent[i][j] = i;
			}
	}
}

void printpath(int parent[][MAX_VERTICES], int s, int e){
	if(parent[s][e] != e)
		printpath(parent, s, parent[s][e]);
	if(parent[s][e] == e)
		cout << s;
	else
		cout << "->" << e;
}

