#include <iostream>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode *left,*right,*parent;
	TreeNode(int v){
		val = v;
		left=right=parent=NULL;
	}
}TreeNode;

TreeNode* findLmost(TreeNode*cur){
	while(cur->left!=NULL) cur = cur->left;
	return cur;
}

TreeNode* nextNode(TreeNode*cur){
	TreeNode *n;
	if(cur==NULL) return NULL;
	else if(cur->right!=NULL){
		n = findLmost(cur->right);
	}else{
		while((n=cur->parent)!=NULL){
			if(n->left==cur){
				break;
			}
			cur = n;
		}
	}
	return n;
}

int main(int argc,char *argv[]){
	TreeNode*root = new TreeNode(3);
	TreeNode*left = new TreeNode(1);
	TreeNode*right = new TreeNode(2);
	root->left = left;
	left->parent = root;
	left->right = right;
	right->parent = left;
	TreeNode *tmp = nextNode(right);
	cout << tmp->val << endl;
	return 0;
}
