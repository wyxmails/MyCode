/*
 Write a method to return all subsets of a set.
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > AllSubSets(set<int> set_nums){
	int n = set_nums.size();
	int group_nums = 1<<n;
	vector<vector<int> > res;
	set<int>::iterator it=set_nums.begin();
	vector<int> store;
	for(;it!=set_nums.end();++it) store.push_back(*it);
	for(int i=0;i<group_nums;++i){
		vector<int> vec;
		for(int j=0;j<n;++j){
			if(i&(1<<j)){
			   	vec.push_back(store[j]);
			}
		}
		res.push_back(vec);
	}
	return res;
}

void AllSubSetsRecursive(const vector<int> &vec_nums,int index,vector<vector<int> > &res){
	int n = res.size();
	if(index>=vec_nums.size()) return;
	for(int i=0;i<n;++i){
		vector<int> vec = res[i];
		vec.push_back(vec_nums[index]);
		res.push_back(vec);
	}
	AllSubSetsRecursive(vec_nums,index+1,res);
}
vector<vector<int> > AllSubSetsRecursive(set<int> set_nums){
	vector<int> vec;
	vector<vector<int> > res;
	res.push_back(vec);
	set<int>::iterator it = set_nums.begin();
	for(;it!=set_nums.end();++it) vec.push_back(*it);
	AllSubSetsRecursive(vec,0,res);
	return res;
}

int main(int argc,char*argv[]){
	set<int> set_nums;
	srand(time(NULL));
	int n = rand()%5;
	cout << "n: " << n << endl;
	int tmp=0;
	for(int i=0;i<n;++i){
		tmp = tmp + rand()%10 +1;
		cout << tmp << " ";
		set_nums.insert(tmp);
	}
	cout << endl;
	cout << "combinatories" << endl;
	vector<vector<int> > res = AllSubSets(set_nums);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << ",";
		cout << endl;
	}
	cout << "recursive: " << endl;
	res = AllSubSetsRecursive(set_nums);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout << res[i][j] << ",";
		cout << endl;
	}
	return 0;
}
