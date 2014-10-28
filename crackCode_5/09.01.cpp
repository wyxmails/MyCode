/*
 A child is running up a staircase with n steps, and can hop either 1step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.
 */

#include <iostream>
#include <vector>
using namespace std;

int PossibleWays(int n){
	if(n<0) return 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 1;
	for(int i=1;i<=n;++i){
		int tmp = s1;
		s1 = s2;
		s2 =s3;
		s3 = tmp+s1+s2;
	}
	return s3;
}

int PossibleWays2(int n,vector<int>&arr){
	if(n<0) return 0;
	if(n==0) return 1;
	if(arr[n]!=-1) return arr[n];
	arr[n] = PossibleWays2(n-1,arr)+PossibleWays2(n-2,arr)+PossibleWays2(n-3,arr);
	return arr[n];
}
int PossibleWays2(int n){
	vector<int> mark(n+1,-1);
	return PossibleWays2(n,mark);
}

int main(int argc,char*argv[]){
	int n = 1;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	n = 2;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	n = 3;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	n = 4;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	n = 5;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	n = 6;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	n = 7;
	cout << PossibleWays(n) << endl;
	cout << PossibleWays2(n) << endl;
	return 0;
}
