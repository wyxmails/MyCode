/*
328. Odd Even Linked List My Submissions Question
Total Accepted: 1393 Total Submissions: 3426 Difficulty: Easy
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *eh,*et;
        ListNode *nt;
        eh=et=NULL;
        nt = head;
        while(nt!=NULL){
            if(nt->next==NULL) break;
            if(et==NULL){
                eh=et=nt->next;
            }else{
                et->next = nt->next;
                et = et->next;
            }
            nt->next = nt->next->next;
            if(nt->next==NULL)
                break;
            nt = nt->next;
        }
        if(et!=NULL) et->next = NULL;
        if(nt!=NULL) nt->next = eh;
        return head;
    }
};
