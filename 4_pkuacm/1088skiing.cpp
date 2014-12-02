//dp problems
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct node{
	int x;
	int y;
	int h;
}node;
int cmp(const void*s1,const void*s2){
	node *p1;
	node *p2;
	p1 = (node*)s1;
	p2 = (node*)s2;
	return p1->h-p2->h;
}
int main(int argc,char*argv[]){
	int R,C,tmp;
	node arr[10010];
	int res[10010];
	scanf("%d%d",&R,&C);
	int count=0;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			arr[count].x = i;
			arr[count].y = j;
			scanf("%d",&arr[count].h);
			count++;
		}
	}
	qsort(arr,count,sizeof(node),cmp);
	res[0] = 1;
	for(int i=1;i<count;++i){
		tmp=1;
		for(int j=i-1;j>=0;--j){
			if((abs(arr[j].x-arr[i].x)==1&&arr[j].y==arr[i].y)||
					(abs(arr[j].y-arr[i].y)==1&&arr[j].x==arr[i].x)){
				if(arr[j].h<arr[i].h&&res[j]+1>tmp) tmp = res[j]+1;
			}
		}
		res[i] = tmp;
	}
	int Max=1;
	for(int i=0;i<count;++i) if(res[i]>Max) Max = res[i];
	cout << Max << endl;
	return 0;
}
