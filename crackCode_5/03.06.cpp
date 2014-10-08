/*
 Write a program to sort a stack in ascending order (with biggest items on top). 
 You may use at most one additional stack to hold items, 
 but you may not copy the elements into any other data structure (such as an array). 
 The stack supports the following operations: push, pop, peek, and isEmpty.
 */
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void SortStack(stack<int>&s1,stack<int>&s2){
	if(s1.size()<=1) return;
	int n = s1.size();
	for(int i=n;i>0;--i){
		int mini = s1.top();
		for(int j=0;j<i;++j){
			if(mini>s1.top())
				mini = s1.top();
			s2.push(s1.top());
			s1.pop();
		}
		bool filter_mini=false;
		s1.push(mini);
		while(!s2.empty()){
			if(s2.top()==mini&&!filter_mini){
				s2.pop();
				filter_mini = true;
				continue;
			}
			s1.push(s2.top());
			s2.pop();
		}
	}
}
stack<int> SortStack2(stack<int> s1){
	if(s1.size()<=1) return s1;
	stack<int> s2;
	while(!s1.empty()){
		int tmp = s1.top();
		s1.pop();
		while(!s2.empty()&&s2.top()>tmp){
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(tmp);
	}
	return s2;
}
int main(int argc,char*argv[]){
	stack<int> s1;
	srand(time(NULL));
	for(int i=0;i<10;++i){
		int tmp = rand()%50;
		s1.push(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	stack<int> s2;
	//SortStack(s1,s2);
	s1 = SortStack2(s1);
	while(!s1.empty()){
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	return 0;
}
