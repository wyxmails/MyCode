#include <iostream>
using namespace std;
/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

  For example,
  Given n = 3, there are a total of 5 unique BST's.

     1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
      /     /       \                 \
     2     1         2                 3
 */
int numTrees(int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	static int arr[20];
	if(arr[n]>0) return arr[n];
	if(n==1||n==0){
		arr[n] = 1;
		return arr[n];
	}
	for(int i=0;i<n;++i){
		arr[n] += numTrees(i)*numTrees(n-i-1);
	}
	return arr[n];
}
int main(int argc,char*argv[]){
	return 0;
}
