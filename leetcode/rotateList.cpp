#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *rotateRight(ListNode *head, int k) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if(head==NULL||k==0) return head;
	if(head->next==NULL) return head;
	ListNode *h1,*h2;
	h1=h2=head;
	int i;
	for(i=0;i<k;++i){
		h2 = h2->next;
		if(h2==NULL) h2 = head;
	}
	if(h2==head) return head;
	while(h2->next!=NULL){
		h1 = h1->next;
		h2 = h2->next;
	}
	cout << "h1: " << h1->val << " h2: " << h2->val << endl;
	ListNode *nh = h1->next;
	h1->next = NULL;
	h2->next = head;
	head = nh;
	return nh;
}

int main(){
	ListNode *h,*t;
	ListNode *n = new ListNode(1);
	h=t=n;
	n = new ListNode(2);
	t->next = n;
	t=n;
	n = new ListNode(3);
	t->next = n;
	t=n;
	h = rotateRight(h,2);
	while(h!=NULL){
   		cout << h->val << endl;
		h = h->next;
	}
	return 0;
}
