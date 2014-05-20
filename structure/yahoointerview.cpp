#include <iostream>
using namespace std;

struct Node{
	Node *left;
	Node *right;
	int value;
};

struct reType{
	bool isUnival;
	int value;
	int num;
};

bool isUnival(Node *n)
{
	Node *l,*r;
	int tmpV;
	tmpV = n->value;
	l=r=NULL;
	l = n->left;
	r = n->right;    
	if(l!=NULL&&l->value!=tmpV) return false;
	if(l!=NULL&&!isUnival(l)) return false;   
	
	
	if(r!=NULL&&r->value!=tmpV) return false;
	if(r!=NULL&&!isUnival(r)) return false;
	
	return true;
}


struct reType countNumUnivalSubtrees(Node *n){
	Node *l, *r;
	int startV;
	startV = n->value;
	l = n->left;
	r = n->right;
	reType rtmp,r1,r2;
	if(l==NULL&&r==NULL){
		rtmp.isUnival = true;
		rtmp.value = startV;
		rtmp.num = 1;
		return rtmp;
	}else{
		if(l==NULL){
			r2 = countNumUnivalSubtrees(r);
			r1.isUnival = true;
			r1.value = startV;
			r1.num = 0;
		}else if(r==NULL){
			r1 = countNumUnivalSubtrees(l);
			r2.isUnival = true;
			r2.value = startV;
			r2.num = 0;

		}else{
			r1 = countNumUnivalSubtrees(l);
			r2 = countNumUnivalSubtrees(r);
		}
	}
	if(r1.isUnival&&r2.isUnival){
		if(startV==r1.value&&startV==r2.value){
			rtmp.isUnival = true;
			rtmp.value = startV;
			rtmp.num = r1.num +r2.num+1;
		}else{
			rtmp.isUnival = false;
			rtmp.value = startV;
			rtmp.num = r1.num + r2.num;
		}
	}else{
		rtmp.isUnival = false;
		rtmp.value = startV;
		rtmp.num = r1.num + r2.num;
	}
	return rtmp;
}

int main(int argc,char*argv[]){
	Node *root,*node;
	for(int i=1;i<=3;++i){
		node = new Node;
		node->value=1;
		//node->value = i;
		node->left=NULL;
		node->right=NULL;
		if(i==1) root=node;
		if(i==2) root->left=node;
		if(i==3) root->right=node;
	}
	if(isUnival(root)) cout << "Unival" << endl;
	else cout << "not Unival" << endl;
	reType rtmp;
	rtmp = countNumUnivalSubtrees(root);
	cout << rtmp.num << endl;
}
