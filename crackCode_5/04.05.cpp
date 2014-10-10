/*
 Implement a function to check if a binary tree is a binary search tree.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct TreeNode{
	int val;
	TreeNode*left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

struct Status{
	TreeNode *node;
	int status; //initial:0,left visited:1
	Status(TreeNode *n):node(n),status(0){}
};

bool IsBST(TreeNode *root){
	if(root==NULL) return true;
	TreeNode *pre=NULL;
	stack<Status> mark;
	Status ss(root);
	mark.push(ss);
	while(!mark.empty()){
		Status &st = mark.top();
		if(st.status==0){
			st.status=1;
			if(st.node->left!=NULL){
				Status tmp(st.node->left);
				mark.push(tmp);
			}else{
				if(pre==NULL) pre = st.node;
				else if(st.node->val<pre->val) return false;
				mark.pop();
			}
		}else if(st.status==1){
			if(st.node->val<pre->val) return false;
			pre = st.node;
			mark.pop();
			if(st.node->right!=NULL){
				Status tmp(st.node->right);
				mark.push(tmp);
			}
		}
	}
	return true;
}

void inorder(TreeNode *root,vector<int>&mark){
	if(root==NULL) return;
	inorder(root->left,mark);
	mark.push_back(root->val);
	inorder(root->right,mark);
}

bool IsBST2(TreeNode *root){
	vector<int> mark;
	inorder(root,mark);
	for(int i=1;i<mark.size();++i)
		if(mark[i]<mark[i-1]) return false;
	return true;
}

bool IsBST3(TreeNode*root,int& pre){
	if(root==NULL) return true;
	
	if(!IsBST3(root->left,pre)) return false;

	if(root->val<pre) return false;
	pre = root->val;

	if(!IsBST3(root->right,pre)) return false;
	
	return true;
}

bool IsBST3(TreeNode*root){
	int v = INT_MIN;
	return IsBST3(root,v);
}

bool IsBST4(TreeNode*root,int l,int r){
	if(root==NULL) return true;
	if(root->val<=l||root->val>r) return false;
	if(!IsBST4(root->left,l,root->val)) return false;
	if(!IsBST4(root->right,root->val,r)) return false;
	return true;
}

bool IsBST4(TreeNode*root){
	int l=INT_MIN,r=INT_MAX;
	return IsBST4(root,l,r);
}

int main(int argc,char*argv[]){
	TreeNode *root,*left,*right;
	root = new TreeNode(3);
	left = new TreeNode(4);
	right = new TreeNode(5);
	root->left = left;
	root->right = right;
	//if(IsBST(root)) cout << "Is BST" << endl;
	//if(IsBST2(root)) cout << "Is BST" << endl;
	//if(IsBST3(root)) cout << "Is BST" << endl;
	if(IsBST4(root)) cout << "Is BST" << endl;
	else cout << "Not BST" << endl;
	return 0;
}
