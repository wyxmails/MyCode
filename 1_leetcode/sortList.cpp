/*
Sort List Total Accepted: 17611 Total Submissions: 86269 My Submissions
Sort a linked list in O(n log n) time using constant space complexity.
*/

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

ListNode *sortList2(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        int n = 0;
        ListNode *h=head;
        while(h!=NULL){
            h = h->next;
            n++;
        }
        return mySort(head,n);
    }
ListNode *mySort(ListNode *head,int n){
        if(n<=1) return head;
        int m = n/2;
        ListNode *h = head;
        for(int i=1;i<m;++i){
            h = h->next;
        }
        ListNode *t = h;
        h = h->next;
        t->next = NULL;
        head = mySort(head,m);
        h = mySort(h,n-m);
        //merge
        ListNode *resH,*resT;
        resH=resT=NULL;
        while(head!=NULL&&h!=NULL){
            if(head->val<=h->val){
                if(resH==NULL) resH = head;
                else resT->next = head;
                resT = head;
                head = head->next;
            }else{
                if(resH==NULL) resH = h;
                else resT->next = h;
                resT = h;
                h = h->next;
            }
        }
        if(head!=NULL){
            if(resH==NULL) resH = head;
            else resT->next = head;
        }
        if(h!=NULL){
            if(resH==NULL) resH = h;
            else resT->next = h;
        }
        return resH;
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
