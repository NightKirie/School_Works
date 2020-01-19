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
bool delete_tree(Link*, int);

int main(){
	char sel;
	int chosen;
	bool del_check;
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
		del_check = delete_tree(&top, chosen);
		if(del_check)
			print_tree(top);
		else
			cout << chosen << " is not in the tree" << endl;
		cout << "Delete element?(Y/N):";
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
	if(top == NULL)
		cout << "There's no node in this tree" << endl;
	int count = 1;
	Link* upper = NULL;
	Link* lower = new Link[count];
	lower[0] = top;
	bool end = false;
	while(!end){
		end = true;
		delete []upper;
		upper = lower;
		lower = new Link[count*2];
		for(int i = 0; i < count; i++){
			if(upper[i] == NULL){
				cout.width(3);
				cout << std::left <<"*";
				lower[i*2] = NULL;
				lower[i*2 + 1] = NULL;

			}
			else{
				cout.width(3);
				cout << std::left << upper[i]->value;
				lower[i*2] = upper[i]->left;
				lower[i*2 + 1] = upper[i]->right;
				if(lower[i*2] != NULL)
					end = false;
				if(lower[i*2 + 1] != NULL)
					end = false;
			}
		}
		cout << endl;
		count *= 2;
	}
	delete []upper;
	delete []lower;
}

bool delete_tree(Link *top, int chosen){
	Link findnode = *top;
	Link temp = NULL;
	if(!top){
		cout << "There's no node in this tree" << endl;
		exit(1);
	}
	while(findnode){
		if(findnode->value == chosen)	//for found the node
			break;
		temp = findnode;
		if(findnode->value > chosen)
			findnode = findnode->left;
		else
			findnode = findnode->right;
	}
	if(!findnode)
		return false;
	if(!temp && (!findnode->right || !findnode->left)){ 
		if(!findnode->left && !findnode->right){
			cout << "There's no node in this tree" << endl;
			exit(1);
		}
		else if(!findnode->left){
			temp = *top;
			*top = (*top)->right;
			delete temp;
		}
		else if(!findnode->right){
			temp = *top;
			*top = (*top)->left;
			delete temp;
		}
		return true;
	}

	if(!findnode->left && !findnode->right){	//no child node for this node
		if(temp->value > findnode->value)
			temp->left = NULL;
		else
			temp->right = NULL;
		delete findnode;
	}	
	else if(!findnode->right){	//no right child node for this node
		if(temp->value > findnode->value)
			temp->left = findnode->left;
		else
			temp->right = findnode->left;
		delete findnode;
	}
	else if(!findnode->left){	//no left child node for this node
		if(temp->value > findnode->value)
			temp->left = findnode->right;
		else
			temp->right = findnode->right;
		delete findnode;
	}
	else{	//have both child node
		Link lowernode = findnode->right;
		Link tempnode = findnode;
		while(lowernode->left){
			tempnode = lowernode;
			lowernode = lowernode->left;
		}
		findnode->value = lowernode->value;
		if(tempnode->right == lowernode){
			if(lowernode->right)
				tempnode->right = lowernode->right;
			else
				tempnode->right = NULL;
		}
		else{
			if(lowernode->right)
				tempnode->left = lowernode->right;
			else
				tempnode->left = NULL;
		}
		delete lowernode;
	}
	
	return true;
}
