/*
Remove Linked List Elements Total Accepted: 10739 Total Submissions: 40585 My Submissions Question Solution 
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head==null) return head;
        if(head.val==val) return removeElements(head.next,val);
        ListNode next = null;
        next = removeElements(head.next,val);
        head.next = next;
        return head;
    }
}
