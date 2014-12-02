/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<string> > mySolveQ(int n,vector<int> &mark){
	vector<vector<string> > res;
	int size = mark.size();
	if(n==size){
		vector<string> vec;
		vec.clear();
		for(int i=0;i<n;++i){
			string s = "";
			for(int j=1;j<mark[i];++j) s += ".";
			s += "Q";
			for(int j=mark[i]+1;j<=n;++j) s += ".";
			vec.push_back(s);
		}
		res.push_back(vec);
		return res;
	}
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
		vector<vector<string> > tmp= mySolveQ(n,mark);
		res.insert(res.end(),tmp.begin(),tmp.end());
		mark.pop_back();
	}
	return res;
}
vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > res;
	for(int i=1;i<=n;++i){
		vector<int> mark;
		mark.clear();
		mark.push_back(i);
		vector<vector<string> > tmp = mySolveQ(n,mark);
		if(tmp.size()) res.insert(res.end(),tmp.begin(),tmp.end());
	}
	return res;
}

class Solution {
public:
    bool legal(int n,int r,int c,const vector<int> &mark){
        for(int i=0;i<n;++i){
            if(mark[i]==-1) continue;
            if(mark[i]==c) return false;
            if(abs(mark[i]-c)==abs(i-r)) return false;
        }
        return true;
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> mark(n,-1);
        mySol(0,n,mark,res);
        return res;
    }
    void mySol(int r,int n,vector<int>&mark,vector<vector<string> >&res){
        if(r==n){
            vector<string> mid(n,string(n,'.'));
            for(int i=0;i<n;++i){
                mid[i][mark[i]] = 'Q';
            }
            res.push_back(mid);
        }
        for(int i=0;i<n;++i){
            if(legal(n,r,i,mark)){
                mark[r] = i;
                mySol(r+1,n,mark,res);
                mark[r] = -1;
            }
        }
    }
};

int main(int argc,char*argv[]){
	int n;
	cin>>n;
	vector<vector<string> > res = solveNQueens(n);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j){
			cout << res[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}
