/*
 Given a positive integer, 
 print the next smallest and the next largest number 
 that have the same number of 1 bits in their binary representation.
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> NextLSest2(int v){
	vector<int> res(2,-1);
	int c = v,c0=0,c1=0;
	while((c&1)==0){
		c0++;
		c >>= 1;
	}
	while((c&1)==1){
		c1++;
		c >>= 1;
	}
	if(c0+c1==31||c0+c1==0) return res;
	res[0] = v+(1<<c0)+(1<<(c1-1))-1;
	c=v;c0=0;c1=0;
	while((c&1)==1){
		c1++;
		c >>= 1;
	}
	if(c==0) return res;
	while((c&1)==0){
		c0++;
		c >>= 1;
	}
	res[1] = v-(1<<c1)-(1<<(c0-1))+1;
	return res;
}

int main(int argc,char*argv[]){
	int a = 6;
	vector<int> res2 = NextLSest2(a);
	cout << a << "'s next lagest: " << res2[0] << " smallest: " << res2[1] << endl;
	a=5;
	res2 = NextLSest2(a);
	cout << a << "'s next lagest: " << res2[0] << " smallest: " << res2[1] << endl;
	a=107;
	res2 = NextLSest2(a);
	cout << a << "'s next lagest: " << res2[0] << " smallest: " << res2[1] << endl;
	return 0;
}
