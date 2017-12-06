#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;
struct node{
	int value;
	struct node* left;
	struct node* right;
}
typedef node* Link;

Link create_tree(Link, int);

int main(){
	Link top = NULL;
	string element, temp;
	stringstream sstream;
	cin >> element;
	sstream << element;
	while(1){
		getline(sstream, temp, ',');
		if(sstream.fail())
			break;
		create_tree(top, atoi(temp.c_str()));
	}
}

Link create_tree(Link top, int value){
	Link newnode, last, temp;
	newnode = new node;
	newnode->value = value;
	newnode->left = NULL;
	newnode->right = NULL;
	if(top == NULL){
		top = newnode;
		return top;
	}
	else{
		for(last = top; last != NULL;){
			temp = last;
			if(last->value > value)
				last = last->left;
			else
				last = last->right;
		}
		if(temp->value > value)
			temp->left = newnode;
		else
			temp->right = newnode;
	}
	return top;
}

