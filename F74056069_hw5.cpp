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
bool delete_tree(Link, int);

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
		del_check = delete_tree(top, chosen);
		if(del_check)
            print_tree(top);
        else
            cout << chosen << " is not in the tree";
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

bool delete_tree(Link top, int chosen){
    Link findnode = top;
    while(findnode){
        if(findnode)
    }
}
