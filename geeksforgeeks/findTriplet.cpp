/*
 There is a slight variation to a popular question.

 1. you are given an unsorted array with +ve and -ve numbers

 2. find a triplet which has the maximum product 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTriplet(vector<int> &vec){
	int n = vec.size();
	if(n<3){
		cerr << "ERROR: Must at least contain 3 members." << endl;
		return vec;
	}
	if(n==3) return vec;
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;++i) cout << vec[i] << " ";
	cout << endl;
	vector<int> res;
	int tmp1 = vec[n-1]*vec[n-2]*vec[n-3];
	int tmp2 = vec[n-1]*vec[0]*vec[1];
	if(tmp1>tmp2){
		res.push_back(vec[n-3]);
		res.push_back(vec[n-2]);
	}else{
		res.push_back(vec[0]);
		res.push_back(vec[1]);
	}
	res.push_back(vec[n-1]);
	return res;
}
int main(int argc,char*argv[]){
	vector<int> vec;
	srand(time(NULL));
	for(int r=0;r<3;++r){
		vec.clear();
		for(int i=0;i<10;++i){
			int tmp = rand()%15-10;
			vec.push_back(tmp);
			cout << tmp << " ";
		}
		cout << endl;
		vector<int> res = findTriplet(vec);
		for(int i=0;i<res.size();++i)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
