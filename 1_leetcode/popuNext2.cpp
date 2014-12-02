#include <iostream>
using namespace std;
/*
 Follow up for problem "Populating Next Right Pointers in Each Node".
 
 What if the given tree could be any binary tree? Would your previous solution still work?
 
Note:
 
 You may only use constant extra space.
 For example,
 Given the following binary tree,
          1
        /  \
       2    3
      / \    \
     4   5    7
 After calling your function, the tree should look like:
          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \    \
     4-> 5 -> 7 -> NULL
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void myCon(TreeLinkNode *root,TreeLinkNode *p){
	if(root==NULL) return;
	if(p==NULL) root->next = NULL;
	TreeLinkNode *c = root;
	while(p!=NULL){  //process current level
		if(c==p->left){
			if(p->right!=NULL){
				c->next = p->right;
				c = c->next;
			}else p = p->next;
		}else if(c==p->right) p = p->next;
		else{
			if(p->left!=NULL){
				c->next = p->left;
				c = c->next;
			}else if(p->right!=NULL){
				c->next = p->right;
				c = c->next;
			}else p = p->next;
		}
		if(c==NULL) break;
	}
	TreeLinkNode*nx = NULL;
	while(root!=NULL&&nx==NULL){ //find the next start
		if(root->left!=NULL) nx = root->left;
		else if(root->right!=NULL) nx = root->right;
		else root = root->next;
	}
	if(nx!=NULL)
		myCon(nx,root);
}
void connectRecurse(TreeLinkNode *root) {
TreeLinkNode *p = NULL;
myCon(root,p);
}

void connectIte(TreeLinkNode *root) {
	if(root==NULL) return;
	TreeLinkNode *c1,*c2,*d1,*p;
	p = NULL;
	c1=c2=root;
	while(c1!=NULL){
		if(c1->left!=NULL) d1 = c1->left;
		else if(c1->right!=NULL) d1 = c1->right;
		else d1 = NULL;
		while(c2!=NULL){ //current level
			if(d1==NULL){
				if(c2->left!=NULL){
					d1 = c2->left;
					c1 = c2;
				}else if(c2->right!=NULL){
					d1 = c2->right;
					c1 = c2;
				} 
			}
			if(p==NULL){
				c2->next = NULL;
			}else{
				if(c2==p->right){
					if(p->next==NULL) c2->next = NULL;
					else{
						while(p->next!=NULL){
							p = p->next;
							if(p->left!=NULL){
								c2->next = p->left;
								break;
							}else if(p->right!=NULL){
								c2->next = p->right;
								break;
							}
						}
					}
				}else{
					if(p->right!=NULL){
						c2->next = p->right;
					}else{
						while(p->next!=NULL){
							p = p->next;
							if(p->left!=NULL){
								c2->next = p->left;
								break;
							}else if(p->right!=NULL){
								c2->next = p->right;
								break;
							}
						}
					}
				}
			}
			c2 = c2->next;
		}
		p = c1;
		c1 = c2 = d1;
	}
}

void connect2(TreeLinkNode *root) {
        TreeLinkNode *next,*p,*cur=root;
        next=p=NULL;
        while(cur!=NULL){
            TreeLinkNode *sub = getSub(cur);
            if(sub!=NULL){
                if(next==NULL){
                    next = sub;
                    p = sub;
                }else p->next = sub;
                while(p->next!=NULL) p = p->next;
            }
            cur = cur->next;
            if(cur==NULL){
                cur = next;
                next = NULL;
            }
        }
}
TreeLinkNode *getSub(TreeLinkNode *root){
        if(root->left!=NULL&&root->right!=NULL)
            root->left->next = root->right;
        if(root->left!=NULL) return root->left;
        if(root->right!=NULL) return root->right;
        return NULL;
}

int main(int argc,char *argv[]){
	return 0;
}
