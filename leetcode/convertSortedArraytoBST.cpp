/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        return myBST(num,0,n-1);
    }
    TreeNode *myBST(vector<int> &num,int l,int r){
        if(l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = myBST(num,l,mid-1);
        root->right = myBST(num,mid+1,r);
        return root;
    }
};
