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

Node * sumLink(Node *n1,Node*n2){
	int carr = 0;
	Node *res = n1;
	Node *t = n1;
	while(n1!=NULL&&n2!=NULL){
		int v = n1->val+n2->val+carr;
		t->val = v%10;
		carr = v/10;
		n1 = n1->next;
		n2 = n2->next;
		if(n1!=NULL) t = t->next;
		else t->next = n2;
	}
	while(n1!=NULL){
		int v = n1->val+carr;
		n1->val = v%10;
		carr = v/10;
		n1 = n1->next;
	}
	while(n2!=NULL){
		int v = n2->val+carr;
		n2->val = v%10;
		carr = v/10;
		n2 = n2->next;
	}
	return res;
}

int main(int argc,char *argv[]){
	Node *num1, *num2, *tail1, *tail2;
	num1 = num2 = tail1 = tail2 = NULL;
	srand((unsigned)time(NULL));
	int k1 = rand()%10;
	int k2 = rand()%10;
	string s1,s2,res;
	s1 = s2 = res = "";
	for(int i=0;i<k1;++i){
		int tmp = rand()%9+1;
		s1 = (char)(tmp+'0')+s1;
		Node*node = new Node(tmp);
		if(num1==NULL) num1 = node;
		else tail1->next = node;
		tail1 = node;
	}
	cout << s1 << endl;
	for(int i=0;i<k2;++i){
		int tmp = rand()%9+1;
		s2 = char(tmp+'0')+s2;
		Node*node = new Node(tmp);
		if(num2==NULL) num2 = node;
		else tail2->next = node;
		tail2 = node;
	}
	cout << s2 << endl;
	tail1 = sumLink(num1,num2);
	while(tail1!=NULL){
		res = char(tail1->val+'0')+res;
		tail1 = tail1->next;
	}
	cout << res << endl;
	return 0;
}
