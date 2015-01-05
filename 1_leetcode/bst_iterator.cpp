/*
Binary Search Tree Iterator Total Accepted: 2400 Total Submissions: 8344 My Submissions Question Solution 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
            TreeNode *run = root;
            while(run!=NULL){
                ms.push(run);
                run = run->left;
            }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(ms.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = ms.top();
        ms.pop();
        v = cur->val;
        cur = cur->right;
        while(cur!=NULL){
            ms.push(cur);
            cur = cur->left;
        }
        return v;
    }
private:
    stack<TreeNode*> ms;
    int v;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
