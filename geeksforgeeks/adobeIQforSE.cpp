/*
 Given a BST, write a program to find kth largest node. 
 */
#include <iostream>
#include <stack>
using namespace std;
// in order traverse the tree, and count the number until k.
// need a stack to reverse the count increase sequence.
// kth smallest
struct TreeNode{
	int val;
	TreeNode*left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode *findKthBST(TreeNode*root,int k){
	if(root==NULL||k==0) return root;
	stack<TreeNode*> myS;
	int count=0;
	myS.push(root);
	TreeNode*cur = NULL;
	while(!myS.empty()&&count<k){
		cur = myS.top();
		if(cur->left!=NULL){
			myS.push(cur->left);
			cur->left = NULL;
		}else{
			count++;
			myS.pop();
			if(cur->right!=NULL) 
				myS.push(cur->right);
		}
	}
	return cur;
}
// solution do not change the tree
// kth largest
struct NodeStatus{
	TreeNode *node;
	int status;
	NodeStatus():node(NULL),status(0){}
};
TreeNode *findKthBST2(TreeNode*root,int k){
	if(root==NULL||k==0) return root;
	stack<NodeStatus> myS;
	NodeStatus ns;
	ns.node = root;
	myS.push(ns);
	int count=0;
	TreeNode *cur = NULL;
	while(!myS.empty()&&count<k){
		NodeStatus &nsCur = myS.top();
		cur = nsCur.node;
		if(nsCur.status==0){
			nsCur.status = 1;
			if(cur->right!=NULL){
				ns.node = cur->right; ns.status = 0;
				myS.push(ns);
			}
		}else{
			count++;
			myS.pop();
			if(cur->left!=NULL){
				ns.node = cur->left; ns.status = 0;
				myS.push(ns);
			}
		}
	}
	return cur;
}

int main(int argc,char*argv[]){
	TreeNode* root = new TreeNode(5);
	TreeNode* left = new TreeNode(3);
	TreeNode* right = new TreeNode(7);
	root->left = left; root->right = right;
	TreeNode *l1 = new TreeNode(1);
	TreeNode *r1 = new TreeNode(4);
	TreeNode *r2 = new TreeNode(2);
	left->left = l1; left->right = r1; l1->right = r2;
	TreeNode *r3 = new TreeNode(8);
	TreeNode *l2 = new TreeNode(6);
	right->left = l2; right->right = r3;
	TreeNode *res = findKthBST2(root,2);
	if(res!=NULL) cout << "2nd: " << res->val << endl;
	res = findKthBST2(root,5);
	if(res!=NULL) cout << "5th: " << res->val << endl;
	res = findKthBST2(root,6);
	if(res!=NULL) cout << "6th: " << res->val << endl;
	return 0;
}
