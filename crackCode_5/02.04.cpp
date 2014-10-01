/*
 Write code to partition a linked list 
 around a value x, such that 
 all nodes less than x come before 
 all nodes greater than or equal to x.
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int v):val(v),next(NULL){}
};

Node* partition(Node*root,int x){
	Node *hl,*tl,*hr,*tr;
	hl=tl=hr=tr=NULL;
	while(root!=NULL){
		if(root->val<x){
			if(hl==NULL) hl = root;
			else tl->next = root;
			tl = root;
		}else{
			if(hr==NULL) hr = root;
			else tr->next = root;
			tr = root;
		}
		root = root->next;
	}
	if(tl!=NULL) tl->next = hr;
	if(tr!=NULL) tr->next = NULL;
	return hl==NULL?hr:hl;
}

Node* partition2(Node*root,int x){
	Node *h,*t;
	h = t = NULL;
	while(root!=NULL){
		Node*next = root->next;
		root->next = NULL;
		if(root->val<x){
			if(h==NULL) t = root;
			else root->next = h;
			h = root;
		}else{
			if(t==NULL) h = root;
			else t->next = root;
			t = root;
		}
		root = next;
	}
	return h;
}

int main(int argc,char*argv[]){
	Node *root,*tail;
	root = tail = NULL;
	srand(time(NULL));
	int n = rand()%5;
	for(int i=0;i<n;++i){
		int tmp = rand()%10;
		if(root==NULL)
			root = tail = new Node(tmp);
		else{
			tail->next = new Node(tmp);
			tail = tail->next;
		}
		cout << tmp << " ";
	}
	cout << endl;
	//Node *nn = partition(root,root->val);
	if(root==NULL){
	   	cout << "NULL" << endl;
		return 0;
	}
	Node *nn = partition2(root,root->val);
	while(nn!=NULL){
		cout << nn->val << " ";
		nn = nn->next;
	}
	cout << endl;
	return 0;
}
