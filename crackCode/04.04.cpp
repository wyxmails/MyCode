#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
}TreeNode;

void linkTree(TreeNode *root,vector<list<TreeNode*> > &vecLink){
	if(root==NULL) return;
	list<TreeNode*> l;
	l.push_back(root);
	vecLink.push_back(l);
	int level = 0;
	cout << "1" << endl;
	while(level<vecLink.size()){
		list<TreeNode*>::iterator it = vecLink[level].begin();
		list<TreeNode*> l1;
		l1.clear();
	cout << "2" << endl;
		while(it!=vecLink[level].end()){
			TreeNode *tmp = *it;
			if(tmp->left!=NULL)	l1.push_back(tmp->left);
			if(tmp->right!=NULL) l1.push_back(tmp->right);
			it++;
		}
		if(l1.size()) vecLink.push_back(l1);
		level++;
	}
	cout << "3" << endl;
}

int main(int argc,char*argv[]){
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	root->left = left;
	root->right = right;
	vector<list<TreeNode*> > vec;
	cout << "before: " << endl;
	linkTree(root,vec);
	cout << "after: " << endl;
	list<TreeNode*>::iterator it;
	int level = 0;
	while(level<vec.size()){
		it = vec[level].begin();
		while(it!=vec[level].end()){
			cout << (*it)->val << " ";
			it++;
		}
		cout << endl;
		level++;
	}
	return 0;
}
