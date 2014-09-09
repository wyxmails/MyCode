#include <iostream>
#include <queue>
using namespace std;

/*implement stack with queue*/

class myS{
	private:
		queue<int> Q1;
		queue<int> Q2;
	public:
		void push(int v){
			Q1.push(v);
		}
		int top(){
			while(Q1.size()>1){
				Q2.push(Q1.front());
				Q1.pop();
			}
			int v = Q1.front();
			Q1.pop();
			Q2.push(v);
			queue<int> tmp = Q1;
		    Q1 = Q2;
			Q2 = tmp;
			return v;
		}
		void pop(){
			while(Q1.size()>1){
				Q2.push(Q1.front());
				Q1.pop();
			}
			Q1.pop();
			queue<int> tmp = Q1;
			Q1 = Q2;
			Q2 = tmp;
		}
};

int main(int argc,char*argv[]){
	myS ns;
	for(int i=1;i<=5;++i) ns.push(i);
	for(int i=5;i>=3;--i){
		cout << ns.top() << " ";
		ns.pop();
	}
	for(int i=6;i<=10;++i) ns.push(i);
	for(int i=10;i>=6;--i){
		cout << ns.top() << " ";
		ns.pop();
	}
	cout << endl;
	return 0;
}

