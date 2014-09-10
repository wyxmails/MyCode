/*
 struct node
 {
 	int data;
 	struct node *next;
 	struct node *next_larger;
 }
 initially next_larger of every node is point to NULL.
 now write a c code which set all node’s next_larger pointer.
 where next_largest point to the next larger then its own value 
 and largest value node’s next_larger pointer points to NULL
 i.e.   if LL is 3->1->5->6->4
 then 3's next_larger points to 4
 and 1's next_larger points to 3
 and 5's next_larger points to 6
 and 6's next_larger points to NULL
 and 4's next_larger points to 5 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	struct Node*next;
	struct Node*next_larger;
	Node(int v):data(v),next(NULL),next_larger(NULL){}
};

bool cmp(Node *n1,Node *n2){
	return n1->data<n2->data;
}

void nextLarger(Node*head){
	vector<Node*> mark;
	Node *run = head;
	while(run!=NULL){
		mark.push_back(run);
		run = run->next;
	}
	sort(mark.begin(),mark.end(),cmp);
	for(int i=0;i+1<mark.size();++i){
		mark[i]->next_larger = mark[i+1];
	}
}

//c code
void nextLarger2(Node*head){
	int n=0;
  	Node *run = head;
	while(run!=NULL){
		n++; run = run->next;
	}
	Node *arr[n];
	run = head;
	int i=0;
	while(run!=NULL){
		arr[i++] = run;
		run = run->next;
	}
	sort(arr,arr+n,cmp);
	for(i=0;i+1<n;++i)
		arr[i]->next_larger = arr[i+1];
}

Node *mergeSort(Node*head,int n){
	Node *l,*r;
	l=r=head;
	int i=0;
	if(head==NULL||head->next_larger==NULL) return head;
	Node*tail = NULL;
	while(i<(n/2)&&r!=NULL){
		i++;
		tail = r;
		r = r->next_larger;
	}
	tail->next_larger = NULL;
	l = mergeSort(l,i);
	r = mergeSort(r,n-i);
	head = NULL;
	tail = NULL;
	while(l!=NULL&&r!=NULL){
		if(l->data<r->data){
			if(head==NULL) head = l;
			else tail->next_larger = l;
			tail = l;
			l = l->next_larger;
		}else{
			if(head==NULL) head = r;
			else tail->next_larger = r;
			tail = r;
			r = r->next_larger;
		}
	}
	if(l!=NULL) tail->next_larger = l;
	if(r!=NULL) tail->next_larger = r;
	return head;
}
//sort next_larger
void nextLarger3(Node*head){
	int n=0;
	Node *run = head;
	while(run!=NULL){
		n++;
		run->next_larger = run->next;
		run = run->next;
	}
	head = mergeSort(head,n);
}

int main(int argc,char *argv[]){
	Node *head,*tail;
	head = new Node(3); tail = new Node(1);
	head->next = tail;
	Node *nn = new Node(5);
	tail->next = nn; tail = nn;
	nn = new Node(6);
	tail->next = nn; tail = nn;
	nn = new Node(4);
	tail->next = nn; tail = nn;
	//nextLarger(head);
	//nextLarger2(head);
	nextLarger3(head);
	while(head!=NULL){
		cout << "cur: " << head->data;
		if(head->next_larger!=NULL)
			cout << " larger: " << head->next_larger->data;
		else
			cout << " larger: NULL" ;
		cout << endl;
		head = head->next;
	}
	return 0;
}
