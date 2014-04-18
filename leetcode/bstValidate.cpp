/*Validate Binary Search Tree
   Assume a BST is defined as follows:
 The left subtree of a node 
 contains only nodes with keys less than the node's key.
 The right subtree of a node contains 
 only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 confused what "{1,#,2,3}" means? > 
 read more on how binary tree is serialized on OJ.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isval(TreeNode*root,int min,int max){
    if(root==NULL) return true;
    if(root->val<=min||root->val>=max) return false;
    return isval(root->left,min,root->val)
        &&isval(root->right,root->val,max);
}
bool isValidBST(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int min= -(1<<31);
    int max= 1<<31-1;
    return isval(root,min,max);
}
