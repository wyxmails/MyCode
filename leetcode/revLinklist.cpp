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
