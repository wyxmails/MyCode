/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flatten(TreeNode *root) {
        if(root!=NULL) preorder(root);
    }
    TreeNode *preorder(TreeNode *root){
        if(root->left==NULL&&root->right==NULL) return root;
        TreeNode*tail;
        if(root->left!=NULL){
            tail = preorder(root->left);
            tail->right = root->right;
            root->right = root->left;
            root->left = NULL;
            if(tail->right!=NULL) return preorder(tail->right);
            else return tail;
        }
        return preorder(root->right);
    }
};
