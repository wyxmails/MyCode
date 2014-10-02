/*
 Given a circular linked list, 
 implement an algorithm 
 which returns the node at the beginning of the loop.
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int v):val(v),next(NULL){}
};

Node* getEnCircle(Node*head){
	Node *s1,*s2;
	s1=s2=head;
	while(s2!=NULL){
		s1 = s1->next;
		s2 = s2->next;
		if(s2==NULL) return NULL;
		s2 = s2->next;
		if(s2==s1) break;
	}
	if(s1==NULL||s2==NULL) return NULL;
	s1 = head;
	while(s1!=s2){
		s1 = s1->next;
		s2 = s2->next;
	}
	return s1;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10+1;
	int c = rand()%n;
	Node *head,*tail,*cycle;
	head = tail = cycle = NULL;
	for(int i=0;i<n;++i){
		int tmp = rand()%100;
		Node *n = new Node(tmp);
		if(head==NULL){
			head = tail = n;
		}else{
			tail->next = n;
			tail = n;
		}
		if(i==c){
		   	cycle = n;
			cout << " cycle: ";
		}
		cout << tmp << " ";
	}
	tail->next = cycle;
	cout << endl;
	Node *cur = getEnCircle(head);
	if(cur!=NULL)
		cout << cur->val << endl;
	return 0;
}
