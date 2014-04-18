/*Symmetric Tree
 Given a binary tree, check whether it is a mirror of itself 
 (ie, symmetric around its center).
 For example, this binary tree is symmetric:
 
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
 
     1
    / \
   2   2
    \   \
    3    3
Note:
 Bonus points if you could solve it both recursively and iteratively.
 OJ's Binary Tree Serialization:
 The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 Here's an example:
 
    1
   / \
  2   3
     /
    4
     \
      5
 The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//recursive version
bool isSym(TreeNode *l,TreeNode*r){
	if(l==NULL&&r==NULL) return true;
	if(l==NULL||r==NULL) return false;
	if(l->val!=r->val) return false;
	return isSym(l->left,r->right)&&isSym(l->right,r->left);
}
bool isSymmetric(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(root==NULL) return true;
	return isSym(root->left,root->right);
}
bool isSymmetricIteratively(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(root==NULL) return true;
	queue<TreeNode*> lt,rt;
	lt.push(root->left);
	rt.push(root->right);
	TreeNode *l,*r;
	while(!lt.empty()&&!rt.empty()){
		l = lt.front();
		r = rt.front();
		lt.pop();
		rt.pop();
		if(l==NULL&&r==NULL) continue;
		if(l==NULL||r==NULL) return false;
		if(l->val!=r->val) return false;
		lt.push(l->left);
		lt.push(l->right);
		rt.push(r->right);
		rt.push(r->left);
	}
	if(lt.empty()&&rt.empty()) return true;
	else return false;
}
