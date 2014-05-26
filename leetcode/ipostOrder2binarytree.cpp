#include <iostream>
#include <vector>
using namespace std;
/*
 Given inorder and postorder traversal of a tree, construct the binary tree.
 
Note:
 You may assume that duplicates do not exist in the tree.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *myBuild(const vector<int> &inorder, int s1, const vector<int> &postorder,int s2,int n) {
	if(n<=0) return NULL;
	TreeNode *root = new TreeNode(postorder[s2+n-1]);
	int i=s1;
	for(;i<s1+n;++i){
		if(inorder[i]==postorder[s2+n-1]) break;
	}
	root->left = myBuild(inorder,s1,postorder,s2,i-s1);
	root->right = myBuild(inorder,i+1,postorder,s2+i-s1,n-i+s1-1);
	return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	int n = inorder.size();
	return myBuild(inorder,0,postorder,0,n);
}
int main(int argc,char*argv[]){
	return 0;
}
