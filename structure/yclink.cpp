#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct node{
	int value;
	node*next;
};
node* insert(node *p, node *head){
//node insert(node *p, node *head){
		if(head!=NULL)
			head->value = 10;
		p->next = head;
		head = p;
		return head;
}

void test(int *a)
{
 	*a = 5;
}
node *reverse(node*head){
	node *tmp1, *tmp2;
	tmp1=tmp2=NULL;
	while(head!=NULL){
		tmp2 = head->next;
		head->next = tmp1;
		tmp1 = head;
		head = tmp2;
	}
	head = tmp1;
	return head;
}
void plink(node *head){
	node *p = head;
	while(p!=NULL){
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
int main(int argc,char*argv[]){
	node *head,*p;
	int n;
	cin>>n;
	p=head=NULL;
	srand(time(0));
	for(int i=0;i<n;++i){
		p = new node;
		p->value = rand()%(2*n);
		cout << "p: " << p->value << endl;
		p->next = NULL;
		head = insert(p,head);
		cout << "head: " << head->value << endl;
	}
	node a,b;
	a.value = 1;
	a.next = NULL;
	b.value = 3;
	b.next = NULL;
	//a = insert(&b,&a);
	//cout << a.value << " " << (a.next)->value << endl;
	cout << "before reverse: " << endl;
	plink(head);
	head = reverse(head);
	cout << "after reverse: " << endl;
	plink(head);
	return 0;
}
