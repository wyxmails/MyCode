/*
   Merge k sorted linked lists and return it as one sorted list. 
   Analyze and describe its complexity.
   my solution: if total number is n, the complexity is O(k*n).
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        return merge(lists,0,n-1);
    }
    ListNode*merge(vector<ListNode*>&lists,int l,int r){
        if(l>r) return NULL;
        if(l==r) return lists[l];
        if(r-l==1) return mergeTwo(lists[l],lists[r]);
        int m = (l+r)/2;
        ListNode *L = merge(lists,l,m);
        ListNode *R = merge(lists,m+1,r);
        return mergeTwo(L,R);
    }
    ListNode*mergeTwo(ListNode*l,ListNode*r){
        if(l==NULL&&r==NULL) return NULL;
        if(l==NULL) return r;
        if(r==NULL) return l;
        if(l->val<r->val){
            l->next = mergeTwo(l->next,r);
            return l;
        }else{
            r->next = mergeTwo(l,r->next);
            return r;
        }
    }
};
