/*
Reverse Linked List II Total Accepted: 24193 Total Submissions: 92522 My Submissions Question Solution 
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if(m==n) return head;
	ListNode *t1,*t2,*h1,*h2;
	t1=h1=head;
	for(int i=1;i<m&&h1!=NULL;++i){
		t1 = h1;
		h1 = h1->next;
	}
	t2=h2=head;
	for(int i=1;i<=n&&h2!=NULL;++i){
		t2 = h2;
		h2 = h2->next;
	}
	if(h1==NULL&&h2==NULL) return head;
	t2->next = NULL;
	while(h1!=NULL){
		t2 = h1->next;
		h1->next = h2;
		h2 = h1;
		h1 = t2;
	}
	if(m==1) return h2;
	t1->next = h2;
	return head;
}
int main(int argc,char*argv[]){
	return 0;
}
