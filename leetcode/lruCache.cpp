#include <iostream>
#include <map>
using namespace std;
/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */
typedef struct Node{
	int v;
	int k;
	Node *next,*pre;
	Node(int key,int value):k(key),v(value),next(NULL),pre(NULL){}
}Node;

class LRUCache{
public:
	LRUCache(int capacity) {
		head=tail=NULL;
		cap = capacity;
		cur=0;
	}
	
	int get(int key) {
		map<int,Node*>::iterator it = mark.find(key);
		if(it!=mark.end()){
			Node*tmp = (*it).second;
			if(tmp!=head){
				if(tmp->pre!=NULL) tmp->pre->next = tmp->next;
				if(tmp->next!=NULL) tmp->next->pre = tmp->pre;
				else tail = tmp->pre;
				tmp->pre = NULL;
				tmp->next = head;
				head->pre = tmp;
				head = tmp;
			}
			return head->v;
		}
		return -1;
	}
	
	void set(int key, int value) {
		if(get(key)!=-1){
			mark[key]->v = value;
			return;
		}
		if(cur<cap){
			Node *n = new Node(key,value);
			if(head==NULL) tail = n;
			else{
				n->next = head;
				head->pre = n;
			}
			head = n;
			mark[key] = head;
			cur++;
		}else{
			mark.erase(tail->k);
			tail->k = key;
			tail->v = value;
			tail->next = head;
			head->pre = tail;
			head = tail;
			tail = tail->pre;
			head->pre = NULL;
			tail->next = NULL;
			mark[key] = head;
		}
	}
private:
	Node *head,*tail;
	map<int,Node*> mark;
	int cur;
	int cap;
};
int main(int argc,char*argv[]){
	LRUCache *l = new LRUCache(2);
	l->set(1,2);
	cout << l->get(1) << endl;
	l->set(3,4);
	cout << l->get(5) << endl;
	l->set(2,4);
	cout << l->get(3) << endl;
	return 0;
}
