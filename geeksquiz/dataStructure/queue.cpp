#include <iostream>
#include <stack>
using namespace std;

/*implement queue with stack*/
//deQ costly version
class myQ{
	private:
		stack<int> S1;
		stack<int> S2;
	public:
		void enQ(int v){
			S1.push(v);
		}
		int deQ(){
			if(S2.empty()){
				while(!S1.empty()){
					S2.push(S1.top());
					S1.pop();
				}
			}
			if(S2.empty()) return -1;
			int v=S2.top();
			S2.pop();
			return v;
		}
};

class myQ1{
	private:
		stack<int> S1;
		stack<int> S2;
	public:
		void enQ(int v){
			if(!S2.empty()){
				while(!S2.empty()){
					S1.push(S2.top());
					S2.pop();
				}
			}
			S2.push(v);
			while(!S1.empty()){
				S2.push(S1.top());
				S1.pop();
			}
		}
		int deQ(){
			if(!S2.empty()){
				int v = S2.top();
				S2.pop();
				return v;
			}
			return -1;
		}
};

int main(int argc,char*argv[]){
	int v;
	myQ nq;
	for(int i=1;i<=5;++i) nq.enQ(i);
	for(int i=1;i<=3;++i) cout << nq.deQ() << " ";
	for(int i=6;i<=10;++i) nq.enQ(i);
	for(int i=4;i<=8;++i) cout << nq.deQ() << " ";
	cout << endl;
	myQ1 nq1;
	for(int i=1;i<=5;++i) nq1.enQ(i);
	for(int i=1;i<=3;++i) cout << nq1.deQ() << " ";
	for(int i=6;i<=10;++i) nq1.enQ(i);
	for(int i=4;i<=8;++i) cout << nq1.deQ() << " ";
	cout << endl;
	return 0;
}
