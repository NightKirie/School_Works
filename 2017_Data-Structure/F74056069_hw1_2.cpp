#include<iostream>
using namespace std;
int count = 0;
void hanoi(int disk, char take, char temp, char put){
	if(disk == 1)
		cout << "Move disk " << disk << " from " << take << " to " << put << endl;
	else{
		hanoi(disk - 1, take, put, temp);
		cout << "Move disk " << disk << " from " << take << " to " << put << endl;
		hanoi(disk - 1, temp, take, put);
	}
	count++;
}
int main(){
	int disk;
	cin >> disk;
	hanoi(disk, 'A', 'B', 'C');	
	cout << "Total steps:" << count << endl;
}
