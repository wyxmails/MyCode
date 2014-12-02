/*Remove Nth Node From End of List
   Given a linked list, 
   remove the nth node from the end of list and return its head.
 For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end,
   	the linked list becomes 1->2->3->5.
Note:
 Given n will always be valid.
 Try to do this in one pass.
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode *tail,*tmp1,*tmp2;
	tmp1 = tmp2 = tail = head;
	for(int i=0;i<n&&tail!=NULL;++i){
		tail = tail->next;
	}
	while(tail!=NULL){
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		tail = tail->next;
	}
	if(tmp1==tmp2) head = head->next;
	else tmp1->next = tmp2->next;
	return head;
}
ListNode *removeNthFromEnd2(ListNode *head, int n) {
        if(head==NULL) return NULL;
        ListNode *tail = head;
        ListNode *pre = head;
        while(tail!=NULL&&n>0){
            tail = tail->next;
            n--;
        }
        if(n!=0) return head;
        if(tail==NULL) return head->next;
        while(tail->next!=NULL){
            pre = pre->next;
            tail = tail->next;
        }
        pre->next = pre->next->next;
        return head;
}
