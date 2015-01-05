/*
Intersection of Two Linked Lists Total Accepted: 9537 Total Submissions: 35653 My Submissions Question Solution 
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0,n2=0;
        ListNode *a = headA;
        while(a!=NULL){
            a = a->next;
            n1++;
        }
        a = headB;
        while(a!=NULL){
            a = a->next;
            n2++;
        }
        a=headA;
        ListNode *b = headB;
        if(n1>n2){
            int t=0;
            while(t<(n1-n2)){
                a = a->next;
                t++;
            }
        }
        if(n2>n1){
            int t=0;
            while(t<(n2-n1)){
                b = b->next;
                t++;
            }
        }
        while(a!=NULL&&b!=NULL){
            if(a==b) return a;
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};
