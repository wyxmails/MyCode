#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
	if(head==NULL||head->next==NULL) return head;
	ListNode* tail = head;
	int num = 0;
	while(tail!=NULL){
		num++;
		tail = tail->next;
	}
	ListNode *s1,*s2,*t1,*t2;
	for(int r=1;r<num;r=r*2){
		s1=s2=head;
		ListNode*pre = NULL;
		while(s1!=NULL){
			s2=s1;
			for(int i=0;i<r&&s2!=NULL;++i){
				s2 = s2->next;
			}
			t2 = s2;
			t1 = s1;
			for(int i=1;i<r&&t1!=NULL;++i){
				t1 = t1->next;
			}
			for(int i=0;i<r&&t2!=NULL;++i){
				t2 = t2->next;
			}
			if(t2!=NULL){
				t1->next = t2;
				t1 = t2;
			}else{
				if(t1!=NULL) t1->next = NULL;
				t1 = NULL;
			}
			while(s1!=t1&&s2!=t2){
				if(s1->val<s2->val){
					if(pre!=NULL) pre->next = s1;
					else head = s1;
					pre = s1;
					s1 = s1->next;
				}else{
					if(pre!=NULL) pre->next = s2;
					else head = s2;
					pre = s2;
					s2 = s2->next;
				}
			}
			while(s1!=t1){
				if(pre!=NULL){
				   	pre->next = s1;
					pre = s1;
					s1 = s1->next;
				}else pre = head = s1;
			}
			if(s2!=t2){
				if(pre!=NULL){
				   	pre->next = s2;
					pre = s2;
					s2 = s2->next;
				}else pre = head = s2;
			}
			s1=t2;
		}
	}
	return head;
}

int main(int argc,char*argv[]){
	ListNode *head = new ListNode(3);
	ListNode *mid = new ListNode(2);
	ListNode *tail = new ListNode(4);
	head->next = mid;
	mid->next = tail;
	ListNode *res = sortList(head);
	while(res!=NULL){
		cout << res->val << endl;
		res = res->next;
	}
	return 0;	
}
