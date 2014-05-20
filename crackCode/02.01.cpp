#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Node{
	int val;
	Node* next;
	Node(int v){
		val = v;
		next = NULL;
	}
}Node;

void rmvDupHash(Node *node){
	if(node==NULL||node->next==NULL) return;
	int myHash[100];
	memset(myHash,false,sizeof(myHash));
	Node* pre = node;
	Node* cur = node->next;
	while(cur!=NULL){
		if(myHash[cur->val]){
			pre->next = cur->next;
			cur = cur->next;
			continue;
		}
		myHash[cur->val] = true;
		pre = cur;
		cur = cur->next;
	}
}

void rmvDup(Node *node){
	if(node==NULL||node->next==NULL) return;
	Node *cur = node->next;
	Node *pre = node;
	Node *runner;
	while(cur!=NULL){
		for(runner=node;runner!=cur;runner=runner->next){
			if(runner->val==cur->val){
				pre->next = cur->next;
				cur = cur->next;
				break;
			}
		}
		if(runner==cur){
			pre = cur;
			cur = cur->next;
		}
	}
}

int main(int argc,char*argv[]){
	srand((unsigned)time(NULL));
	Node *node=NULL;
	Node *tail=NULL;
	for(int i=0;i<10;++i){
		int tmp = rand()%9;
		cout << tmp << " ";
		Node *t = new Node(tmp);
		if(node==NULL) node = t;
		else tail->next = t;
		tail = t;
	}
	cout << endl;
	//rmvDup(node);
	rmvDupHash(node);
	for(tail=node;tail!=NULL;tail=tail->next)
		cout << tail->val << " ";
	cout << endl;
	return 0;
}
