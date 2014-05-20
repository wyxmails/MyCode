#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc,char*argv[]){
	int t,n,i,j,num;
	int P[21];
	int W[21];
	scanf("%d",&t);
	while(t){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&P[i]);
		for(i=0;i<n;++i){
			if(i==0){
				W[i] = 1;
				for(j=0;j<n;++j) P[j] -= 1;
				continue;
			}
			j=i-1;
			while(j>=0&&P[j]==P[i]) j--;
			num = i-1-j;
			W[i] = num+1;
			for(j++;j<n;++j) P[j] -= 1;
		}
		for(i=0;i<n-1;++i) printf("%d ",W[i]);
		printf("%d\n",W[i]);
		t--;
	}
	return 0;
}
