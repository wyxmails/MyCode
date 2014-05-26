#include <iostream>
#include <vector>
using namespace std;
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 
Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
int maxProfit(vector<int> &prices) {
	int n = prices.size();
	if(n<=1) return 0;
	int left[n];
	int right[n];
	left[0]=0;
	right[n-1] = 0;
	int Min = prices[0];
	int Max = prices[n-1];
	for(int i=1;i<n;++i){
		if(prices[i]<Min){
		   	Min = prices[i];
			left[i] = left[i-1];
		}else{
			if(prices[i]-Min>left[i-1]) left[i] = prices[i]-Min;
			else left[i] = left[i-1];
			cout << left[i] << endl;
		}
		if(prices[n-i-1]>Max){
		   	Max = prices[n-i-1];
			right[n-i-1] = right[n-i];
		}else{
			if(Max-prices[n-i-1]>right[n-i]) right[n-i-1] = Max-prices[n-i-1];
			else right[n-i-1] = right[n-i];
		}
	}
	int res = 0;
	for(int i=0;i+1<n;++i){
		cout << "left[" << i << "]: " << left[i] << endl;
		cout << "right[" << i+1 << "]: " << right[i+1] << endl;
		if(left[i]+right[i+1]>res) res = left[i]+right[i+1];
	}
	cout << "left[n-1]: " << left[n-1] << endl;
	if(left[n-1]>res) res = left[n-1];
	return res;
}
int main(int argc,char *argv[]){
	vector<int> prices;
	prices.push_back(2);
	prices.push_back(1);
	cout << maxProfit(prices) << endl;
	return 0;
}
