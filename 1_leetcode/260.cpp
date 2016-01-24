/*
260. Single Number III My Submissions Question
Total Accepted: 22418 Total Submissions: 53387 Difficulty: Medium
Given an array of numbers nums, 
in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant space complexity?

*/
/*lowbit :
a value bit and its negative number can get the value that only contains the lowest 1 bit
eg: 6=0110, 6&-6 = 0110&1010 = 0010 = 2
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int uncom = 0;
        for(int i=0;i<nums.size();++i){
            uncom = uncom^nums[i];
        }
        int lowbit = uncom&-uncom;
        int a=0,b=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]&lowbit)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        vector<int> res(2,0);
        res[0] = a;
        res[1] = b;
        return res;
    }
};
