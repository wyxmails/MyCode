#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N;
int M;
int ttime;
long long final;
typedef struct value{
	int w,c,num;
}value;
inline bool cmpvalue(const value &a,const value&b){
	return (double)a.c*b.w>(double)b.c*a.w;
}
value arr[20];
int brr[20];
inline bool cmp(int x,int y){
	return (double)arr[x].c*arr[y].w>(double)arr[y].c*arr[x].w;
}
bool chk(int LEFT,int dep,long long RES){
	double m=LEFT;
	double res=RES;
	for(int i=1;i<=N;++i){
		if(brr[i]>=dep){
			if(arr[brr[i]].w*arr[brr[i]].num<m){
				res += (double)arr[brr[i]].c*arr[brr[i]].num;
				m -= (double)arr[brr[i]].w*arr[brr[i]].num;
			}else{
				res += m/arr[brr[i]].w*arr[brr[i]].c;
				return res-(1e-6)>final;
			}
		if(res>final) return true;
		}
	}
	return res>final;
}
void dfs(int left,int dep,long long res){
	if(dep>N){
		if(res>final) final=res;
		return;
	}
	if((++ttime)>10000000) return;
	if(!chk(left,dep,res)) return;
	int i=arr[dep].num;
	while(i*(long long)arr[dep].w>left) i--;
	for(;i>=0;--i){
		dfs(left-i*arr[dep].w,dep+1,res+(long long)i*arr[dep].c);
	}
}

int main(int argc,char*argv[]){
	int t;
	scanf("%d",&t);
	while(t){
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;++i){
			scanf("%d",&arr[i].w);
			arr[i].num = i;
			brr[i] = i;
		}
		for(int i=1;i<=N;++i){
			scanf("%d",&arr[i].c);
		}
		sort(arr+1,arr+N+1,cmpvalue);
		sort(brr+1,brr+N+1,cmp);
		ttime=0;
		final=0;
		dfs(M,1,0);
		printf("%lld\n",final);
		t--;
	}
	return 0;
}
