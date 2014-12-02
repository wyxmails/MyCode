/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        int n=0;
        ListNode *h=head;
        while(h!=NULL){
            h = h->next;
            n++;
        }
        if(n<=2) return;
        ListNode *t;
        h=head;
        for(int i=0;i<(n+1)/2;++i){
            t = h;
            h = h->next;
        }
        t->next = NULL;
        h = reverse(h);
        t = head;
        ListNode *tmp;
        while(h!=NULL&&t!=NULL){
            tmp = t->next;
            t->next = h;
            t = tmp;
            tmp = h->next;
            h->next = t;
            h = tmp;
        }
    }
    ListNode *reverse(ListNode *head){
        ListNode *h=NULL;
        ListNode *tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            tmp->next = h;
            h = tmp;
        }
        return h;
    }
};
