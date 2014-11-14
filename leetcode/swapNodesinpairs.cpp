/*Swap Nodes in Pairs
   Given a linked list, swap every two adjacent nodes and return its head.
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 Your algorithm should use only constant space. 
 You may not modify the values in the list, 
 only nodes itself can be changed.
 */
ListNode *swapPairs(ListNode *head) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(head==NULL) return head;
	ListNode *l,*r,*pre;
	l = head;
	r = head->next;
	while(r!=NULL){
		l->next = r->next;
		r->next = l;
		if(l==head) head = r;
		pre = l;
		l = l->next;
		if(l!=NULL) r = l->next;
		else r = NULL;
		if(r!=NULL) pre->next = r;
	}
	return head;
}

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *h = head->next,*next = head->next->next;
        h->next = head;
        head->next = swapPairs(next);
        return h;
    }
};
