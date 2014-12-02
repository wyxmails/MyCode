/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> mid;
        vector<vector<int> > res;
        combine(1,n,k,mid,res);
        return res;
    }
    void combine(int cur,int n,int k,vector<int>&mid,vector<vector<int> >&res){
        if(mid.size()==k){
            res.push_back(mid);
            return;
        }
        if(cur>n) return;
        for(int i=cur;i<=n;++i){
            mid.push_back(i);
            combine(i+1,n,k,mid,res);
            mid.pop_back();
        }
    }
};
