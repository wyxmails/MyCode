#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {
	if(head==NULL||head->next==NULL) return head;
	ListNode * pre = head;
	ListNode * cur = head->next;
	cout << "while" << endl;
	while(cur!=NULL){
		bool flag = false;
		cout << "in" << endl;
		if(cur->val<head->val){
			pre->next = cur->next;
			cur->next = head;
			head = cur;
			cur = pre->next;
			flag = true;
		}else{
			ListNode *run = head;
			while(run!=pre){
				if(run->next->val<=cur->val) run = run->next;
				else{
					pre->next = cur->next;
					cur->next = run->next;
					run->next = cur;
					cur = pre->next;
					flag = true;
					break;
				}
			}
		}
		if(!flag){
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}

int main(int argc,char*argv[]){
	ListNode*head = new ListNode(4);
	ListNode*one = new ListNode(2);
	ListNode*two = new ListNode(1);
	ListNode*tail = new ListNode(3);
	head->next = one;
	one->next = two;
	two->next = tail;
	ListNode*res = insertionSortList(head);
	while(res!=NULL){
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
