#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;
};

void printTree(Node *root){
	int cur,nex;
	queue<Node*> myque;
	myque.push(root);
	cur=1;
	nex = 0;
	while(!myque.empty()){
		Node *tmp = myque.front();
		myque.pop();
		vector<Node*>::iterator it;
		cout << (*tmp).data << " ";
		cur--;
		for(it=(*tmp).children.begin();it!=(*tmp).children.end();++it){
			myque.push(*it);
			nex++;
		}
		if(cur==0){
			cout << endl;
			cur = nex;
			nex = 0;
		}
	}
}

int main()
{
	Node nodes[10];
	
	for (int i = 0; i < 10; i++) nodes[i].data = i+1;
	
	nodes[0].children.push_back(&nodes[1]);
	nodes[0].children.push_back(&nodes[2]);
	nodes[0].children.push_back(&nodes[3]);
	
	nodes[1].children.push_back(&nodes[4]);
	nodes[1].children.push_back(&nodes[5]);
	
	nodes[3].children.push_back(&nodes[6]);
	nodes[3].children.push_back(&nodes[7]);
	
	printTree(nodes);
	
	return 0;  
}
