#include <iostream>
#include <vector>
using namespace std;
typedef struct TreeNode{
	int v;
	TreeNode*left,*right;
	TreeNode(int value):v(value),left(NULL),right(NULL){}
}TreeNode;

int myMaxH(TreeNode*root,int height);
int getMaxHeight(TreeNode *root){
	if(root==NULL) return 0;
	int height = 1;
	return myMaxH(root,height);
}
int myMaxH(TreeNode*root,int height){
	if(root->left==NULL&&root->right==NULL) return height;
	int l,r;
	l=r=0;
	if(root->left!=NULL){
		l = myMaxH(root->left,height+1);
	}
	if(root->right!=NULL){
		r = myMaxH(root->right,height+1);
	}
	return max(l,r);
}

typedef struct res{
	int maxH;
	int diameter;
}res;


struct res myGetD(TreeNode*root){
	res myRes;
	if(root==NULL){
		myRes.maxH = 0;
		myRes.diameter = 0;
		return myRes;
	}
	res myL,myR;
	myL = myGetD(root->left);
	myR = myGetD(root->right);
	myRes.maxH = max(myL.maxH,myR.maxH)+1;
	myRes.diameter = max(max(myL.diameter,myR.diameter),myL.maxH+myR.maxH+1);
	return myRes;
}
int getDiameter(TreeNode*root){
	res myRes = myGetD(root);
	return myRes.diameter;
}

int main(int argc,char*argv[]){
	TreeNode*root = new TreeNode(1);
	TreeNode*l = new TreeNode(2);
	TreeNode*r = new TreeNode(3);
	root->left = l; root->right = r;
	cout << getMaxHeight(root) << endl;
	TreeNode*n4 = new TreeNode(4);
	TreeNode*n5 = new TreeNode(5);
	TreeNode*n6 = new TreeNode(6);
	TreeNode*n7 = new TreeNode(7);
	TreeNode*n8 = new TreeNode(8);
	l->left = n4;l->right = n5;
	n4->left = n6; n5->right = n7;
	n7->right = n8;
	cout << getDiameter(root) << endl;
	return 0;
}

