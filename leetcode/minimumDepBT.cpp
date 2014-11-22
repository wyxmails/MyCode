/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        queue<TreeNode*> myQ;
        queue<TreeNode*> myQt;
        myQ.push(root);
        int level = 1;
        while(!myQ.empty()){
            while(!myQ.empty()){
                TreeNode *node = myQ.front();
                myQ.pop();
                if(node->left==NULL&&node->right==NULL) return level;
                if(node->left!=NULL){
                    myQt.push(node->left);
                }
                if(node->right!=NULL){
                    myQt.push(node->right);
                }
            }
            myQ = myQt;
            while(!myQt.empty()){
                myQt.pop();
            }
            level++;
        }
    }
};
 
class Solution2 {
public:
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        int dep = 1;
        queue<TreeNode *> myQ;
        myQ.push(root);
        int pre = 1;
        int cur = 0;
        while(!myQ.empty()){
            TreeNode *tmp = myQ.front();
            myQ.pop(); pre--;
            if(tmp->left==NULL&&tmp->right==NULL) return dep;
            if(tmp->left!=NULL){
                cur++;
                myQ.push(tmp->left);
            }
            if(tmp->right!=NULL){
                cur++;
                myQ.push(tmp->right);
            }
            if(pre==0){
                dep++;
                pre = cur;
                cur = 0;
            }
        }
    }
};


class Solution {
public:
    int minDepth(TreeNode *root) {
        int h=0;
        if(root==NULL) return h;
        vector<TreeNode*> layers[2];
        int cur=0,pre=1;
        layers[cur].push_back(root);
        while(!layers[cur].empty()){
            cur = !cur;
            pre = !pre;
            h++;
            layers[cur].clear();
            for(int i=0;i<layers[pre].size();++i){
                if(layers[pre][i]->left==NULL&&layers[pre][i]->right==NULL)
                    return h;
                if(layers[pre][i]->left!=NULL) layers[cur].push_back(layers[pre][i]->left);
                if(layers[pre][i]->right!=NULL) layers[cur].push_back(layers[pre][i]->right);
            }
        }
    }
};
