#include <iostream>
using namespace std;

typedef struct Node{
	int val;
	Node *next;
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
			Node *nnode = new Node(v);
			nnode->next = buf;
			buf = nnode;
		}
		void pop(){
			if(!empty()){
				Node *tmp = buf;
				buf = buf->next;
				delete tmp;
			}
		}
		int top(){
			if(!empty()){
				return buf->val;
			}
		}
		bool empty(){
			return buf==NULL;
		}
	private:
		Node *buf;
};

void moveHanoi(myStack &src,myStack &mid,myStack &des,int n){
	if(n==0) return;
	if(n==1){
		if(src.empty()) return;
		int v = src.top();
		src.pop();
		des.push(v);
		return;
	}
	moveHanoi(src,des,mid,n-1);
	moveHanoi(src,mid,des,1);
	moveHanoi(mid,src,des,n-1);
}

int main(int argc,char*argv[]){
	myStack s1,s2,s3;
	int n=3;
	for(int i=0;i<n;++i){
		s1.push(n-i);
	}
	cout << s1.top() << endl << "des: " << endl;
	moveHanoi(s1,s2,s3,3);
	while(!s3.empty()){	cout << s3.top() << " ";
		s3.pop();
	}
	cout << endl;
	return 0;
}
