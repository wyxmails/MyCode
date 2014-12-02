#include <iostream>
using namespace std;
/*
 Given a binary tree
 
     struct TreeLinkNode {
       TreeLinkNode *left;
       TreeLinkNode *right;
       TreeLinkNode *next;
     }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
Note:
 
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
          1
        /  \
       2    3
      / \  / \
     4  5  6  7
 After calling your function, the tree should look like:
          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \  / \
     4->5->6->7 -> NULL
 */
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
