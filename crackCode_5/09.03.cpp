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

int MagicIndexDup(const vector<int>&A,int l,int r){
	 if(l>r) return -1;
	 int m = (l+r)/2;
	 if(A[m]==m) return m;
	 int mr = min(m-1,A[m]);
	 int resl = MagicIndexDup(A,l,mr);
	 if(resl!=-1) return resl;
	 int ml = max(m+1,A[m]);
	 int resr = MagicIndexDup(A,ml,r);
	 if(resr!=-1) return resr;
	 return -1;
}

int MagicIndexDup(vector<int> A){
	int l=0,r=A.size()-1;
	return MagicIndexDup(A,l,r);
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
	int arr[] = {-1,0,1,3,3,4,4,5,6,7};
	vector<int> vec1;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
		cout << arr[i] << " ";
		vec1.push_back(arr[i]);
	}
	cout << endl;
	cout << MagicIndexDup(vec1) << endl;
	return 0;
}
