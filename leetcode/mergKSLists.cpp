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
