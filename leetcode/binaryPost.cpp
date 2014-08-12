/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    struct Status{
        TreeNode *node;
        int st;
    };
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        if(root==NULL) return res;
        stack<Status> myS;
        Status st;
        st.node = root;
        st.st = 0;
        myS.push(st);
        while(!myS.empty()){
            Status &stt = myS.top();
            if(stt.st==0){
                Status st1;
                if(stt.node->right!=NULL){
                    st1.node = stt.node->right;
                    st1.st = 0;
                    myS.push(st1);
                }
                if(stt.node->left!=NULL){
                    st1.node = stt.node->left;
                    st1.st = 0;
                    myS.push(st1);
                }
                stt.st = 1;
            }else{
                res.push_back(stt.node->val);
                myS.pop();
            }
        }
        return res;
    }
};
 
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> resL,resR;
        if(root==NULL) return resL;
        resL = postorderTraversal(root->left);
        resR = postorderTraversal(root->right);
        if(resL.size()==0){
            resR.push_back(root->val);
            return resR;
        }
        resL.insert(resL.end(),resR.begin(),resR.end());
        resL.push_back(root->val);
        return resL;
    }
};
