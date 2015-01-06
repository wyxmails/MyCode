/*
Factorial Trailing Zeroes Total Accepted: 4059 Total Submissions: 13582 My Submissions Question Solution 
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n>1){
            res += n/5;
            n /= 5;
        }
        return res;
    }
};
