/*
Subsets II Total Accepted: 15791 Total Submissions: 58630 My Submissions
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        vector<vector<int> > res;
        vector<int> mid;
        res.push_back(mid);
        if(n==0) return res;
        mySub(S,0,n-1,mid,res);
        return res;
    }
    void mySub(vector<int> &S,int cur,int n,vector<int>&mid,vector<vector<int> >&res){
        mid.push_back(S[cur]);
        if(cur==n){
            res.push_back(mid);
            mid.pop_back();
            return;
        }
        res.push_back(mid);
        mySub(S,cur+1,n,mid,res);
        mid.pop_back();
        while(cur<n&&S[cur+1]==S[cur]) cur++;
        if(cur<n) mySub(S,cur+1,n,mid,res);
    }
};
