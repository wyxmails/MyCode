/*
342. Power of Four   My Submissions QuestionEditorial Solution
Total Accepted: 11305 Total Submissions: 33807 Difficulty: Easy
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        if(num&(num-1)) return false;
        if(num&0xaaaaaaaa) return false;
        return true;
    }
};
