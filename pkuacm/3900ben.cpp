#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct value{
	long long w;
	long long c;
	int num;
}value;

int main(int argc,char*argv[]){
	long long M,cost;
	int MAXN=150,N,tmpw,tmpc,count,t;
	struct value tmpv;
	value arr[MAXN];
	vector<struct value> f[MAXN];
	scanf("%d",&t);
	while(t){
		scanf("%d%lld",&N,&M);
		for(int i=1;i<=N;++i){
			scanf("%lld",&arr[i].w);
			arr[i].num = i;
		}
		for(int i=1;i<=N;++i){
			scanf("%lld",&arr[i].c);
		}
		for(int i=0;i<=N*(N+1)/2;++i){
			vector<struct value> tmpvec;
			tmpvec.clear();
			f[i] = tmpvec;
		}
		tmpv.w=0;
		tmpv.c=0;
		tmpv.num=0;
		f[0].push_back(tmpv);
		//qsort(arr,N,sizeof(value),cmp);
		vector<struct value>::iterator it,it1,it2;
		for(int i=0;i<N*(N+1)/2;++i){
			for(it=f[i].begin();it!=f[i].end();++it){
				for(int k=1;k<=N;++k){
					tmpw = (*it).w + arr[k].w;
					tmpc = (*it).c + arr[k].c;
					if(tmpw>M) continue;
					for(it1=f[i+1].begin();it1!=f[i+1].end();++it1){
						if((*it1).w==tmpw) break;
					}
					count=0;
					if(it1!=f[i+1].end()&&(*it1).c<tmpc||it1==f[i+1].end()){
						if((*it).num==k) count++;
						tmpw = (*it).w-arr[(*it).num].w;
						tmpc = (*it).c-arr[(*it).num].c;
						for(int index=i-1;index>=0;--index){
							for(it2=f[index].begin();it2!=f[index].end();++it2){
								if((*it2).w==tmpw&&(*it2).c==tmpc){
									break;
								}
							}
							if((*it2).num==k) count++;
							tmpw = (*it2).w-arr[(*it2).num].w;
							tmpc = (*it2).c-arr[(*it2).num].c;
						}
						if(count<k){
							if(it1!=f[i+1].end()){
								(*it1).c = (*it).c+arr[k].c;
								(*it1).num = k;
							}else{
								tmpv.c = (*it).c+arr[k].c;
								tmpv.w = (*it).w+arr[k].w;
								tmpv.num = k;
								f[i+1].push_back(tmpv);
							}
						}
					}
				}
			}
		}
		cost=-1;
		for(int i=1;i<=N*(N+1)/2;++i){
			for(it=f[i].begin();it!=f[i].end();++it){
				if((*it).w<=M&&(*it).c>cost) cost = (*it).c;
			}
		}
		printf("%lld\n",cost);
		t--;
	}
	return 0;
}
