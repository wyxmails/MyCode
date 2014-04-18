/*Binary Tree Zigzag Level Order Traversal
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 
     3
    / \
   9  20
     /  \
    15   7
 return its zigzag level order traversal as:
 
 [
   [3],
   [20,9],
   [15,7]
 ]
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > vecres;
	vecres.clear();
	if(root==NULL) return vecres;
	stack<TreeNode*> curr;
	stack<TreeNode*> next;
	bool seq=true;
	vector<int> vec;
	curr.push(root);
	TreeNode *node;
	while(!curr.empty()){
		vec.clear();
		while(!curr.empty()){
			node = curr.top();
			vec.push_back(node->val);
			if(seq){
				if(node->left!=NULL)
				next.push(node->left);
				if(node->right!=NULL)
				next.push(node->right);
			}else{
				if(node->right!=NULL)
					next.push(node->right);
				if(node->left!=NULL)
					next.push(node->left);
			}
			curr.pop();
		}
		vecres.push_back(vec);
		curr = next;
		while(!next.empty()) next.pop();
		seq = !seq;
	}
	return vecres;
}
