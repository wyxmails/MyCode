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

vector<vector<int> > zigzagLevelOrder2(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        int cur=0;
        int pre=1;
        vector<TreeNode *> arr[2];
        arr[cur].push_back(root);
        bool seq = true;
        while(!arr[cur].empty()){
            pre=!pre;cur=!cur;
            vector<int> vec;
            if(seq){
                for(int i=0;i<arr[pre].size();++i) 
                    vec.push_back(arr[pre][i]->val);
            }else{
                for(int i=arr[pre].size()-1;i>=0;--i) 
                    vec.push_back(arr[pre][i]->val);
            }
            res.push_back(vec);
            vec.clear();
            seq=!seq;
            for(int i=0;i<arr[pre].size();++i){
                if(arr[pre][i]->left!=NULL) arr[cur].push_back(arr[pre][i]->left);
                if(arr[pre][i]->right!=NULL) arr[cur].push_back(arr[pre][i]->right);
            }
            arr[pre].clear();
        }
        return res;
}

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<vector<TreeNode*> > layers(2);
        int pre=1,cur=0;
        layers[cur].push_back(root);
        bool rev = false;
        while(!layers[cur].empty()){
            pre = !pre;
            cur = !cur;
            vector<int> mid;
            layers[cur].clear();
            for(int i=0;i<layers[pre].size();++i){
                mid.push_back(layers[pre][i]->val);
                if(layers[pre][i]->left!=NULL) layers[cur].push_back(layers[pre][i]->left);
                if(layers[pre][i]->right!=NULL) layers[cur].push_back(layers[pre][i]->right);
            }
            if(rev) reverse(mid.begin(),mid.end());
            rev = !rev;
            res.push_back(mid);
        }
        return res;
    }
};
