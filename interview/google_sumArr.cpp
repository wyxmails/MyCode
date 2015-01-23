/*
 You are given an array of integers 'a' that can fit in a memory. Write a method that retuns an array of the same lenght such that each element 'i' of this array is a sum of 'a' except the element a[i]. You are not allowed to use '-' operator.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> SumNoMe(vector<int> vec){
	int n = vec.size();
	vector<int> res(n,0);
	int sum=0;
	for(int i=0;i<n;++i){
		res[i] += sum;
		sum += vec[i];
	}
	sum = 0;
	for(int i=n-1;i>=0;--i){
		res[i] += sum;
		sum += vec[i];
	}
	return res;
}

int main(int argc,char*argv[]){
	srand(time(NULL));
	int n = rand()%10;
	vector<int> vec;
	for(int i=0;i<n;++i){
		int tmp = rand()%n+1;
		cout << tmp << " ";
		vec.push_back(tmp);
	}
	cout << endl;
	vector<int> res = SumNoMe(vec);
	for(int i=0;i<res.size();++i){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
