#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc,char*argv[]){
	long L,M,s,e,sum;
	while(scanf("%ld%ld",&L,&M)&&(L+M)){
		sum = 0;
		for(int i=0;i<M;++i){
			scanf("%ld%ld",&s,&e);
			sum += e-s+1;
		}
		printf("%ld\n",L+1-sum);
	}
	return 0;
}
