/*
326. Power of Three My Submissions Question
Total Accepted: 8827 Total Submissions: 25129 Difficulty: Easy
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1){
            if(n%3==0) 
                n /= 3;
            else
                return false;
        }
        return (n==1);
    }
};


class Solution2 {
public:
    bool isPowerOfThree(int n) {
        int max_power3 = 1162261467;
        if(n<=0) return false;
        if(max_power3%n==0) return true;
        return false;
    }
};
