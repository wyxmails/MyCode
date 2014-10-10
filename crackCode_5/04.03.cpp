/*
 Given a sorted (increasing order) array with unique integer elements, 
 write an algo- rithm to create a binary search tree with minimal height.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode*CreateMinimalTree(const vector<int>&vec,int l,int r){
	if(r<l) return NULL;
	int mid = (l+r)/2;
	TreeNode *root = new TreeNode(vec[mid]);
	root->left = CreateMinimalTree(vec,l,mid-1);
	root->right = CreateMinimalTree(vec,mid+1,r);
	return root;
}

TreeNode* CreateMinimalTree(const vector<int> &vec){
	return CreateMinimalTree(vec,0,vec.size()-1);
}

void PrintTree(TreeNode *root){
	if(root==NULL) return ;
	PrintTree(root->left);
	cout << root->val << " ";
	PrintTree(root->right);
}

int main(int argc,char*argv[]){
	vector<int> vec;
	int pre=0,cur;
	srand(time(NULL));
	for(int i=0;i<10;++i){
		int cur = rand()%10+1;
		cur += pre;
		vec.push_back(cur);
		cout << cur << " ";
		pre = cur;
	}
	cout << endl;
	TreeNode *root = CreateMinimalTree(vec);
	PrintTree(root);
	cout << endl;
	return 0;
}
