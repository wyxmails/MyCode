/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *h,*pre,*cur;
        h=pre=NULL; cur=head;
        while(cur!=NULL){
            if(cur->next==NULL||cur->val!=cur->next->val){
                if(pre==NULL) h = cur;
                else pre->next = cur;
                pre = cur;
            }else{
                while(cur->next!=NULL&&cur->next->val==cur->val) 
                    cur = cur->next;
            }
            cur = cur->next;
        }
        if(pre!=NULL) pre->next=NULL;
        return h;
    }
};
