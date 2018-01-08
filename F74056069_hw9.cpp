#include<iostream>
#include<map>

using namespace std;
class graph{
	public:
		int s_ver;
		int e_ver ;
		int act_req;
};

int main(){
	int edge;
	cin >> edge;
	map<int, graph>aoe;
	for(int i = 0; i < edge; i++){
		int num, s, e, act;
		cin >> num >> s >> e >> act;
		aoe.insert(pair<int, graph>(num, graph{s, e, act}));
		
	}
		
}
