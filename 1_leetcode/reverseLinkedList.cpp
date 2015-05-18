/*
Reverse Linked List Total Accepted: 9784 Total Submissions: 29053 My Submissions Question Solution 
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionIte {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *nh = NULL;
        ListNode *run = head;
        while(head!=NULL){
            head = head->next;
            run->next = nh;
            nh = run;
            run = head;
        }
        return nh;
    }
};
