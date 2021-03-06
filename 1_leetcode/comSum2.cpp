#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 Each number in C may only be used once in the combination.
 
Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 A solution set is: 
 [1, 7] 
 [1, 2, 5] 
 [2, 6] 
 [1, 1, 6] 
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
		tmpres = myComSum(candidates,target-candidates[i],i+1);
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
vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	sort(num.begin(),num.end());
	return myComSum(num,target,0);
}
void myCom(set<vector<int> > &setRes,vector<int>&cur,vector<int> &num, int target,int s){
        if(target<0) return;
        if(target==0){
            if(cur.size()>0) setRes.insert(cur);
            return;
        }
        int n = num.size();
        for(int i=s;i<n;++i){
            if(num[i]>target) return;
            cur.push_back(num[i]);
            myCom(setRes,cur,num,target-num[i],i+1);
            cur.pop_back();
        }
}
vector<vector<int> > combinationSum2_2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        set<vector<int> > setRes;
        vector<int> cur;
        myCom(setRes,cur,num,target,0);
        set<vector<int> >::iterator it = setRes.begin();
        vector<vector<int> > res;
        for(;it!=setRes.end();++it) res.push_back(*it);
        return res;
}


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        vector<int> mid;
        myCom(num,0,n,target,mid,res);
        return res;
    }
    void myCom(vector<int> &num,int cur,int len,int target,vector<int> &mid,vector<vector<int> >&res){
        if(target==0){
            res.push_back(mid);
            return;
        }
        for(int i=cur;i<len;++i){
            if(num[i]>target) break;
            if(i!=cur&&num[i]==num[i-1]) continue;
            mid.push_back(num[i]);
            myCom(num,i+1,len,target-num[i],mid,res);
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
	vector<vector<int> > res = combinationSum2(can,7);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
