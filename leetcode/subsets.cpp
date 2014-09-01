/*
Subsets Total Accepted: 20382 Total Submissions: 73060
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        long long m = 1<<n;
        vector<vector<int> > res(m,vector<int>());
        if(n<=0) return res;
        sort(S.begin(),S.end());
        for(int i=0;i<m;++i){
            int bit=0;
            int tmp = i;
            while(tmp){
                if(1&tmp) res[i].push_back(S[bit]);
                tmp >>= 1;
                bit++;
            }
        }
        return res;
    }
};
