/*
 Implement an algorithm to delete a node in the middle 
 of a singly linked list, given only access to that node.
 EXAMPLE
 Input: the node c from the linked list a->b->c->d->e
 Result: nothing is returned, 
   but the new linked list looks like a- >b- >d->e
 */
#include <iostream>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int v):val(v),next(NULL){}
};

void deleteNode(Node *del){
	if(del==NULL||del->next==NULL) return;
	del->val = del->next->val;
	del->next = del->next->next;
}

int main(int argc,char*argv[]){
	Node *root = new Node(1);
	Node *tail = new Node(3);
	Node *mid = new Node(2);
	root->next = mid;
	mid->next = tail;
	deleteNode(mid);
	while(root!=NULL){
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
	return 0;
}
