#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    int value;
    struct Node* point;
};
typedef Node* Link;
Link XOR(Link, Link);

int main(){
    Link newnode = NULL;
    Link leftnode = NULL;
    Link head = new Node;
    Link temp = NULL;
    head->value = 1;
    head->point = NULL;
    leftnode = head;
    for(int i = 2; i <= 20; i++){
        newnode = new Node;
        newnode->value = i;
        leftnode->point = XOR(leftnode->point, newnode);
        newnode->point = leftnode;
        leftnode = newnode;
    }
    printf("The data from left to right:\n");
    printf("%d", head->value);
    newnode = head->point;
    for(int i = 1; i < 20; i++){
        printf(", %d", newnode->value);
        temp = newnode;
        newnode = XOR(newnode->point, head);
        head = temp;
    }
    printf("\n\nThe data from right to left:\n");
    printf("%d", leftnode->value);
    newnode = leftnode->point;
    for(int i = 1; i < 20; i++){
        printf(", %d", newnode->value);
        temp = newnode;
        newnode = XOR(newnode->point, leftnode);
        leftnode = temp;
    }
    printf("\n");
}

Link XOR(Link a, Link b){
    return((Link)((unsigned long long)a ^ (unsigned long long)b));
}
