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

int main(){
	char sel;
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
    while(cin >> sel != 'N'){
  
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

void print_tree(Link node){
    if(node != NULL){
        cout << node->value;
        if(node->left){
            cout << ", ";
            print_tree(node->left);
        }
        if(node->right){
            cout << ", ";
            print_tree(node->right);
        }
    }
}
