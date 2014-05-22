#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> myGen(int l, int r){
	vector<TreeNode*> res;
	if(r<l){
		res.push_back(NULL);
		return res;
	} 
	if(r==l){
		res.push_back(new TreeNode(l));
		return res;
	}
	for(int i=l;i<=r;++i){
		vector<TreeNode*> left,right;
		left = myGen(l,i-1);
		right = myGen(i+1,r);
		for(int j=0;j<left.size();++j){
			for(int k=0;k<right.size();++k){
				TreeNode *root = new TreeNode(i);
				root->left = left[j];
				root->right = right[k];
				res.push_back(root);
			}
		}
	}
	return res;
}
vector<TreeNode *> generateTrees(int n) {
	vector<TreeNode*> res;
	if(n==0){
		res.push_back(NULL);
		return res;
	} 
	for(int i=1;i<=n;++i){
		vector<TreeNode*> left,right;
		left = myGen(1,i-1);
		right = myGen(i+1,n);
		for(int j=0;j<left.size();++j){
			for(int k=0;k<right.size();++k){
				TreeNode *root = new TreeNode(i);
				root->left = left[j];
				root->right = right[k];
				res.push_back(root);
			}
		}
	}
	return res;
}

int main(int argc,char*argv[]){
	return 0;
}
