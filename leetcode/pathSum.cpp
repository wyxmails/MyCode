/*Path Sum
 Given a binary tree and a sum, 
 determine if the tree has a root-to-leaf path 
 such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \      \
         7    2      1
 return true, 
 as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(root==NULL) return false;
	sum -= root->val;
	if(sum==0){
		if(root->left==NULL&&root->right==NULL) return true;
	}
	if(root->left!=NULL)
		if(hasPathSum(root->left,sum)) return true;
	if(root->right!=NULL)
		return hasPathSum(root->right,sum);
	return false;
}


class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        int cur = 0;
        return mySum(root,cur,sum);
    }
    bool mySum(TreeNode *root, int cur, int sum){
        cur += root->val;
        if(root->left==NULL&&root->right==NULL) return cur==sum;
        if(root->left!=NULL&&mySum(root->left,cur,sum))
            return true;
        if(root->right!=NULL&&mySum(root->right,cur,sum))
            return true;
        cur -= root->val;
        return false;
    }
};
