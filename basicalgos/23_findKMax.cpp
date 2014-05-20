#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int val;
	Node*left;
	Node*right;
};
Node* findKth(Node *root,unsigned int k){
	vector<struct Node*> nodes;
	vector<int> state;
	nodes.clear();
	state.clear();
	nodes.push_back(root);
	state.push_back(0);
	Node *tmpnode;
	int cnt=0;
	while(!nodes.empty()){
		tmpnode = nodes.back();
		int & nc = state.back();
		if(tmpnode==NULL){
			nodes.pop_back();
			state.pop_back();
			continue;
		}
		if(nc==0){
			nc=1;
			nodes.push_back(tmpnode->right);
			state.push_back(0);
		}else if(nc==1){
			nc=2;
			cnt++;
			if(cnt==k) break;
			nodes.push_back(tmpnode->left);
			state.push_back(0);
		}else{
			nodes.pop_back();
			state.pop_back();
		}
	}
	return (cnt==k)?nodes.back():NULL;
}
void printTree(Node*root){
	if(root==NULL) return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}
int main(){
	int n,val;
	cout << "input node number: " << endl;
	cin>>n;
	Node *Tree,*node,*tail1,*tail2;
	Tree=node=NULL;
	cout << "input node val: " << endl;
	for(int i=0;i<n;++i){
		cin>>val;
		node = new Node;
		node->val = val;
		node->left = node->right = NULL;
		if(Tree==NULL) Tree = node;
		else{
			tail1 = Tree;
			bool r;
			while(tail1!=NULL){
				tail2 = tail1;
				if(val>tail1->val){
				   	tail1 = tail1->right;
					r = true;
				}else{
				   	tail1 = tail1->left;
					r = false;
				}
			}
			if(r) tail2->right = node;
			else tail2->left = node;
		}
	}
	cout << "print tree: " << endl;
	printTree(Tree);
	cout << endl << "input K: " << endl;
	int k;
	cin>>k;
	node = findKth(Tree,k);
	if(node==NULL) cout << "null" << endl;
	else	cout << node->val << endl;
}
