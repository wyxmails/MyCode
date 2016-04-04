/*
338. Counting Bits My Submissions QuestionEditorial Solution
Total Accepted: 11219 Total Submissions: 20082 Difficulty: Medium
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? 
Do it without using any builtin function like __builtin_popcount 
in c++ or in any other language.
Hint:

You should make use of what you have produced already.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        int power = 1;
        int run = 1;
        vector<int> res(num+1,0);
        res[1] = 1;
        for(int i=2;i<=num;++i){
            if(2*power==i){
                res[i] = 1;
                run = 1;
                power = i;
            }else
                res[i] = res[run++]+1;
        }
        return res;
    }
};
