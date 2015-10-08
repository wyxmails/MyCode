/*
Power of Two My Submissions Question Solution 
Total Accepted: 31726 Total Submissions: 100333 Difficulty: Easy
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1){
            if(n%2) return false;
            n /= 2;
        }
        if(n<=0) return false;
        return true;
    }
};
