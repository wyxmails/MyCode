/*
 Implement int sqrt(int x).
 Compute and return the square root of x.
 */
#include <iostream>
using namespace std;

int sqrt(int x) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int sss=x;
	int bits = 0;
	while(sss){
		sss = sss>>1;
		bits++;
	}
	long long num=0;
	int index = 1;
	long long tmp;
	while(1){
		tmp = index<<(bits/2+1);
		if((tmp+num)*(tmp+num)==x){
			num += tmp;
			break;
		}else if((tmp+num)*(tmp+num)<x){
			num +=tmp;
			bits -= 2;
		}else if((tmp+num)*(tmp+num)>x){
			bits -= 2;
		}
		if(bits<0) break;
	}
	if(num*num==x) return num;
	else if(num*num<x){
		if((num+1)*(num+1)<=x) return num+1;
		else return num;
	}
}
int main(){
	int x;
	cin>>x;
	cout << sqrt(x) << endl;
}
