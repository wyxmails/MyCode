#include <iostream>
using namespace std;

const int gSize=(1<<5);

struct Node{
	int key;
	int val;
	Node(int k,int v):key(k),val(v){}
};

class HashMap{
	private:
		Node **table;
	public:
		HashMap(){
			table = new Node*[gSize];
			for(int i=0;i<gSize;++i)
				table[i] = NULL;
		}
		~HashMap()
		{
			for(int i=0;i<gSize;++i)
				if(table[i]!=NULL)
					delete table[i];
			delete []table;
		}
		int get(int key){
			int index = key%gSize;
			int end = index;
			while(table[index]!=NULL&&table[index]->key!=key){
				index = (index+1)%gSize;
				if(index==end) return -1;
			}
			if(table[index]==NULL) return -1;
			return table[index]->val;
		}
		bool put(int key,int value){
			int index = key%gSize;
			int end = index;
			while(table[index]!=NULL&&table[index]->key!=key){
				index = (index+1)%gSize;
				if(index==end) return false;
			}
			if(table[index]!=NULL)
				delete table[index];
			table[index] = new Node(key,value);
		}
};

int main(){
	HashMap hm;
	hm.put(1,2);
	hm.put(3,5);
	cout << hm.get(1) << endl;
	cout << hm.get(3) << endl;
	return 0;
}
