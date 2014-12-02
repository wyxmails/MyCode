#include <iostream>
using namespace std;
/*Given a singly linked list 
*  where elements are sorted in ascending order, 
*  convert it to a height balanced BST.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head) {
	if(head==NULL) return NULL;
	if(head->next==NULL){
		return new TreeNode(head->val);
	}
	ListNode *tail = head;
	int cnt = 0;
	while(tail!=NULL){
		tail = tail->next;
		cnt++;
	}
	ListNode *cur = head->next;
	ListNode *pre = head;
	for(int i=1;i<cnt/2&&cur!=NULL;++i){
		pre = cur;
		cur = cur->next;
	}
	TreeNode *root = new TreeNode(cur->val);
	pre->next = NULL;
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(cur->next);
	return root;
}
int main(int argc,char*argv[]){
	return 0;
}
