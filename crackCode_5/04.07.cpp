/*
 Design an algorithm and write code to find 
 the first common ancestor of two nodes in a binary tree.
 Avoid storing additional nodes in a data structure.
 NOTE: This is not necessarily a binary search tree.
 */
#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

struct Result{
	int num_found;
	TreeNode *ancestor;
	Result(TreeNode *root):num_found(0),ancestor(root){}
};

Result* MyCom(TreeNode*root,TreeNode*n1,TreeNode*n2){
	Result *res = new Result(root);
	if(root==NULL) return res;
	if(root==n1&&root==n2){
		res->num_found=2;
		return res;
	}
	Result *res_left = MyCom(root->left,n1,n2);
	if(res_left->num_found==2) return res_left;
	res->num_found = res_left->num_found;
	if(root==n1||root==n2)
		res->num_found++;
	if(res->num_found==2) return res;
	Result *res_right = MyCom(root->right,n1,n2);
	if(res_right->num_found==2) return res_right;
	res->num_found += res_right->num_found;
	return res;
}

TreeNode* CommonAncestor(TreeNode* root,TreeNode *n1,TreeNode *n2){
	Result *res = MyCom(root,n1,n2);
	if(res->num_found==2) return res->ancestor;
	else return NULL;
}

int main(int argc,char*argv[]){
	TreeNode *root = new TreeNode(5);
	TreeNode *l1 = new TreeNode(3);
	TreeNode *l2 = new TreeNode(1);
	TreeNode *r1 = new TreeNode(2);
	TreeNode *r2 = new TreeNode(4);
	root->left = l1;
	l1->left = l2;l1->right = r2;
	l2->right = r1;
	TreeNode *r3 = new TreeNode(7);
	TreeNode *l3 = new TreeNode(6);
	root->right = r3;
	r3->left = l3;
	TreeNode *res = CommonAncestor(root,l1,l2);
	if(res!=NULL)
		cout << l1->val << " and " << l2->val << "'s ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;
	res = CommonAncestor(root,l1,l3);
	if(res!=NULL)
		cout << l1->val << " and " << l3->val << "'s ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;
	res = CommonAncestor(root,r1,l2);
	if(res!=NULL)
		cout << r1->val << " and " << l2->val << "'s ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;
	res = CommonAncestor(root,r2,r1);
	if(res!=NULL)
		cout << r2->val << " and " << r1->val << "'s ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;
	res = CommonAncestor(root,r2,root);
	if(res!=NULL)
		cout << r2->val << " and " << root->val << "'s ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;	
	res = CommonAncestor(root,r2,NULL);
	if(res!=NULL)
		cout << r2->val << " and NULL's ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;	
	res = CommonAncestor(root,r2,r2);
	if(res!=NULL)
		cout << r2->val << " and " << r2->val << "'s ancestor is " << res->val << endl;
	else cout << "Not Found" << endl;	
	return 0;
}

