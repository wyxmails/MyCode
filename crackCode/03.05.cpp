#include <iostream>
using namespace std;

typedef struct Node{
	int val;
	Node* next;
	Node(int v){
		val = v;
		next = NULL;
	}
}Node;

class myStack{
	public:
		myStack(){
			buf = NULL;
		}
		~myStack(){
			while(buf!=NULL){
				Node *tmp = buf;
				buf = buf->next;
				delete tmp;
			}
		}
		void push(int v){
			Node *tmp = new Node(v);
			tmp->next = buf;
			buf = tmp;
		}
		void pop(){
			Node *tmp = buf;
			buf = buf->next;
			delete tmp;
		}
		int top(){
			if(!empty()) return buf->val;
			return -1;
		}
		bool empty(){
			return buf==NULL;
		}
	private:
		Node *buf;
};

class q2stack{
	public:
		int front(){
			if(s2.empty()) move(s1,s2);
			return s2.top();
		}
		int back(){
			if(s1.empty()) move(s2,s1);
			return s1.top();
		}
		void push(int v){
			s1.push(v);
		}
		void pop(){
			if(s2.empty()) move(s1,s2);
			s2.pop();
		}
		bool empty(){
			return s1.empty()&&s2.empty();
		}
		void move(myStack &f,myStack &t){
			if(f.empty()) return;
			while(!f.empty()){
				int v = f.top();
				f.pop();
				t.push(v);
			}
		}
	private:
		myStack s1,s2;
};

int main(int argc,char*argv[]){
	q2stack q1;
	q1.push(1);
	q1.push(2);
	cout << q1.front() << endl;
	cout << q1.back() << endl;
	q1.pop();
	cout << q1.front() << endl;
	return 0;
}
