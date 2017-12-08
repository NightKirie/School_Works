#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;
struct node{
	int value;
	struct node* left;
	struct node* right;
};
typedef struct node* Link;

Link create_tree(Link, int);
void print_tree(Link);
Link delete_tree(Link, int);

int main(){
	char sel;
	int chosen;
    Link top = NULL;
	string element, temp;
	stringstream sstream;
	cin >> element;
	sstream << element;
	while(1){
		getline(sstream, temp, ',');
		if(sstream.fail())
			break;
		top = create_tree(top, atoi(temp.c_str()));
	}
    cout << "Create Binary search tree" << endl;
    print_tree(top);
	cout << "Delete element?(Y/N):";
    cin >> sel;
	while(sel != 'N'){
		cout << "Choice element:";
		cin >> chosen;
		top = delete_tree(top, chosen);
		print_tree(top);
		cin >> sel;
	}
}

Link create_tree(Link top, int value){
    if(value == -1)
        return top;
    Link newnode, last, temp;
	newnode = new node;
	newnode->value = value;
	newnode->left = NULL;
	newnode->right = NULL;
	if(top == NULL){	//if there's no top
		top = newnode;
		return top;
	}
	else{	//for going through the tree
		for(last = top; last != NULL;){
			temp = last;
			if(last->value > value)
				last = last->left;
			else
				last = last->right;
		}
		if(temp->value > value)	//for put the node at the end
			temp->left = newnode;
		else
			temp->right = newnode;
	}
	return top;
}

void print_tree(Link top){
	int count = 1;
	while(1){
		if(count == 1){
			Link 
		}
		count *= 2;
	}
}

Link delete_tree(Link top, int chosen){

}
