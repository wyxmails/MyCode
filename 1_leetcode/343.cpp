/*
343. Integer Break   My Submissions QuestionEditorial Solution
Total Accepted: 7913 Total Submissions: 19480 Difficulty: Medium
Given a positive integer n, 
break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
*/

class Solution {
public:
    int integerBreak(int n) {
        if(n<1000&&arr[n]>0)
            return arr[n];
        if(n<=3){
            arr[n] = n-1;
            return arr[n];
        }
        if(n==4){
            arr[n] = n;
            return arr[n];
        }
        int res = 1;
        for(int i=2;i<=n/2;++i){
            int left = integerBreak(i);
            int right = integerBreak(n-i);
            left = max(left,i);
            right = max(right,n-i);
            res = max(left*right,res);
        }
        arr[n] = res;
        return res;
    }
private:
    int arr[1000];
};
