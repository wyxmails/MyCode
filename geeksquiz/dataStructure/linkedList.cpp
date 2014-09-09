#include <iostream>
#include <cstdlib>
using namespace std;

/*XOR doubly linked list*/
struct dNode{
	int val;
	dNode *npx;
	dNode(int v):val(v),npx(NULL){}
};
struct dNode *XOR(struct dNode *p,struct dNode*n){
	return (struct dNode*)((long long)p^(long long)n);
}
dNode*insert(dNode*head,dNode*nN){
	if(head!=NULL)
		head->npx = XOR(head->npx,nN);
	nN->npx = XOR(head,NULL);
	head = nN;
	return head;
}
void traverse(dNode*head){
	dNode*pre = NULL,*next;
	cout << "traverse start:" << endl;
	while(head!=NULL){
		cout << head->val << " ";
		next = XOR(pre,head->npx);
		pre = head;
		head = next;
	}
	cout << endl << "traverse end." << endl;
}
int main(int argc,char*argv[]){
	struct dNode*head = new dNode(1);
	for(int i=2;i<=5;++i){
		dNode *nN = new dNode(i);
		head = insert(head,nN);
	}
	traverse(head);
	return 0;
}
