#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode*left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
}TreeNode;

TreeNode*myCom(vector<int> &pre,int l1,int r1,vector<int> &post,int l2,int r2){
	if(l1>r1||l2>r2) return NULL;
	TreeNode *root = new TreeNode(pre[l1]);
	if(l1==r1) return root; 
	int i=l2;
	for(;i<r2;++i)
		if(post[i]==pre[l1+1])
			break;
	root->left = myCom(pre,l1+1,l1+i-l2+1,post,l2,i);
	root->right = myCom(pre,l1+i-l2+2,r1,post,i+1,r2-1);
	return root;
}

TreeNode*completeTree(vector<int> &pre,vector<int>& post){
	int n = pre.size();
	return myCom(pre,0,n-1,post,0,n-1);
}

void printTree(TreeNode*root){
	if(root==NULL) return;
	vector<vector<TreeNode*> > vec(2);
	int cur=0,pre=1;
	vec[cur].push_back(root);
	while(!vec[cur].empty()){
		vec[pre].clear();
		cur = !cur;
		pre = !pre;
		for(int i=0;i<vec[pre].size();++i){
			cout << vec[pre][i]->val << " ";
			if(vec[pre][i]->left!=NULL) 
				vec[cur].push_back(vec[pre][i]->left);
			if(vec[pre][i]->right!=NULL)
				vec[cur].push_back(vec[pre][i]->right);
		}
		cout << endl;
	}
}

int main(int argc,char*argv[]){
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	vector<int> v1(9),v2(9);
	for(int i=0;i<9;++i){
		v1[i] = pre[i];
		v2[i] = post[i];
	}
	cout << "print tree: " << endl;
	TreeNode*root = completeTree(v1,v2);
	printTree(root);
	return 0;
}
