/*
Palindrome Linked List My Submissions Question Solution 
Total Accepted: 22395 Total Submissions: 95712 Difficulty: Easy
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        int n=0;
        ListNode *run = head;
        while(run!=NULL){
            n++;
            run = run->next;
        }
        ListNode *nh = NULL;
        for(int i=0;i*2<n;++i){
            run = head;
            head = head->next;
            run->next = nh;
            nh = run;
        }
        if(n%2) run = nh->next;
        ListNode *run1 = head;
        bool flag = true;
        while(run!=NULL&&run1!=NULL&&run->val==run1->val){
            run = run->next;
            run1 = run1->next;
        }
        if(run!=NULL||run1!=NULL) flag = false;
        return flag;
    }
};
