/*
 Write an algorithm to find the 'next'node 
 (i.e., in-order successor) of a given node in a binary search tree. 
 You may assume that each nodehas a link to its parent.
 */

#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right,*parent;
	TreeNode(int v):val(v),left(NULL),right(NULL),parent(NULL){}
};

TreeNode* GetNext(TreeNode*cur_node){
	if(cur_node==NULL) return NULL;
	if(cur_node->right==NULL){
		while(cur_node->parent!=NULL&&cur_node->parent->left!=cur_node)
			cur_node = cur_node->parent;
		return cur_node->parent;
	}
	TreeNode *right = cur_node->right;
	while(right->left!=NULL) right = right->left;
	return right;
}

int main(int argc,char*argv[]){
	TreeNode *root = new TreeNode(5);
	TreeNode *l1 = new TreeNode(3);
	TreeNode *l2 = new TreeNode(1);
	TreeNode *r1 = new TreeNode(2);
	TreeNode *r2 = new TreeNode(4);
	root->left = l1; l1->parent = root;
	l1->left = l2;l1->right = r2;l2->parent = l1;r2->parent = l1;
	l2->right = r1;r1->parent = l2;
	TreeNode *r3 = new TreeNode(7);
	TreeNode *l3 = new TreeNode(6);
	root->right = r3;r3->parent = root;
	r3->left = l3;l3->parent = r3;
	TreeNode *res = GetNext(l1);
	if(res!=NULL)
		cout << l1->val << "'s next: " << res->val << endl;
	else
		cout << l1->val << "'s next: NULL " << endl;
	res = GetNext(l2);
	if(res!=NULL)
		cout << l2->val << "'s next: " << res->val << endl;
	else
		cout << l2->val << "'s next: NULL " << endl;
	res = GetNext(l3);
	if(res!=NULL)
		cout << l3->val << "'s next: " << res->val << endl;
	else
		cout << l3->val << "'s next: NULL " << endl;
	res = GetNext(r1);
	if(res!=NULL)
		cout << r1->val << "'s next: " << res->val << endl;
	else
		cout << r1->val << "'s next: NULL " << endl;
	res = GetNext(r2);
	if(res!=NULL)
		cout << r2->val << "'s next: " << res->val << endl;
	else
		cout << r2->val << "'s next: NULL " << endl;
	res = GetNext(r3);
	if(res!=NULL)
		cout << r3->val << "'s next: " << res->val << endl;
	else
		cout << r3->val << "'s next: NULL " << endl;
	res = GetNext(root);
	if(res!=NULL)
		cout << root->val << "'s next: " << res->val << endl;
	else
		cout << root->val << "'s next: NULL " << endl;
}
