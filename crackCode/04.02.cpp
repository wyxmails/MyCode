#include <iostream>
#include <queue>
using namespace std;

const int node = 15;
bool graph[node][node];
void init(){
	for(int i=0;i<node;++i){
		for(int j=0;j<node;++j){
			if(i<j) graph[i][j] = true;
			else graph[i][j] = false;
		}
	}
}
bool route(int src,int des){
	if(src==des) return true;
	if(graph[src][des]) return true;
	queue<int> myQ;
	myQ.push(src);
	while(!myQ.empty()){
		int n = myQ.front();
		if(n==des) return true;
		myQ.pop();
		for(int i=0;i<node;++i){
			if(graph[n][i]&&n!=i) myQ.push(i);
		}
	}
	return false;
}

int main(int argc,char*arv[]){
	init();
	if(route(0,10)) cout << "There is a route!!!" << endl;
	else cout << "No route!!!" << endl;
	if(route(10,0)) cout << "There is a route!!!" << endl;
	else cout << "No route!!!" << endl;
}
