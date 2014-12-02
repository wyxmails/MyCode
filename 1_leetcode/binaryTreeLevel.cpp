/*
Binary Tree Level Order Traversal II Total Accepted: 24322 Total Submissions: 78827 My Submissions Question Solution 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<TreeNode*> layers[2];
        int cur=0,pre=1;
        layers[cur].push_back(root);
        while(!layers[cur].empty()){
            cur = !cur;
            pre = !pre;
            layers[cur].clear();
            vector<int> mid;
            for(int i=0;i<layers[pre].size();++i){
                mid.push_back(layers[pre][i]->val);
                if(layers[pre][i]->left!=NULL) layers[cur].push_back(layers[pre][i]->left);
                if(layers[pre][i]->right!=NULL) layers[cur].push_back(layers[pre][i]->right);
            }
            res.push_back(mid);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
