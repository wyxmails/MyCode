/*
 Implement a function to check if a binary tree is balanced. 
 For the purposes of this question, 
 a balanced tree is defined to be a tree such that 
 the heights of the two subtrees of any node never differ by more than one.
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

struct Result{
	bool balance;
	int height;
};

Result MyBalanced(TreeNode*root){
	Result res,res_left,res_right;
	if(root==NULL){
		res.balance = true;
		res.height = 0;
		return res;
	}
	res_left = MyBalanced(root->left);
	res_right = MyBalanced(root->right);
	if(res_left.balance&&res_right.balance){
		if(abs(res_left.height-res_right.height)>1){
			res.balance = false;
		}else res.balance = true;
		res.height = max(res_left.height,res_right.height);
		return res;
	}
	res.balance = false;
	res.height = max(res_left.height,res_right.height);
	return res;
}

bool IsBalanced(TreeNode*root){
	Result res = MyBalanced(root);
	return res.balance;
}

int GetHeight(TreeNode*root){
	if(root==NULL) return 0;
	int left_height = GetHeight(root->left);
	if(left_height==-1) return -1;
	int right_height = GetHeight(root->right);
	if(right_height==-1) return -1;
	int height_distance = abs(left_height-right_height);
	if(height_distance>1) return -1;
	else return max(left_height,right_height)+1;
}

bool IsBalanced2(TreeNode*root){
	if(GetHeight(root)==-1) return false;
	else return true;
}

int main(int argc,char*argv[]){
	TreeNode*root = new TreeNode(1);
	TreeNode*left = new TreeNode(2);
	TreeNode*right = new TreeNode(3);
	root->left = left;
	root->right = right;
	//if(IsBalanced(root)) cout << "balanced" << endl;
	if(IsBalanced2(root)) cout << "balanced" << endl;
	else cout << "not balanced" << endl;
	return 0;
}
