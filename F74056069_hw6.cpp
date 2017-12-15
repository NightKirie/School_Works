#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;
typedef struct tree{
	int height;
	string parent;
}Node;

void heightUnion(Node*, int, int);

int main(){
	int n;
	cin >> n;
	Node node[n];
	for(int i = 0; i < n; i++){
		node[i].height = 1;
		node[i].parent = "root";
	}
	for(int i = 1; i < n; i++)
		heightUnion(node, 0, i);
	cout << setw(8) << std::left << "Node" << "parent" << endl;
	for(int i = 0; i < n; i++)
		cout << setw(8) << std::left << i << node[i].parent << endl;
}

void heightUnion(Node* node, int a, int b){
	int totalheight = node[a].height + node[b].height;
	if(node[a].height < node[b].height){
		node[a].parent = std::to_string(b);
		node[b].height = totalheight;
	}
	else{
		node[b].parent = std::to_string(a);
		node[a].height = totalheight;
	}
}
