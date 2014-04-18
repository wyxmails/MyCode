#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode *h,*t,*x,*pre,*cur;
	pre = cur = NULL;
	h = x = head;
	if(head==NULL||k<=1) return head;
	else t = head->next;
	bool first = true;
	int cnt;
	while(h!=NULL&&t!=NULL){
		x = h;
		cnt=0;
		while(cnt<k&&x!=NULL){
			x = x->next;
			cnt++;
		}
		pre = cur;
		cur = h;
		if(x==NULL&&cnt<k){
			if(pre!=NULL)
				pre->next = cur;
			break;
		}
		cnt = 0;
		while(cnt<k){
			cnt++;
			h->next = x;
			x = h;
			h = t;
			if(h!=NULL) t = h->next;
			else t = NULL;
		}
		if(first){
			head = x;
			first = false;
		}
		if(pre!=NULL) pre->next = x;
	}
	return head;
}
int main(){
	ListNode *h,*t,*node;
	h=t=node=NULL;
	for(int i=0;i<4;++i){
		node = new ListNode(i+1);
		node->next = NULL;
		if(t==NULL) h = node;
		else t->next = node;
		t = node;
	}
	int k=2;
	h = reverseKGroup(h,k);
	while(k++<10&&h!=NULL){
		cout << h->val << " ";
		h = h->next;
	}
	cout << endl;
	return 0;
}
