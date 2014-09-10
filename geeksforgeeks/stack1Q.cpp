/*
 implement a stack using one queue 
 */
#include <iostream>
#include <queue>
using namespace std;

class myStack{
	private:
		queue<int> Q;
	public:
		bool empty(){
			return (Q.size()==0);
		}
		void push(int v){
			if(Q.empty()) Q.push(v);
			else{
				int n= Q.size();
				Q.push(v);
				while(n-->0){
					int tmp = Q.front();
					Q.pop();
					Q.push(tmp);
				}
			}
		}
		void pop(){
			Q.pop();
		}
		int top(){
			return Q.front();
		}
};

int main(int argc,char*argv[]){
	myStack ms;
	//ms.push(5);ms.push(4);ms.push(3);ms.push(2);ms.push(1);
	int v;
	while(cin>>v){
		ms.push(v);
	}
	while(!ms.empty()){
		cout << ms.top() << " ";
		ms.pop();
	}
	cout << endl;
	return 0;
}
