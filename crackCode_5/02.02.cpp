/*
 Implement an algorithm to find the kth to last element 
 of a singly linked list.
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int v):val(v),next(NULL){}
};

int kthToEnd(Node*head,int k){
	int i=0;
	Node *t=head;
	while(i++<k&&t!=NULL) t = t->next;
	if(i<k) return head->val;
	Node *h = head;
	while(t!=NULL){
		t = t->next;
		h = h->next;
	}
	return h->val;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int tmp = rand()%10;
	Node*head = new Node(tmp);
	cout << tmp << " ";
	Node *t = head;
	for(int i=0;i<5;++i){
		tmp = rand()%10;
		t->next = new Node(tmp);
		t = t->next;
		cout << tmp << " ";
	}
	cout << endl;
	int k = rand()%5+1;
	cout << "k: " << k << endl;
	cout << kthToEnd(head,k) << endl;
	return 0;
}
