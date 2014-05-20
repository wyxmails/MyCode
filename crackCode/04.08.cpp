#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
}TreeNode;

void printPath(int level,vector<int> vec){
	int n = vec.size();
	while(level<n){
		cout << vec[level] << " ";
		level++;
	}
	cout << endl;
}

void sumPath(TreeNode* root,int sum,vector<int> &vec){
	if(root==NULL) return;
	vec.push_back(root->val);
	int level = vec.size()-1;
	int tmp = sum;
	while(level>-1){
		tmp -= vec[level];
		if(tmp==0) printPath(level,vec);
		level--;
	}
	vector<int> vecL;
	vecL.clear();
	vecL.assign(vec.begin(),vec.end());
	sumPath(root->left,sum,vecL);
	vector<int> vecR;
	vecR.clear();
	vecR.assign(vec.begin(),vec.end());
	sumPath(root->right,sum,vecR);
}

int main(int argc,char *argv[]){
	TreeNode* root = new TreeNode(4);
	TreeNode* L1 = new TreeNode(3);
	TreeNode* L2 = new TreeNode(2);
	TreeNode* L3 = new TreeNode(1);
	TreeNode* R1 = new TreeNode(6);
	TreeNode* R2 = new TreeNode(5);
	TreeNode* R3 = new TreeNode(5);
	root->left = L1; L1->left = L2; L2->left = L3;
	root->right = R1; R1->left = R2; R2->right = R3;
	vector<int> vec;
	sumPath(root,10,vec);
	return 0;
}
