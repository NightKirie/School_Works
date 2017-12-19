#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;
void heightUnion(int*, int, int);
int findroot(int*, int);

int main(){
	int n;
	cin >> n;
	int node[n];
	for(int i = 0; i < n; i++){
		node[i]= -(i+1);
	}
	for(int i = 1; i < n; i++)
		heightUnion(node, findroot(node, 0), findroot(node, i));
	cout << setw(8) << std::left << "Node" << "parent" << endl;
	for(int i = 0; i < n; i++){
		cout << setw(8) << std::left << i; 
		//if(node[i] < 0)
	//		cout << "root" << endl;
	//	else
			cout << node[i] << endl;
	}
}
int findroot(int* node, int i){
	int root;
	for(root = i; node[root] >= 0; root = node[root])
		;
	return root;
}
void heightUnion(int* node, int rooti, int rootj){
	int totalheight;
	if(node[rooti] == node[rootj])
		totalheight = node[rooti] - 1;	
	else if(node[rooti] > node[rootj])
		totalheight = node[rooti];
	else
		totalheight = node[rootj];
	if(node[rooti] > node[rootj]){
		node[rooti] = rootj;
		node[rootj] = totalheight;
	}
	else{
		node[rootj] = rooti;
		node[rooti] = totalheight;
	}
}
