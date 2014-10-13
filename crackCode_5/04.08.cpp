/*
 You have two very large binary trees: 
 Tl, with millions of nodes, 
 and T2, with hundreds of nodes.
 Create an algorithm to decide if T2 is a subtree of Tl.
 A tree T2 is a subtree of Tl if 
 there exists a node n in Tl such that the subtree of n is identical to T2.
 That is, if you cut off the tree at node n, 
 the two trees would be identical.
 */
#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

bool IsSameTree(TreeNode *t1,TreeNode *t2){
	if(t1==NULL&&t2==NULL) return true;
	if(t1==NULL||t2==NULL) return false;
	if(t1->val!=t2->val) return false;
	return IsSameTree(t1->left,t2->left)&&IsSameTree(t1->right,t2->right);
}

bool IsSubtree(TreeNode *T1,TreeNode *T2){
	if(T2==NULL) return true;
	if(T1==NULL) return false;
	if(T1==T2) return true;
	if(T1->val==T2->val){
		if(IsSameTree(T1,T2))
			return true;
	}
	return IsSubtree(T1->left,T2)||IsSubtree(T1->right,T2);
}

int main(int argc,char*argv[]){
	TreeNode *root = new TreeNode(5);
	TreeNode *l1 = new TreeNode(4);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *l3 = new TreeNode(1);
	TreeNode *r1 = new TreeNode(3);
	root->left = l1; l1->left = l2; l2->left = l3;
	l2->right = r1;
	TreeNode *r2 = new TreeNode(6);
	TreeNode *r3 = new TreeNode(8);
	TreeNode *l4 = new TreeNode(7);
	root->right = r2; r2->right = r3; r3->left = l4;
	TreeNode *rr = new TreeNode(10);
	if(IsSubtree(root,l3)) cout << "Is subtree" << endl;
	else cout << "Not subtree" << endl;
	if(IsSubtree(root,rr)) cout << "Is subtree" << endl;
	else cout << "Not subtree" << endl;
	if(IsSubtree(l1,r3)) cout << "Is subtree" << endl;
	else cout << "Not subtree" << endl;
	if(IsSubtree(r2,l4)) cout << "Is subtree" << endl;
	else cout << "Not subtree" << endl;
	return 0;
}
