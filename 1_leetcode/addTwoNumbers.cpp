/*Add Two Numbers
   You are given two linked lists representing two non-negative numbers. 
   The digits are stored in reverse order 
   and each of their nodes contain a single digit. 
   Add the two numbers and return it as a linked list.
 
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int tmp, carry = 0;
	ListNode *h,*t,*node;
	h=t=NULL;
	while(l1!=NULL&&l2!=NULL){
	tmp = (*l1).val + (*l2).val;
	(*l1).val = (tmp+carry)%10;
	carry = (tmp+carry)/10;
	if(t==NULL){
	h = t = l1;
	}else{
	t->next = l1;
	t = l1;
	}
	l1 = (*l1).next;
	l2 = (*l2).next;
	}
	while(l1!=NULL){
	tmp = (*l1).val;
	(*l1).val = (tmp+carry)%10;
	if(t==NULL){
	h = t = l1;
	}else{
	t->next = l1;
	t = l1;
	}
	carry = (tmp+carry)/10;
	l1 = (*l1).next;
	}
	while(l2!=NULL){
	tmp = (*l2).val;
	(*l2).val = (tmp+carry)%10;
	if(t==NULL){
	h = t = l2;
	}else{
	t->next = l2;
	t = l2;
	}
	carry = (tmp+carry)/10;
	l2 = (*l2).next;
	}
	if(carry){
	ListNode*node;
	node = new ListNode(0);
	node->val = carry;
	node->next = NULL;
	t->next = node;
	t = node;
	}
	t->next = NULL;
	return h;
}
ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int carry = 0;
        ListNode *tail;
        while(t1!=NULL&&t2!=NULL){
            t1->val += t2->val+carry;
            carry = t1->val/10;
            t1->val %= 10;
            tail = t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=NULL){
            t1->val += carry;
            carry = t1->val/10;
            t1->val %= 10;
            tail = t1;
            t1 = t1->next;
        }
        tail->next = t2;
        while(t2!=NULL){
            t2->val += carry;
            carry = t2->val/10;
            t2->val %= 10;
            tail = t2;
            t2 = t2->next;
        }
        tail->next = l2;
        while(carry){
            l2->val = carry;
            carry = l2->val/10;
            l2->val %= 10;
            tail = l2;
            l2 = l2->next;
        }
        tail->next = NULL;
        return l1;
}
