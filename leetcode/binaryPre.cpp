/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty()){
            TreeNode *node = myStack.top();
            myStack.pop();
            res.push_back(node->val);
            if(node->right!=NULL) myStack.push(node->right);
            if(node->left!=NULL) myStack.push(node->left);
        }
        return res;
    }
};
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> resL,resR;
        if(root==NULL) return resL;
        resL = preorderTraversal(root->left);
        resR = preorderTraversal(root->right);
        if(resL.size()==0){
            resR.insert(resR.begin(),root->val);
            return resR;
        }
        resL.insert(resL.begin(),root->val);
        resL.insert(resL.end(),resR.begin(),resR.end());
        return resL;
    }
};
