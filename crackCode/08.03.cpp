#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> mySet,vector<vector<int> > &res){
	int n = mySet.size();
	if(n>31) return;
	int total = 1<<(n-1);
	for(int i=0;i<=total;++i){
		vector<int> tmp;
		tmp.clear();
		for(int j=0;j<mySet.size();++j){
			if(i&(1<<j)) tmp.push_back(mySet[j]);
		}
		res.push_back(tmp);
	}
}

int main(int argc,char*argv[]){
	vector<int> vec;
	for(int i=0;i<5;++i){
		vec.push_back(i+1);
	}
	vector<vector<int> > res;
	subset(vec,res);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
