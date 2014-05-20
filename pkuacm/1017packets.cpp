#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc,char*argv[]){
	int x1,x2,x3,x4,x5,x6,N,n2,n1;
	int num[4] = {0,5,3,1};
	while(scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6)){
		if(x1==0&&x2==0&&x3==0&&x4==0&&x5==0&&x6==0) break;
		N = x6+x5+x4+(x3+3)/4;
		n2 = 5*x4+num[x3%4];
		if(x2>n2) N += (x2-n2+8)/9;
		n1 = 36*N-36*x6-25*x5-16*x4-9*x3-4*x2;
		if(x1>n1) N += (x1-n1+35)/36;
		cout << N << endl;
	}
	return 0;
}
