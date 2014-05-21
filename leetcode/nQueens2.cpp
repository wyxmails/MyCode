#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int mySolve(int n,vector<int>&mark){
	int size = mark.size();
	if(size==n) return 1;
	int cnt = 0;
	for(int j=1;j<=n;++j){
		bool flag = true;
		for(int k=0;k<size;++k){
			if(mark[k]==j){
				flag = false;
				break;
			}
			if(abs(mark[k]-j)==abs(size-k)){
				flag = false;
				break;
			}
		}
		if(!flag) continue;
		mark.push_back(j);
		cnt += mySolve(n,mark);
		mark.pop_back();
	}
	return cnt;
}
int totalNQueens(int n) {
	int cnt = 0;
	for(int i=1;i<=n;++i){
		vector<int> mark;
		mark.clear();
		mark.push_back(i);
		cnt += mySolve(n,mark);
	}
	return cnt;
}

int main(int argc,char*argv[]){
	int n;
	cin>>n;
	cout << totalNQueens(n) << endl;
	return 0;
}
