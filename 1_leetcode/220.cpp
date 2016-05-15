/*
220. Contains Duplicate III   My Submissions QuestionEditorial Solution
Total Accepted: 27955 Total Submissions: 150173 Difficulty: Medium
Given an array of integers, 
find out whether there are two distinct indices i and j in the array 
such that the difference between nums[i] and nums[j] is at most t 
and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        int n = nums.size();
        if(k<t){
            for(int i=0;i<n;++i){
                for(int j=i+1;j<=i+k&&j<n;++j){
                    if(abs((long long)nums[i]-(long long)nums[j])<=t)
                        return true;
                }
            }
            return false;
        }
        set<int> ss;
        for(int i=0;i<n&&i<=k;++i){
            for(int j=0;j<=t;++j){
                ss.insert(nums[i]+j);
            }
        }
        if(ss.size()<(k+1)*(t+1)&&ss.size()<n*(t+1))
            return true;
        for(int i=0,j=k+1;j<n;++i,++j){
            for(int m=0;m<=t;++m){
                ss.erase(nums[i]+m);
            }
            for(int m=0;m<=t;++m){
                ss.insert(nums[j]+m);
            }
            if(ss.size()<(k+1)*(t+1))
                return true;
        }
        return false;
    }
};
