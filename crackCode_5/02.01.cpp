/*
 Write code to remove duplicates from an unsorted linked list. 
 FOLLOW UP
 How would you solve this problem if a temporary buffer is not allowed?
 */
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

struct Node{
	int val;
	Node *next;
	Node(int v):val(v),next(NULL){}
};

Node* rmvDup(Node*head){
	if(head==NULL||head->next==NULL) return head;
	unordered_map<int,int> mark;
	Node *n = head;
	mark[n->val] = 1;
	while(n->next!=NULL){
		if(mark.find(n->next->val)!=mark.end())
			n->next = n->next->next;
		else{
			mark[n->next->val] = 1;
			n = n->next;
		}
	}
	return head;
}

Node *rmvDup2(Node*head){
	if(head==NULL||head->next==NULL) return head;
	Node *cur,*nex;
	cur = head;
	while(cur!=NULL){
		nex = cur;
		while(nex->next!=NULL){
			if(nex->next->val==cur->val)
				nex->next = nex->next->next;
			else 
				nex = nex->next;
		}
		cur = cur->next;
	}
	return head;
}

int main(int argc,char*argv[]){
	Node *head = new Node(1);
	Node *tail = head;
	srand(time(NULL));
	cout << "1 ";
	for(int i=0;i<5;++i){
		int tmp = rand()%5;
		cout << tmp << " ";
		tail->next = new Node(tmp);
		tail = tail->next;
	}
	cout << endl;
	//head = rmvDup(head);
	head = rmvDup2(head);
	while(head!=NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
