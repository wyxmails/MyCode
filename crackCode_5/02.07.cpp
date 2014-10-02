/*
 Implement a function to check 
 if a linked list is a palindrome.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int v):val(v),next(NULL){}
};

bool isPal(Node*head){
	if(head==NULL||head->next==NULL) return true;
	int n=0;
	Node *run = head;
	while(run!=NULL){
		n++; run = run->next;
	}
	vector<int> vec1(n,0),vec2(n,0);
	run = head;
	int i=0,j=n-1;
	while(run!=NULL){
		vec1[i++] = run->val;
		vec2[j--] = run->val;
		run = run->next;
	}
	for(i=0;i<n;++i){
		if(vec1[i]!=vec2[i])
			return false;
	}
	return true;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10;
	Node*head,*tail;
	head=tail=NULL;
	cout << "n: " << n << endl;
	for(int i=0;i<n;++i){
		int tmp = rand()%5;
		if(head==NULL) head=tail=new Node(tmp);
		else{
			tail->next = new Node(tmp);
			tail = tail->next;
		}
		cout << tmp << " ";
	}
	cout << endl;
	if(isPal(head)) cout << "Palindrome" << endl;
	else cout << "Not Palindrome" << endl;
	return 0;
}
