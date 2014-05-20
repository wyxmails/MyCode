#include <iostream>
using namespace std;

class stack3{
	public:
		stack3(int size=100){
			arr = new int[size*3];
			index[0] = index[1] = index[2] = 0;
			capa = size;
		}
		~stack3(){
			delete[] arr;
		}
		void push(int v,int sNum){
			if(!full(sNum))
				arr[sNum*capa+index[sNum]++] = v;
		}
		void pop(int sNum){
			if(!empty(sNum))
				index[sNum]--;
		}
		int top(int sNum){
			if(!empty(sNum))
				return arr[sNum*capa+index[sNum]-1];
		}
		bool empty(int sNum){
			return index[sNum]==0;
		}
		bool full(int sNum){
			return index[sNum]==capa;
		}
	private:
		int *arr;
		int index[3];
		int capa;
};

typedef struct Node{
	int val,pre;
}Node;

class stack3_1{
	public:
		stack3_1(int size=100){
			buf = new Node[size*3];
			index[0] = index[1] = index[2] = -1;
			capa = size;
			cur = 0;
		}
		~stack3_1(){
			delete []buf;
		}
		void push(int v,int sNum){
			if(!full()){
				buf[cur].val = v;
				buf[cur].pre = index[sNum];
				index[sNum] = cur;
				cur++;
			}
		}
		void pop(int sNum){
			if(!empty(sNum)){
				index[sNum] = buf[index[sNum]].pre;
			}
		}
		int top(int sNum){
			if(!empty(sNum)){
				if(!empty(sNum))
					return buf[index[sNum]].val;
			}
		}
		bool empty(int sNum){
			return index[sNum]==-1;
		}
		bool full(){
			return cur==capa*3;
		}
	private:
		Node *buf;
		int index[3];
		int capa;
		int cur;
};

int main(int argc,char *argv[]){
	stack3 s1;
	s1.push(0,0);
	s1.push(1,1);
	s1.push(2,2);
	cout << s1.top(0) << s1.top(1) << s1.top(2) << endl;
	stack3_1 s2;
	s2.push(0,0);
	s2.push(1,1);
	s2.push(2,2);
	cout << s2.top(0) << s2.top(1) << s2.top(2) << endl;
	
}
