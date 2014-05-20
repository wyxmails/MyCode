#include <iostream>
using namespace std;
int StackSize = 10;
int StackNum = 10;
class stack{
	public:
		stack(int size=StackSize){
			buf = new int[size];
			cur = -1;
			capa = size;
		}
		~stack(){
			delete []buf;
		}
		void push(int val){
			buf[++cur] = val;
		}
		void pop(){
			--cur;
		}
		int top(){
			return buf[cur];
		}
		bool empty(){
			return cur==-1;
		}
		bool full(){
			return cur==(capa-1);
		}
	private:
		int cur;
		int capa;
		int *buf;
};
class SetOfStack{
	public:
		SetOfStack(int size=StackNum){
			buf = new stack[size];
			cur = 0;
			capa = size;
		}
		~SetOfStack(){
			delete[] buf;
		}
		void push(int val){
			if(buf[cur].full()) cur++;
			buf[cur].push(val);
		}
		void pop(){
			if(buf[cur].empty()) cur--;
			buf[cur].pop();;
		}
		int top(){
			if(buf[cur].empty()) --cur;
			return buf[cur].top();
		}
		bool empty(){
			if(cur==0) return buf[cur].empty();
			return false;
		}
		bool full(){
			if(cur==(capa-1)) return buf[cur].full();
			return false;
		}
	private:
		stack *buf;
		int cur;
		int capa;
};

class SetOfStackAt{
	public:
		SetOfStackAt(int size=StackNum){
			buf = new stack[size];
			cur = 0;
			capa = size;
		}
		void push(int val){
			if(buf[cur].full()) cur++;
			buf[cur].push(val);
		}
		void pop(){
			while(buf[cur].empty()) cur--;
			buf[cur].pop();
		}
		void popAt(int index){
			while(buf[index].empty()) index--;
			buf[index].pop();
		}
		int top(){
			while(buf[cur].empty()) cur--;
			return buf[cur].top();
		}
		bool empty(){
			if(cur==0) return buf[cur].empty();
			return false;
		}
		bool full(){
			if(cur==(capa-1)) return buf[cur].full();
			return false;
		}
	private:
		stack *buf;
		int cur;
		int capa;
};

int main(int argc,char*argv[]){
	SetOfStack ss;
	for(int i=0;i<3*StackSize+1;++i){
		ss.push(i);
	}
	for(int i=0;i<StackSize;++i){
		cout << ss.top() << endl;
		ss.pop();
	}
	return 0;
}
