/*
 A magic index in an array A[l...n-l] is defined to be an index such that A[i] = i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
 FOLLOW UP
 What if the values are not distinct?
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MagicIndex(vector<int> A){
	int l=0,r=A.size()-1;
	while(l<=r){
		int m = (l+r)/2;
		if(A[m]==m) return m;
		else if(A[m]>m) r = m-1;
		else l = m+1;
	}
	return -1;
}

int main(int argc,char *argv[]){
	srand(time(NULL));
	int n = rand()%10+2;
	int m = rand()%(n-1)+1;
	vector<int> vec(n,m);
	for(int i=m-1;i>=0;i--){
		int tmp = vec[i+1]-rand()%m-2;
		cout << tmp << " ";
		vec[i] = tmp;
	}
	cout << endl;
	for(int i=m+1;i<n;++i){
		int tmp = vec[i-1]+rand()%m+2;
		cout << tmp << " ";
		vec[i] = tmp;
	}
	cout << endl;
	cout << "m: " << m << endl;
	cout << MagicIndex(vec) << endl;
	return 0;
}
