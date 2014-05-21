#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	if(head==NULL||head->next==NULL) return NULL;
	ListNode *r1,*r2;
	r1=r2=head;
	while(r1!=NULL&&r2!=NULL){
		r1 = r1->next;
		r2 = r2->next;
		if(r2==NULL) break;
		r2 = r2->next;
		if(r1==r2) break;
	}
	if(r1==NULL||r2==NULL) return NULL;
	else{
		r1=head;
		while(r1!=r2){
			r1 = r1->next;
			r2 = r2->next;
		}
		return r1;
	}
}

int main(int argc,char*argv[]){
	ListNode *head = new ListNode(1);
	ListNode *tail = new ListNode(2);
	head->next = tail;
	ListNode *res = detectCycle(head);
	if(res==NULL) cout << "no cycle" << endl;
	else cout << res->val << endl;
	return 0;
}
