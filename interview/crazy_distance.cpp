/*
 This Question was asked to me at the Google interview. I could do it O(n*n) ... Can I do it in better time. A string can be formed only by 1 and 0.

Definition:

X & Y are strings formed by 0 or 1

D(X,Y) = Remove the things common at the start from both X & Y. Then add the remaining lengths from both the strings.

For e.g.

D(1111, 1000) = Only First alphabet is common. So the remaining string is 111 & 000. Therefore the result length("111") & length("000") = 3 + 3 = 6

D(101, 1100) = Only First two alphabets are common. So the remaining string is 01 & 100. Therefore the result length("01") & length("100") = 2 + 3 = 5

It is pretty that obvious that do find out such a crazy distance is going to be linear. O(m).

Now the question is

given n input, say like

1111
1000
101
1100
Find out the maximum crazy distance possible.

n is the number of input strings. m is the max length of any input string.

The solution of O(n2 * m) is pretty simple. Can it be done in a better way? Let's assume that m is fixed. Can we do this in better than O(n^2) ?

 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	char c;
	int cnt;
	TreeNode *left,*right;
	TreeNode(char c,int cnt):c(c),cnt(cnt),left(NULL),right(NULL){}
};

void buildTree(const string &S,int cur,int m, TreeNode*root){
	if(cur>=m) return;
	if(S[cur]=='0'){
		if(root->left==NULL)
			root->left = new TreeNode('0',0);
		root->left->cnt++;
		buildTree(S,cur+1,m,root->left);
	}else{
		if(root->right==NULL)
			root->right = new TreeNode('1',0);
		root->right->cnt++;
		buildTree(S,cur+1,m,root->right);
	}
}

int maxDiameter(TreeNode *root,int &maxi){
	if(root==NULL) return 0;
	int left = maxDiameter(root->left,maxi);
	int right = maxDiameter(root->right,maxi);
	if(left!=0&&right!=0) maxi = max(maxi,left+right);
	if(left!=0||right!=0){
		if(left==0&&root->right->cnt==1) maxi = max(maxi,left+right);
		else if(right==0&&root->left->cnt==1) maxi = max(maxi,left+right);
	}
	return max(left,right)+1;
}

int CrazyDis(vector<string> vec){
	TreeNode *root = new TreeNode(' ',0);
	int n = vec.size();
	for(int i=0;i<n;++i)
		buildTree(vec[i],0,vec[i].size(),root);
	int maxi=0;
	maxDiameter(root,maxi);
	return maxi;
}

int main(int argc,char*argv[]){
	//string arr[] = {"001","1111","1000","101","1100"};
	//string arr[] = {"",""};
	//string arr[] = {"1","1"};
	string arr[] = {"10","1"};
	vector<string> vec;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
		vec.push_back(arr[i]);
	cout << CrazyDis(vec) << endl;
	return 0;
}
