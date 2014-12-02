/*
Sort a linked list using insertion sort.
*/

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

ListNode *insertionSortList(ListNode *head) {
        ListNode *h,*run;
        h=NULL; run = head;
        while(run!=NULL){
            ListNode *tmp1 = run->next;
            if(h==NULL){
                h = run;
                h->next = NULL;
            } 
            else if(h->val>run->val){
                run->next = h;
                h = run;
            }else{
                ListNode *tmp2 = h;
                while(tmp2->next!=NULL&&run->val>=tmp2->next->val) tmp2 = tmp2->next;
                if(tmp2->next==NULL){
                    tmp2->next = run;
                    run->next = NULL;
                }else{
                    run->next = tmp2->next;
                    tmp2->next = run;
                }
            }
            run = tmp1;
        }
        return h;
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
