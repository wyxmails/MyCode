/*
 You are given two 32-bit numbers,N and M, and two bit positions, i and j. 
 Write a method to insert M into N 
 such that M starts at bit j and ends at bit i. 
 You can assume that the bits j through i have enough space to fit all of M.
 That is,if M=10011, 
 you can assume that there are at least 5 bits between j and i. 
 You would not, for example,have j=3 and i=2,
 because M could not fully fit between bit 3 and bit 2.
EXAMPLE:
Input: N = 16000000000, M = 10011, i = 2, j = 6 Output: N = 10001001100
 */

#include <iostream>
using namespace std;

int BitInsert(int N,int M,int i,int j){
	int all_ones = ~0;
	int left = all_ones<<(j+1);
	int right = ((1<<i)-1);
	int mark = left|right;
	N &= mark;
	M <<= i;
	return N|M;
}
int main(int argc,char*argv[]){
	int N = 0x400;
	int M = 0x13;
	cout << BitInsert(N,M,2,6) << endl;
	return 0;
}
