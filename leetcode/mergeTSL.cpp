/*
   Merge two sorted linked lists and return it as a new list. 
   The new list should be made by splicing together the nodes of 
   the first two lists.
   */
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	bool asc = true;
	ListNode *head,*tail;
	ListNode *h1,*h2;
	head = tail = h1 = h2 = NULL;
	if(l1!=NULL) h1 = (*l1).next;
	while(h1!=NULL){
		if((*l1).val<(*h1).val){
			asc = true;
			break;
		}
		if((*l1).val>(*h1).val){
			asc = false;
			break;
		}
		h1 = (*h1).next;
	}
	if(l2!=NULL) h2 = (*l2).next;
	while(h2!=NULL){
		if((*l2).val<(*h2).val){
			asc = true;
			break;
		}
		if((*l2).val<(*h2).val){
			asc = false;
			break;
		}
		h2 = (*h2).next;
	}
	h1 = l1;
	h2 = l2;
	while(h1!=NULL&&h2!=NULL){
		if(asc){
			if((*h1).val<(*h2).val){
				if(tail==NULL) head = h1;
				else tail->next = h1;
				tail = h1;
				h1 = (*h1).next;
			}else{
				if(tail==NULL) head = h2;
				else tail->next = h2;
				tail = h2;
				h2 = (*h2).next;
			}
		}else{
			if((*h1).val>(*h2).val){
				if(tail==NULL) head = h1;
				else tail->next = h1;
				tail = h1;
				h1 = (*h1).next;
			}else{
				if(tail==NULL) head = h2;
				else tail->next = h2;
				tail = h2;
				h2 = (*h2).next;
			}
		}
	}
	while(h1!=NULL){
		if(tail==NULL)
			head = h1;
		else tail->next = h1;
		tail = h1;
		h1 = (*h1).next;
	}
	while(h2!=NULL){
		if(tail==NULL)
			head = h2;
		else tail->next = h2;
		tail = h2;
		h2 = (*h2).next;
	}
	return head;
}
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
// Note: The Solution object is instantiated only once and is reused by each test case.
if(l1==NULL) return l2;
if(l2==NULL) return l1;
bool asc = true;
if(l1->next!=NULL){
if(l1->val<l1->next->val) asc = true;
else asc = false;	
}else if(l2->next!=NULL){
if(l2->val<l2->next->val) asc = true;
else asc = false;
}
ListNode *t1 = l1;
ListNode *t2 = l2;
ListNode *h,*t;
h=t=NULL;
while((t1!=NULL)&&(t2!=NULL)){
if(h==NULL){
	if(asc){
		if((t1->val)<(t2->val)){
			cout << "min: " << t1->val << " " << t2->val << endl;
			h=t=t1;
			t1 = t1->next;
		}else{
			cout << "max: " << t1->val << " " << t2->val << endl;
			h=t=t2;
			t2 = t2->next;
		}
	}else{
	if(t1->val<t2->val){
			cout << "min: " << t1->val << " " << t2->val << endl;
	h=t=t2;
	t2 = t2->next;
	}else{
			cout << "max: " << t1->val << " " << t2->val << endl;
	h=t=t1;
	t1 = t1->next;
	}
	}
	continue;
}
if(asc){			if(t1->val<t2->val){
t->next = t1;
t = t1;
t1 = t1->next;
}else{
t->next = t2;
t = t2;
t2 = t2->next;
}
}else{
if(t1->val<t2->val){
t->next = t2;
t = t2;
t2 = t2->next;
}else{
t->next = t1;
t = t1;
		t1 = t1->next;
					}
}
}
while(t1!=NULL){
t->next = t1;
t = t1;
t1 = t1->next;
}
while(t2!=NULL){
t->next = t2;
t = t2;
t2 = t2->next;
}
return h;

}

ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2) {
        if(l1==NULL&&l2==NULL) return NULL;
        ListNode *head,*tail;
        head=tail=NULL;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<=l2->val){
                if(tail==NULL) head = l1;
                else tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }else{
                if(tail==NULL) head = l2;
                else tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if(l1!=NULL){
            if(tail==NULL) head = l1;
            else tail->next = l1;
            tail = l1;
        }
        if(l2!=NULL){
            if(tail==NULL) head = l2;
            else tail->next = l2;
            tail = l2;
        }
        return head;
}

int main(){
	ListNode *h1,*h2,*t1,*t2,*ln;
	h1=h2=t1=t2=ln=NULL;
	int start = 1;
	srand(time(0));
	ln = new ListNode(-7);
	h2 = t2 = ln;
	ln = new ListNode(-10);
	h1=t1= ln;
	ln = new ListNode(-10);
	t1->next = ln;
	t1 = ln;
	ln = new ListNode(1);
	t1->next = ln;
	t1 = ln;
	/*
	for(int i=0;i<10;++i){
		ln = new ListNode(0);
		if(t1!=NULL) ln->val = t1->val + rand()%5;
		else ln->val = rand()%5;
		cout << ln->val << ",	";
		ln->next = NULL;
		if(t1==NULL) h1 = ln;
		else t1->next = ln;
		t1 = ln;
		ln = new ListNode(0);
		if(t2!=NULL) ln->val = t2->val + rand()%5;
		else ln->val = rand()%5;
		cout << ln->val << endl;
		ln->next = NULL;
		if(t2==NULL) h2 = ln;
		else t2->next = ln;
		t2 = ln;
	}*/
	h1 = mergeTwoLists2(h1,h2);
	while(h1!=NULL){
		cout << h1->val << ",";
		h1 = h1->next;
	}
	cout << endl;
	return 0;
}
