/*
322. Coin Change My Submissions Question
Total Accepted: 1542 Total Submissions: 5996 Difficulty: Medium
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
       vector<int> f(amount+1,amount+1);
        f[0] = 0;
        for(int j=0;j<amount;++j)
        for(int i=0;i<coins.size();++i){
            if(j+coins[i]<=amount){
                f[j+coins[i]] = min(f[j+coins[i]],f[j]+1);
            }
        }
        return f[amount]==amount+1?-1:f[amount];
    }
};
