/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *,RandomListNode *> mark;
        return myCopy(head,mark);
    }
    RandomListNode *myCopy(RandomListNode *head,unordered_map<RandomListNode *,RandomListNode *> &mark){
        if(head==NULL) return head;
        if(mark.find(head)!=mark.end()) return mark[head];
        RandomListNode *hc = new RandomListNode(head->label);
        mark[head] = hc;
        hc->next = myCopy(head->next,mark);
        hc->random = myCopy(head->random,mark);
        return hc;
    }
};
