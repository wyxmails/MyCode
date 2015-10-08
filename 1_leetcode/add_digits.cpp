/*
Add Digits My Submissions Question Solution 
Total Accepted: 30117 Total Submissions: 64580 Difficulty: Easy
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful.
*/
class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        if(num%9==0) return 9;
        return num%9;
    }
};


class Solution1 {
public:
    int addDigits(int num) {
        while(num>9){
            int tmp = 0;
            while(num>0){
                tmp += num%10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};
