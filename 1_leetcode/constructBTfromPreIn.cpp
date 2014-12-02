#include <iostream>
#include <vector>
using namespace std;
/*
 Given preorder and inorder traversal of a tree, construct the binary tree.
 
Note:
 You may assume that duplicates do not exist in the tree.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *myBuild(vector<int> &preorder,int s1, vector<int> &inorder,int s2,int n){
	if(n<=0) return NULL;
	TreeNode *root = new TreeNode(preorder[s1]);
	int i=s2;
	for(;i<s2+n;++i){
		if(inorder[i]==preorder[s1]) break;
	}
	root->left = myBuild(preorder,s1+1,inorder,s2,i-s2);
	root->right = myBuild(preorder,s1+i-s2+1,inorder,i+1,n-i+s2-1);
	return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	int n = preorder.size();
	return myBuild(preorder,0,inorder,0,n);
}
int main(int argc,char*argv[]){
	return 0;
}


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
    TreeNode *build(vector<int>&pre,int lp,int rp,vector<int>&in,int li,int ri){
        if(lp>rp||li>ri) return NULL;
        TreeNode *root = new TreeNode(pre[lp]);
        int i = li;
        for(;i<=ri;++i){
            if(in[i]==pre[lp]) break;
        }
        root->left = build(pre,lp+1,lp+i-li,in,li,i-1);
        root->right = build(pre,lp+i-li+1,rp,in,i+1,ri);
        return root;
    }
};
