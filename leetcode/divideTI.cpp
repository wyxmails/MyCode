/*Divide two integers without using multiplication, 
  division and mod operator.*/
#include <iostream>
using namespace std;
int divide(int dividend, int divisor) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int cnt=0,quo=0,sum=0;
	long long d1,d2;
	bool neg = false;
	d1 = dividend;
	d2 = divisor;
	if(dividend>=0&&divisor>=0){
		d1 = d1;
		d2 = d2;
	}else if(dividend<0&&divisor<0){
		d1 = -d1;
		d2 = -d2;
	}else{
		neg = true;
		if(dividend<0){
		d1 = -d1;
		d2 = d2;
		}else{
		d1 = d1;
		d2 = -d2;
		}
	}
	long long dd = d1;
	while(dd>0){
		dd = dd>>1;
		cnt++;
	}
	dd = d2;
	while(dd>0){
		dd = dd>>1;
		cnt--;
	}
	long long tmp = d2<<cnt;
	while(cnt>=0&&d1>=0){
		while(cnt>0&&tmp>d1){
			cnt--;
			tmp = d2<<cnt;
		}
		if(tmp<=d1){
		   	d1 -= tmp;
			if(cnt>=0) quo += 1<<cnt;
		}
		if(cnt==0) break;
	}
	if(d1<0) quo--;
	if(neg) quo = -quo;
	return quo;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout << divide(a,b) << endl;
}
