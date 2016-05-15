/*
217. Contains Duplicate   My Submissions QuestionEditorial Solution
Total Accepted: 89484 Total Submissions: 215669 Difficulty: Easy
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> ss;
        for(int i=0;i<n;++i)
            ss.insert(nums[i]);
        if(ss.size()<n) return true;
        return false;
    }
};
