#include <iostream>
using namespace std;

struct tNode{
	int val;
	tNode*left;
	tNode*right;
};

tNode* getChild(int in[],int pre[],int sin,int ein,int rootpos){
	int pos;
	tNode *root;
	root = NULL;
	if(ein<sin) return root;
	root = new tNode;
	root->val = pre[rootpos];
	for(int i=sin;i<=ein;++i){
		if(in[i]==root->val){
			pos = i;
			break;
		}
	}
	root->left = getChild(in,pre,sin,pos-1,rootpos+1);
	root->right = getChild(in,pre,pos+1,ein,rootpos+pos+1-sin);
	return root;
}

tNode* buildT(int in[],int pre[],int n){
	tNode *root,*tmp;
	int pos;
	root=tmp=NULL;
	root = new tNode;
	root->val = pre[0];
	for(int i=0;i<n;++i){
		if(in[i]==root->val){
			pos = i;
			break;
		}
	}
	root->left = getChild(in,pre,0,pos-1,1);
	root->right = getChild(in,pre,pos+1,n-1,pos+1);
	return root;
}
void inprint(tNode*root){
	tNode*left,*right;
	left = root->left;
	right = root->right;
	if(left!=NULL) inprint(left);
	cout << root->val << " ";
	if(right!=NULL) inprint(right);
}
void delT(tNode*root){
	tNode*left,*right;
	left = root->left;
	right = root->right;
	if(left!=NULL) delT(left);
	if(right!=NULL) delT(right);
	root->left = NULL;
	root->right = NULL;
	delete(root);	
}
int main(int argc,char*argv[]){
	int n = 5;
	int in[5] = {1,2,3,4,5};
	int pre[5] = {3,1,2,4,5};
	tNode *root;
	root = buildT(in,pre,n);
	inprint(root);
	cout << endl;
	delT(root);
	return 0;
}
