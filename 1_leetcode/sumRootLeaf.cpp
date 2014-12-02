/*
Sum Root to Leaf Numbers Total Accepted: 19885 Total Submissions: 66758 My Submissions
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root==NULL) return 0;
        return mysum(root,0);
    }
    int mysum(TreeNode *root,int cnt){
        int l=0,r=0;
        if(root->left==NULL&&root->right==NULL){
            return cnt*10 +root->val;
        }
        cnt = cnt*10+root->val;
        if(root->left!=NULL){
            l = mysum(root->left,cnt);
        }
        if(root->right!=NULL){
            r = mysum(root->right,cnt);
        }
        return l+r;
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        int res=0;
        int mid=0;
        if(root==NULL) return res;
        mySum(root,mid,res);
        return res;
    }
    void mySum(TreeNode *root,int&mid,int&res){
        mid = mid*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            res += mid;
            mid /=10;
            return;
        }
        if(root->left!=NULL) mySum(root->left,mid,res);
        if(root->right!=NULL) mySum(root->right,mid,res);
        mid /= 10;
    }
};
