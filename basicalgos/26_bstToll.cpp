#include <iostream>
#include <climits>
using namespace std;
struct Node {
int data;
Node * left;
Node * right;
};


/*
* We use pair<Node*,Node*> to store the start and end
* of the double link list. 
*/
pair<Node*, Node*> bst_to_ll_internal(Node * root)
{
pair<Node*, Node*> retval, ll_left, ll_right;

if (root->left != NULL){
ll_left = bst_to_ll_internal(root->left);
retval.first = ll_left.first;
root->left = ll_left.second;
(ll_left.second)->right = root;
}
else{
retval.first = root;
retval.second = root;
}

if (root->right != NULL){
ll_right = bst_to_ll_internal(root->right);
retval.second = ll_right.second;
root->right = ll_right.first;
(ll_right.first)->left = root;
}

return retval;
}

Node* bst_to_ll(Node * root)
{
pair<Node*, Node*> ht = bst_to_ll_internal(root);
return ht.first;
}
bool isBi(Node *root,int b,int t){
	if(root==NULL) return true;
	if(root->data<=b||root->data>=t) return false;
	return isBi(root->left,b,root->data)&&isBi(root->right,root->data,t);
}
bool is_binary_search_tree(Node *root){
	//int MIN = -(1<<31-1);
	//int MAX = 1<<31-1;
	return isBi(root,INT_MIN,INT_MAX);
}

int main()
{
Node nodes[10];
for (int i = 0; i < 10;i++){ 
nodes[i].data = i;  
nodes[i].left = nodes[i].right = NULL;
}

nodes[5].left = &nodes[4];
nodes[5].right = &nodes[7];
nodes[4].right = &nodes[2];
nodes[7].left = &nodes[6];

cout << "is Bi? " << is_binary_search_tree(&nodes[5]) << endl;
Node* res = bst_to_ll(&nodes[5]);
while(res!=NULL){
   	cout << res->data << " ";
	res = res->right;
}
cout << endl;
return 0;  
}
