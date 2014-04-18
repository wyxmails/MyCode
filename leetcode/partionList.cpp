/*Partition List
 Given a linked list and a value x, 
 partition it such that all nodes less than x come before 
 nodes greater than or equal to x.
 You should preserve the original relative order 
 of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
 */
// Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode *small = new ListNode(-1);
	ListNode *big = new ListNode(x);
	ListNode *s_last = small;
	ListNode *b_last = big;
	ListNode *cur = head;
	while(cur!=NULL){
		if(cur->val<x){
			s_last->next = cur;
			s_last = cur;
		}   
		else if(cur->val>=x){
			b_last->next = cur;
			b_last = cur;	
		}   
		cur = cur->next;
	}
	b_last->next = NULL;
	s_last->next = big->next;
	return small->next;
}

int main(){
	ListNode *head = new ListNode(1);
	ListNode *nnode = new ListNode(1);
	head->next = nnode;
	cout << head->val << " " << head->next->val << endl;
	nnode = partition(head,0);
	cout << nnode->val << " " << nnode->next->val << endl;
}
/*
class Solution {
	public:
	ListNode *partition(ListNode *head, int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(head==NULL) return head;
		ListNode *pre,*cur,*p,*s,*e;
		cur=head;
		pre=p=NULL;
		while(cur!=NULL){
			s=cur;
			e=pre;
			while(cur!=NULL&&cur->val<x){
				pre=cur;
				cur=cur->next;
			}
			if(s!=cur){
				if(p==NULL){
					if(s==head){
						p=pre;
					}else{
						p=pre;
						p->next = head;
						head = s;
						e->next = cur;
					}
				}else{
					pre->next = p->next;
					p->next = s;
					e->next = cur;
					p=pre;
				}
			}
			while(cur!=NULL&&cur->val>=x){
				pre=cur;
				cur=cur->next;
			}
		}
		return head;
	}
};*/

