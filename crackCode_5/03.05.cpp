/*
 Implement a MyQueue class which implements a queue using two stacks.
 */

#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
public:
	int front();
	int back();
	void push(int v);
	void pop();
	bool empty();
private:
	stack<int> stack_push_;
	stack<int> stack_pop_;
};

int MyQueue::front(){
	if(empty()) return -1;
	if(!stack_pop_.empty())
		return stack_pop_.top();
	while(!stack_push_.empty()){
		stack_pop_.push(stack_push_.top());
		stack_push_.pop();
	}
	return stack_pop_.top();
}
int MyQueue::back(){
	if(empty()) return -1;
	if(!stack_push_.empty())
		return stack_push_.top();
	while(!stack_pop_.empty()){
		stack_push_.push(stack_pop_.top());
		stack_pop_.pop();
	}
	return stack_push_.top();
}

void MyQueue::push(int v){
	stack_push_.push(v);
}
void MyQueue::pop(){
	if(empty()) return;
	if(stack_pop_.empty()){
		while(!stack_push_.empty()){
			stack_pop_.push(stack_push_.top());
			stack_push_.pop();
		}
	}
	stack_pop_.pop();
}

bool MyQueue::empty(){
	return stack_push_.empty()&&stack_pop_.empty();
}

int main(int argc,char*argv[]){
	MyQueue mq;
	for(int i=1;i<=5;++i)
		mq.push(i);
	for(int i=1;i<=6;++i){
		cout << "front: " << mq.front() << endl;
		cout << "back: " << mq.back() << endl;
		mq.pop();
	}
	return 0;
}
