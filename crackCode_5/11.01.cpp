/*
 Youare given two sorted arrays, A and B, 
 where A has a large enough buffer at the end to hold B.
 Write a method to merge B into A in sorted order.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &A,vector<int> B){
	int n = A.size()-1;
	int b = B.size()-1;
	int a = n-b-1;
	while(a>=0&&b>=0){
		if(A[a]>B[b]) A[n--] = A[a--];
		else A[n--] = B[b--];
	}
	while(b>=0) A[b] = B[b--];
}

int main(){
	int n,a,b;
	srand(time(NULL));
	n = rand()%20+1;
	a = rand()%n;
	b = n-a;
	n += 2;
	a++;
	b++;
	cout << n << " " << a << " " << b << endl;
	vector<int> vec1(n),vec2(b);
	int pre = 0;
	for(int i=0;i<a;++i){
		int tmp = rand()%5+pre;
		vec1[i] = tmp;
		pre = tmp;
		cout << tmp << " ";
	}
	cout << endl;
	pre = 0;
	for(int i=0;i<b;++i){
		int tmp = rand()%5+pre;
		vec2[i] = tmp;
		pre = tmp;
		cout << tmp << " ";
	}
	cout << endl;
	merge(vec1,vec2);
	cout << "result: " << endl;
	for(int i=0;i<vec1.size();++i)
		cout << vec1[i] << " ";
	cout << endl;
	return 0;
}
