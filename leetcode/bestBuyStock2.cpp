#include <iostream>
#include <vector>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
int maxProfit(vector<int> &prices) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	int n = prices.size();
	if(n==0||n==1) return 0;
	vector<int> vec;
	vec.clear();
	int amt = 0;
	prices.push_back(prices.back());
	for(int i=0;i<=n;){
		if(vec.empty()||vec.back()<prices[i]) vec.push_back(prices[i++]);
		else{
			amt += vec.back()-vec.front();
			vec.clear();
		}
	}
	return amt;
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int mini = prices[0];
        int cur = 0;
        int res = 0;
        for(int i=1;i<=n;++i){
            if(i==n||prices[i]<prices[i-1]){
                if(i!=n) mini = prices[i];
                res += cur;
                cur = 0;
            }else cur = max(cur,prices[i]-mini);
        }
        return res;
    }
};

int main(int argc,char*argv[]){
	return 0;
}
