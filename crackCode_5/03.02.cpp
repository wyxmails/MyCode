/*
 How would you design a stack which, in addition to push and pop, 
 also has a function min which returns the minimum element? 
 Push, pop and min should all operate in 0(1) time.
 */
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class StackWithMin{
	public:
		void push(int v);
		void pop();
		int top();
		int min();
		bool empty();
	private:
		stack<int> s;
		stack<int> sMin;
};

bool StackWithMin::empty(){
	return s.empty();
}

void StackWithMin::push(int v){
	if(empty()){
		s.push(v);
		sMin.push(v);
	}else{
		if(v<=sMin.top())
				sMin.push(v);
		s.push(v);
	}
}

void StackWithMin::pop(){
	if(empty()) return;
	if(sMin.top()==s.top())
		sMin.pop();
	s.pop();
}

int StackWithMin::top(){
	if(empty()){
		cerr << "ERROR: Empty stack" << endl;
		return -1;
	}
	return s.top();
}

int StackWithMin::min(){
	if(empty()){
		cerr << "ERROR: Empty stack" << endl;
		return -1;
	}
	return sMin.top();
}

class StackWithMin2: public stack<int>{
	public:
		void push(int v);
		void pop();
		int top();
		int min();
		bool empty();
	private:
		stack<int> mini;
};

void StackWithMin2::push(int v){
	if(empty()||v<=mini.top())
			mini.push(v);
	stack::push(v);
}
void StackWithMin2::pop(){
	if(empty()){
		cerr << "ERROR: Empty stack" << endl;
		return;
	}
	if(mini.top()==stack::top())
		mini.pop();
	stack::pop();
}
int StackWithMin2::top(){
	if(empty()){
		cerr << "ERROR: Empty stack" << endl;
		return -1;
	}
	return stack::top();
}
int StackWithMin2::min(){
	if(mini.empty()){
		cerr << "ERROR: Empty stack" << endl;
		return -1;
	}
	return mini.top();
}
bool StackWithMin2::empty(){
	return stack::empty();
}

int main(int argc,char*argv[]){
	StackWithMin swm;
	StackWithMin2 swm2;
	cout << "size: " << sizeof(swm) << " " << sizeof(swm2) << endl;
	srand(time(NULL));
	int m = rand()%10;
	int n = rand()%10;
	cout << "push " << m << " times" << endl;
	for(int i=0;i<m;++i){
		int tmp = rand()%50;
		swm.push(tmp);
		swm2.push(tmp);
		cout << tmp << " ";
	}
	cout << endl << "size: " << sizeof(swm) << " " << sizeof(swm2) << endl;
	cout << "pop " << n << " times" << endl;
	for(int i=0;i<n;++i){
		cout << "mini: " << swm.min() << endl;
		cout << "mini2: " << swm2.min() << endl;
		swm.pop();
		swm2.pop();
	}
	return 0;
}
