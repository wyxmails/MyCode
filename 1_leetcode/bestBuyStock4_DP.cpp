/*
Best Time to Buy and Sell Stock IV Total Accepted: 1425 Total Submissions: 8535 My Submissions Question Solution 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if(k*2>=n) return origSolve(prices);
        vector<int> mark(k*2+1,INT_MIN);
        mark[0] = 0;
        for(int i=0;i<n;++i){
            for(int j=1;j<=min(i+1,2*k);++j){
                int tmp = prices[i];
                if(j%2) tmp = -tmp;
                mark[j] = max(mark[j], mark[j-1]+tmp);
            }
        }
        return *max_element(mark.begin(),mark.end());
    }
    int origSolve(vector<int> &prices){
        int n = prices.size();
        int res = 0;
        for(int i=1;i<n;++i){
            int tmp = prices[i]-prices[i-1];
            res += (tmp>0?tmp:0);
        }
        return res;
    }
};
