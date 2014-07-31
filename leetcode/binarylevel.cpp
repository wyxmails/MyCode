/*Binary Tree Level Order Traversal
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 
     3
    / \
   9  20
     /  \
    15   7
 return its level order traversal as:
 
 [
   [3],
   [9,20],
   [15,7]
 ]
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > levelOrder(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	queue<TreeNode*> curr;
	queue<TreeNode*> next;
	
	vector<vector<int> > vecres;
	vector<int> vec;
	vecres.clear();
	if(root==NULL) return vecres;
	curr.push(root);
	while(!curr.empty()){
		vec.clear();
		while(!curr.empty()){
			TreeNode *node = curr.front();
			vec.push_back(node->val);
			if(node->left!=NULL)
				next.push(node->left);
			if(node->right!=NULL)
				next.push(node->right);
			curr.pop();
		}
		vecres.push_back(vec);
		while(!next.empty()){
			curr.push(next.front());
			next.pop();
		}
	}
	return vecres;
}
vector<vector<int> > levelOrder2(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<TreeNode *> arr[2];
        int pre=1;
        int cur = 0;
        arr[cur].push_back(root);
        while(!arr[cur].empty()){
            cur=!cur; pre=!pre;
            vector<int> vec;
            for(int i=0;i<arr[pre].size();++i){
                vec.push_back(arr[pre][i]->val);
                if(arr[pre][i]->left!=NULL) arr[cur].push_back(arr[pre][i]->left);
                if(arr[pre][i]->right!=NULL) arr[cur].push_back(arr[pre][i]->right);
            }
            res.push_back(vec);
            vec.clear();
            arr[pre].clear();
        }
        return res;
}
