#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
typedef struct value{
	int w;
	int c;
	int num;
}value;
int cmp(const void*s1,const void*s2){
	value*p1;
	value*p2;
	p1 = (value*)s1;
	p2 = (value*)s2;
	return p2->c*p1->w-p1->c*p2->w;
}
int main(int argc,char*argv[]){
	int MMM=100010;
	int M,cost,tW,tC;
	int MAXN=150,N,tmpw,tmpc,count,count2,t;
	value arr[16];
	int totalW[MMM];
	int totalC[MMM];
	bool flag;
	scanf("%d",&t);
	while(t){
		scanf("%d%d",&N,&M);
		for(int i=0;i<MMM;++i){
			totalW[i] = 0;
			totalC[i] = 0;
		}
		for(int i=0;i<N;++i){
			scanf("%d",&arr[i].w);
			arr[i].num = i+1;
		}
		for(int i=0;i<N;++i){
			scanf("%d",&arr[i].c);
		}
		qsort(arr,N,sizeof(value),cmp);
		flag=false;
		tW=0;
		tC=0;
		for(int i=0;i<N&&!flag;++i){
			for(int k=1;k<=arr[i].num;++k){
				tW += arr[i].w;
				tC += arr[i].c;
				if(tW==M){
					flag=true;
					cost = tC;
					break;
				}
			}
			if(tW>M) break;
		}
		if(tW<M){
			flag = true;
			cost = tC;
		}
		count=0;
		count2=1;
		for(int i=0;i<N&&!flag&&count2<MMM;++i){
			count = count2-1;
			for(int k=1;k<=arr[i].num&&!flag;++k){
				for(int j=0;j<=count;++j){
					//cout << "j: " << j << " total: " << totalW[j] << " " << totalC[j] << endl;
					tmpw = totalW[j]+k*arr[i].w;
					tmpc = totalC[j]+k*arr[i].c;
					//cout << "tmp: " << tmpw << " " << tmpc << endl;
					if(tmpw==M){
						//cout << "kkk" << endl;
						flag=true;
						cost = tmpc;
						break;
					}
					if(tmpw>M) break;
					totalW[count2] = tmpw;
					totalC[count2] = tmpc;
					count2++;
				}
			}
		//	for(int k=1;k<=arr[i].num&&!flag;++k){
		//		if(k*arr[i].w==M){
		//			cout << "sss" << endl;
		//			flag=true;
		//			cost = k*arr[i].c;
		//			continue;
		//		}
		//		totalW[count2] = tmpw;
		//		totalC[count2] = tmpc;
		//		count2++;
		//	}
		}
		//cout << count2 << endl;
		if(!flag){
			cost=-1;
			for(int i=0;i<count2;++i){
				if(totalC[i]>cost){
					cost = totalC[i];
				}
			}
			cout << cost << endl;
		}else{
			cout << cost << endl;
		}
		t--;
	}
	return 0;
}
