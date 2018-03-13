//compile: g++ -o hw1 hw1.cpp
//execute: ./hw1
//you can input from 1 ~ 9
#include <iostream>
using namespace std;

#define DOTS 10	//for using 1 ~ 9 nodes
 
int CalculatePaths(bool visited[DOTS], int passby[DOTS][DOTS], int thisNode, int nodesToGo){
    if (nodesToGo <= 0)
        return (nodesToGo == 0)? 1 : 0;
    int path = 0;
    visited[thisNode] = true;	//Currently set this node is visited
    for(int i = 1; i < DOTS; i++){
       if(!visited[i] && (!passby[thisNode][i] || visited[passby[thisNode][i]]))	//if node i is unvisited, and no node between node i and this node, or the node between node i and this node is visited, go to node i
         	path += CalculatePaths(visited, passby, i, nodesToGo-1);
    }
    visited[thisNode] = false;	//after recursive, this node will be reseted to unvisited for next loop
    return path;
}
 
int PathsOfConnection(int minNode, int maxNode){	//for 
    int passby[DOTS][DOTS] = {0};	//for the node that pass by
	bool visited[DOTS] = {false};	//for node that have been visited
	int path = 0;	
    
	//2 is between 1 and 3
	passby[1][3] = 2;
	passby[3][1] = 2;	
    
	//8 is between 7 and 9
	passby[7][9] = 8;
	passby[9][7] = 8;	
   	
	//4 is between 1 and 7
	passby[1][7] = 4;
	passby[7][1] = 4;	
    
	//6 is between 3 and 9
	passby[3][9] = 6;
	passby[9][3] = 6;	
 
    //5 is in the center of other 8 nodes
    passby[1][9] = 5;
	passby[9][1] = 5;
	passby[2][8] = 5;
	passby[8][2] = 5;
    passby[3][7] = 5;
	passby[7][3] = 5;
	passby[4][6] = 5;
	passby[6][4] = 5;
 
    for(int i = minNode; i <= maxNode; i++){
        path += 4 * CalculatePaths(visited, passby, 1, i-1);	//1, 3, 7, 9 have same number of paths
        path += 4 * CalculatePaths(visited, passby, 2, i-1);	//2, 4, 6, 8 have same number of paths
        path += CalculatePaths(visited, passby, 5, i-1);	//5 is lonely :(
    }
    return path;
}
 
//  Driver code to test above method
int main(){
    int minNode, maxNode;
	
	cout << "Please input the minimum number of nodes you want to connect: ";
	cin >> minNode;
	cout << endl;
	
	cout << "Please input the maximum number of nodes you want to connect: ";
	cin >> maxNode;
	cout << endl;
    
	cout << "\nThere\'s " << PathsOfConnection(minNode, maxNode) << " kind of path patterns for " << minNode << " to " << maxNode << " nodes connected" << endl;
    return 0;
}
