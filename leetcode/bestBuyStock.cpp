#include <iostream>
#include <vector>
using namespace std;
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
int maxProfit(vector<int> &prices) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	
	if(prices.size()==0||prices.size()==1) return 0;
	int mini = prices[0];
	//int e ＝ 0;
	int res = 0;
	for(int i=1;i<prices.size();++i){
		if(prices[i]<mini) mini = prices[i];
		else if(prices[i]-mini>res) res = prices[i]-mini;
	}
	return res;
}
int main(int argc,char*argv[]){
	return 0;
}
