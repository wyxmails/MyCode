/*
 Imagine a (literal) stack of plates. 
 If the stack gets too high, it might topple. 
 Therefore, in real life, 
 we would likely start a new stack when the previous stack exceeds some threshold. 
 Implement a data structure SetOfStacks that mimics this. 
 SetOfStacks should be composed of several stacks 
 and should create a new stack once the previous one exceeds capacity. 
 SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
 (that is,pop() should return the same values as it would if there were just a single stack).
 FOLLOW UP
 Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SetOfStacks{
public:
	SetOfStacks(int capacity=10);
	void push(int v);
	void pop();
	void popAt(int index);
	int top();
	bool empty();
private:
	vector<stack<int> > my_stacks_;
	int cap;
	int cur;
};

SetOfStacks::SetOfStacks(int capacity){
	cap = capacity;
	cur = 0;
	stack<int> s;
	my_stacks_.push_back(s);
}
void SetOfStacks::push(int v){
	if(my_stacks_[cur].size()>=cap){
		cur++;
		stack<int> s;
		my_stacks_.push_back(s);
	}
	my_stacks_[cur].push(v);
}
void SetOfStacks::pop(){
	if(empty()) return ;
	if(my_stacks_[cur].empty()){
		my_stacks_.pop_back();
		cur--;
	}
	if(cur>=0) my_stacks_[cur].pop();
}
int SetOfStacks::top(){
	if(empty()) return -1;
	while(cur>=0&&my_stacks_[cur].empty()){
		my_stacks_.pop_back();
		cur--;
	}
	if(cur>=0) return my_stacks_[cur].top();
	else return -1;
}
bool SetOfStacks::empty(){
	if(cur<0) return true;
	if(cur==0&&my_stacks_[cur].empty()) return true;
	return false;
}
void SetOfStacks::popAt(int index){
	if(index<0||index>cur) return;
	my_stacks_[index].pop();
}

int main(int argc,char*argv[]){
	SetOfStacks sos(1);
	sos.push(10);
	sos.push(5);
	cout << sos.top() << endl;
	sos.popAt(0);
	cout << "1" << endl;
	sos.pop();
	cout << "2" << endl;
	cout << sos.top() << endl;
	return 0;
}
