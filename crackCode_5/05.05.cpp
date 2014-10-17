/*
 Write a function to determine the number of bits required 
 to convert integer A to integer B.
 */

#include <iostream>
using namespace std;

int Bits2Convert(int A,int B){
	int C = A^B;
	int cnt=0;
	while(C>0){
		if(C&1) cnt++;
		C >>= 1;
	}
	return cnt;
}
int Bits2Convert2(int A,int B){
	int cnt=0;
	for(int c=A^B;c>0;c=c&(c-1))
		cnt++;
	return cnt;
}

int main(int argc,char*argv[]){
	int A=10;
	int B=30;
	cout << Bits2Convert(A,B) << endl;
	cout << Bits2Convert2(A,B) << endl;
	return 0;
}
