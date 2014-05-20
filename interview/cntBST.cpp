//Given the numbers from 1 to n, write an algorithm to find how many distinct binary search trees can be formed.. eg n=4, no of distinct bst’s are 14. ??
//count number of binary search tree
#include <iostream>
using namespace std;

int arr[20];
int cntBst(int n){
	if(arr[n]>0) return arr[n];
	if(n==1||n==0){
	   	arr[n] = 1;
		return arr[n];
	}
	for(int i=0;i<n;++i){
		arr[n] += cntBst(i)*cntBst(n-i-1);
	}
	return arr[n];
}

int main(int mm,char*nn[]){
	for(int i=0;i<20;++i) cout << arr[i] << " ";
	cout << endl;
	int n;
	while(cin>>n)
		cout << cntBst(n) << endl;
	return 0;
}
