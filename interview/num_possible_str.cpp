#include <iostream>
using namespace std;

int myNum(int n,int b,int cc){
	if(n<0) return 0;
	if(n==0) return 1;
	if(n==1) return 2+b;
	if(n==2) return (2+b+2*b+2+cc);
	int res = 0;
	res += myNum(n-1,b,cc);
	res += myNum(n-2,b,cc);
	if(b>0){
	   	res += myNum(n-1,b-1,cc);
		res += myNum(n-2,b-1,cc);
	}
	if(cc>0){
	   	res += myNum(n-3,b,cc-1);
		if(b>0) myNum(n-3,b-1,cc-1);
	}
	return res;
}

int myDP(int n){
	
}

int numPosStr(int n){
	return myNum(n,1,1);
}

int main(int argc,char*argv[]){
	cout << numPosStr(1) << endl;
	cout << numPosStr(2) << endl;
	cout << numPosStr(3) << endl;
	cout << numPosStr(4) << endl;
	cout << numPosStr(5) << endl;
	return 0;
}
