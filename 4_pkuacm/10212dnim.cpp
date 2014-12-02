#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool board[100][100];
int width,height;
typedef struct node{
	int xpos;
	int ypos;
	node *next;
}node;
typedef struct graph{
	node *head;
	node *tail;
	int total;
}graph;

typedef struct key{
	int total;
	int width;
	int height;
	int weight;
}key;

void dfs4graph(graph& tmpgraph, int xpos, int ypos){
	if(xpos<0||ypos<0||xpos>=width||ypos>=height)	return;
	if(board[xpos][ypos]){
		board[xpos][ypos] = false;
		node *tmpnode = new node;
		tmpnode->xpos = xpos;
		tmpnode->ypos = ypos;
		tmpnode->next = NULL;
		if(tmpgraph.head==NULL){
			tmpgraph.head = tmpnode;
			tmpgraph.tail = tmpnode;
		}else{
			tmpgraph.tail->next = tmpnode;
			tmpgraph.tail = tmpnode;
		}
		tmpgraph.total++;
		dfs4graph(tmpgraph,xpos-1,ypos);
		dfs4graph(tmpgraph,xpos+1,ypos);
		dfs4graph(tmpgraph,xpos,ypos-1);
		dfs4graph(tmpgraph,xpos,ypos+1);
	}
	return;
}

bool vecCMP(const key key1,const key key2){
	if(key1.total!=key2.total){
		return key1.total<key2.total?true:false;
	}else if(key1.width!=key2.width){
		return key1.width<key2.width?true:false;
	}else if(key1.height!=key2.height){
		return key1.height<key2.height?true:false;
	}else if(key1.weight!=key2.weight){
		return key1.weight<key2.weight?true:false;
	}else{
		return true;
	}
}
int process(vector<graph>&vecgraph,vector<key>&veckey){
	for(int i=0;i<100;++i){
		for(int j=0;j<100;++j){
			if(board[i][j]){
				graph tmpgraph;
				tmpgraph.head = NULL;
				tmpgraph.tail = NULL;
				tmpgraph.total = 0;
				dfs4graph(tmpgraph,i,j);
				vecgraph.push_back(tmpgraph);
			}
		}
	}
	int left,right,bottom,top;
	vector<graph>::iterator it=vecgraph.begin();
	for(;it!=vecgraph.end();++it){
		left=bottom=100;
		right=top=-1;
		node* tmpnode = (*it).head;
		while(tmpnode!=NULL){
			if(tmpnode->xpos<left) left = tmpnode->xpos;
			if(tmpnode->xpos>right) right = tmpnode->xpos;
			if(tmpnode->ypos<bottom) bottom = tmpnode->ypos;
			if(tmpnode->ypos>top) top = tmpnode->ypos;
			tmpnode = tmpnode->next;
		}
		left--;
		bottom--;
		right++;
		top++;
		key tmpkey;
		tmpkey.total = (*it).total;
		tmpkey.width = right - left -1;
		tmpkey.height = top - bottom - 1;
		tmpkey.weight = 0;
		if(tmpkey.width<tmpkey.height){
			int tmp = tmpkey.width;
			tmpkey.width = tmpkey.height;
			tmpkey.height = tmp;
		}
		tmpnode = (*it).head;
		while(tmpnode!=NULL){
			tmpkey.weight += (tmpnode->xpos-left)*(tmpnode->xpos-left);
			tmpkey.weight += (tmpnode->xpos-right)*(tmpnode->xpos-right);
			tmpkey.weight += (tmpnode->ypos-bottom)*(tmpnode->ypos-bottom);
			tmpkey.weight += (tmpnode->ypos-top)*(tmpnode->ypos-top);
			tmpnode = tmpnode->next;
		}
		veckey.push_back(tmpkey);
	}
	//free memory
	for(it = vecgraph.begin();it!=vecgraph.end();++it){
		node *tmp = (*it).head;
		node *tmp1;
		while(tmp!=NULL){
			tmp1 = tmp->next;
			delete tmp;
			tmp = tmp1;
		}
	}
	sort(veckey.begin(),veckey.end(),vecCMP);
}

void compare(vector<key>&veckey1,vector<key>&veckey2){
	if(veckey1.size()!=veckey2.size()){
		cout << "NO" << endl;
		return;
	}else{
		vector<key>::iterator it1,it2;
		it1 = veckey1.begin();
		it2 = veckey2.begin();
		for(;it1!=veckey1.end()&&it2!=veckey2.end();++it1,++it2){
			if((*it1).total!=(*it2).total||
					(*it1).width!=(*it2).width||
					(*it1).height!=(*it2).height||
					(*it1).weight!=(*it2).weight){
				cout << "NO" << endl;
				break;
			}
		}
		if(it1==veckey1.end()&&it2==veckey2.end()){
			cout << "YES" << endl;
		}
	}
}

int main(int argc,char*argv[]){
	int testcase,n,xpos,ypos;
	vector<graph> vecgraph1,vecgraph2;
	vector<key> veckey1,veckey2;
	cin>>testcase;
	while(testcase){
		vecgraph1.clear();
		vecgraph2.clear();
		veckey1.clear();
		veckey2.clear();
		cin>>width>>height>>n;
		//first board
		for(int i=0;i<100;++i){
			for(int j=0;j<100;++j){
				board[i][j] = false;
			}
		}
		for(int i=0;i<n;++i){
			cin>>xpos>>ypos;
			board[xpos][ypos] = true;
		}
		process(vecgraph1,veckey1);
		//second board
		for(int i=0;i<100;++i){
			for(int j=0;j<100;++j){
				board[i][j] = false;
			}
		}
		for(int i=0;i<n;++i){
			cin>>xpos>>ypos;
			board[xpos][ypos] = true;
		}
		process(vecgraph2,veckey2);
		//compare
		compare(veckey1,veckey2);
		testcase--;
	}
	return 0;
}
