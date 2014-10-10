/*
 Given a directed graph, 
 design an algorithm to find out 
 whether there is a route between two nodes.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphNode{
	int val;
	vector<GraphNode*> neighbors;
	GraphNode(int v):val(v){}
};
bool Reachable(GraphNode*n1,GraphNode*n2){
	GraphNode *start = n1,*end=n2;
	if(start==end) return true;
	if(start==NULL||end==NULL) return false;
	queue<GraphNode*> mark;
	mark.push(start);
	while(!mark.empty()){
		GraphNode *tmp = mark.front();
		mark.pop();
		for(int i=0;i<tmp->neighbors.size();++i){
			if(tmp->neighbors[i]==end) return true;
			mark.push(tmp->neighbors[i]);
		}
	}
	return false;
}
bool IsConnected(GraphNode*n1,GraphNode*n2){
	if(Reachable(n1,n2)) return true;
	if(Reachable(n2,n1)) return true;
	return false;
}

int main(int argc,char*argv[]){
	GraphNode *n1,*n2;
	n1 = new GraphNode(1);
	n2 = new GraphNode(2);
	n1->neighbors.push_back(n2);
	n2->neighbors.push_back(n1);
	if(IsConnected(n1,n2)) cout << "There is a route" << endl;
	else cout << "No route" << endl;
	return 0;
}
