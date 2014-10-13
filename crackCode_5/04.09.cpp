/*
 You are given a binary tree in which each node contains a value. 
 Design an algorithm to print all paths which sum to a given value. 
 The path does not need to start or end at the root or a leaf.
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

void MySum(TreeNode *root,int target,vector<int>&mid,vector<vector<int> >&res){
	mid.push_back(root->val);
	int i=mid.size()-1;
	int sum = 0;
	for(;i>=0;--i){
		sum += mid[i];
		if(sum==target){
			vector<int> tmp;
			for(int j=i;j<mid.size();++j)
				tmp.push_back(mid[j]);
			res.push_back(tmp);
		}
	}
	if(root->left!=NULL) MySum(root->left,target,mid,res);
	if(root->right!=NULL) MySum(root->right,target,mid,res);
	mid.pop_back();
}

vector<vector<int> > SumPath(TreeNode *root,int target){
	vector<int> mid;
	vector<vector<int> > res;
	if(root==NULL) return res;
	MySum(root,target,mid,res);
	return res;
}

int main(int argc,char*argv[]){
	//TreeNode *root = new TreeNode(5);
	TreeNode *root = new TreeNode(-5);
	TreeNode *l1 = new TreeNode(4);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *l3 = new TreeNode(-1);
	TreeNode *r1 = new TreeNode(3);
	root->left = l1; l1->left = l2; l2->left = l3;
	l2->right = r1;
	TreeNode *r2 = new TreeNode(6);
	TreeNode *r3 = new TreeNode(8);
	TreeNode *l4 = new TreeNode(7);
	root->right = r2; r2->right = r3; r3->left = l4;
	TreeNode *rr = new TreeNode(10);
	cout << "sum 14 pathes: " << endl;
	vector<vector<int> > res = SumPath(root,14);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "sum 9 pathes: " << endl;
	res = SumPath(root,9);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "sum 5 pathes: " << endl;
	res = SumPath(root,5);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "sum 0 pathes: " << endl;
	res = SumPath(root,0);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
