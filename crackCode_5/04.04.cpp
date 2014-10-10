/*
 Given a binary tree, design an algorithm 
 which creates a linked list of all the nodes at each depth 
 (e.g., if you have a tree with depth D,you'll have D linked lists).
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

struct Node{
	TreeNode *node;
	Node *next;
	Node(TreeNode *n):node(n),next(NULL){}
};

vector<Node*> CreateLinkedList(TreeNode *root){
	vector<Node*> res;
	if(root==NULL) return res;
	Node *head,*tail;
	head=tail=NULL;
	Node *run = new Node(root);
	res.push_back(run);
	while(run!=NULL){
		if(run->node->left!=NULL){
			if(head==NULL) head = tail = new Node(run->node->left);
			else{
			   	tail->next = new Node(run->node->left);
				tail = tail->next;
			}
		}
		if(run->node->right!=NULL){
			if(head==NULL) head = tail = new Node(run->node->right);
			else{
				tail->next = new Node(run->node->right);
				tail = tail->next;
			}
		}
		run = run->next;
		if(run==NULL){
			run = head;
			head = tail = NULL;
			if(run!=NULL) res.push_back(run);
		}
	}
	return res;
}

int main(int argc,char*argv[]){
	TreeNode *root,*left,*right;
	root = new TreeNode(2);
	left = new TreeNode(1);
	right = new TreeNode(3);
	root->left = left;
	root->right = right;
	vector<Node*> res = CreateLinkedList(root);
	for(int i=0;i<res.size();++i){
		Node *run = res[i];
		while(run!=NULL){
			cout << run->node->val << " ";
			run = run->next;
		}
		cout << endl;
	}
	return 0;
}
