/*
 Write a program to swap odd and even bits in an integer 
 with as few instructions as possible
 (e.g.,bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
 */
#include <iostream>
using namespace std;

int ExOddEven(int N){
	int even_ones = 0x2aaaaaaa;
	int odd_ones = 0x55555555;
	return ((N&even_ones)>>1)|((N&odd_ones)<<1);
}

int main(int argc,char*argv[]){
	int N = 10;
	cout << ExOddEven(N) << endl;
	N=13;
	cout << ExOddEven(N) << endl;
	N=16;
	cout << ExOddEven(N) << endl;
	return 0;
}
