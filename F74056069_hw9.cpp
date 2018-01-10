#include<iostream>
#include<map>

using namespace std;

class graph{
	public:
		int s_ver;
		int e_ver;
		int act_req;
};
class ver_time{
	public:
		int ee;
		int le;
};
class edge_time{
	public:
		int e;
		int l;
		int s;
		char c;
};
void gotoend(int, map<int, graph>aoe);

int main(){
	int edges;
	cin >> edges;
	map<int, graph>aoe;
	map<int, int>start_ver;	//0 for not exist, 1 for exist, 2 for used
	map<int, int>end_ver;	//0 for not exist, 1 for exist, 2 for used
	map<int, ver_time>vertex;
	map<int, edge_time>edge;
	for(int i = 0; i < edges; i++){
		int num, s, e, act;
		cin >> num >> s >> e >> act;
		aoe.insert(pair<int, graph>(num, graph{s, e, act}));
		start_ver.insert(pair<int, int>(s, 1));
		end_ver.insert(pair<int, int>(e, 1));
	}
	for(map<int, int>::iterator it_ver = start_ver.begin(); it_ver != start_ver.end(); it_ver++)	//for n edges, have at most n+1 vertexs
		if(end_ver.find(it_ver->first) == end_ver.end())	//for this vertex has no front
			gotoend(it_ver->first, aoe);
			
}

void gotoend(int start, map<int, graph>aoe){

}
