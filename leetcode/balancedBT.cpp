/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
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
    struct res{
        int h;
        bool b;
    };
    struct res bal(TreeNode *root){
        res lres,rres,cur;
        if(root==NULL){
            lres.h = 0;
            lres.b = true;
            return lres;
        }
        if(root->left==NULL&&root->right==NULL){
            lres.h = 1;
            lres.b = true;
            return lres;
        }
        lres = bal(root->left);
        rres = bal(root->right);
        
        cur.h = max(lres.h,rres.h)+1;
        if(lres.b&&rres.b){
            if(abs(lres.h-rres.h)<=1) cur.b = true;
            else cur.b = false;
        }else cur.b = false;
        return cur;
    }
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root==NULL) return true;
        res lres,rres;
        lres = bal(root->left);
        if(lres.b){
            rres = bal(root->right);
        }else return false;
        if(rres.b){
            if(abs(lres.h-rres.h)<=1) return true;
            else return false;
        }else return false;
    }
};
class Solution2 {
public:
    bool isBalanced(TreeNode *root) {
        if(root==NULL) return true;
        int lH,rH;
        if(!myBalance(root->left,lH)) return false;
        if(!myBalance(root->right,rH)) return false;
        if(abs(lH-rH)<=1) return true;
        return false;
    }
    bool myBalance(TreeNode *root,int& h){
        if(root==NULL){
            h = 0;
            return true;
        }
        int lh,rh;
        if(!myBalance(root->left,lh)) return false;
        if(!myBalance(root->right,rh)) return false;
        if(abs(lh-rh)<=1){
            h = max(lh,rh)+1;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int h=0;
        return balance(root,h);
    }
    bool balance(TreeNode*root,int &h){
        if(root==NULL){
            h=0;
            return true;
        }
        int hl,hr;
        if(balance(root->left,hl)&&balance(root->right,hr)){
            h = max(hl,hr)+1;
            return (abs(hl-hr)<=1);
        }
        return false;
    }
};
