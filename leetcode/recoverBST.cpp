#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> vec;
TreeNode* pre;
void inorder(TreeNode *root){
	if(root==NULL) return;
	inorder(root->left);
	if(pre!=NULL&&root->val<pre->val){
		bool f=false;
		for(int i=0;i<vec.size();++i){
			if(vec[i]->val==pre->val){
				f = true;
				break;
			}
		}
		if(!f) vec.push_back(pre);
		f=false;
		for(int i=0;i<vec.size();++i){
			if(vec[i]->val==root->val){
				f=true;
			break;
			}
		}
		if(!f) vec.push_back(root);
	}
	pre = root;
	inorder(root->right);
}

void recoverTree(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(root==NULL) return;
	pre = NULL;
	vec.clear();
	inorder(root);
	int val = vec.at(0)->val;
	vec[0]->val = vec[vec.size()-1]->val;
	vec[vec.size()-1]->val = val;
}
void printTree(TreeNode*root){
	if(root==NULL) return;
	printTree(root->left);
	cout << root->val << " " ;
	printTree(root->right);
}
int main(){
	TreeNode *root = new TreeNode(2);
	TreeNode *nnode = new TreeNode(1);
	root->right = nnode;
	//nnode = new TreeNode(1);
	//root->left->left = nnode;
	printTree(root);
	cout << endl;
	recoverTree(root);
	printTree(root);
	cout << endl;
	return 0;
}
