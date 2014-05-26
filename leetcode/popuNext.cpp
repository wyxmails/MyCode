#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if(root==NULL) return;
	TreeLinkNode *p = NULL;
	TreeLinkNode *c1=root,*c2=root;//current level
	TreeLinkNode *d1;//next level
	while(c1!=NULL){
		d1 = c1->left;
		if(p==NULL){//root
			c2->next = NULL;
		}else{
			while(c2!=NULL){
				if(p->right==c2){//right child
					if(p->next==NULL) c2->next=NULL; //right most
					else{
						p = p->next;
						c2->next = p->left;
					}
				}else{//left child's next is right child
					c2->next = p->right;
				}
				c2 = c2->next; //travers this level
			}
		}
		p = c1;
		c1 = c2 = d1;
	}
}
int main(int argc,char*argv[]){
	return 0;
}
