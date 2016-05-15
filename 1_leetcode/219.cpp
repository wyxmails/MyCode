/*
219. Contains Duplicate II   My Submissions QuestionEditorial Solution
Total Accepted: 58081 Total Submissions: 192909 Difficulty: Easy
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> ss;
        for(int i=0;i<n&&i<=k;++i){
            ss.insert(nums[i]);
        }
        if(ss.size()<k+1&&ss.size()<n) return true;
        for(int i=0,j=k+1;j<n;++i,++j){
            ss.erase(nums[i]);
            ss.insert(nums[j]);
            if(ss.size()<k+1) return true;
        }
        return false;
    }
};
