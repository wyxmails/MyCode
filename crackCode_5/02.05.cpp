/*
 You have two numbers represented by a linked list, 
 where each node contains a single digit. 
 The digits are stored in reverse order, 
 such that the 1's digit is at the head of the list. 
 Write a function that adds the two numbers and 
 returns the sum as a linked list.
 FOLLOW UP
 Suppose the digits are stored in forward order. 
 Repeat the above problem.
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	Node*next;
	Node(int v):val(v),next(NULL){}
};

Node* getSum(Node*l1,Node*l2){
	int carry=0;
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	Node *h,*t;
	h=t=NULL;
	while(l1!=NULL&&l2!=NULL){
		int tmp = l1->val+l2->val+carry;
		if(h==NULL) h = t = new Node(tmp%10);
		else{
		   	t->next = new Node(tmp%10);
			t = t->next;
		}
		carry = tmp/10;
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1!=NULL){
		int tmp = l1->val+carry;
		if(h==NULL) h = t = new Node(tmp%10);
		else{
		   	t->next = new Node(tmp%10);
			t = t->next;
		}
		carry = tmp/10;
		l1 = l1->next;
	}
	while(l2!=NULL){
		int tmp = l2->val+carry;
		if(h==NULL) h = t = new Node(tmp%10);
		else{
		   	t->next = new Node(tmp%10);
			t = t->next;
		}
		carry = tmp/10;
		t = l2;
		l2 = l2->next;
	}
	if(carry>0){
		t->next = new Node(carry);
	}
	return h;
}

Node*revList(Node*list){
	if(list==NULL||list->next==NULL) return list;
	Node *h=NULL;
	while(list!=NULL){
		Node*next = list->next;
		list->next = h;
		h = list;
		list = next;
	}
	return h;
}
Node* getSumForward(Node*l1,Node*l2){
	l1 = revList(l1);
	l2 = revList(l2);
	Node*res = getSum(l1,l2);
	return revList(res);
}

int main(int argc,char*argv[]){
	Node *l1,*l2;
	l1 = new Node(3);
	l2 = new Node(5);
	Node *t1=l1,*t2=l2;
	srand(time(NULL));
	cout << "3 5" << endl;
	for(int i=0;i<5;++i){
		int tmp = rand()%10;
		cout << tmp << " ";
		t1->next = new Node(tmp);
		tmp = rand()%10;
		cout << tmp << endl;
		t2->next = new Node(tmp);
		t1 = t1->next;
		t2 = t2->next;
	}
	Node *res = getSum(l1,l2);
	while(res!=NULL){
		cout << res->val;
		res = res->next;
	}
	cout << endl;
	Node *res2 = getSumForward(l1,l2);
	while(res2!=NULL){
		cout << res2->val;
		res2 = res2->next;
	}
	cout << endl;
	return 0;
}
