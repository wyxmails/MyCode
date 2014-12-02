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

class Solution2 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||head->next==NULL||k<=1) return head;
        ListNode *h1,*h2,*t,*pre;
        pre = NULL;
        h2=head;
        int i;
        while(true){
            h1 = h2;
            for(i=0;i<k&&h2!=NULL;++i){
                t = h2;
                h2 = h2->next;
            }
            if(i<k) break;
            vector<ListNode*> res = myR(h1,t);
            if(pre==NULL) head = res[0];
            else pre->next = res[0];
            pre = res[1];
            pre->next = h2;
        }
        return head;
    }
    vector<ListNode*> myR(ListNode *h,ListNode *t){
        t->next = NULL;
        ListNode *r1,*r2;
        r1=r2=t=NULL;
        while(h!=NULL){
            r1 = h->next;
            h->next = r2;
            r2 = h;
            h = r1;
            if(t==NULL) t = r2;
        }
        vector<ListNode*> res;
        res.push_back(r2);
        res.push_back(t);
        return res;
    }
};

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
