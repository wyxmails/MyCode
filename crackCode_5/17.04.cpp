/*
 Write a method which finds the maximum of two numbers. 
 You should not use if-else or any other comparison operator.
 */

#include <iostream>
#include <climits>
using namespace std;

int flip(int bit){
	return 1^bit;
}

int getSign(int x){
	return (flip(x>>31&&1));
}

int getBig(int a,int b){
	int k = getSign(a-b);
	int q = flip(k);
	return a*k+b*q;
}

//getBig can not process overflow condition
int getBig2(int a,int b){
	int sa = getSign(a);
	int sb = getSign(b);
	int sc = getSign(a-b);

	int use_sa = sa^sb;
	int use_sc = flip(sa^sb);

	int k = use_sa*sa+use_sc*sc;
	int q = flip(k);
	return a*k+b*q;
}

int main(int argc,char*argv[]){
	int a,b;
	cout << "INT_MAX: " << INT_MAX << endl;
	cin>>a>>b;
	/*bad case: 2147483645 -9*/
	cout << "bigger one: " << getBig(a,b) << endl;
	cout << "bigger one2: " << getBig2(a,b) << endl;
	return 0;
}
