/*
House Robber
Total Accepted: 894 Total Submissions: 3423

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        vector<pair<int,int> > mark(n,pair<int,int>(0,0));
        if(n<=0) return 0;
        mark[0].second = num[0];
        for(int i=1;i<n;++i){
            mark[i].first = max(mark[i-1].first,mark[i-1].second);
            mark[i].second = max(mark[i-1].first,mark[i-1].first+num[i]);
        }
        return max(mark[n-1].first,mark[n-1].second);
    }
};
