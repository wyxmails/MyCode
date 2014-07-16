/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

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
    struct com{
        int l;
        int r;
        int Max;
        com():Max(0),l(0),r(0){}
    };
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;
        com res = myMax(root);
        return res.Max;
    }
    com myMax(TreeNode *root){
        com res,rl,rr;
        res.l = res.r = res.Max = root->val;
        if(root->left==NULL&&root->right==NULL) return res;
        if(root->left!=NULL){
            rl = myMax(root->left);
            res.l = max(res.l,max(rl.l,rl.r)+res.l);
            res.Max = max(max(rl.Max,res.l),res.Max);
        } 
        if(root->right!=NULL){
            rr = myMax(root->right);
            res.r = max(res.r,max(rr.l,rr.r)+res.r);
            res.Max = max(max(rr.Max,res.r),res.Max);
        }
        res.Max = max(res.Max,res.r+res.l-root->val);
        return res;
    }
};
