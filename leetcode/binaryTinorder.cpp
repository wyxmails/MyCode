#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> vec;
	vec.clear();
	if(root==NULL) return vec;
	stack<TreeNode*> mystack;
	mystack.push(root);
	TreeNode *node;
	while(!mystack.empty()){
		node = mystack.top();
		if(node->left!=NULL){
			mystack.push(node->left);
			node->left = NULL;
		}else{
			vec.push_back(node->val);
			mystack.pop();
			if(node->right!=NULL) mystack.push(node->right);
		}
	}
	return vec;
}
int main(){
	TreeNode *root = new TreeNode(2);
	TreeNode *nnode = new TreeNode(1);
	root->left = nnode;
	nnode = new TreeNode(3);
	root->right = nnode;
	vector<int> vec;
	vec.clear();
	cout << root->val << " " << root->left->val << endl;
	vec =  inorderTraversal(root);
	for(int i=0;i<vec.size();++i)
		cout << vec[i] << " ";
	cout << endl;
	cout << root->val << " " << root->left->val << endl;
}
