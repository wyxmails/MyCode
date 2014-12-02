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



typedef struct res{
    int maxSum;
    int maxH;
 }res;
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;
        res myRes = myMax(root);
        return myRes.maxSum;
    }
    res myMax(TreeNode*root){
        res myRes,myL,myR;
        myRes.maxSum = root->val;
        myRes.maxH = root->val;
        if(root->left==NULL&&root->right==NULL) return myRes;
        if(root->left!=NULL){
            myL = myMax(root->left);
            myRes.maxH = max(myL.maxH+root->val,myRes.maxH);
            myRes.maxSum = max(myRes.maxH,myL.maxSum);
        }
        if(root->right!=NULL){
            myR = myMax(root->right);            
            myRes.maxSum = max(max(myR.maxSum,myRes.maxSum),myRes.maxH+myR.maxH);
            myRes.maxH = max(myRes.maxH,root->val+myR.maxH);
        }
        return myRes;
    }
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;
        int res=root->val;
        myMax(root,res);
        return res;
    }
    int myMax(TreeNode*root,int &res){
        if(root->left==NULL&&root->right==NULL){
            res = max(root->val,res);
            return root->val;
        }
        int hL=0,hR=0;
        if(root->left!=NULL) hL = myMax(root->left,res);
        if(root->right!=NULL) hR = myMax(root->right,res);
        int h = max(root->val,max(hL,hR)+root->val);
        int cur = max(h,root->val+hL+hR);
        res = max(res,cur);
        return h;
    }
};
