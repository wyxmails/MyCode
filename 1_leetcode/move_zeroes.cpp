/*
Move Zeroes My Submissions Question Solution 
Total Accepted: 17404 Total Submissions: 42098 Difficulty: Easy
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = -1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                cur++;
                nums[cur] = nums[i];
            }
        }
        while(cur+1<nums.size()){
            cur++;
            nums[cur] = 0;
        }
    }
};
