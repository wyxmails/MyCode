#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node{
	int val;
	Node *next;
	Node(int v){
		val = v;
		next = NULL;
	}
}Node;

Node *loopHead(Node *root){
	if(root==NULL) return root;
	Node *step1,*step2;
	step1 = step2 = root;
	while(step2&&step2->next){
		step1 = step1->next;
		step2 = step2->next->next;
		if(step1==step2) break;
	}
	if(!step2||!step2->next) return NULL;
	step1 = root;
	while(step1!=step2){
		step1 = step1->next;
		step2 = step2->next;
	}
	return step1;
}

int main(int argc,char*argv[]){
	Node *root,*tail;
	root = tail = NULL;
	srand((unsigned)time(NULL));
	int s = rand()%10;
	Node *head = NULL;
	for(int i=0;i<10;++i){
		int tmp = rand()%30;
		cout << tmp << " ";
		Node *node = new Node(tmp);
		if(i==s) head = node;
		if(root==NULL) root = node;
		else tail->next = node;
		tail = node;
	}
	tail->next = head;
	cout << endl << "\t" << head->val << endl;
	Node *res = loopHead(root);
	if(res==head) cout << "Found the loop head!!! " << res->val << endl;
	else cout << "Oops, Wrong answer!!!" << endl;
	return 0;
}
