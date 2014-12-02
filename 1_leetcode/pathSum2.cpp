/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        if(root->left==NULL&&root->right==NULL){
            if(root->val==sum){
                vector<int> vec;
                vec.push_back(root->val);
                res.push_back(vec);
            }
            return res;
        }
        if(root->left!=NULL){
            res = pathSum(root->left,sum-root->val);
            for(int i=0;i<res.size();++i){
                res[i].insert(res[i].begin(),root->val);
            }
        }
        vector<vector<int> > resR;
        if(root->right!=NULL){
            resR = pathSum(root->right,sum-root->val);
            for(int i=0;i<resR.size();++i){
                resR[i].insert(resR[i].begin(),root->val);
            }
            res.insert(res.end(),resR.begin(),resR.end());
        }
        return res;
    }
};
class Solution2 {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<int> mid;
        mySum(root,sum,mid,res);
        return res;
    }
    void mySum(TreeNode *root, int sum,vector<int>&mid,vector<vector<int> >&res){
        sum -= root->val;
        mid.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==0) res.push_back(mid);
            mid.pop_back();
            return;
        }
        if(root->left!=NULL)
            mySum(root->left,sum,mid,res);
        if(root->right!=NULL)
            mySum(root->right,sum,mid,res);
        sum += root->val;
        mid.pop_back();
    }
};
