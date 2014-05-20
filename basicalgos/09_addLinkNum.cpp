#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x) : val(x),next(NULL){}
};

ListNode* addT(ListNode*l1,ListNode*l2){
	ListNode*head,*tail,*hl2;
	head=tail=l1;
	hl2=l2;
	int carr=0,tmp;
	while(l1!=NULL&&l2!=NULL){
		tmp = (*l1).val + (*l2).val;
		(*l1).val = (carr+tmp)%10;
		carr = (carr+tmp)/10;
		tail = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1!=NULL){
		tmp = (*l1).val;
		(*l1).val = (carr+tmp)%10;
		carr = (carr+tmp)/10;
		tail = l1;
		l1 = l1->next;
	}
	while(l2!=NULL){
		tmp = (*l2).val;
		(*l2).val = (carr+tmp)%10;
		carr = (carr+tmp)/10;
		tail->next = l2;
		tail = l2;
		l2 = l2->next;
	}
	if(carr){
		(*hl2).val = carr;
		tail->next = hl2;
		tail = hl2;	
	}
	tail->next = NULL;
	return head;
}
int main(){
	ListNode *l1,*l2,*t1,*t2,*tmp;
	l1=l2=t1=t2=NULL;
	int n;
	cin>>n;
	int val;
	for(int i=0;i<n;++i){
		cin>>val;
		tmp = new ListNode(val%10);
		if(t1==NULL) l1=tmp;
		else t1->next = tmp;
		t1 = tmp;
		tmp = new ListNode((val+1)%10);
		if(t2==NULL) l2 = tmp;
		else t2->next = tmp;
		t2 = tmp;
	}
	l1 = addT(l1,l2);
	while(l1->next!=NULL){
		cout << l1->val << "->";
		l1 = l1->next;
	}
	cout << l1->val << endl;
	return 0;
}
