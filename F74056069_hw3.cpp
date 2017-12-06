#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct list{
	int posx, posy;
	struct list* next;
} node;
typedef node* Link;

Link push(Link, int, int);
Link pop(Link, int*, int*);
int checkend(int, int, int, int);
void print(int, int, int, int, int, int, char*);
static int count = 0;

int main(){
	int M, N;
	cin >> N >> M;
	//for the wall around the maze
	N += 2;
	M += 2;	
	char maze[N*M];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			maze[M * i + j] = 1;
	int posx, posy, endx, endy, startx, starty;
	cin.ignore();
	for(int i = 1; i < N - 1; i++){
		for(int j = 1; j < M - 1; j++){
			cin.get(maze[M * i + j]);
			if(maze[M * i + j] == 48 || maze[M * i + j] == 49)	
				maze[M * i + j] -= 48;
			if(maze[M * i + j] == 115){
				posx = j;
				posy = i;
				startx = posx;
				starty = posy;
				maze[M * i + j] = 0;
			}	
			else if(maze[M * i + j] == 100){
				endx = j;
				endy = i;
				maze[M * i + j] = 0;
			}
		}
		cin.ignore();
	}	
	Link path = NULL;
	while(1){
		maze[M * posy + posx] = 2;
		if(posx == endx && posy == endy)	//if the mouse get to the end
			break;
	    else if(maze[M * (posy - 1) + posx] == 0){	//N
			--posy;
			path = push(path, posx, posy);
		}
		else if(maze[M * (posy - 1) + posx + 1] == 0){	//NE
			++posx;
			--posy;
			path = push(path, posx, posy);
		}
		else if(maze[M * posy + posx + 1] == 0){	//E
			++posx;
			path = push(path, posx, posy);
		}
		else if(maze[M * (posy + 1) + posx + 1] == 0){	//SE
			++posx;
			++posy;
			path = push(path, posx, posy);
		}
		else if(maze[M * (posy + 1) + posx] == 0){	//S
			++posy;
			path = push(path, posx, posy);
		}
		else if(maze[M * (posy + 1) + posx - 1] == 0){	//SW
			--posx;
			++posy;
			path = push(path, posx, posy);
		}
		else if(maze[M * posy + posx - 1] == 0){	//W
			--posx;
			path = push(path, posx, posy);
		}
		else if(maze[M * (posy - 1) + posx - 1] == 0){	//NW
			--posx;
			--posy;
			path = push(path, posx, posy);
		}
		else{	//if the mouse stuck
		    if(count == 0) //if there's no route
				break;
			else{   //if there still has route
				maze[M * posy + posx] = 2;
				path = pop(path, &posx, &posy);
			}	
		}
	}
	print(M, N, startx, starty, endx, endy, maze);
}

Link push(Link stack, int posx, int posy){
	Link newnode;
    newnode = (Link)malloc(sizeof(node));
	newnode->posx = posx;
	newnode->posy = posy;
	newnode->next = stack;
	stack = newnode;
    ++count;
	return stack;
}

Link pop(Link stack, int* posx, int* posy){
	Link top;
	if(stack != NULL){
		top = stack;
		stack = stack->next;
		*posx = top->posx;
		*posy = top->posy;
		free(top);
        --count;
		return stack;
	}
	else    //for there's no route
		*posx = -1;
	return stack;
}

void print(int M, int N, int startx, int starty, int endx, int endy, char* maze){
	maze[M * starty + startx] = 115;
	maze[M * endy + endx] = 100;	
	if(count == 0){
		cout << "No route" << endl;
		return;
	}
	for(int i = 1; i < N - 1; i++){
		for(int j = 1; j < M - 1; j++) {
			switch(maze[M * i + j]){
				case 0:
					cout << '0';
					break;
				case 1:
					cout << '1';
					break;
				case 2:
					cout << '*';
					break;
				case 100:
					cout << 'd';
					break;
				case 115:
					cout << 's';
					break;
			}
		}
		cout << endl;
	}	
	cout << count+1 << " steps" << endl;	//count+1 because the start point was change to "*" when counting
}
