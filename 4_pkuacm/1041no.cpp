#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
using namespace std;

int output[2000];
map<int,int> junction[50];
set<int> graph[50][50];
bool dfs(int s1,int x,int y,int &count){
	set<int>::iterator it;
	it = graph[x][y].begin();
	it++;
	it--;
	output[count] = *it;
	junction[x].erase(output[count]);
	junction[y].erase(output[count]);
	graph[x][y].erase(it);
	for(it=graph[y][x].begin();it!=graph[y][x].end();++it)
		if(*it==output[count]){
			graph[y][x].erase(it);
			break;
		}
	count++;
	if(s1==y) return true;
	for(map<int,int>::iterator it1=junction[y].begin();it1!=junction[y].end();++it1){
		if(!graph[y][(*it1).second].empty())
			if(dfs(s1,y,(*it1).second,count)) return true;
			else return false;
	}
	return false;
}
int main(int argc,char*argv[]){
	int x,y,z,s1,s2,count,i,j;
	set<int> node;
	bool flag,connect;
	while(scanf("%d%d",&x,&y)==2&&(x+y)){
		node.clear();
		for(i=0;i<50;++i){
			map<int,int> tmpmap;
			tmpmap.clear();
			junction[i] = tmpmap;
			for(int j=0;j<50;++j){
				set<int> tmp;
				tmp.clear();
				graph[i][j]=tmp;
			}
		}
		scanf("%d",&z);
		s1=x,s2=y;
		graph[x][y].insert(z);
		graph[y][x].insert(z);
		junction[x][z] = y;
		junction[y][z] = x;
		node.insert(x);
		node.insert(y);
		while(scanf("%d%d",&x,&y)==2&&(x+y)){
			scanf("%d",&z);
			graph[x][y].insert(z);
			graph[y][x].insert(z);
			junction[x][z] = y;
			junction[y][z] = x;
			node.insert(x);
			node.insert(y);
		}
		connect = true;
		set<int>::iterator itset1,itset2;
		itset1=itset2=node.begin();
		for(itset2++;itset2!=node.end();++itset1,++itset2){
			if(graph[*itset1][*itset2].empty()){
				connect=false;
				break;
			}
		}
		if(!connect){
			printf("Round trip does not exist.\n");
			continue;
		}
		count=0;
		if(!dfs(s1,s1,s2,count)){
			printf("Round trip does not exist.\n");
			continue;
		}
		flag = true;
		for(map<int,int>::iterator it=junction[s1].begin();it!=junction[s1].end();++it){
			if(!graph[s1][(*it).second].empty())
				if(!dfs(s1,s1,(*it).second,count)){
					flag = false;
					break;
				}
		}
		for(i=1;flag&&i<50;++i){
			for(j=1;j<50;++j){
				if(!graph[i][j].empty()){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			for(i=0;i<count;++i)
				printf("%d ",output[i]);
			printf("\n");
		}else
			printf("Round trip does not exist.\n");
		
	}
	return 0;
}
