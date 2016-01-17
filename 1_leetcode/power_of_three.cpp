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
