#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7, 
 A solution set is: 
 [7] 
 [2, 2, 3] 
 */
vector<vector<int> > myComSum(vector<int> &candidates, int target,int s){
	vector<vector<int> > res;
	set<vector<int> > setres;
	res.clear();
	setres.clear();
	for(int i=s;i<candidates.size();++i){
		if(target<candidates[i]) break;
		if(target==candidates[i]){
			vector<int> vectmp;
			vectmp.clear();
			vectmp.push_back(candidates[i]);
			setres.insert(vectmp);
			break;
		}
		vector<vector<int> > tmpres;
		tmpres.clear();
		tmpres = myComSum(candidates,target-candidates[i],i);
		for(int j=0;j<tmpres.size();++j){
			tmpres[j].insert(tmpres[j].begin(),candidates[i]);
			setres.insert(tmpres[j]);
		}
	}
	set<vector<int> >::iterator it;
	for(it=setres.begin();it!=setres.end();++it){
		res.push_back(*it);
	}
	return res;
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(),candidates.end());
	return myComSum(candidates,target,0);
}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> mid;
        myCom(candidates,0,n,target,mid,res);
        return res;
    }
    void myCom(vector<int> &can,int cur,int len,int target,vector<int>&mid,vector<vector<int> >&res){
        if(target==0){
            res.push_back(mid);
            return;
        }
        for(int i=cur;i<len;++i){
            if(can[i]>target) break;
            //if(i+1<len&&can[i+1]==can[i]) continue;
            if(i!=cur&&can[i]==can[i-1]) continue;
            mid.push_back(can[i]);
            myCom(can,i,len,target-can[i],mid,res);
            mid.pop_back();
        }
    }
};

int main(int argc,char*argv[]){
	vector<int> can;
	can.push_back(2);
	can.push_back(3);
	can.push_back(6);
	can.push_back(7);
	vector<vector<int> > res = combinationSum(can,7);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
