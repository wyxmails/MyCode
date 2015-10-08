/*
Binary Tree Paths My Submissions Question Solution 
Total Accepted: 16159 Total Submissions: 73007 Difficulty: Easy
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp = "";
        vector<string> res;
        myBi(root,tmp,res);
        return res;
    }
    void myBi(TreeNode* root,string&tmp,vector<string>&res){
        if(root==NULL) return;
        stringstream ss;
        ss.clear();
        string s;
        ss<<root->val;
        ss>>s;
        bool flag = false;
        int len = s.size();
        if(tmp.size()>0){flag = true; tmp += "->";}
        tmp = tmp + s;
        if(root->left==NULL&&root->right==NULL){
            res.push_back(tmp);
            if(flag) tmp.resize(tmp.size()-len-2);
            else tmp.resize(tmp.size()-len);
            return;
        }
        if(root->left!=NULL){
            myBi(root->left,tmp,res);
        }
        if(root->right!=NULL)
            myBi(root->right,tmp,res);
        if(flag) tmp.resize(tmp.size()-len-2);
        else tmp.resize(tmp.size()-len);
    }
};
