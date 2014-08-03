/*
   Merge k sorted linked lists and return it as one sorted list. 
   Analyze and describe its complexity.
   my solution: if total number is n, the complexity is O(k*n).
 */
ListNode *mergeKLists(vector<ListNode *> &lists) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode*head,*tail;
	head=tail=NULL;
	if(lists.size()==0) return head;
	if(lists.size()==1) return lists[0];
	int mini;
	while(lists.size()){
		mini=0;
		while(lists.size()&&lists[mini]==NULL){
			lists.erase(lists.begin()+mini);
		}
		for(int i=mini+1;i<lists.size();++i){
			if(lists[i]!=NULL&&lists[i]->val<lists[mini]->val) mini = i;
		}
		if(lists.size()){
			if(tail==NULL){
				head = tail = lists[mini];
			}else{
				tail->next = lists[mini];
				tail = lists[mini];
			}
			lists[mini] = (*lists[mini]).next;
			if(lists[mini]==NULL) lists.erase(lists.begin()+mini);
		}
	}
	return head;
}
ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n==0) return NULL;
        ListNode *head = lists[0];
        for(int i=1;i<n;++i){
            if(lists[i]==NULL) continue;
            if(head==NULL){
                head = lists[i];
                continue;
            } 
            ListNode *cur1,*cur2,*pre;
            cur1 = head;
            cur2 = lists[i];
            pre = NULL;
            if(cur1->val>cur2->val) head = cur2;
            while(cur1!=NULL&&cur2!=NULL){
                if(cur1->val>cur2->val){
                    if(pre!=NULL) pre->next = cur2;
                    pre = cur2;
                    cur2 = cur2->next;
                }else{
                    if(pre!=NULL) pre->next = cur1;
                    pre = cur1;
                    cur1 = cur1->next;
                }
            }
            if(cur1!=NULL) pre->next = cur1;
            if(cur2!=NULL) pre->next = cur2;
        }
        return head;
}
