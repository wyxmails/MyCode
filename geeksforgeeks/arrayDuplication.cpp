/*
 Suppose there is an array with n-1 elements. 
 Each of the elements fall in the range 1 to n. 
 All elements of the array are distinct, except one. 
 Find the two missing numbers between 1 and n which are not contained in the array.
 */
#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

vector<int> findMiss(vector<int> &vec,int n){
	unordered_map<int,int> mark;
	for(int i=0;i<n-1;++i){
		mark[vec[i]] = 1;
	}
	vector<int> res;
	for(int i=1;i<=n;++i){
		if(mark[i]==0)
			res.push_back(i);
	}
	return res;
}

vector<int> findMiss2(vector<int>&vec,int n){
	for(int i=0;i<n-1;++i){
		if(vec[i]!=i+1&&vec[i]<n){
			if(vec[vec[i]-1]!=vec[i]){
				int tmp = vec[i];
				vec[i] = vec[tmp-1];
			   	vec[tmp-1] = tmp;
				i--;
			}
		}
	}
	vector<int> res;
	for(int i=0;i<n-1;++i){
		if(vec[i]!=i+1)
			res.push_back(i+1);
	}
	if(res.size()==1) res.push_back(n);
	return res;
}

int main(int argc,char*argv[]){
	vector<int> vec;
	//vec.push_back(3);vec.push_back(3);
	vec.push_back(1);vec.push_back(1);
	vector<int> res = findMiss2(vec,3);
	for(int i=0;i<res.size();++i)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
