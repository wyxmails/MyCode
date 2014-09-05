/*
 Find the first repeating element in an array of size n in O(n).

 Elements are in range.

 e.g 3,2,1,2,2,3

 The first repeating element is 3
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

int findFirstR(vector<int>&vec){
	unordered_map<int,int> mark;
	int n = vec.size();
	for(int i=0;i<n;++i){
		mark[vec[i]]++;
	}
	for(int i=0;i<n;++i)
		if(mark[vec[i]]>1) return vec[i];
}

int main(int argc,char*argv[]){
	vector<int> vec;
	srand(time(NULL));
	for(int i=0;i<10;++i){
		int tmp = rand()%4;
		vec.push_back(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	cout << findFirstR(vec) << endl;
	return 0;
}
