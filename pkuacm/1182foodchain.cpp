#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct node{
	int judge;
	int a1;
	int a2;
}node;
int main(int argc,char*argv[]){
	int N,K,fake,judge,a1,a2,i,j,count;
	bool flag;
	int animal[50010];
	node dsc[100010];
	scanf("%d%d",&N,&K);
	for(i=0;i<=N;++i){
		animal[i] = 0;
	}
	fake=0;
	i=0;
	count=1;
	while(i<K){
		scanf("%d%d%d",&judge,&a1,&a2);
		i++;
		if(a1>N||a2>N){
			fake++;
			continue;
		}
		if(judge==1){
			if(a1==a2) continue;
			if(animal[a1]&&animal[a2]&&animal[a1]!=animal[a2]&&abs(animal[a1]-animal[a2])<3){
				fake++;
				continue;
			}
		}
		if(judge==2){
			if(a1==a2){
				fake++;
				continue;
			}
			if(animal[a1]&&animal[a2]&&animal[a1]==animal[a2]){
				fake++;
				continue;
			}
		}
		flag=true;
		for(j=i-1;j>=0;--j){
			if(a1==dsc[j].a1&&a2==dsc[j].a2
					||a1==dsc[j].a2&&a2==dsc[j].a1){
				if(judge!=dsc[j].judge){
					fake++;
					flag=false;
					break;
				}
			}
		}
		if(!flag) continue;
		if(judge==1){
			if(animal[a1]!=0) animal[a2] = animal[a1];
			else if(animal[a2]!=0) animal[a1] = animal[a2];
			else{
				animal[a1] = animal[a2] = 3*(count-1) + 1;
				count++;
			}
		}else if(judge==2){	
			if(animal[a1]!=0){
				int tmp = animal[a1]%3>0?1:-2;
				animal[a2] = (animal[a1]+tmp);//animal[a1]%3>0?1:-2);
			}else if(animal[a2]!=0){
			   	int tmp = animal[a2]%3==1?2:-1;
				animal[a1] = (animal[a2] + tmp);//animal[a2]%3==1?2:-1);
			}else{
				animal[a1] = 3*(count-1) + 1;
				animal[a2] = animal[a1] + 1;
				count++;
			}
		}
	}
	cout << fake << endl;
	return 0;
}
