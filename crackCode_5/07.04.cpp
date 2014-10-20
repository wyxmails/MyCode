/*
 Write methods to implement the multiply, subtract, 
 and divide operations for integers. Use only the add operator.
 */
#include <iostream>
using namespace std;

int negate(int a){
	int neg = 0;
	int d = a>0?-1:1;
	while(a!=0){
		a += d;
		neg += d;
	}
	return neg;
}

int multiply(int x1,int x2){
	int p1=x1,p2=x2;
	if(p1<0) p1 = negate(p1);
	if(p2<0) p2 = negate(p2);
	int res = 0;
	for(int i=0;i<p1;++i)
		res += p2;
   if((x1<0&&x2>0)||(x1>0&&x2<0)) res = negate(res);
   return res;
}

int subtract(int x1,int x2){
	x2 = negate(x2);
	return x1+x2;
}
int divide(int x1,int x2){
	int p1 = x1,p2=x2;
	bool neg = false;
	if(p1<0){ p1 = negate(p1);neg = !neg;}
	if(p2<0){ p2 = negate(p2);neg = !neg;}
	int sum=p2;
	int cnt=1;
	while(sum+p2<=p1){
		cnt++;
		sum += p2;
	}
	if(neg) return negate(cnt);
	return cnt;
}
