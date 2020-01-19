#include<iostream>
#include<iomanip>
using namespace std;

void printout(int, int*, int*);
bool possibility(int, int*, int*, int*, int*);
void travel(int, int, int, int*, int*, int*, int*, int*);
int main(){
	int posx = 0, posy = 0;
	int N[8] = {1, 2, 3, 4, 5 ,6 ,7, 8};	
	int movex[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int movey[8] = {1, 2, 2, 1, -1, -2, -2, -1};	
	for(int i = 0; i < 8; i++){
		int npos[N[i] * N[i]] = {0};	//for how many ways this block can go
		int board[N[i] * N[i]] = {0};	//for record steps in which block
		if(i == 0){
			board[0] = 1;
			printout(i ,N, board);
			continue;
		}
		bool check = false;	//for checking if any element in npos is 0
		check = possibility(i, N, npos, movex, movey);
		if(check == true)
			continue;
		else if(check == false){
			board[0] = 1;
			travel(i, posx, posy, board, npos, movex, movey, N);
		}
	}
}
void printout(int i, int* N, int* board){
	cout << N[i] << ":" << endl;
	for(int a = 0; a < N[i]; a++){
		for(int b = 0; b < N[i]; b++)
			cout << setw(3) << board[N[i] * a + b];
		cout << endl;
	}	
	cout << endl;		
}
bool possibility(int i, int *N, int *npos, int* movex, int* movey){
	for(int a = 0; a < N[i]; a++)   //posy = a
		for(int b = 0; b < N[i]; b++){  //posx = b
	    	for(int c = 0; c < 8; c++){ //for checking 8 ways of movement
	        	if(movex[c] + b > N[i] - 1 || movex[c] + b < 0 || movey[c] + a > N[i] - 1 || movey[c] + a < 0)
	            	continue;
            	++npos[N[i] * a + b];
        	}
    		if(npos[N[i] * a + b] == 0){
    			cout << N[i] << ":" << endl << "no solution" << endl << endl;
				return true;
			}	//if any element in npos is 0
		}
	return false;	//if all elements in npos isn't 0
}
void travel(int i, int posx, int posy, int* board, int* npos, int* movex, int* movey, int* N){
	for(int a = 2; a <= N[i] * N[i]; a++){
		int tempgo = 0;	//record npos for next possible going
		int tempposx = 0, tempposy = 0;
		for(int b = 0; b < 8; b++){	//b for how much can move, c for where it move
			if(movex[b] + posx < 0 || movex[b] + posx > N[i] - 1 || movey[b] + posy < 0 || movey[b] + posy > N[i] - 1) 
				continue;	 
			if(board[(movey[b] + posy) * N[i] + (movex[b] + posx)] != 0)
				continue;
			--npos[(movey[b] + posy) * N[i] + (movex[b] + posx)];
			if(npos[(movey[b] + posy) * N[i] + (movex[b] + posx)] >= tempgo && tempgo != 0)
				continue;
			else{
				tempgo = npos[(movey[b] + posy) * N[i] + (movex[b] + posx)];
				tempposx = posx + movex[b];
				tempposy = posy + movey[b];
			}
		}
		board[tempposy * N[i] + tempposx] = a;
		if(tempposx == posx && tempposy == posy){
 	     	cout << N[i] << ":" << endl << "no solution" << endl << endl;
            return;
        }
		posx = tempposx;
		posy = tempposy;
	}
	printout(i, N, board);
}














