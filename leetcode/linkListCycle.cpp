/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        ListNode *s1,*s2;
        s1=s2=head;
        while(s1!=NULL&&s2!=NULL){
            s1 = s1->next;
            s2 = s2->next;
            if(s2==NULL) break;
            s2 = s2->next;
            if(s1==s2) return true;
        }
        return false;
    }
};
